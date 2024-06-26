#include "GameMenu.hpp" 

std::pair<Menu::Event, int> GameMenu::handleInput(int input) 
{
    if (input < 0 || input > 3) 
    {
        return std::make_pair(Event::InvalidInput, 0);
    }  
    else if (input == 1) 
    {
        function();
        return std::make_pair(Event::None, 0);
    }
    else if (input == 2) 
    {
        return std::make_pair(Event::ChangeLocation, 0); 
    }
    else if (input == 3)
    {
        return std::make_pair(Event::Exit, 0);
    } 
    else 
    {
        return std::make_pair(Event::None, 0);
    }
}