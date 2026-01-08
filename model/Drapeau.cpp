#include "Drapeau.hpp"

Drapeau::Drapeau(Case *caseInitiale, const Regles &rules) : Agent(caseInitiale, ObjectType::FLAG, rules)
{
}

Agent *Drapeau::clone() const
{
    return new Drapeau(*this);
}

Drapeau::~Drapeau()
{
}
