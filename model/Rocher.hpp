#ifndef _ROCHER
#define _ROCHER
#include "Agent.hpp"

class Rocher : public Agent
{
private:
public:
    Rocher(Case *caseActuelle, const Regles &rules);
    Agent *clone() const;
    ~Rocher();
};
#endif