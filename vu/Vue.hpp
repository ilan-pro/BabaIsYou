#ifndef _VUE
#define _VUE

#include <map>
#include <SFML/Graphics.hpp>
#include "../model/Jeu.hpp"

class Vue
{
private:
    sf::RenderWindow &window; // référence à la fenêtre SFML
    Jeu &jeu;
    sf::Texture spriteSheet;
    std::map<ObjectType, sf::IntRect> rectsEntity;
    sf::Texture textureLapin;
    sf::Texture textureMur;
    sf::Texture textureRocher;
    sf::Texture textureEau;
    sf::Texture textureFlag;
    sf::Texture textureText;
    std::map<Word, sf::IntRect> wordTextures;

public:
    Vue(sf::RenderWindow &win, Jeu &j);
    sf::IntRect &getTextureForAgent(Agent *a);
    void chargerTextures();
    void afficher();
    ~Vue();
};

#endif