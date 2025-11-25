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
    Plateau plateau;

    /*
     * Attention ici ne pas oublié de delete dans le destructeur de Jeu sinon fuite de mémoire
     */
    vector<Agent *> agents;

    vector<Agent *> joueur;

public:
    Jeu();

    void ajouterAgent(Agent *a);
    bool deplaceRec(pair<int, int> nv_direction, Case *c);
    void deplace(Direction d);

    const Plateau &getPlateau() const;

    ~Jeu();
};

#endif