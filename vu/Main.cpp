#include <SFML/Graphics.hpp>
#include "../controller/Controller.hpp"
#include "../vu/Vue.hpp"
#include "../model/Jeu.hpp"

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "Test MVC");
    sf::Event event;

    Jeu jeu;
    Controller controller(jeu);
    Vue vue(window, jeu); 

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            controller.gestionEvenement(event);
        }
        vue.afficher();
        window.clear();
    }
    return EXIT_SUCCESS;
}
