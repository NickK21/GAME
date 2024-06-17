#include "MapMenu.hpp"

std::pair<Menu::Event, int> MapMenu::handleInput(int input)
    {
        if (input < 0 || input > 5) 
        {
            return std::make_pair(Event::InvalidInput, 0);
        } 
        else if (input == 1) 
        {
            return std::make_pair(Event::ChangeLocation, 1);
        }
        else if (input == 2)
        {
            return std::make_pair(Event::ChangeLocation, 2);
        } 
        else if (input ==3)
        {
            return std::make_pair(Event::ChangeLocation, 3);
        }
        else if (input == 4)
        {
            return std::make_pair(Event::ChangeLocation, 4);
        }
        else if (input == 5)
        {
            return std::make_pair(Event::Exit, 5);
        }
        else 
        {
            return std::make_pair(Event::None, 0);
        }
    }