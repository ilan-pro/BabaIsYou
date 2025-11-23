#include "Mouvement.hpp"

 pair<int, int> Mouvement::directionToPair(Direction d) {
    switch (d)
    {
    case Direction::Gauche:
        return {-1, 0};
    case Direction::Droite:
        return {1, 0};
    case Direction::Haut:
        return {0, -1};
    case Direction::Bas:
        return {0, 1};
    }
    return {0, 0}; // pour la sécurité au cas ou
}

/**
  * On recupere la pair d'entier puis on mets a jour les coordonnés de la
  * case actuelle ou est placé l'agent
  */

