#include <SFML/Graphics.hpp>
#include <File.h>
#include <TextController.h>
#include <KeyController.h>
#include <GuiController.h>

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <TGUI/Widgets/Button.hpp>
#include <TGUI/Widgets/CheckBox.hpp>


int main(){
    sf::RenderWindow window(sf::VideoMode(DEFAULT_WIDTH, DEFAULT_HEIGHT), "text");
    window.setFramerateLimit(60);

    File _file;
    KeyMsg key_msg;
    GuiController gui_controller(window);

    while(window.isOpen()){
        sf::Event event;

        while(window.pollEvent(event)){
            gui_controller.gui.handleEvent(event);

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

                    _file.setFileName(FILE_NAME);

                    switch(key_msg){
                        case KeyMsg::SAVE:
                            gui_controller.makeSaveBox(window);

                            _file.fileSave();
                            break;
                        // case KeyMsg::SAVE_ANOTHER_NAME:
                        //     break;
                        // case KeyMsg::NONE:
                        //     break;
                    };

                    break;
                case sf::Event::KeyReleased:
                    _file.keyController.updatePressedKey(event.key.code, false);
                    break;
            }
        }

        _file.textController.setFontSize(FONT_SIZE);
        _file.textController.setFontColor(sf::Color::Black);

        window.clear(sf::Color::White);
        gui_controller.gui.draw();
        _file.textController.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}