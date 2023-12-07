#ifndef __GUI_CONTROLLER_
#define __GUI_CONTROLLER_

#include <common.h>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

class GuiController{
    // private:
    public:
        tgui::Gui gui;

        GuiController(sf::RenderWindow& window){
            gui.setWindow(window);
        }
        ~GuiController(){};
        void makeSaveBox(sf::RenderWindow&);
};

#endif // __GUI_CONTROLLER_