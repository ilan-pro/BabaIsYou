#include "Mur.hpp"

Mur::Mur(Case *caseActuelle, const Regles &regles) : Agent(caseActuelle, ObjectType::WALL, regles) {}

Agent *Mur::clone() const
{
    return new Mur(*this);
}

Mur::~Mur()
{
}