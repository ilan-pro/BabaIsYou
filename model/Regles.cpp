#include "Regles.hpp"
// #include "Word.hpp"
// #include "Mot.hpp"
// #include "Case.hpp"

void Regles::clear()
{
    rules.clear();
}

void Regles::addRule(ObjectType obj, Property prop)
{
    rules[prop].push_back(obj);
}

bool Regles::has(Property prop, ObjectType obj) const
{
    /* j'utilise un iterator car find me retourne un itérator (qui est ici une pair puisque c'est une map<Propréite,obj> )
        je compare mon it avec rules.end()(ca me retourne le dernier +1 donc un pointeur non compatible)
        si it =a ce pointeur alors ca signifie que je n'ai pas trouvé la clé
        sinon il faut que j'aille cherche dans mon vector l'obj
        puisque it est une pair car on est dans une map tjs
        alors pour acceder a la deuxieme valeur, it->second ou it->first pour la premiere valeur

    */

    RuleMap::const_iterator it = rules.find(prop);

    if (it == rules.end())
    {
        return false;
    }

    /*attention ici ne pas oublier de mettre une référence sinon je parcours sur une copie ce que l'on ne souhaite pas*/

    const vector<ObjectType> &v = it->second;

    /*
    j'ai essayé de le faire avec un itérator vu qu'on a vu ca dans le cours 8
    ça revient a la meme chose bref on gardera soit le premier ou le 2eme mais
    c'était cool de mieux comprendre comment marche les itérators
    */

    // for (vector<ObjectType>::const_iterator it = v.begin(); it != v.end(); it++)
    // {
    //     if (*it == obj)
    //     {
    //         return true;
    //     }
    // }

    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i] == obj)
        {
            return true;
        }
    }

    return false;
}

const vector<ObjectType> &Regles::get(Property prop) const
{
    RuleMap::const_iterator it = rules.find(prop);

    if (it == rules.end())
    {

        /*
        Si la clé n'existe pas , je souhaite retouner un vector vide
        si ce n'est pas static, mon vector n'existe plus apres l'execution de cette fonction
        c'est mieux de faire ca car sinon on doit manipuler des pointeurs null
        et dans le sujet du projet justement il ne souhaite pas qu on le fasse
        et donc on aura juste a tester si le vector est vide pour savoir si la clé existe ou nn
        et donc si il y a des obj qui cette propriété.
        */

        static const vector<ObjectType> empty;
        return empty;
    }
    return it->second;
}

void Regles::print() const
{
    RuleMap::const_iterator it;
    for (it = rules.begin(); it != rules.end(); ++it)
    {
        // std::cout << toString(it->first) << " : ";
        const std::vector<ObjectType> &objs = it->second;
        for (std::size_t i = 0; i < objs.size(); ++i)
        {
            // std::cout << toString(objs[i]) << " ";
        }
        // std::cout << "\n";
    }
}

Regles::~Regles(){}

// void Regles::VerifRule(const WordInfo& m_info, const Case *c, Regles &regles, const Plateau& p) const
// {
//     int i = c->getX();
//     int j = c->getY();
//     Mot *operator1 = BonMotPresent(i, j + 1, p, true);
//     Mot *propriete1 = BonMotPresent(i, j + 2, p, false);
//     Mot *operator2 = BonMotPresent(i + 1, j, p, true);
//     Mot *propriete2 = BonMotPresent(i + 2, j, p, false);
//     if (operator1 != nullptr && propriete1 != nullptr)
//     {
//         const Word w = propriete1->getWord();
//         const WordInfo w1 = getWordInfo(w);
//         regles.addRule(m_info.object, w1.property);
//     }
//     if (operator2 != nullptr && propriete2)
//     {
//         const Word w = propriete2->getWord();
//         const WordInfo w1 = getWordInfo(w);
//         regles.addRule(m_info.object, w1.property);
//     }
// }

// Mot *Regles::BonMotPresent(int i, int j, const Plateau& p, bool veutOperator) const
// {
//     /**
//      * pas besoin de vérifier j car la boucle va jusqu'à largeur-2
//      */
//     if(i < p.getLongueur()){
//         const Case *c = p.getCase(i, j);
//         for (Agent *a : c->getAgents())
//         {
//             if (a->getType() == ObjectType::TEXT)
//             {
//                 Mot *m = dynamic_cast<Mot *>(a);
//                 if (m->isOperator() && veutOperator)
//                 {
//                     return m;
//                 }else if(m->isProperty()) {
//                     return m;
//                 }
//             }
//         }
//     }
//     return nullptr;
// }