#ifndef __TEXT_CONTROLLER_
#define __TEXT_CONTROLLER_

#include <SFML/Graphics.hpp>
#include <CursorProcessor.h>

#include <common.h>

class TextController{
    private:
        uint32_t num_linefeed;
        uint8_t line_height;
        float_t char_width;

        sf::Font font;
        std::unique_ptr<sf::Text> text;

        std::string inputText;
        std::vector<uint32_t> line_width;

        CursorProcessor cursor;
    public:
        TextController(sf::RenderWindow&);
        ~TextController(){};

        void draw(sf::RenderWindow&);
        void setFontSize(const int&);
        void setFontColor(sf::Color);
        void textProcess(sf::RenderWindow&, sf::Event&);
};

#endif // __TEXT_CONTROLLER_