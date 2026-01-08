#ifndef _MUR
#define _MUR

#include "Agent.hpp"

class Mur : public Agent
{
private:
public:
    Mur(Case *caseActuelle, const Regles &rules);
    Agent *clone() const;
    ~Mur();
};

#endif