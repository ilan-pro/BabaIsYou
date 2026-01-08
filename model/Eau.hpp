#ifndef _EAU
#define _EAU
#include "Agent.hpp"

class Eau : public Agent
{
private:
public:
    Eau(Case *caseInitiale, const Regles &rules);
    Agent *clone() const;
    virtual ~Eau();
};

#endif