#include "Rocher.hpp"

Rocher::Rocher(Case *caseActuelle, const Regles &rules) : Agent(caseActuelle, ObjectType::ROCK, rules) {}

Rocher::~Rocher()
{
}
