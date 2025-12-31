#include "Agent.hpp"

Agent::Agent(Case *caseActuelle, ObjectType type, const Regles &rules) : caseActuelle{caseActuelle}, type{type}, rules{rules} {}

Case *Agent::getCaseActuelle() const
{
    return caseActuelle;
}

void Agent::setCaseActuelle(Case *nouvelleCase)
{
    caseActuelle = nouvelleCase;
}

Agent::~Agent()
{
    cout << "destruction de l'agent de nom :" << endl;
}

ObjectType Agent::getType() const
{
    return type;
}

bool Agent::toutFaux() const { return !isPush() && !isWin() && !isStop(); }
bool Agent::isPush() const { return rules.has(Property::PUSH, type); }
bool Agent::isStop() const { return rules.has(Property::STOP, type); }
bool Agent::isYou() const { return rules.has(Property::YOU, type); }
bool Agent::isWin() const { return rules.has(Property::WIN, type); }
bool Agent::isMot() const { return false; }
