#include <SFML/Graphics.hpp>
#include <File.h>
#include <TextController.h>
#include <KeyController.h>


#define FILENAME "test.txt"

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "text");

    File _file;
    KeyMsg key_msg;

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::TextEntered:
                    _file.textController.textProcess(window, event);
                    break;
                case sf::Event::KeyPressed:
                    _file.keyController.updatePressedKey(event.key.code, true);
                    key_msg = _file.keyController.keyProcess(window, event, _file.textController);

                    _file.setFileName(FILENAME);

                    switch(key_msg){
                        case KeyMsg::SAVE:
                            _file.fileSave();
                            break;
                        case KeyMsg::SAVE_ANOTHER_NAME:
                            break;
                        case KeyMsg::NONE:
                            break;
                    };

                    break;
                case sf::Event::KeyReleased:
                    _file.keyController.updatePressedKey(event.key.code, false);
                    break;
            }
        }

        _file.textController.setFontSize(13);
        _file.textController.setFontColor(sf::Color::Black);

        window.clear(sf::Color::White);
        _file.textController.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}