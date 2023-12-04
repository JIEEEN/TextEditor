#ifndef __CURSOR_PROCESSOR_
#define __CURSOR_PROCESSOR_

#include <SFML/Graphics.hpp>
#include <common.h>


class CursorProcessor{
    private:
        uint8_t cursor_offset_x;
        uint8_t cursor_offset_y;

        uint32_t cursor_index_x;
        uint32_t cursor_index_y;

        const uint8_t cursor_width;
        const uint8_t cursor_height;

        sf::RectangleShape cursor_shape;
        std::chrono::time_point<std::chrono::high_resolution_clock> toggle_timer;
    public:
        CursorProcessor(uint32_t x_idx, uint32_t y_idx, uint8_t c_w, uint8_t c_h):
            cursor_offset_x(10),
            cursor_offset_y(10),
            cursor_index_x(0),
            cursor_index_y(0),
            cursor_width(c_w),
            cursor_height(c_h),
            toggle_timer(std::chrono::high_resolution_clock::now())
            {
                this->cursor_shape.setSize(sf::Vector2f(c_w, c_h));
                this->cursor_shape.setFillColor(sf::Color::Black);
                this->cursor_shape.setPosition(10, 10);
            };
        ~CursorProcessor(){};
        void setCursorIndexX(uint32_t);
        void setCursorIndexY(uint32_t);
        void setCursorColor(sf::Color);
        uint32_t getCursorIndexX() const;
        uint32_t getCursorIndexY() const;
        void moveCursorShape(float_t, uint32_t);
        void drawCursor(sf::RenderWindow& window);
        void cursorToggle();
        void resetToggleTimer();
};

#endif // __CURSOR_PROCESSOR_