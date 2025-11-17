#ifndef _BOARD
#define _BOARD

#include "Case.hpp"
#include <vector>

using namespace std;

class Board {
    private:
        /**
         * on veut pouvoir changer l'état des cases mais pas le nombre (unique par niveau)
         */
        const vector<Case> cases;    
    public:
        /* Voir quoi faire pour les copies de vecteurs */
        Board(const vector<Case> cases);
        ~Board();
        /**
         * On à cases en constant et on veut un singleton du Board, on ne veut donc pas pouvoir réattribuer le board
         * ni le copier
         */
        Board(const Board& board) = delete;
        const Board& operator =(const Board& x) = delete;
        /**
         * Ici on utilise un getter constant et pas un using class BoardTerm; car cela casserait l'encapsulation 
         * de la classe 
         */
        void getBoard() const;
};

#endif