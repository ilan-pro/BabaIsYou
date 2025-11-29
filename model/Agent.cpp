#include "Agent.hpp"

Agent::Agent(string const name, bool pousse, bool gagne, bool stop, bool baba, Case *caseActuelle) : name{name}, pousse{pousse}, gagne{gagne}, stop{stop}, baba{baba}, caseActuelle{caseActuelle}
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

bool Agent::getPousse() const
{
    return pousse;
}

bool Agent::getGagne() const
{
    return gagne;
}

bool Agent::getStop() const
{
    return stop;
}

bool Agent::getBaba() const
{
    return baba;
}

void Agent::setPousse(bool valeur)
{
    pousse = valeur;
}

void Agent::setGagne(bool valeur)
{
    gagne = valeur;
}

void Agent::setStop(bool valeur)
{
    stop = valeur;
}

void Agent::setBaba(bool valeur)
{
    baba = valeur;
}

Agent::~Agent()
{
    cout << "destruction de l'agent de nom :" << name << endl;
}

bool Agent::toutFaux() const {
    if(!(pousse || gagne || stop)){
        return true;
    }
    return false;
}