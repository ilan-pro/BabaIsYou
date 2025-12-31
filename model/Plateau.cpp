#include "Plateau.hpp"
#include "Word.hpp"
#include <iostream>

using namespace std;

Plateau::Plateau(int largeur, int longueur) : Largeur{largeur}, Longueur{longueur}, cases(Longueur)
{
    // cases.reserve(longueur);
    for (int i = 0; i < longueur; i++)
    {
        cases.at(i).reserve(largeur);
        for (int j = 0; j < largeur; j++)
        {
            cases.at(i).emplace_back(i, j);
        }
    }
}

Case *Plateau::getCase(int i, int j)
{
    if (i < 0 || i >= Longueur || j < 0 || j >= Largeur)
    {
        return nullptr;
    }
    return &cases[i][j];
}

const Case *Plateau::getCase(int i, int j) const
{
    if (i < 0 || i >= Longueur || j < 0 || j >= Largeur)
    {
        return nullptr;
    }
    return &cases[i][j];
}

Plateau::~Plateau()
{
    cout << "destruction du plateau" << endl;
}

void Plateau::affichePlateau() const
{
    for (int i = 0; i < Longueur; i++)
    {
        for (int j = 0; j < Largeur; j++)
        {
            cout << '[' << i << ']' << '[' << j << ']' << " liste d'agents : " << cases[i][j] << endl;
        }
    }
}

int Plateau::getLongueur() const
{
    return Longueur;
}

int Plateau::getLargeur() const
{
    return Largeur;
}

const WordInfo* Plateau::motPresentEtNom(const Case* c) const
{
    for (Agent *a : c->getAgents())
    {
        if (a->getType() == ObjectType::TEXT)
        {
            Mot *m = dynamic_cast<Mot *>(a);
            if (m->isNoun())
            {
                const WordInfo &m_info = getWordInfo(m->getWord());
                return &m_info;
            }
        }
    }
    return nullptr;
}

Regles Plateau::parseRegle() const
{
    Regles regles;
    for (int i = 0; i < Longueur; i++)
    {
        for (int j = 0; j < Largeur - 2; j++)
        {
            const Case *c = getCase(i, j);
            // const WordInfo *m_info = c->motPresentEtNom();
            const WordInfo *m_info = motPresentEtNom(c);
            // regles.VerifRule(*m_info, c, regles, *this);
            if(m_info != nullptr) {
                VerifRule(*m_info, c, regles);
            }
        }
    }
    return regles;
}


void Plateau::VerifRule(const WordInfo& m_info, const Case *c, Regles &regles) const
{
    int i = c->getX();
    int j = c->getY();
    Mot *operator1 = BonMotPresent(i, j + 1, true);
    Mot *propriete1 = BonMotPresent(i, j + 2, false);
    Mot *operator2 = BonMotPresent(i + 1, j, true);
    Mot *propriete2 = BonMotPresent(i + 2, j, false);
    if (operator1 != nullptr && propriete1 != nullptr)
    {
        const Word w = propriete1->getWord();
        const WordInfo w1 = getWordInfo(w);
        regles.addRule(m_info.object, w1.property);
        regles.addRule(ObjectType::TEXT, Property::PUSH);
    }
    if (operator2 != nullptr && propriete2)
    {
        const Word w = propriete2->getWord();
        const WordInfo w1 = getWordInfo(w);
        regles.addRule(m_info.object, w1.property);
        regles.addRule(ObjectType::TEXT, Property::PUSH);
    }
}

Mot *Plateau::BonMotPresent(int i, int j, bool veutOperator) const
{
    /**
     * pas besoin de vérifier j car la boucle va jusqu'à largeur-2
     */
    if(i < getLongueur()){
        const Case *c = getCase(i, j);
        for (Agent *a : c->getAgents())
        {
            if (a->getType() == ObjectType::TEXT)
            {
                Mot *m = dynamic_cast<Mot *>(a);
                if (m->isOperator() && veutOperator)
                {
                    return m;
                }else if(m->isProperty()) {
                    return m;
                }
            }
        }
    }
    return nullptr;
}