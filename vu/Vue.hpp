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
    sf::Texture textureFlag;
    sf::Texture textureText;
    private map<Word, sf::Texture> wordTextures;
public:
    Vue(sf::RenderWindow &win, Jeu &j);

    sf::Texture &getTextureForAgent(Agent *a);

    void chargerTextures();

    void afficher();

    ~Vue();
};

#endif