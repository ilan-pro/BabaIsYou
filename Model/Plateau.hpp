#ifndef _PLATEAU
#define _PLATEAU

#include "Case.hpp"
#include <vector>

using namespace std;

class Plateau
{
private:
    const int largeur, longueur;
    /**
     * on veut pouvoir changer l'état des cases mais pas le nombre (unique par niveau)
     * ATTENTION
     * mais en réalité ça rend tout le vector et son contenu non-modifiables via le vector avec le const avant vector
     * si on souhaite modifier la liste des agents d'une case on ne pourra pas le faire 
     * 
     * Et ducoup const int largeur et longeur suffit a limité la taille 
     */


     vector<Case> cases;

public:
    /* Voir quoi faire pour les copies de vecteurs */
    Plateau(const vector<Case> cases, int largeur, int longueur);
    ~Plateau();
    int getLargeur();
    int getLongueur();
    /**
     * On à cases en constant et on veut un singleton du Plateau, on ne veut donc pas pouvoir réattribuer le Plateau
     * ni le copier
     */
    Plateau(const Plateau &plateau) = delete;
    const Plateau &operator=(const Plateau &x) = delete;
    /**
     * Ici on utilise un getter constant et pas un using class PlateauTerm; car cela casserait l'encapsulation
     * de la classe
     */
    void affichePlateau() const;
};

#endif