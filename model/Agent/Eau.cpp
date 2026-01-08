#include "Eau.hpp"

Eau::Eau(Case *caseInitiale, const Regles &regles) : Agent(caseInitiale, ObjectType::WATER, regles) {}

Eau::~Eau() {}
