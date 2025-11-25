#ifndef _MOUVEMENT
#define _MOUVEMENT

#include "Agent.hpp"
#include "Plateau.hpp"
#include "Direction.hpp"

using namespace std;

/*
On remarque qu'ici on a pas besoin d'instance de Mouvement donc c'est une classe stateless elle n'a pas d'attribut et possède des méthodes statiques
*/

class Mouvement
{
private:
public:
    /**
     * est-ce qu'il faut mettre un const ? je crois qu'on veut pouvoir retirer des murs dans le cas ou on touche les
     * bords avec un mur certains s'enlèvent et donc il faut pas mettre const ?
     */
    Mouvement();

    static pair<int, int> directionToPair(Direction d);

    ~Mouvement();
};

#endif