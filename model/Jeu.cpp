#include "Jeu.hpp"
#include "Agent.hpp"
#include "Agent/Lapin.hpp"
#include "Agent/Rocher.hpp"
#include "Agent/Mur.hpp"
#include "Agent/Eau.hpp"
#include "Agent/Mot.hpp"
#include "Word.hpp"

Jeu::Jeu() : plateau(23, 23)
{
    // Initialise les règles
    // regles.addRule(ObjectType::BABA, Property::YOU);
    // regles.addRule(ObjectType::ROCK, Property::PUSH);
    // regles.addRule(ObjectType::WALL, Property::STOP);
    // regles.addRule(ObjectType::FLAG, Property::WIN);
    // regles.addRule(ObjectType::BABA, Property::STOP);
    // // regles.addRule(ObjectType::BABA, Property::PUSH);
    // regles.addRule(ObjectType::TEXT, Property::PUSH);

    // Initialise la map de test
    initTestMap();
    regles.print();
}

Jeu::~Jeu()
{
    // destruction propre des agents
    for (Agent *a : agents)
        delete a;
}

void Jeu::ajouterAgent(Agent *a)
{
    agents.push_back(a);
}

void Jeu::initTestMap()
{
    // --- Lapins ---
    Lapin *l0 = new Lapin(plateau.getCase(4, 4), regles);
    plateau.getCase(4, 4)->ajouterAgent(l0);
    agents.push_back(l0);
    joueur.push_back(l0);

    Lapin *l1 = new Lapin(plateau.getCase(4, 4), regles);
    plateau.getCase(4, 4)->ajouterAgent(l1);
    agents.push_back(l1);
    joueur.push_back(l1);

    Lapin *l2 = new Lapin(plateau.getCase(4, 4), regles);
    plateau.getCase(4, 4)->ajouterAgent(l2);
    agents.push_back(l2);
    joueur.push_back(l2);

    // --- Rochers ---
    Rocher *r1 = new Rocher(plateau.getCase(0, 1), regles);
    plateau.getCase(0, 1)->ajouterAgent(r1);
    agents.push_back(r1);

    Rocher *r2 = new Rocher(plateau.getCase(0, 2), regles);
    plateau.getCase(0, 2)->ajouterAgent(r2);
    agents.push_back(r2);

    // --- Mur ---
    Mur *m = new Mur(plateau.getCase(1, 7), regles);
    plateau.getCase(1, 7)->ajouterAgent(m);
    agents.push_back(m);

    // --- Eau ---
    Eau *e = new Eau(plateau.getCase(1, 5), regles);
    plateau.getCase(1, 5)->ajouterAgent(e);
    agents.push_back(e);

    // BABA IS YOU
    Mot *baba = new Mot(plateau.getCase(4, 5), Word::BABA, regles);
    plateau.getCase(4, 5)->ajouterAgent(baba);
    agents.push_back(baba);

    Mot *is = new Mot(plateau.getCase(4, 6), Word::IS, regles);
    plateau.getCase(4, 6)->ajouterAgent(is);
    agents.push_back(is);

    Mot *you = new Mot(plateau.getCase(4, 7), Word::YOU, regles);
    plateau.getCase(4, 7)->ajouterAgent(you);
    agents.push_back(you);

    // WALL IS STOP
    Mot *wall = new Mot(plateau.getCase(7, 7), Word::WALL, regles);
    plateau.getCase(7, 7)->ajouterAgent(wall);
    agents.push_back(wall);

    Mot *is2 = new Mot(plateau.getCase(7, 8), Word::IS, regles);
    plateau.getCase(7, 8)->ajouterAgent(is2);
    agents.push_back(is2);

    Mot *stop = new Mot(plateau.getCase(7, 9), Word::STOP, regles);
    plateau.getCase(7, 9)->ajouterAgent(stop);
    agents.push_back(stop);

    // ROCK IS PUSH
    Mot *rock = new Mot(plateau.getCase(10, 3), Word::ROCK, regles);
    plateau.getCase(10, 3)->ajouterAgent(rock);
    agents.push_back(rock);

    Mot *is3 = new Mot(plateau.getCase(10, 4), Word::IS, regles);
    plateau.getCase(10, 4)->ajouterAgent(is3);
    agents.push_back(is3);

    Mot *push = new Mot(plateau.getCase(10, 5), Word::PUSH, regles);
    plateau.getCase(10, 5)->ajouterAgent(push);
    agents.push_back(push);
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
            cout << "is STOP or NOT YOU" << endl;
            cout << toString(a->getType()) << endl;
            return false;
        }
    }

    for (Agent *a : cible->getAgents())
    {
        if (aDejaBouge(a))
        {
            cout << "j'ai déja bougé" << endl;
            marqueCommeDemandeur(a);
        }
    }

    if (cible->getAgents().empty() || cible->ToutSuperposable())
    {
        cout << "baba ou rien devant moi" << endl;
        deplacerAgents(c, cible, agentjoueur);
        return true;
    }

    bool res = deplaceRec(nv_direction, cible, agentjoueur);

    if (res)
    {
        cout << "rec" << endl;
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
            cout << "a deja bougé" << endl;
            supprimerDeDemandeur(a);
            continue;
        }

        else if (!aDejaBouge(a) && !demandeuraDejaBouge() && a != demandeur)
        {
            cout << toString(a->getType()) << endl;
            cout << "je dois pas bouger car derriere il a déja bougé" << endl;
            continue;
        }

        else if ((a->isYou() && a == demandeur))
        {
            aDeplacer.clear();
            aDeplacer.push_back(a);
            cout << "you se deplace" << endl;
            break;
        }

        else if (a->isPush())
        {
            cout << "is push se déplace" << endl;
            aDeplacer.push_back(a);
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
        cout << "prochain lapin" << endl;
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

void Jeu::MajRegle() {
    cout << "entrée dans majregle" << endl;
    regles = plateau.parseRegle();
    VerifJoueur();
}

void Jeu::VerifJoueur() {
    joueur.clear();
    for (Agent *a : agents){
        if(a->isYou()) {
            joueur.push_back(a);
        }
    }
}

