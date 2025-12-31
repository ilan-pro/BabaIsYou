#include <SFML/Graphics.hpp>
#include "../controller/Controller.hpp"
#include "../vu/Vue.hpp"
#include "../model/Jeu.hpp"

using namespace sf;

int main()
{ 
    sf::RenderWindow window(sf::VideoMode(900, 900), "Test MVC");

    Jeu jeu;                    // modèle
    Controller controller(jeu); // contrôleur
    Vue vue(window, jeu);       // vue

    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            controller.gestionEvenement(event);
        }

        // éventuellement jeu.update(); si tu simules les animaux

        vue.afficher();
        window.clear();
    }

    return EXIT_SUCCESS;
}
