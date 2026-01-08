#ifndef _ETATJEU
#define _ETATJEU

#include "Jeu.hpp"
#include "Regles.hpp"

class Jeu;
class Regles;

class EtatJeu
{
public:
    vector<Agent *> agents;
    Plateau plateau;
    Regles regles;

    EtatJeu(const Jeu &jeu);

    EtatJeu(const EtatJeu &) = delete;
    EtatJeu &operator=(const EtatJeu &) = delete;
    virtual ~EtatJeu();
};

#endif