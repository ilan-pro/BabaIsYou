#include "Mur.hpp"


Mur::Mur(Case *caseActuelle, const Regles &rules) : Agent(caseActuelle, ObjectType::WALL, rules) {}

Mur::~Mur()
{
}