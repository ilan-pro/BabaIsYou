#include "Vue.hpp"

#include "../model/Lapin.hpp"
#include "../model/Mur.hpp"
#include "../model/Rocher.hpp"
#include "../model/Eau.hpp"

Vue::Vue(sf::RenderWindow &win, Jeu &j)
    : window(win), jeu(j)
{
    chargerTextures();
}

void Vue::chargerTextures()
{
    textureLapin.loadFromFile("./ressource/rabbit.png");
    textureMur.loadFromFile("./ressource/blanc.png");
    textureRocher.loadFromFile("./ressource/roche.png");
    textureEau.loadFromFile("./ressource/waves.png");
    textureFlag.loadFromFile("./ressource/mur.png");
    textureText.loadFromFile("./ressource/murs.png");
}

sf::Texture &Vue::getTextureForAgent(Agent *a)
{
    switch (a->getType())
    {
    case ObjectType::WATER:
        return textureEau;
    case ObjectType::BABA:
        return textureLapin;
    case ObjectType::ROCK:
        return textureRocher;
    case ObjectType::WALL:
        return textureMur;
    case ObjectType::FLAG:
        return textureFlag;
    case ObjectType::TEXT:
        return textureText;
    default:
        return textureLapin; // fallback
    }
}

void Vue::afficher()
{
    window.clear(sf::Color::White);

    const Plateau &plateau = jeu.getPlateau();
    for (int i = 0; i < plateau.getLongueur(); ++i)
    {
        for (int j = 0; j < plateau.getLargeur(); ++j)
        {
            const Case *c = plateau.getCase(i, j);
            for (Agent *a : c->getAgents())
            {
                sf::Sprite sprite;
                sprite.setTexture(getTextureForAgent(a));

                // sprite.setScale(sf::Vector2f(0.1, 0.1));

                // sprite.setPosition(j * 32, i * 32);

                float targetSize = 32.0f;
                sf::Vector2u size = sprite.getTexture()->getSize();
                sprite.setScale(targetSize / size.x, targetSize / size.y);
                /* ICI les sprite utilise les vraies coordonnées trigo avec x : colonne et y : ligne (inverse de nous) */
                sprite.setPosition(j * 32, i * 32); // taille case = 32px
                window.draw(sprite);
            }
        }
    }
    window.display();
}

Vue::~Vue()
{
}