#ifndef _DRAPEAU
#define _DRAPEAU
#include "Agent.hpp"

class Drapeau : public Agent
{
private:
public:
    Drapeau(bool pousse, bool gagne, bool stop, bool baba, Case *caseInitiale);
    string getName() const;

    ~Drapeau();
};

#endif