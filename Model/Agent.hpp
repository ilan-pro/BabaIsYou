#ifndef _AGENT
#define _AGENT

#include <string>

using namespace std;

class Agent {
    private:
        string const name;
        bool état;
        
    public:
        Agent(/* args */);
        virtual string getName() const;
        virtual bool getEtat() const;
        ~Agent();
};

#endif 