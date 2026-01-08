#include "Lapin.hpp"

Lapin::Lapin(Case *caseInitiale, const Regles &regles) : Agent(caseInitiale, ObjectType::BABA, regles) {}

Agent *Lapin::clone() const
{
    return new Lapin(*this);
}

Lapin::~Lapin()
{
}