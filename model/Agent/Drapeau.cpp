#include "Drapeau.hpp"

Drapeau::Drapeau(Case *caseInitiale, const Regles &regles) : Agent(caseInitiale, ObjectType::FLAG, regles)
{
}

Agent *Drapeau::clone() const
{
    return new Drapeau(*this);
}

Drapeau::~Drapeau() {}
