#include "Lapin.hpp"

Lapin::Lapin(Case *caseInitiale, const Regles &rules) : Agent(caseInitiale, ObjectType::BABA, rules) {}

Agent *Lapin::clone() const
{
    return new Lapin(*this);
}

Lapin::~Lapin()
{
}