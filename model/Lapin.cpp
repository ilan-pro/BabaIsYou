#include "Lapin.hpp"

// Constructeur — si Agent a besoin d’infos, tu peux lui passer ici
Lapin::Lapin(bool pousse, bool gagne, bool stop, bool baba, Case *caseInitiale) : Agent("Lapin", pousse, gagne, stop, baba, caseInitiale)
{
}

std::string Lapin::getName() const
{
    return "Lapin";
}

Lapin::~Lapin()
{
}
