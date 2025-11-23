#include "Case.hpp"

#include <iostream>

using namespace std;

Case::Case(vector<Agent *> agents) : agents{agents} {}

Case::~Case()
{
    cout << "destruction de la Case" << endl;
}

void Case::ajouterAgent(Agent *a)
{
    for (size_t i = 0; i < agents.size(); i++)
    {
        if (agents[i] == a)
        {
            cout << "présence de doublons" << endl;
            return;
        }
    }
    agents.push_back(a);
}

void Case::retirerAgent(Agent *a)
{
    for (size_t i = 0; i < agents.size(); i++)
    {
        if (agents.at(i) == a)
        {
            agents.erase(agents.begin() + i);
            cout << "retirer agents de listeagents dans Case" << endl;
            return;
        }
    }
}

const vector<Agent *> &Case::getAgents() const
{
    return agents;
}
