#include "Eau.hpp"

// Constructeur — si Agent a besoin d’infos, tu peux lui passer ici
Eau::Eau(bool pousse, bool gagne, bool stop, bool baba, Case *caseInitiale) : Agent("Drapeau", pousse, gagne, stop, baba, caseInitiale)
{
}

std::string Eau::getName() const
{
    return "Lapin";
}

Eau::~Eau()
{
}
