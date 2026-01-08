#ifndef _CASE
#define _CASE
#include <vector>
#include <iostream>
#include "Word.hpp"

using namespace std;

class Agent;

class Case
{
private:
    vector<Agent *> agents; // pour les 0 à N agents sur la case
    int const x;
    int const y;

public:
    Case(int x, int y);
    ~Case();

    /**
     * Ici on vérifie avec un boucle s'il n'y a pas déjà cet agent dans cette case
     */
    void ajouterAgent(Agent *a);
    /**
     * on ajoute un return pour ne pas faire plus de travail
     */
    void retirerAgent(Agent *a);

    int getX() const;
    int getY() const;
    // bool containBaba_only() const;
    /* vérifie qu'on à des éléments superposable comme l'eau OU si y a un BABA*/
    bool ToutSuperposable() const;

    /**
     * on souhaite retourner un vector const c'est a dire non modifiable premier const pour la valeur de retour 2eme const pour nous assurer que la fonction ne modifie rien
     */
    vector<Agent *> &getAgents();
    const vector<Agent *> &getAgents() const;

    void afficherAgents() const;
    friend std::ostream &operator<<(std::ostream &out, const Case &c);
    const WordInfo *motPresentEtNom() const;
};

#endif