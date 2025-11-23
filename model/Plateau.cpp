#include "Plateau.hpp"
#include <iostream>

using namespace std;

Plateau::Plateau(int largeur, int longueur) : largeur{largeur}, longueur{longueur}, cases(longueur)
{
    // cases.reserve(longueur);
    for (int i = 0; i < longueur; i++)
    {
        cases.at(i).reserve(largeur);
        for (int j = 0; j < largeur; j++)
        {
            cases.at(i).emplace_back(i, j);
        }
    }
}

Case *Plateau::getCase(int i, int j)
{
    if (i < 0 || i >= longueur || j < 0 || j >= largeur)
    {
        return nullptr;
    }
    return &cases[i][j];
}

const Case *Plateau::getCase(int i, int j) const
{
    if (i < 0 || i >= longueur || j < 0 || j >= largeur)
    {
        return nullptr;
    }
    return &cases[i][j];
}

Plateau::~Plateau()
{
    cout << "destruction du plateau" << endl;
}

void Plateau::affichePlateau() const
{
    for (int i = 0; i < longueur; i++)
    {
        for (int j = 0; j < largeur; j++)
        {
            cout << '[' << i << ']' << '[' << j << ']' << " liste d'agents : " << cases[i][j] << endl;
        }
    }
}

int Plateau::getLongueur() const
{
    return longueur;
}

int Plateau::getLargeur() const
{
    return largeur;
}