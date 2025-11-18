#ifndef _CASE
#define _CASE
#include <vector>

class Agent;

class Case
{
private:
    int x, y;
    vector<Agent *> agents; // pour les 0 à N agents sur la case

public:
    Case(int x, int y);
    ~Case();
    void getCase() const;
    void ajouterAgent(Agent *a);
    void retirerAgent(Agent *a);
    const vector<Agent *> &getAgents() const;
};

#endif