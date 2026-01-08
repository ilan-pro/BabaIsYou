#include "Agent.hpp"

Agent::Agent(Case *caseActuelle, ObjectType type, const Regles &regles) : caseActuelle{caseActuelle}, type{type}, regles{regles} {}

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
    // cout << "destruction de l'agent de nom :" << endl;
}

ObjectType Agent::getType() const
{
    return type;
}

bool Agent::toutFaux() const { return !isPush() && !isWin() && !isStop(); }
bool Agent::isPush() const { return regles.has(Property::PUSH, type); }
bool Agent::isStop() const { return regles.has(Property::STOP, type); }
bool Agent::isYou() const { return regles.has(Property::YOU, type); }
bool Agent::isWin() const { return regles.has(Property::WIN, type); }
bool Agent::isMot() const { return false; }
