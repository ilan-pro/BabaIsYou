#ifndef _DIRECTION
#define _DIRECTION

using namespace std;

#include <utility>

enum class Direction
{
    Gauche,
    Droite,
    Haut,
    Bas,
};

pair<int, int> directionToPair(Direction d);

#endif