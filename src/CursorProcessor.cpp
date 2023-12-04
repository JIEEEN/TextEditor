#include <CursorProcessor.h>


void CursorProcessor::setCursorIndexX(uint32_t idx){
    this->cursor_index_x = idx;
}
void CursorProcessor::setCursorIndexY(uint32_t idx){
    this->cursor_index_y = idx;
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
    this->cursor_shape.setFillColor()
} 
