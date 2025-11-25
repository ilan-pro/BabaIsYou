#include <SFML/Graphics.hpp>
#include "../controller/Controller.hpp"
#include "../vu/Vue.hpp"
#include "../model/Jeu.hpp"

using namespace sf;
// int main()
// {
//     Controller* controller;
//     Jeu* jeu;
//     Vue vue = {};;
//     sf::Event event;
//     RenderWindow app(VideoMode(800, 600, 32), "Test");
//     while (app.isOpen())
//     {
//         /** envoyer l'état de l'app pour que le controller puisse mettre à jour les états du clavier dans la même app */

//         while(app.pollEvent(event)){
//             controller->gestionEvenement(event);
//         }

//         // update model

//         // update graphic
//         app.clear();

//         //appelle de la vue

//         app.display();
//     }
//     return EXIT_SUCCESS;
// }

int main()
{ 

    

    cout << "ahhh" << endl;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test MVC");

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
