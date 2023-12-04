#include <TextController.h>

TextController::TextController(sf::RenderWindow& window): num_linefeed(0), inputText(""), cursor(0, 0, 8, 15){
    if (!this->font.loadFromFile("/Users/jin/Desktop/TED/assets/DejaVuSansMono.ttf")) {
        std::cerr << "FILE OPEN FAILED" << std::endl;
        exit(EXIT_FAILURE);
    }

    this->text = std::unique_ptr<sf::Text>(new sf::Text("TEST", font, 15)); 
    this->text->setFillColor(sf::Color::Black);
    this->text->setPosition(10, 10);

    this->text->setString("_");
    this->char_width = this->text->getLocalBounds().width;
}

void TextController::draw(sf::RenderWindow& window){
    window.draw(*this->text);
    this->cursor.drawCursor(window);
    this->cursor.cursorToggle();
}

void TextController::setFontSize(const int& font_size){
    this->text->setCharacterSize(font_size);
}

void TextController::setFontColor(sf::Color color){
    this->text->setFillColor(color);
}

void TextController::textProcess(sf::RenderWindow& window, sf::Event& event){
    if(event.text.unicode < 128){
        this->cursor.resetToggleTimer();

        if(event.text.unicode == '\b' && !this->inputText.empty()){ // backspace
            const char erased_char = this->inputText.back();
            this->inputText.pop_back();
            if(erased_char == '\n'){
                this->cursor.setCursorIndexX(this->line_width.back());
                this->cursor.setCursorIndexY(this->cursor.getCursorIndexY()-1);

                this->num_linefeed -= 1;
                this->cursor.moveCursorShape(this->char_width, this->num_linefeed);
                this->line_width.pop_back();
            }
            else{
                this->cursor.setCursorIndexX(this->cursor.getCursorIndexX()-1);
                this->cursor.moveCursorShape(this->char_width, this->num_linefeed);
            }
        }else if(event.text.unicode == '\n'){
            this->inputText += '\n';
            this->num_linefeed += 1;

            this->line_width.push_back(this->cursor.getCursorIndexX());

            this->cursor.setCursorIndexX(0);
            this->cursor.setCursorIndexY(this->cursor.getCursorIndexY()+1);
            this->cursor.moveCursorShape(this->char_width, this->num_linefeed);
        }else{
            char new_char = static_cast<char>(event.text.unicode);
            this->inputText += new_char;

            this->cursor.setCursorIndexX(this->cursor.getCursorIndexX()+1);
            this->cursor.moveCursorShape(this->char_width, this->num_linefeed);
        }

        this->text->setString(this->inputText);
    }
}



