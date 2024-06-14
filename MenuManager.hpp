#pragma once
#include "std::lib.hpp"
#include "Menu.hpp"


class MenuManager
{
public:
    MenuManager();

    void handleInput(int input);
    void addMenu(Menu& menu);
    void print();
    
private:
    std::size_t g_CurrentMenu;
    std::vector<Menu*> g_Menu;
};