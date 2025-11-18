#ifndef _AGENT
#define _AGENT

#include <string>

using namespace std;

class Case;

class Agent
{
private:
    string const name;
    bool état;

protected:
    Case *caseActuelle; // ici un pointeur car un agent ne possede pas une Case elle existe a l'exterieur (on veut pas de composition)
                        // en protected car seul les classes dérievées doivent pouvoir y accéder

public:
    Agent(/* args */);
    virtual string getName() const;
    Case *getCaseActuelle() const;
    void setCaseActuelle(Case *nouvelleCase);
    virtual bool getEtat() const;
    ~Agent();
};

#endif