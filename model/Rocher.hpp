#ifndef _ROCHER
#define _ROCHER
#include "Agent.hpp"

class Rocher : public Agent
{
private:
public:
    Rocher(bool pousse, bool gagne, bool stop, bool baba, Case *caseInitiale);
    string getName() const;

    ~Rocher();
};

#endif