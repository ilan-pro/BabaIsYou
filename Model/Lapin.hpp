#ifndef _LAPIN
#define _LAPIN

#include <string>

using namespace std;

class Lapin {
private:
public:
    Lapin(/* args */);
    string getName() const;
    bool getEtat() const;

    ~Lapin();
};

#endif