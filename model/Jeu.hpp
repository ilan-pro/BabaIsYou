#ifndef _JEU
#define _JEU

#include <vector>
#include "Plateau.hpp"
#include "Direction.hpp"
#include "EtatJeu.hpp"

using namespace std;

class EtatJeu;

class Jeu
{
private:
    /*
     * ici on souhaite une composition donc si on avait Plateau &plateau ,
     * on devait initialiser le plateau a l'exterieur de Jeu ce qui est problématique
     */
    Plateau plateau;

    /*
     * Attention ici ne pas oublié de delete dans le destructeur de Jeu sinon fuite de mémoire
     */
    vector<Agent *> agents;
    vector<Agent *> joueur;
    Regles regles;
    vector<Agent *> dejaBouges;
    vector<Agent *> demandeur;
    vector<EtatJeu *> undoStack;
    vector<EtatJeu *> redoStack;

public:
    bool closeWin;
    Jeu();
    ~Jeu();
    void ajouterAgent(Agent *a);
    void initTestMap();
    void initMap1();
    void supprimerDeDemandeur(Agent *a);
    bool deplaceRec(pair<int, int> nv_direction, Case *c, Agent *joueur);
    void deplacerAgents(Case *src, Case *dst, Agent *demandeur);
    template<typename T>
    T* spawnAgent(int x, int y, bool estJoueur);
    Mot* spawnMot(int x, int y, Word w);
    void deplace(Direction d);
    bool aDejaBouge(Agent *a);
    bool demandeuraDejaBouge();
    void marqueCommeBouge(Agent *a);
    void marqueCommeDemandeur(Agent *a);
    const Plateau &getPlateau() const;
    vector<Agent *> getAgents() const;
    Regles getRule() const;
    void MajRegle();
    void VerifJoueur();
    void sauvegarderEtat();
    void redo();
    void undo();
    void restaurer(const EtatJeu *etat);
};

#endif