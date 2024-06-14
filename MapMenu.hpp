#pragma once
#include "std::lib.hpp"
#include "Menu.hpp"

class MapMenu : public Menu
{
public:

    std::pair<Event, int> handleInput(int input) override;

};