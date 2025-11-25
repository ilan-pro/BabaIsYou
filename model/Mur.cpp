#include "Mur.hpp"

Mur::Mur(bool pousse, bool gagne, bool stop, bool baba, Case *caseInitiale) : Agent{"Mur", pousse, gagne, stop, baba, caseInitiale}
{
}

std::string Mur::getName() const
{
    return "Mur";
}

Mur::~Mur()
{
}