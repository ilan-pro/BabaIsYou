#include "Agent.hpp"

Agent::Agent(string const name, bool état, Case *caseActuelle)
    : name(name), état(état), caseActuelle(caseActuelle)
{
}

string Agent::getName() const
{
    return name;
}

Case *Agent::getCaseActuelle() const
{
    return caseActuelle;
}

void Agent::setCaseActuelle(Case *nouvelleCase)
{
    caseActuelle = nouvelleCase;
}

bool Agent::getEtat() const
{
    return état;
}

Agent::~Agent()
{
    cout << "destruction de l'agent de nom :" << name << endl;
}