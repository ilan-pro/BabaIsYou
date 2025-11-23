#include "Vue.hpp"

#include "../model/Lapin.hpp"



Vue::Vue(sf::RenderWindow &win, Jeu &j)
    : window(win), jeu(j)
{
    chargerTextures();
}


void Vue::chargerTextures()
{
    textureLapin.loadFromFile("../ressource/lapin.png");
}

void Vue::afficher()
{
    window.clear(sf::Color::Black);

    const Plateau &plateau = jeu.getPlateau();
    for (int y = 0; y < plateau.getLongueur(); ++y)
    {
        for (int x = 0; x < plateau.getLargeur(); ++x)
        {
            const Case *c = plateau.getCase(x, y);
            for (Agent *a : c->getAgents())
            {
                sf::Sprite sprite;
                if (dynamic_cast<Lapin *>(a))
                    sprite.setTexture(textureLapin);

                sprite.setPosition(x * 32, y * 32); // taille case = 32px
                window.draw(sprite);
            }
        }
    }
    window.display();
}