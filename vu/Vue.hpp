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
    sf::View view;
    sf::Image sheetImg;
    sf::Texture spriteSheet;
    std::map<ObjectType, std::pair<sf::IntRect, sf::Color>> rectsEntity;
    sf::Texture textureLapin;
    sf::Texture textureMur;
    sf::Texture textureRocher;
    sf::Texture textureEau;
    sf::Texture textureFlag;
    sf::Texture textureText;
    std::map<Word, std::pair<sf::IntRect, sf::Color>> wordTextures;
public:
    Vue(sf::RenderWindow &win, Jeu &j);
    void initView();
    std::pair<sf::IntRect, sf::Color>& getTextureForAgent(Agent *a);
    void chargerTextures();
    void afficher();
    ~Vue();
};

#endif