#include "Vue.hpp"

#include "../model/Agent/Lapin.hpp"
#include "../model/Agent/Mur.hpp"
#include "../model/Agent/Rocher.hpp"
#include "../model/Agent/Eau.hpp"
#include "../model/Agent/Mot.hpp"

using namespace sf;

Vue::Vue(RenderWindow &win, Jeu &j) : window(win), jeu(j)
{
    initView();
    chargerTextures();
}

void Vue::initView() {
    int worldWidth  = jeu.getPlateau().getLargeur()  * 32;
    int worldHeight = jeu.getPlateau().getLongueur() * 32;

    view.setSize(worldWidth, worldHeight);
    view.setCenter(worldWidth / 2.0, worldHeight / 2.0);
    // view.zoom(2.f);

    window.setView(view);
    window.clear(Color(15, 10, 25));
}

void Vue::chargerTextures()
{
    spriteSheet.loadFromFile("./ressource/spritesheet.png");

    // un carré sur la sprite fait 8 pixels donc un baba donne 8*3
    int affiche_tuile = 8*3;
    
    rectsEntity[ObjectType::BABA] = IntRect(0, 0, affiche_tuile, affiche_tuile);
    rectsEntity[ObjectType::FLAG] = IntRect(6*affiche_tuile, 23*affiche_tuile, affiche_tuile, affiche_tuile);
    rectsEntity[ObjectType::ROCK] = IntRect(15*affiche_tuile, 22*affiche_tuile, affiche_tuile, affiche_tuile);
    rectsEntity[ObjectType::WALL] = IntRect(0, 57*affiche_tuile, affiche_tuile, affiche_tuile);
    rectsEntity[ObjectType::WATER] = IntRect(0, 49*affiche_tuile, affiche_tuile, affiche_tuile);

    wordTextures[Word::BABA] = IntRect(6*affiche_tuile, 27*affiche_tuile, affiche_tuile, affiche_tuile);
    wordTextures[Word::ROCK] = IntRect(11*affiche_tuile, 33*affiche_tuile, affiche_tuile, affiche_tuile);
    wordTextures[Word::WALL] = IntRect(27*affiche_tuile, 34*affiche_tuile, affiche_tuile, affiche_tuile);
    wordTextures[Word::IS] = IntRect(18*affiche_tuile, 32*affiche_tuile, affiche_tuile, affiche_tuile);
    wordTextures[Word::YOU] = IntRect(20*affiche_tuile, 42*affiche_tuile, affiche_tuile, affiche_tuile);
    wordTextures[Word::STOP] = IntRect(12*affiche_tuile, 42*affiche_tuile, affiche_tuile, affiche_tuile);
    wordTextures[Word::PUSH] = IntRect(2*affiche_tuile, 42*affiche_tuile, affiche_tuile, affiche_tuile);
    wordTextures[Word::FLAG] = IntRect(1*affiche_tuile, 30*affiche_tuile, affiche_tuile, affiche_tuile);
    wordTextures[Word::WIN] = IntRect(17*affiche_tuile, 44*affiche_tuile, affiche_tuile, affiche_tuile);
}

Vue::~Vue() {}

IntRect &Vue::getTextureForAgent(Agent *a)
{
    if(a->getType() == ObjectType::TEXT) {
        Mot *m = dynamic_cast<Mot *>(a);
        if(m){
            return wordTextures[m->getWord()];
        
        }
    }
    return rectsEntity[a->getType()];
}



void Vue::afficher()
{
    const Plateau &plateau = jeu.getPlateau();
    for (int i = 0; i < plateau.getLongueur(); ++i)
    {
        for (int j = 0; j < plateau.getLargeur(); ++j)
        {
            const Case *c = plateau.getCase(i, j);
            for (Agent *a : c->getAgents())
            {
                Sprite sprite;
                sprite.setTexture(spriteSheet);
                sprite.setTextureRect(getTextureForAgent(a));
                sprite.setPosition(j * 32, i * 32); // taille case = 32px
                window.draw(sprite);
            }
        }
    }
    window.display();
}
