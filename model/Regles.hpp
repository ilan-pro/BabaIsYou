#ifndef REGLES_HPP
#define REGLES_HPP
#include "Enums.hpp"
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
// #include "Plateau.hpp"

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

    ~Regles();

    /**
     * Fonction qui permet de vérifier si une règle est bien formé et l'ajout si c'est le cas
     */
    // void VerifRule(const WordInfo& m_info, const Case *c, Regles &regles, const Plateau& p) const;
    // Mot* BonMotPresent(int i, int j, const Plateau& p, bool veutOperator) const;
};

#endif
