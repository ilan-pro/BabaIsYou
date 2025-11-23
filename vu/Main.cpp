#include <SFML/Graphics.hpp>

#include "../controller/Controller.hpp"

using namespace sf;
int main()
{
    Controller* controller;
    Jeu* jeu;
    sf::Event event
    RenderWindow app(VideoMode(800, 600, 32), "Test");
    while (app.isOpen())
    {
        /** envoyer l'état de l'app pour que le controller puisse mettre à jour les états du clavier dans la même app */
        while(app.pollEvent(event)){
            controller->gestionEvenement(app);

        }
    } 
    return EXIT_SUCCESS;
}



