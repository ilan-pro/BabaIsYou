#include <SFML/Graphics.hpp>
#include "../controller/Controller.hpp"
#include "../vu/Vue.hpp"
#include "../model/Jeu.hpp"

using namespace sf;



int main()
{
    RenderWindow window(VideoMode(880, 700), "Baba is You");
    Event event;

    Jeu jeu;
    Controller controller(jeu);
    Vue vue(window, jeu);

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            controller.gestionEvenement(event);
        }
        if (jeu.closeWin)
        {
            window.close();
        }
        vue.afficher();
        window.clear();
    }
    return EXIT_SUCCESS;
}