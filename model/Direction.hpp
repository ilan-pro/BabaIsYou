#ifndef _DIRECTION
#define _DIRECTION

#include <utility>

enum class Direction
{
    Gauche,
    Droite,
    Haut,
    Bas,
};

std::pair<int, int> directionToPair(Direction d);

#endif