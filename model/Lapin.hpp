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
  Lapin(bool pousse, bool gagne, bool stop, bool baba, Case *caseInitiale);
  string getName() const;
  ~Lapin();
};

#endif