#include "Plateau.hpp"
#include <iostream>

using namespace std;

Plateau::Plateau(const vector<Case> cases, int largeur, int longueur) : cases{cases}, largeur{largeur}, longueur{longueur} {}

Plateau::~Plateau()
{
    cout << "destruction du plateau" << endl;
}

void Plateau::affichePlateau() const
{
    for (size_t i = 0; i < cases.size(); i++)
    {
        cases.at(i).afficheCase();
    }
}