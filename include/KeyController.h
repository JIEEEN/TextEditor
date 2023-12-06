#ifndef __KEY_CONTROLLER_
#define __KEY_CONTROLLER_

#include <SFML/Graphics.hpp>
#include <TextController.h>
#include <common.h>

class KeyController{
    private:
        std::vector<bool> is_key_pressed;
    public:
        KeyController(): 
            is_key_pressed(76, false)
        {};
        ~KeyController(){};
        void updatePressedKey(const int, const int);
        KeyMsg keyProcess(sf::RenderWindow&, sf::Event&, TextController&);
};

#endif // __KEY_CONTROLLER_