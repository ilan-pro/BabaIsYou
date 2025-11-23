#ifndef _DIRECTION
#define _DIRECTION

using namespace std;

enum class Direction
{
    Gauche,
    Droite,
    Haut,
    Bas,
};

static pair<int, int> directionToPair(Direction d)
{
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

#endif