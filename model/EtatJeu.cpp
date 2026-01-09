#include "EtatJeu.hpp"

EtatJeu::EtatJeu(const Jeu &jeu) : regles(jeu.getRule())
{
    // on à les agents dans le plateau grace à la lambda du haut
    for (Agent *a : jeu.getAgents())
    {
        agents.push_back(a->clone());
    }
    plateau = Plateau(jeu.getPlateau(), agents);
}

EtatJeu::~EtatJeu()
{
    for (Agent *a : agents)
    {
        delete a;
    }
}
