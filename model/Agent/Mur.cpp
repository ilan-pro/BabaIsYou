#include "Mur.hpp"

Mur::Mur(Case *caseActuelle, const Regles &regles) : Agent(caseActuelle, ObjectType::WALL, regles) {}

Mur::~Mur() {}