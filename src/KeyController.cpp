#include <KeyController.h>

void KeyController::updatePressedKey(const int key_code, const int is_key_pressed){
    if(is_key_pressed == true){
        this->is_key_pressed[key_code+1] = true;
    }else{
        this->is_key_pressed[key_code+1] = false;
    }
}


KeyMsg KeyController::keyProcess(sf::RenderWindow& window, sf::Event& event, TextController& textController){
    if( // save
        this->is_key_pressed[19] && this->is_key_pressed[41] || // command + s
        this->is_key_pressed[19] && this->is_key_pressed[38] // ctrl + s
    ){
        return KeyMsg::SAVE;
    }

    return KeyMsg::NONE;
}