#include "Plateau.hpp"
#include <iostream>

using namespace std;

Plateau::Plateau(int largeur, int longueur) : Largeur{largeur}, Longueur{longueur}, cases(Longueur)
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
    if (i < 0 || i >= Longueur || j < 0 || j >= Largeur)
    {
        return nullptr;
    }
    return &cases[i][j];
}

const Case *Plateau::getCase(int i, int j) const
{
    if (i < 0 || i >= Longueur || j < 0 || j >= Largeur)
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
    for (int i = 0; i < Longueur; i++)
    {
        for (int j = 0; j < Largeur; j++)
        {
            cout << '[' << i << ']' << '[' << j << ']' << " liste d'agents : " << cases[i][j] << endl;
        }
    }
}

int Plateau::getLongueur() const
{
    return Longueur;
}

int Plateau::getLargeur() const
{
    return Largeur;
}