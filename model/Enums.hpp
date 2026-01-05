#ifndef _ENUMS_HPP
#define _ENUMS_HPP

#include <string>
using namespace std;

/*
enums pour faire en sorte qu on est une map ou on va pouvoir
check la propriéte et regarder la list de ObjectType qui possède
cette proprité
*/

enum class ObjectType
{
    WATER,
    BABA,
    ROCK,
    WALL,
    FLAG,
    TEXT
};

enum class Property
{
    YOU,
    PUSH,
    STOP,
    WIN
};

string toString(ObjectType obj);
string toString(Property p);

#endif
