#include "Eau.hpp"

Eau::Eau(Case *caseInitiale, const Regles &rules) : Agent(caseInitiale, ObjectType::WATER, rules)
{
}

Eau::~Eau()
{
}
