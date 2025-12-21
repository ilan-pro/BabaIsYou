#include "Case.hpp"
#include "Agent.hpp"

#include <iostream>

using namespace std;

Case::Case(int x, int y) : agents{}, x{x}, y{y} {}

Case::~Case()
{
    // cout << "destruction de la Case" << endl;
}

// bool Case::containBaba_only() const {
//     for(size_t i=0; i<agents.size(); i++) {
//         if(!(agents.at(i)->getBaba())) {
//             return false;
//         }
//     }
//     return true;
// }

bool Case::ToutSuperposable() const
{
    for (size_t i = 0; i < agents.size(); i++)
    {
        if (!(agents.at(i)->toutFaux()))
        {
            return false;
        }
    }
    return true;
}



void Case::ajouterAgent(Agent *a)
{
    for (size_t i = 0; i < agents.size(); i++)
    {
        if (agents[i] == a)
        {
            cout << "présence de doublons" << endl;
            return;
        }
    }
    agents.push_back(a);
}

// void Case::retirerAgent(Agent *a)
// {
//     for (size_t i = 0; i < agents.size(); i++)
//     {
//         if (agents.at(i) == a)
//         {
//             agents.erase(agents.begin() + i);
//             cout << "retirer agents de listeagents dans Case" << endl;
//             return;
//         }
//     }
// }

/*
Pour gérer les problemes de suppressions dans
un vector

Soit avec un itérator on fait pointer it vers erase puisque erase renvoie le nouvel itérateur suivant

Soit soit on fait une copie des objet dans un nouveau vector dans lequel on va supprimer tous ces éléments


*/

void Case::retirerAgent(Agent *a)
{
    /*

    Attention ici erase renvoie un itérator pas un const itérator
    */
    std::vector<Agent *>::iterator it = agents.begin();

    while (it != agents.end())
    {
        if (*it == a)
        {
            it = agents.erase(it);
            cout << "retirer agents de listeagents dans Case" << endl;
            break;
        }
        else
        {
            ++it;
        }
    }
}

int Case::getX() const
{
    return x;
}

int Case::getY() const
{
    return y;
}

vector<Agent *> &Case::getAgents()
{
    return agents;
}

const vector<Agent *> &Case::getAgents() const
{
    return agents;
}

void Case::afficherAgents() const
{
    if (agents.size() == 0)
    {
        cout << "vide";
    }
    else
    {
        for (size_t i = 0; i < agents.size(); i++)
        {
            // ici on à include le header de agent donc on peut
            cout << '[' << toString(agents.at(i)->getType()) << ']';
        }
    }
}

ostream &operator<<(ostream &out, const Case &c)
{
    for (size_t i = 0; i < c.agents.size(); i++)
    {
        out << '[' << c.agents.at(i) << ']';
    }
    return out;
}