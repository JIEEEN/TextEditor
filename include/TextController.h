#ifndef __TEXT_CONTROLLER_
#define __TEXT_CONTROLLER_

#include <SFML/Graphics.hpp>
#include <CursorProcessor.h>

#include <common.h>

class TextController{
    private:
        sf::Font font;
        std::unique_ptr<sf::Text> text;
        std::string inputText;
        CursorProcessor cursor;
        
    public:
        TextController(sf::RenderWindow&);
        ~TextController(){};

        void draw(sf::RenderWindow&);
        void setFontSize(const int&);
        void setFontColor(sf::Color);
        void textProcess(sf::Event&);
};

#endif // __TEXT_CONTROLLER_