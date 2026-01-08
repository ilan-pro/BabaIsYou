#ifndef _DRAPEAU
#define _DRAPEAU
#include "Agent.hpp"

class Drapeau : public Agent
{
private:
public:

    Drapeau(Case *caseInitiale, const Regles &rules);
     Agent *clone() const;
    ~Drapeau();
};

#endif