#include "Rocher.hpp"

Rocher::Rocher(Case *caseActuelle, const Regles &rules) : Agent(caseActuelle, ObjectType::ROCK, rules) {}

Agent *Rocher::clone() const
{
    return new Rocher(*this);
}

Rocher::~Rocher()
{
}
