#include "Rocher.hpp"

Rocher::Rocher(bool pousse, bool gagne, bool stop, bool baba, Case *caseInitiale) : Agent{"Rocher", pousse, gagne, stop, baba, caseInitiale} {}

std::string Rocher::getName() const
{
    return "Lapin";
}

Rocher::~Rocher()
{
}
