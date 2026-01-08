#include "Eau.hpp"

Eau::Eau(Case *caseInitiale, const Regles &regles) : Agent(caseInitiale, ObjectType::WATER, regles)
{
}

Agent *Eau::clone() const
{
    return new Eau(*this);
}

Eau::~Eau()
{
}
