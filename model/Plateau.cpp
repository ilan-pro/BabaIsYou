#include "Plateau.hpp"
#include "Agent/Mot.hpp"

using namespace std;


Plateau::Plateau() : cases() {
    
}

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

Plateau::Plateau(const Plateau &original, const vector<Agent *> &nouveauxAgents)
    : Largeur(original.getLargeur()), Longueur(original.getLongueur())
{
    for (int i = 0; i < Longueur; i++)
    {
        vector<Case> ligne;
        ligne.reserve(Largeur);
        for (int j = 0; j < Largeur; j++)
        {
            ligne.emplace_back(i, j);
        }
        cases.push_back(move(ligne));
    }

    for (Agent *a : nouveauxAgents)
    {
        int x = a->getCaseActuelle()->getX();
        int y = a->getCaseActuelle()->getY();
        cases[x][y].ajouterAgent(a);
    }
}

const Plateau &Plateau::operator=(const Plateau &other)
{
    if (this != &other)
    {
        Largeur = other.Largeur;
        Longueur = other.Longueur;
        cases = other.cases;
    }
    return *this;
}

vector<Agent *> Plateau::getAllAgents()
{
    vector<Agent *> allAgents;

    // Parcours de toutes les cases
    for (int i = 0; i < Longueur; ++i)
    {
        for (int j = 0; j < Largeur; ++j)
        {
            Case &c = cases[i][j];
            const vector<Agent *> &agentsInCase = c.getAgents();
            allAgents.insert(allAgents.end(), agentsInCase.begin(), agentsInCase.end());
        }
    }

    return allAgents;
}

// const Plateau &Plateau::operator=(const Plateau &x)
// {
//     return x;
// }

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
    // cout << "destruction du plateau" << endl;
}

void Plateau::affichePlateau() const
{
    for (int i = 0; i < Longueur; i++)
    {
        for (int j = 0; j < Largeur; j++)
        {
            // cout << '[' << i << ']' << '[' << j << ']' << " liste d'agents : " << cases[i][j] << endl;
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

Regles Plateau::parseRegle() const
{
    Regles regles;
    for (int i = 0; i < Longueur; i++)
    {
        for (int j = 0; j < Largeur - 2; j++)
        {
            const Case *c = getCase(i, j);
            const WordInfo *m_info = c->motPresentEtNom();
            if(m_info != nullptr) {
                regles.VerifRule(*m_info, c, regles, this);
                // VerifRule(*m_info, c, regles);
            }
        }
    }
    return regles;
}