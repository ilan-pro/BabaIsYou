#include "Case.hpp"
#include "Agent.hpp"

#include <iostream>

using namespace std;

Case::Case(int x, int y) : x{x}, y{y}, agents() {}

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

int Case::getX() const {    
    return x;
}

int Case::getY() const {
    return y;
}

const vector<Agent *> &Case::getAgents() const
{
    return agents;
}

void Case::afficherAgents() const
{
    if (agents.size() == 0)
    {
        cout << "vide";
    }
    else
    {
        for (size_t i = 0; i < agents.size(); i++)
        {
            // ici on à include le header de agent donc on peut
            cout << '[' << agents.at(i)->getName() << ']';
        }
    }
}


ostream& operator<<(ostream& out , const Case& c) {
    for(size_t i=0; i<c.agents.size(); i++) {
        out << '[' << c.agents.at(i) << ']';
    }
    return out;
}