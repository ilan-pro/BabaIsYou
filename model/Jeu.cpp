#include "Jeu.hpp"
#include "Agent.hpp"
#include "Agent/Lapin.hpp"
#include "Agent/Rocher.hpp"
#include "Agent/Mur.hpp"
#include "Agent/Eau.hpp"
#include "Agent/Mot.hpp"
#include "Agent/Drapeau.hpp"
#include "Word.hpp"

Jeu::Jeu() : plateau(27, 22), closeWin{false} 
{
    initTestMap();
    regles.print();
}

Jeu::~Jeu()
{
    // destruction propre des agents
    for (Agent *a : agents){
        delete a;
    }
    for (EtatJeu *e : undoStack){
        delete e;
    }
    for (EtatJeu *e : redoStack){
        delete e;
    }
}

void Jeu::ajouterAgent(Agent *a)
{
    agents.push_back(a);
}

template<typename T>
T* Jeu::spawnAgent(int x, int y, bool estJoueur)
{
    Case* c = plateau.getCase(x, y);
    T* a = new T(c, regles);
    c->ajouterAgent(a);
    agents.push_back(a);
    if(estJoueur) {
        joueur.push_back(a);
    }
    return a;
}

Mot* Jeu::spawnMot(int x, int y, Word w)
{
    Case* c = plateau.getCase(x, y);
    Mot* a = new Mot(c, w, regles);
    c->ajouterAgent(a);
    agents.push_back(a);
    return a;
}


void Jeu::initTestMap()
{
    spawnAgent<Lapin>(4, 4, true);
    spawnAgent<Drapeau>(8, 4, false);
    spawnAgent<Rocher>(1, 1, false);
    spawnAgent<Rocher>(1, 2, false);
    // pour faire une ligne de mur (plus simple)
    for(int i=0; i<10; i++) {
        spawnAgent<Mur>(1, 7+i, false);
    }
    spawnAgent<Eau>(1, 5, false);
    spawnAgent<Rocher>(1, 1, false);
    
    // BABA IS YOU
    spawnMot(4, 5, Word::BABA);
    spawnMot(4, 6, Word::IS);
    spawnMot(4, 7, Word::YOU);

    // WALL IS STOP
    spawnMot(7, 7, Word::WALL);
    spawnMot(7, 8, Word::IS);
    spawnMot(7, 9, Word::STOP);

    // ROCK IS PUSH
    spawnMot(10, 3, Word::ROCK);
    spawnMot(10, 4, Word::IS);
    spawnMot(10, 5, Word::PUSH);

    // FLAG IS WIN
    spawnMot(15, 3, Word::FLAG);
    spawnMot(15, 4, Word::IS);
    spawnMot(15, 5, Word::WIN);
}

bool Jeu::aDejaBouge(Agent *a)
{
    return std::find(dejaBouges.begin(), dejaBouges.end(), a) != dejaBouges.end();
}

bool Jeu::demandeuraDejaBouge()
{
    return demandeur.empty();
}

void Jeu::marqueCommeBouge(Agent *a)
{
    dejaBouges.push_back(a);
}
void Jeu::marqueCommeDemandeur(Agent *a)
{
    demandeur.push_back(a);
}

void Jeu::supprimerDeDemandeur(Agent *a)
{
    demandeur.erase(
        std::remove(demandeur.begin(), demandeur.end(), a),
        demandeur.end());
}

bool Jeu::deplaceRec(pair<int, int> nv_direction, Case *c, Agent *agentjoueur)
{
    if (!c)
        return false;

    Case *cible = plateau.getCase(c->getX() + nv_direction.first, c->getY() + nv_direction.second);
    if (!cible)
        return false; // sortie du plateau

    for (Agent *a : cible->getAgents())
    {
        if (a->isStop() && !(a->isYou()))
        {
            // cout << "is STOP or NOT YOU" << endl;
            // cout << toString(a->getType()) << endl;
            return false;
        }
    }

    for (Agent *a : cible->getAgents())
    {
        if (aDejaBouge(a))
        {
            // cout << "j'ai déja bougé" << endl;
            marqueCommeDemandeur(a);
        }
    }

    if (cible->getAgents().empty() || cible->ToutSuperposable())
    {
        // cout << "baba ou rien devant moi" << endl;
        deplacerAgents(c, cible, agentjoueur);
        return true;
    }

    bool res = deplaceRec(nv_direction, cible, agentjoueur);

    if (res)
    {
        // cout << "rec" << endl;
        deplacerAgents(c, cible, agentjoueur);
        return true;
    }
    else
    {
        return false;
    }
}

void Jeu::deplacerAgents(Case *src, Case *dst, Agent *demandeur)
{

    vector<Agent *> aDeplacer;

    for (Agent *a : src->getAgents())
    {
        if (aDejaBouge(a))
        {
            // cout << "a deja bougé" << endl;
            supprimerDeDemandeur(a);
            continue;
        }

        else if (!aDejaBouge(a) && !demandeuraDejaBouge() && a != demandeur)
        {
            // cout << toString(a->getType()) << endl;
            // cout << "je dois pas bouger car derriere il a déja bougé" << endl;
            continue;
        }

        else if ((a->isYou() && a == demandeur))
        {
            aDeplacer.clear();
            aDeplacer.push_back(a);
            // cout << "you se deplace" << endl;
            break;
        }

        else if (a->isPush())
        {
            // cout << "is push se déplace" << endl;
            aDeplacer.push_back(a);
        }
        else if (a->isWin())
        {
            closeWin = true;
        }
    }

    // On déplace après avoir fini de parcourir
    for (Agent *a : aDeplacer)
    {
        src->retirerAgent(a);
        dst->ajouterAgent(a);
        a->setCaseActuelle(dst);
        marqueCommeBouge(a);
    }
}

void Jeu::deplace(Direction d)
{
    pair<int, int> nv_direction = directionToPair(d);
    vector<Agent *>::iterator it = joueur.begin();
    for (it = joueur.begin(); it != joueur.end(); ++it)
    {

        if (aDejaBouge(*it))
        {
            continue;
        }
        // cout << "prochain lapin" << endl;
        Case *courant = (*it)->getCaseActuelle();
        deplaceRec(nv_direction, courant, *it);
        demandeur.clear();
    }
    demandeur.clear();
    dejaBouges.clear();
}

const Plateau &Jeu::getPlateau() const
{
    return plateau;
}

void Jeu::MajRegle()
{
    // cout << "entrée dans majregle" << endl;
    regles = plateau.parseRegle();
    VerifJoueur();
}

void Jeu::VerifJoueur()
{
    joueur.clear();
    for (Agent *a : agents)
    {
        if (a->isYou())
        {
            joueur.push_back(a);
        }
    }
}

vector<Agent *> Jeu::getAgents() const
{
    return agents;
}

Regles Jeu::getRule() const
{
    return regles;
}

void Jeu::sauvegarderEtat()
{
    cout << "sauvegarderEtat" << endl;
    EtatJeu *j = new EtatJeu(*this);

    undoStack.push_back(j);

    for (EtatJeu *e : redoStack)
        delete e;
    redoStack.clear();
}

void Jeu::undo()
{
    if (undoStack.empty())
    {
        cout << "undo vide" << endl;
        return;
    }
    else
    {
        cout << "undo pas vide" << endl;

        EtatJeu *j = new EtatJeu(*this);
        redoStack.push_back(j);

        EtatJeu *prev = undoStack.back();
        undoStack.pop_back();

        restaurer(prev);
        delete prev;
    }
}

void Jeu::redo()
{
    if (redoStack.empty())
    {
        cout << "redo empty" << endl;
        return;
    }
    else
    {
        cout << " redo je suis pas vide" << endl;
        EtatJeu *j = new EtatJeu(*this);

        undoStack.push_back(j);

        EtatJeu *next = redoStack.back();
        redoStack.pop_back();

        restaurer(next);
        delete next;
    }
}

void Jeu::restaurer(const EtatJeu *etat)
{
    for (Agent *a : agents)
        delete a;
    agents.clear();

    for (Agent *a : etat->agents)
    {
        agents.push_back(a->clone());
    }
    VerifJoueur();

    plateau = Plateau(etat->plateau, agents);

    regles = etat->regles;
}
