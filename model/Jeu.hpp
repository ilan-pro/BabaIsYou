#ifndef _JEU
#define _JEU

#include <vector>
#include "Plateau.hpp"
#include "Direction.hpp"
#include "Agent.hpp"
#include "Regles.hpp"

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
    Regles rules;
    vector<Agent *> dejaBouges;
    vector<Agent *> demandeur;

public:
    Jeu();
    ~Jeu();
    void ajouterAgent(Agent *a);
    void initTestMap();
    void supprimerDeDemandeur(Agent *a);
    bool deplaceRec(pair<int, int> nv_direction, Case *c, Agent *joueur);
    void deplacerAgents(Case *src, Case *dst, Agent *demandeur);
    void deplace(Direction d);
    bool aDejaBouge(Agent *a);
    bool demandeuraDejaBouge();
    void marqueCommeBouge(Agent *a);
    void marqueCommeDemandeur(Agent *a);
    const Plateau &getPlateau() const;
};

#endif