#include "Jeu.hpp"

Jeu::Jeu(Plateau &plateau) : plateau{plateau} {}

Jeu::~Jeu()
{
    // cout << "destruction de Jeu" << endl;
}



void Jeu::deplace(Agent &a, Direction d)
{
    Case *courant = a.getCaseActuelle();
    pair<int, int> next_direction = directionToPair(d);
    Case *cible = plateau.getCase(courant->getX() + next_direction.first, courant->getY() + next_direction.second);
    if(cible != nullptr) {
        a.setCaseActuelle(cible);
        courant->retirerAgent(&a);
        cible->ajouterAgent(&a);
    }
    // fonction pour regarder cible ???
}