#include "Jeu.hpp"

Jeu::Jeu(Plateau &board) : plateau{board} {}

Jeu::~Jeu()
{
    // cout << "destruction de Jeu" << endl;
}