#ifndef _AGENT
#define _AGENT

#include <iostream>
#include <string>
#include "Regles.hpp"

using namespace std;

class Case;

class Agent
{
protected:
    Case *caseActuelle;
    ObjectType type;
    const Regles &regles;
    /*
        ici on ne creer surtout pas de case avec new (pas de composition)
        Donc cela implique que dans le destructeur il ne faut surtout pas faire de delete Case
    */

    // ici un pointeur car un agent ne possede pas une Case elle existe a l'exterieur (on veut pas de composition)
    // en protected car seul les classes dérievées doivent pouvoir y accéder

public:
    Agent(Case *caseActuelle, ObjectType type, const Regles &regles);
    virtual ObjectType getType() const;
    Case *getCaseActuelle() const;
    virtual void setCaseActuelle(Case *nouvelleCase);
    /*il faut mettre virtual car le type change pour la recherche dans la map*/

    
     virtual Agent* clone() const = 0;

 

    virtual bool isPush() const;
    virtual bool isStop() const;
    virtual bool isYou() const;
    virtual bool isWin() const;
    virtual bool isMot() const;
    virtual ~Agent();
    /*tous les booléans à faux SAUF pour le baba car nous pouvons aller sur un baba*/

    bool toutFaux() const;
};

#endif