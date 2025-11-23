#ifndef _LAPIN
#define _LAPIN

#include <string>
#include "Agent.hpp"

using namespace std;

class Lapin : public Agent
{
private:
public:
    Lapin(Case *caseInitiale);
    string getName() const;
    bool getEtat() const;

    ~Lapin();
};

#endif