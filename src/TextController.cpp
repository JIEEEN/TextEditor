#include <TextController.h>

TextController::TextController(sf::RenderWindow& window): inputText("") {
    if (!this->font.loadFromFile("/Users/jin/Desktop/sfml/assets/OpenSans-Light.ttf")) {
        std::cerr << "FILE OPEN FAILED" << std::endl;
        exit(EXIT_FAILURE);
    }

    this->text = std::unique_ptr<sf::Text>(new sf::Text("TEST", font, 16)); // 에러 발생하는 부분
    this->text->setFillColor(sf::Color::Black);
    this->text->setPosition(10, 10);
}

void TextController::draw(sf::RenderWindow& window){
    window.draw(*this->text);
}

void TextController::setFontSize(const int& font_size){
    this->text->setCharacterSize(font_size);
}

void TextController::setFontColor(sf::Color color){
    this->text->setFillColor(color);
}

void TextController::textProcess(sf::Event& event){
    if(event.text.unicode < 128){
        if(event.text.unicode == '\b' && !inputText.empty()){
            inputText.pop_back();
        }else if(event.text.unicode == 13){
            inputText += '\n';
        }else{
            inputText += static_cast<char>(event.text.unicode);
        }

        this->text->setString(inputText);
    }
}



