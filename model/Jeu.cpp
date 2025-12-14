#include "Jeu.hpp"
#include "Lapin.hpp"
#include "Rocher.hpp"
#include "Mur.hpp"
#include "Eau.hpp"

Jeu::Jeu() : plateau(23, 23)
{

    // Initialise les règles
    rules.addRule(ObjectType::BABA, Property::YOU);
    rules.addRule(ObjectType::ROCK, Property::PUSH);
    rules.addRule(ObjectType::WALL, Property::STOP);
    rules.addRule(ObjectType::FLAG, Property::WIN);
    rules.addRule(ObjectType::BABA, Property::STOP);
    rules.addRule(ObjectType::BABA, Property::PUSH);

    // Initialise la map de test
    initTestMap();
    rules.print();
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
    Lapin *l0 = new Lapin(plateau.getCase(0, 0), rules);
    plateau.getCase(0, 0)->ajouterAgent(l0);
    agents.push_back(l0);
    joueur.push_back(l0);

    Lapin *l1 = new Lapin(plateau.getCase(0, 0), rules);
    plateau.getCase(0, 0)->ajouterAgent(l1);
    agents.push_back(l1);
    joueur.push_back(l1);

    Lapin *l2 = new Lapin(plateau.getCase(0, 0), rules);
    plateau.getCase(0, 0)->ajouterAgent(l2);
    agents.push_back(l2);
    joueur.push_back(l2);

    // --- Rochers ---
    Rocher *r1 = new Rocher(plateau.getCase(0, 1), rules);
    plateau.getCase(0, 1)->ajouterAgent(r1);
    agents.push_back(r1);

    Rocher *r2 = new Rocher(plateau.getCase(0, 2), rules);
    plateau.getCase(0, 2)->ajouterAgent(r2);
    agents.push_back(r2);

    // --- Mur ---
    Mur *m = new Mur(plateau.getCase(1, 7), rules);
    plateau.getCase(1, 7)->ajouterAgent(m);
    agents.push_back(m);

    // --- Eau ---
    Eau *e = new Eau(plateau.getCase(1, 5), rules);
    plateau.getCase(1, 5)->ajouterAgent(e);
    agents.push_back(e);
}

bool Jeu::aDejaBouge(Agent *a)
{
    return std::find(dejaBouges.begin(), dejaBouges.end(), a) != dejaBouges.end();
}

void Jeu::marqueCommeBouge(Agent *a)
{
    dejaBouges.push_back(a);
}

/**
On appelle recursivement sur tous les agents en direction de nv_direct et si un retourne false alors nous ne pouvons pas faire le déplacement
car il y aura un obstacle (ou fin de map) et si c'est vrai alors nous bougeons tous les agents poussable dans la liste
des cases sur le chemin */
// bool Jeu::deplaceRec(pair<int, int> nv_direction, Case *c, Agent *agentjoueur)
// {
//     // au cas ou mais impossible normalement car un joueur à toujours une case mais sécurité
//     if (c != nullptr)
//     {
//         // check les booléans de ses agents sur la case
//         // si ok appeler sur case cible
//         // sinon false arret recursion;
//         Case *cible = plateau.getCase(c->getX() + nv_direction.first, c->getY() + nv_direction.second);

//         for (size_t i = 0; i < c->getAgents().size(); i++)
//         {
//             Agent *a = c->getAgents().at(i);
//             /*si dans notre case actuelle ou les suivantes il y a un élément pas poussable*/
//             if (a->isStop() && !(a->isYou()))
//             {
//                 cout << "is STOP or NOT YOU" << endl;
//                 cout << toString(a->getType()) << endl;
//                 return false;
//             }

//             // if ()
//             // {
//             //     cout << "is not YOU" << endl;
//             //     cout << toString(a->getType()) << endl;
//             //     return false;
//             // }
//         }

//         if (cible != nullptr)
//         {
//             /*si la cible est vide ou contient uniquement des baba*/
//             /*nos cas d'arrêts*/
//             if (cible->getAgents().empty() || /*cible->containBaba_only() ||*/ cible->ToutSuperposable())
//             {
//                 for (size_t i = 0; i < c->getAgents().size(); i++)
//                 {
//                     // on déplace
//                     Agent *a = c->getAgents().at(i);
//                     /*si c'est poussable ou que c'est notre agent qu'on doit déplacer*/
//                     /*TODO: est-ce que getBaba est vraiment utile ? si a==agent alors c'est forcément un baba ?*/
//                     if (a->isPush() || (a->isYou() && a == agentjoueur))
//                     {
//                         a->setCaseActuelle(cible);
//                         c->retirerAgent(a);
//                         cible->ajouterAgent(a);
//                     }
//                 }
//                 return true;
//             }
//             bool res = deplaceRec(nv_direction, cible, agentjoueur);
//             if (res)
//             {
//                 for (size_t i = 0; i < c->getAgents().size(); i++)
//                 {
//                     // on déplace
//                     Agent *a = c->getAgents().at(i);
//                     if (a->isPush() || (a->isYou() && a == agentjoueur))
//                     {
//                         a->setCaseActuelle(cible);
//                         c->retirerAgent(a);
//                         cible->ajouterAgent(a);
//                     }
//                 }
//                 return true; // on avait un petit probleme mais réglé ici en effet il faut retourner true seulement si res == true sinon false
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         else
//         {
//             // nous sommes arrivé aux bornes
//             return false;
//         }
//     }
//     // il n'est pas poussable
//     return false;
// }

bool Jeu::deplaceRec(pair<int, int> nv_direction, Case *c, Agent *agentjoueur)
{
    // au cas ou mais impossible normalement car un joueur à toujours une case mais sécurité

    if (!c)
        return false;

    // check les booléans de ses agents sur la case
    // si ok appeler sur case cible
    // sinon false arret recursion;
    Case *cible = plateau.getCase(c->getX() + nv_direction.first, c->getY() + nv_direction.second);
    if (!cible)
        return false; // sortie du plateau
    
    for (Agent *a : cible->getAgents()) 
    {
        //  Agent *a = c->getAgents().at(i);
        /*si dans notre case actuelle ou les suivantes il y a un élément pas poussable*/
        if (a->isStop() && !(a->isYou()))
        {
            cout << "is STOP or NOT YOU" << endl;
            cout << toString(a->getType()) << endl;
            return false;
        }
    }

    /*si la cible est vide ou contient uniquement des baba*/
    /*nos cas d'arrêts*/

    if (cible->getAgents().empty() || /*cible->containBaba_only() ||*/ cible->ToutSuperposable())
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
            continue;
        else if ((a->isYou() && a == demandeur))
        {
            aDeplacer.clear();
            aDeplacer.push_back(a);
            break;
        }
        else if (a->isPush())
        {
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
    // if (d == Direction::Droite || d == Direction::Bas)
    // {

    //     vector<Agent *>::iterator it = joueur.end() - 1;
    //     while (it != joueur.begin())
    //     {
    //         Case *courant = (*it)->getCaseActuelle();

    //         deplaceRec(nv_direction, courant, *it);
    //         it--;
    //     }
    //     if (it == joueur.begin())
    //     {
    //         Case *courant = (*it)->getCaseActuelle();

    //         deplaceRec(nv_direction, courant, *it);
    //     }
    //     dejaBouges.clear();
    // }
    // else
    // {
    vector<Agent *>::iterator it = joueur.begin();
    for (it = joueur.begin(); it != joueur.end(); ++it)
    {
        if (aDejaBouge(*it))
            continue;

        Case *courant = (*it)->getCaseActuelle();
        deplaceRec(nv_direction, courant, *it);
    }

    // for (size_t i = 0; i < joueur.size(); i++)
    // {
    //     Agent &a = *(joueur.at(i));
    //     if (aDejaBouge(&a))
    //         continue;
    //     Case *courant = a.getCaseActuelle();

    //     cout << i << endl;

    //     deplaceRec(nv_direction, courant, &a);
    //     // deplacer liste
    // }
    dejaBouges.clear();
    //  }
}

const Plateau &Jeu::getPlateau() const
{
    return plateau;
}