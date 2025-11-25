#include "Drapeau.hpp"

// Constructeur — si Agent a besoin d’infos, tu peux lui passer ici
Drapeau::Drapeau(bool pousse, bool gagne, bool stop, bool baba, Case *caseInitiale) : Agent("Drapeau", pousse, gagne, stop, baba, caseInitiale)
{
}

std::string Drapeau::getName() const
{
    return "Lapin";
}

Drapeau::~Drapeau()
{
}
