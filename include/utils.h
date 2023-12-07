#include <common.h>
#include <SFML/Graphics.hpp>

const std::tuple<uint16_t, uint16_t> getWidgetCenter(sf::RenderWindow& window){
    uint16_t center_x;
    uint16_t center_y;

    sf::Vector2u window_size = window.getSize();

    center_x = static_cast<uint16_t>(window_size.x)/2;
    center_y = static_cast<uint16_t>(window_size.y)/2;

    return std::make_tuple(center_x, center_y);
}