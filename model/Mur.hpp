#ifndef _MUR
#define _MUR

#include "Agent.hpp"

class Mur : public Agent {
    private:
    public:
        Mur(bool pousse, bool gagne, bool stop, bool baba, Case* caseInitiale);
        string getName() const;

        ~Mur();
};

#endif