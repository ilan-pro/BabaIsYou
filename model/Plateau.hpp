#ifndef _PLATEAU
#define _PLATEAU

#include <vector>
#include "Case.hpp"
#include "Agent.hpp"
#include "Regles.hpp"

using namespace std;

class Mot;

class Plateau
{
private:
    int Largeur, Longueur;
    /**
     * on veut pouvoir changer l'état des cases mais pas le nombre (unique par niveau)
     * ATTENTION
     * mais en réalité ça rend tout le vector et son contenu non-modifiables via le vector avec le const avant vector
     * si on souhaite modifier la liste des agents d'une case on ne pourra pas le faire
     *
     * Et ducoup const int largeur et longeur suffit a limité la taille
     */
    friend class Jeu;
    friend class EtatJeu;
    vector<vector<Case>> cases;
    const Plateau &operator=(const Plateau &x);

public:
    /* Voir quoi faire pour les copies de vecteurs */
    Plateau();
    Plateau(int largeur, int longueur);
    Plateau(const Plateau &original, const std::vector<Agent *> &nouveauxAgents);
    ~Plateau();
    int getLargeur() const;
    int getLongueur() const;
    /**
     * Ici le getter ne peut être constant car quand nous l'appelons nous sommes dans des fonctions susceptibles de
     * modifier l'état interne d'une case (i.e la liste des agents de la case)
     */
    Case *getCase(int i, int j);
    /** celui pour la vue */
    const Case *getCase(int i, int j) const;
    /**
     * On à cases en constant et on veut un singleton du Plateau, on ne veut donc pas pouvoir réattribuer le Plateau
     * ni le copier
     */
    Plateau(const Plateau &plateau) = delete;
    // const Plateau &operator=(const Plateau &x) = delete;

    vector<Agent *> getAllAgents();
    /**
     * Ici on utilise un getter constant et pas un using class PlateauTerm; car cela casserait l'encapsulation
     * de la classe
     */
    void affichePlateau() const;
    Case &getCase(const Agent &a) const;

    Regles parseRegle() const; 
};

#endif