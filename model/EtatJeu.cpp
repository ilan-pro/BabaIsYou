#include "EtatJeu.hpp"

EtatJeu::EtatJeu(const Jeu &jeu)
    // : plateau([&]()
    //           {
    //       // créer les clones temporaires pour le plateau
    //       std::vector<Agent*> clones;
    //       for (Agent* a : jeu.getAgents())
    //           clones.push_back(a->clone());
    //       return Plateau(jeu.getPlateau(), clones); }()),
    : regles(jeu.getRule())
{
    // on à les agents dans le plateau grace à la lambda du haut

    for (Agent *a : jeu.getAgents())
    {
        agents.push_back(a->clone());
    }
    plateau = Plateau(jeu.getPlateau(), agents);
    // agents = plateau.getAllAgents();
}

EtatJeu::~EtatJeu()
{
    for (Agent *a : agents)
    {
        delete a;
    }
}
