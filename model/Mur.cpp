#include "Mur.hpp"

Mur::Mur(Case *caseActuelle, const Regles &rules) : Agent(caseActuelle, ObjectType::WALL, rules) {}

Agent *Mur::clone() const
{
    return new Mur(*this);
}

Mur::~Mur()
{
}