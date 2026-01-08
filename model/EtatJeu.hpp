#ifndef _ETATJEU
#define _ETATJEU
#include "Jeu.hpp"

class Jeu;
class EtatJeu
{
public:
    vector<Agent *> agents;
    Plateau plateau;
    Regles rules;

    EtatJeu(const Jeu &jeu);

    EtatJeu(const EtatJeu &) = delete;
    EtatJeu &operator=(const EtatJeu &) = delete;
    virtual ~EtatJeu();
};

#endif