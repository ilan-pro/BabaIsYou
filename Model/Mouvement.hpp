#ifndef _MOUVEMENT
#define _MOUVEMENT

#include "Agent.hpp"
#include "Board.hpp"
#include "Direction.hpp"

using namespace std;

class Mouvement
{
private:
public:
    /**
     * est-ce qu'il faut mettre un const ? je crois qu'on veut pouvoir retirer des murs dans le cas ou on touche les
     * bords avec un mur certains s'enlèvent et donc il faut pas mettre const ?
     */
    Mouvement();

    void deplacer(Agent &a, Direction d);
    void checkCollision(Board &b);
    pair<int, int> getCoordDirection(Direction d);

    ~Mouvement();
};

#endif