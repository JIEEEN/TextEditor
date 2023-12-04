#include <CursorProcessor.h>


void CursorProcessor::setCursorIndexX(uint32_t idx){
    this->cursor_index_x = idx;
}
void CursorProcessor::setCursorIndexY(uint32_t idx){
    this->cursor_index_y = idx;
}
void CursorProcessor::setCursorColor(sf::Color color){
    this->cursor_shape.setFillColor(color);
}

uint32_t CursorProcessor::getCursorIndexX() const{
    return this->cursor_index_x;
}
uint32_t CursorProcessor::getCursorIndexY() const{
    return this->cursor_index_y;
}

void CursorProcessor::moveCursorShape(float_t char_width, uint32_t num_linefeed){
    this->cursor_shape.setPosition(this->cursor_offset_x + 8*this->cursor_index_x, this->cursor_offset_y + 15*num_linefeed);
}

void CursorProcessor::drawCursor(sf::RenderWindow& window){
    window.draw(this->cursor_shape);
}

void CursorProcessor::cursorToggle(){
    auto check_point = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(check_point - this->toggle_timer);
    sf::Color current_color = this->cursor_shape.getFillColor();

    if(duration.count() > 500){
        if(current_color == sf::Color::White){
            this->cursor_shape.setFillColor(sf::Color::Black);
        }else this->cursor_shape.setFillColor(sf::Color::White);

        this->toggle_timer = std::chrono::high_resolution_clock::now();
    }
} 

void CursorProcessor::resetToggleTimer(){
    this->toggle_timer = std::chrono::high_resolution_clock::now();
    this->setCursorColor(sf::Color::Black);
}
