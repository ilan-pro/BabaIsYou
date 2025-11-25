#ifndef _VUE
#define _VUE

#include <SFML/Graphics.hpp>
#include "../model/Jeu.hpp"

class Vue
{
private:
    sf::RenderWindow &window; // référence à la fenêtre SFML
    Jeu &jeu;
    sf::Texture textureLapin;
    sf::Texture textureMur;
    sf::Texture textureRocher;
    sf::Texture textureEau;

public:
    Vue(sf::RenderWindow &win, Jeu &j);

    void chargerTextures();

    void afficher();

    ~Vue();
};

#endif