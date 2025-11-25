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
                if (dynamic_cast<Lapin *>(a))
                    sprite.setTexture(textureLapin);
                else if (dynamic_cast<Mur *>(a))
                    sprite.setTexture(textureMur);
                else if (dynamic_cast<Rocher *>(a))
                    sprite.setTexture(textureRocher);
                else if (dynamic_cast<Eau *>(a))
                    sprite.setTexture(textureEau);

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