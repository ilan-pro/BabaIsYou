#ifndef _ROCHER
#define _ROCHER
#include "Agent.hpp"

class Rocher : public Agent
{
private:
public:
    Rocher(/* args */);
    string getName() const;
    bool getEtat() const;

    ~Rocher();
};

#endif