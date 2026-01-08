#include "Drapeau.hpp"

Drapeau::Drapeau(Case *caseInitiale, const Regles &regles) : Agent(caseInitiale, ObjectType::FLAG, regles)  {}
Drapeau::~Drapeau() {}