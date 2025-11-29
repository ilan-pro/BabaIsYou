#include "Jeu.hpp"
#include "Lapin.hpp"
#include "Rocher.hpp"
#include "Mur.hpp"
#include "Eau.hpp"

Jeu::Jeu() : plateau(23, 23)
{
    Lapin *l = new Lapin(false, false, false, true, plateau.getCase(0, 0));
    Case *c = plateau.getCase(0, 0);
    c->ajouterAgent(l);
    agents.push_back(l);
    joueur.push_back(l);

    Lapin *l2 = new Lapin(false, false, false, true, plateau.getCase(0, 1));
    Case *c5 = plateau.getCase(0, 1);
    c5->ajouterAgent(l2);
    agents.push_back(l2);
    joueur.push_back(l2);

    Rocher *r = new Rocher(true, false, false, false, plateau.getCase(1, 1));
    Case *c1 = plateau.getCase(1, 1);
    c1->ajouterAgent(r);
    agents.push_back(r);
    Rocher *r2 = new Rocher(true, false, false, false, plateau.getCase(1, 2));
    Case *c2 = plateau.getCase(1, 2);
    c2->ajouterAgent(r2);
    agents.push_back(r2);

    Mur *m = new Mur(false, false, true, false, plateau.getCase(1, 7));

    Case *c3 = plateau.getCase(1, 7);
    c3->ajouterAgent(m);
    agents.push_back(m);

    Eau *e = new Eau(false, false, false, false, plateau.getCase(1, 5));

    Case *c4 = plateau.getCase(1, 5);
    c4->ajouterAgent(e);
    agents.push_back(e);

    // Lapin *m1 = new Lapin(plateau.getCase(0, 0), );
    // Lapin *m2 = new Lapin(plateau.getCase(20, 0));
    // Lapin *m3 = new Lapin(plateau.getCase(0, 20));
    // Lapin *m4 = new Lapin(plateau.getCase(21, 21));

    // Case *c1 = plateau.getCase(0, 0);
    // Case *c2 = plateau.getCase(20, 0);
    // Case *c3 = plateau.getCase(0, 20);
    // Case *c4 = plateau.getCase(21, 21);

    // c1->ajouterAgent(m1);
    // c2->ajouterAgent(m2);
    // c3->ajouterAgent(m3);
    // c4->ajouterAgent(m4);

    // agents.push_back(m1);
    // agents.push_back(m2);
    // agents.push_back(m3);
    // agents.push_back(m4);

    // joueur.push_back(m1);
    // joueur.push_back(m2);
    // joueur.push_back(m3);
    // joueur.push_back(m4);
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

/**
On appelle recursivement sur tous les agents en direction de nv_direct et si un retourne false alors nous ne pouvons pas faire le déplacement
car il y aura un obstacle (ou fin de map) et si c'est vrai alors nous bougeons tous les agents poussable dans la liste
des cases sur le chemin */
bool Jeu::deplaceRec(pair<int, int> nv_direction, Case *c, Agent *agentjoueur)
{
    // au cas ou mais impossible normalement car un joueur à toujours une case mais sécurité
    if (c != nullptr)
    {
        // check les booléans de ses agents sur la case
        // si ok appeler sur case cible
        // sinon false arret recursion;
        Case *cible = plateau.getCase(c->getX() + nv_direction.first, c->getY() + nv_direction.second);

        for (size_t i = 0; i < c->getAgents().size(); i++)
        {
            Agent *a = c->getAgents().at(i);
            /*si dans notre case actuelle ou les suivantes il y a un élément pas poussable*/
            if (a->getStop())
            {
                return false;
            }
        }
        
        if (cible != nullptr)
        {
            /*si la cible est vide ou contient uniquement des baba*/
            /*nos cas d'arrêts*/
            if (cible->getAgents().empty() || /*cible->containBaba_only() ||*/ cible->ToutSuperposable())
            {
                for (size_t i = 0; i < c->getAgents().size(); i++)
                {
                    // on déplace
                    Agent *a = c->getAgents().at(i);
                    /*si c'est poussable ou que c'est notre agent qu'on doit déplacer*/
                    /*TODO: est-ce que getBaba est vraiment utile ? si a==agent alors c'est forcément un baba ?*/
                    if (a->getPousse() || (a->getBaba() && a == agentjoueur))
                    {
                        a->setCaseActuelle(cible);
                        c->retirerAgent(a);
                        cible->ajouterAgent(a);
                    }
                }
                return true;
            }
            bool res = deplaceRec(nv_direction, cible, agentjoueur);
            if (res)
            {
                for (size_t i = 0; i < c->getAgents().size(); i++)
                {
                    // on déplace
                    Agent *a = c->getAgents().at(i);
                    if (a->getPousse() || (a->getBaba() && a == agentjoueur))
                    {
                        a->setCaseActuelle(cible);
                        c->retirerAgent(a);
                        cible->ajouterAgent(a);
                    }
                }
                return true; // on avait un petit probleme mais réglé ici en effet il faut retourner true seulement si res == true sinon false
            }
            else
            {
                return false;
            }
        }
        else
        {
            // nous sommes arrivé aux bornes
            return false;
        }
    }
    // il n'est pas poussable
    return false;
}

void Jeu::deplace(Direction d)
{

    for (size_t i = 0; i < joueur.size(); i++)
    {
        Agent &a = *(agents.at(i));
        Case *courant = a.getCaseActuelle();
        pair<int, int> nv_direction = directionToPair(d);
        deplaceRec(nv_direction, courant, &a);
    }
}

const Plateau &Jeu::getPlateau() const
{
    return plateau;
}