#ifndef _CONTROLLER
#define _CONTROLLER

#include "../model/Jeu.hpp"

class Controller {
    private:
        Jeu& jeu;
    public:
    Controller(Jeu& jeu);
    void gestionEvenement(const sf::Event& e);

};

#endif