#pragma once
#include "std::lib.hpp"
#include "Menu.hpp"

class GameMenu : public Menu
{
public:
    std::function<void(void)> function;
    std::pair<Event, int> handleInput(int input) override;
    
private:
};