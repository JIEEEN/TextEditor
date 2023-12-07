#include <GuiController.h>
#include <utils.h>


void GuiController::makeSaveBox(sf::RenderWindow& window){
    tgui::ChildWindow::Ptr save_box = tgui::ChildWindow::create();

    save_box->setTitle("Save");
    save_box->setResizable(true);

    std::tuple<uint16_t, uint16_t> center = getWidgetCenter(window);
    uint16_t center_x = std::get<0>(center);
    uint16_t center_y = std::get<1>(center);

    sf::Vector2f sb_size = save_box->getSize();
    std::cout << sb_size.x << " " << sb_size.y << std::endl;
    save_box->setPosition(center_x-sb_size.x/2, center_y-sb_size.y/2);



    this->gui.add(save_box);
}
