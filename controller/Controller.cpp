#include "Controller.hpp"


void Controller::gestionEvenement(const sf::Event& e) {
    if (e.type == sf::Event::KeyPressed) {
        Direction dir;
        bool pressed = true;
        switch (e.key.code) {
            case sf::Keyboard::Left:  dir = Direction::Gauche; break;
            case sf::Keyboard::Right: dir = Direction::Droite; break;
            case sf::Keyboard::Up:    dir = Direction::Haut; break;
            case sf::Keyboard::Down:  dir = Direction::Bas; break;
            default: pressed = false; break;
        }
        if (pressed) {
            jeu.deplace(dir); // le modèle fait tout le calcul
        }
    }
}
