#ifndef _CASE
#define _CASE
#include <vector>
#include <iostream>

using namespace std;

class Agent;

class Case
{
private:
  vector<Agent *> agents; // pour les 0 à N agents sur la case

public:
  Case(vector<Agent *> agents);
  ~Case();

  /**
   * Ici on vérifie avec un boucle s'il n'y a pas déjà cet agent dans cette case
   */
  void ajouterAgent(Agent *a);
  /**
   * on ajoute un return pour ne pas faire plus de travail
   */
  void retirerAgent(Agent *a);

  /*
  on souhaite retourner un vector const c'est a dire non modifiable premier const pour la valeur de retour 2eme const pour nous assurer que la fonction ne modifie rien
  */

  const vector<Agent *> &getAgents() const;
};

#endif