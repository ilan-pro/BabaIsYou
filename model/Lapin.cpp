#include "Lapin.hpp"

// Constructeur — si Agent a besoin d’infos, tu peux lui passer ici
Lapin::Lapin(Case *caseInitiale) : Agent("Lapin", true, caseInitiale)
{
}

std::string Lapin::getName() const
{
    return "Lapin";
}

bool Lapin::getEtat() const
{
    return true;
}

Lapin::~Lapin()
{
}
