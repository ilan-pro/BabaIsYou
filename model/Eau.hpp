#ifndef _EAU
#define _EAU
#include "Agent.hpp"

class Eau : public Agent
{
private:
public:
    Eau(bool pousse, bool gagne, bool stop, bool baba, Case *caseInitiale);
    string getName() const;

    ~Eau();
};

#endif