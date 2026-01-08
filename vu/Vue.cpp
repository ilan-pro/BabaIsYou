#include "Vue.hpp"

#include "../model/Lapin.hpp"
#include "../model/Mur.hpp"
#include "../model/Rocher.hpp"
#include "../model/Eau.hpp"

Vue::Vue(sf::RenderWindow &win, Jeu &j) : window(win), jeu(j)
{
    chargerTextures();
}

void Vue::chargerTextures()
{
    spriteSheet.loadFromFile("./ressource/spritesheet.png");
    // un carré sur la sprite fait 8 pixels donc un baba donne 8*3
    int affiche_tuile = 8*3;
    rectsEntity[ObjectType::BABA] = sf::IntRect(0, 0, affiche_tuile, affiche_tuile);
    rectsEntity[ObjectType::FLAG] = sf::IntRect(6*affiche_tuile, 17*affiche_tuile, affiche_tuile, affiche_tuile);
    rectsEntity[ObjectType::ROCK] = sf::IntRect(15*affiche_tuile, 22*affiche_tuile, affiche_tuile, affiche_tuile);
    rectsEntity[ObjectType::WALL] = sf::IntRect(0, 57*affiche_tuile, affiche_tuile, affiche_tuile);
    rectsEntity[ObjectType::WATER] = sf::IntRect(0, 49*affiche_tuile, affiche_tuile, affiche_tuile);
    wordTextures[Word::BABA] = sf::IntRect(6*affiche_tuile, 27*affiche_tuile, affiche_tuile, affiche_tuile);
    wordTextures[Word::ROCK] = sf::IntRect(11*affiche_tuile, 33*affiche_tuile, affiche_tuile, affiche_tuile);
    wordTextures[Word::WALL] = sf::IntRect(27*affiche_tuile, 34*affiche_tuile, affiche_tuile, affiche_tuile);
    wordTextures[Word::IS] = sf::IntRect(18*affiche_tuile, 32*affiche_tuile, affiche_tuile, affiche_tuile);
    wordTextures[Word::YOU] = sf::IntRect(20*affiche_tuile, 42*affiche_tuile, affiche_tuile, affiche_tuile);
    wordTextures[Word::STOP] = sf::IntRect(12*affiche_tuile, 42*affiche_tuile, affiche_tuile, affiche_tuile);
    wordTextures[Word::PUSH] = sf::IntRect(2*affiche_tuile, 42*affiche_tuile, affiche_tuile, affiche_tuile);

    wordTextures[Word::FLAG] = sf::IntRect(1*affiche_tuile, 30*affiche_tuile, affiche_tuile, affiche_tuile);
    wordTextures[Word::WIN] = sf::IntRect(17*affiche_tuile, 0*affiche_tuile, affiche_tuile, affiche_tuile);
    

}

sf::IntRect &Vue::getTextureForAgent(Agent *a)
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
    window.clear(sf::Color(15, 10, 25));

    const Plateau &plateau = jeu.getPlateau();
    for (int i = 0; i < plateau.getLongueur(); ++i)
    {
        for (int j = 0; j < plateau.getLargeur(); ++j)
        {
            const Case *c = plateau.getCase(i, j);
            for (Agent *a : c->getAgents())
            {
                sf::Sprite sprite;
                sprite.setTexture(spriteSheet);
                sprite.setTextureRect(getTextureForAgent(a));
                sprite.setPosition(j * 32, i * 32); // taille case = 32px
                window.draw(sprite);
            }
        }
    }
    window.display();
}

Vue::~Vue() {}