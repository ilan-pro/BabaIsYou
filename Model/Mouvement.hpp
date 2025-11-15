#ifndef _MOUVEMENT
#define _MOUVEMENT

#include <vector>
#include "Agent.hpp"

using namespace std;

class Mouvement {
    private:
        vector<Agent> agent_body;
        int x, y;
    public:
        /**
         * est-ce qu'il faut mettre un const ? je crois qu'on veut pouvoir retirer des murs dans le cas ou on touche les 
         * bords avec un mur certains s'enlèvent et donc il faut pas mettre const ? 
         */
        Mouvement(int x, int y, vector<Agent> agent_body);
};

#endif