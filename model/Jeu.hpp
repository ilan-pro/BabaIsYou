#ifndef _JEU
#define _JEU
#include <vector>
#include "Plateau.hpp"
#include "Direction.hpp"
#include "Agent.hpp"
using namespace std;

class Jeu
{
private:
    /*
     * ici on souhaite une composition donc si on avait Plateau &plateau , 
     * on devait initialiser le plateau a l'exterieur de Jeu ce qui est problématique
     */
    Plateau& plateau;

    /*
     * Attention ici ne pas oublié de delete dans le destructeur de Jeu sinon fuite de mémoire
     */
    vector<Agent *> agents;

public:
    Jeu(Plateau &plateau);

    void deplace(Agent& a, Direction d);

    ~Jeu();
};

#endif