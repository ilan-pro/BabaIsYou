#include "Controller.hpp"



Controller::Controller(Jeu &jeu) : jeu{jeu} {}

void Controller::gestionEvenement(const sf::Event &e) {
    if (e.type == sf::Event::KeyPressed) {
        Direction dir;
        bool pressed = false;
        bool action_redo = false;
        bool action_undo = false;
        switch (e.key.code) {
            case sf::Keyboard::Left:  dir = Direction::Gauche; pressed = true; break;
            case sf::Keyboard::Right: dir = Direction::Droite; pressed=true; break;
            case sf::Keyboard::Up:    dir = Direction::Haut; pressed=true; break;
            case sf::Keyboard::Down:  dir = Direction::Bas; pressed=true; break;
            case sf::Keyboard::X:     action_redo = true; break;
            case sf::Keyboard::C:     action_undo = true; break;     
            default: pressed = false; break;
        }
        if (pressed) {
            jeu.MajRegle();
            jeu.sauvegarderEtat();
            jeu.deplace(dir); // le modèle fait tout le calcul
        }else if(action_redo) {
            jeu.redo();
            action_redo = false;
        } else if(action_undo) {
            jeu.undo();
            action_undo = false;
        }
    }
}
