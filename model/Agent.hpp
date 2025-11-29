#ifndef _AGENT
#define _AGENT

#include <string>
#include <iostream>

using namespace std;

class Case;

class Agent
{
private:
    string const name;

protected:
    bool pousse;
    bool gagne;
    bool stop;
    bool baba;

protected:
    /*
        ici on ne creer surtout pas de case avec new (pas de composition)
        Donc cela implique que dans le destructeur il ne faut surtout pas faire de delete Case
    */

    Case *caseActuelle; // ici un pointeur car un agent ne possede pas une Case elle existe a l'exterieur (on veut pas de composition)
                        // en protected car seul les classes dérievées doivent pouvoir y accéder

public:
    Agent(string const name, bool pouuse, bool gagne, bool stop, bool baba, Case *caseActuelle);
    virtual string getName() const;
    Case *getCaseActuelle() const;
    void setCaseActuelle(Case *nouvelleCase);
    virtual ~Agent();
    void setPousse(bool valeur);
    void setGagne(bool valeur);
    void setStop(bool valeur);
    void setBaba(bool valeur);
    /*tous les booléans à faux SAUF pour le baba car nous pouvons aller sur un baba*/
    bool toutFaux() const;

    bool getPousse() const;
    bool getGagne() const;
    bool getStop() const;
    bool getBaba() const;
};

#endif