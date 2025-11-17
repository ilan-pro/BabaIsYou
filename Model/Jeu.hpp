#ifndef _JEU
#define _JEU

#include "Board.hpp"

class Jeu {
    private:
        Board& board;

    public:
        Jeu(Board& board);
        ~Jeu();
};

#endif