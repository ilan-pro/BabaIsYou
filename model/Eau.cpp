#include "Eau.hpp"

Eau::Eau(Case *caseInitiale, const Regles &rules) : Agent(caseInitiale, ObjectType::WATER, rules)
{
}

Agent *Eau::clone() const
{
    return new Eau(*this);
}

Eau::~Eau()
{
}
