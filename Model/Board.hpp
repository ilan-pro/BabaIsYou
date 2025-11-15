#ifndef _BOARD
#define _BOARD

#include "Case.hpp"
#include <vector>

using namespace std;

class Board {
    private:
        vector<Case> cases;    
    public:
        /* Voir quoi faire pour les copies de vecteurs */
        Board(const vector<Case> cases);
        ~Board();
        // faire un friend pour afficher en mode terminal ou faire un getter ? pour séparer l'affichage du calcul
        void getBoard() const;  
};

#endif