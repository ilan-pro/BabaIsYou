#include "Rocher.hpp"

Rocher::Rocher(Case *caseActuelle, const Regles &regles) : Agent(caseActuelle, ObjectType::ROCK, regles) {}

Agent *Rocher::clone() const
{
    return new Rocher(*this);
}

Rocher::~Rocher()
{
}
