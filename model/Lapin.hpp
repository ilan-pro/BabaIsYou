#ifndef _LAPIN
#define _LAPIN

#include <string>
#include "Agent.hpp"

using namespace std;

/**
 * Classe singleton MAYBE À VOIR DANS LES DIFF NIVEAU
 **/
class Lapin : public Agent
{
private:
public:
  Lapin(Case *caseInitiale, const Regles &rules);
  ~Lapin();
};

#endif