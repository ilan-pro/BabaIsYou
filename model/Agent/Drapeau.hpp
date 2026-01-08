#ifndef _DRAPEAU
#define _DRAPEAU

#include "../Agent.hpp" 

class Drapeau : public Agent {
    private:
    public:
        Drapeau(Case *caseInitiale, const Regles &regles);
        ~Drapeau();
};


#endif