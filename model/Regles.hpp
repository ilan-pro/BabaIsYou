#ifndef REGLES_HPP
#define REGLES_HPP
#include "Enums.hpp"
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef map<Property, vector<ObjectType>> RuleMap;

class Regles
{
private:
    RuleMap rules;

public:
    Regles() = default;
    void clear();

    void addRule(ObjectType obj, Property prop);

    bool has(Property prop, ObjectType obj) const;

    const vector<ObjectType> &get(Property prop) const;

    /*
    pour que l'on puisse debuger lorsqu'on testera
    */
    void print() const;
};

#endif
