#ifndef REGLES_HPP
#define REGLES_HPP

#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Enums.hpp"
// #include "Plateau.hpp"

using namespace std;

typedef map<Property, vector<ObjectType>> RuleMap;

/**
 * on fait des déclarations préalable éviter la dépendance circulaire entre plateau et règle et le reste...
 */
class Plateau;
class Case;
class Mot;
class WordInfo;

class Regles
{
private:
    RuleMap regles;

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
     * on appelle ces fonctions uniquement depuis plateau donc l'attribut plateau est évidemment != nullptr
     */
    void VerifRule(const WordInfo& m_info, const Case *c, Regles &regles, const Plateau* p) const;
    Mot* BonMotPresent(int i, int j, const Plateau* p, bool veutOperator) const;
};

#endif
