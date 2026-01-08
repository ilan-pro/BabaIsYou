#include "Enums.hpp"

/** 
 * Fonctions pour debug dans la map et voir quelles sont les
 * regles présentent
 */
string toString(ObjectType obj)
{
    switch (obj)
    {
    case ObjectType::WATER:
        return "WATER";
    case ObjectType::BABA:
        return "BABA";
    case ObjectType::ROCK:
        return "ROCK";
    case ObjectType::WALL:
        return "WALL";
    case ObjectType::FLAG:
        return "FLAG";
    case ObjectType::TEXT:
        return "TEXT";
    }
    return "?";
}

string toString(Property p)
{
    switch (p)
    {
    case Property::YOU:
        return "YOU";
    case Property::PUSH:
        return "PUSH";
    case Property::STOP:
        return "STOP";
    case Property::WIN:
        return "WIN";
    }
    return "?";
}
