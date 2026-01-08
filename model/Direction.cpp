#include "Direction.hpp"

using namespace std;


pair<int, int> directionToPair(Direction d)
{
    switch (d)
    {
    case Direction::Gauche:
        return {0, -1};
    case Direction::Droite:
        return {0, 1};
    case Direction::Haut:
        return {-1, 0};
    case Direction::Bas:
        return {1, 0};
    }
    return {0, 0}; // pour la sécurité au cas ou
}