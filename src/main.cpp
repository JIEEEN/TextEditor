#include <SFML/Graphics.hpp>
#include <TextController.h>

// #include "common.h"


int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "text");

    TextController textController(window);

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::TextEntered){
                textController.textProcess(event);
            }
        }

        textController.setFontSize(13);
        textController.setFontColor(sf::Color::Black);

        window.clear(sf::Color::White);
        textController.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}