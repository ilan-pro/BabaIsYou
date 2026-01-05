#ifndef _PLATEAU
#define _PLATEAU

#include "Regles.hpp"
#include "Case.hpp"
#include "Agent.hpp"
#include "Mot.hpp"
#include <vector>

using namespace std;

class Plateau
{
private:
    const int Largeur, Longueur;
    /**
     * on veut pouvoir changer l'état des cases mais pas le nombre (unique par niveau)
     * ATTENTION
     * mais en réalité ça rend tout le vector et son contenu non-modifiables via le vector avec le const avant vector
     * si on souhaite modifier la liste des agents d'une case on ne pourra pas le faire
     *
     * Et ducoup const int largeur et longeur suffit a limité la taille
     */

    vector<vector<Case>> cases;

public:
    /* Voir quoi faire pour les copies de vecteurs */
    Plateau(int largeur, int longueur);
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
    const Plateau &operator=(const Plateau &x) = delete;
    /**
     * Ici on utilise un getter constant et pas un using class PlateauTerm; car cela casserait l'encapsulation
     * de la classe
     */
    void affichePlateau() const;
    Case &getCase(const Agent &a) const;

    Regles parseRegle() const; 
    void VerifRule(const WordInfo& m_info, const Case *c, Regles &regles) const;
    Mot* BonMotPresent(int i, int j, bool veutOperator) const;
};

#endif