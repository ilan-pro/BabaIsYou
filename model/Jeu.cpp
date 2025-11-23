#include "Jeu.hpp"
#include "Lapin.hpp"

Jeu::Jeu() : plateau(0, 0)
{
    // Lapin *l = new Lapin(plateau.getCase(0, 0));
    // Case *c = plateau.getCase(0, 0);
    // c->ajouterAgent(l);
    // agents.push_back(l);
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

void Jeu::deplace(Direction d)
{
    Agent &a = *(agents.at(0));
    Case *courant = a.getCaseActuelle();
    pair<int, int> next_direction = directionToPair(d);
    Case *cible = plateau.getCase(courant->getX() + next_direction.first, courant->getY() + next_direction.second);
    if (cible != nullptr)
    {
        a.setCaseActuelle(cible);
        courant->retirerAgent(&a);
        cible->ajouterAgent(&a);
    }
    cout << "ancienne case: (" << courant->getX() << "," << courant->getY() << ")" << endl;
    cout << "nouvelle case: (" << cible->getX() << "," << cible->getY() << ")" << endl;
}

const Plateau &Jeu::getPlateau() const
{
    return plateau;
}