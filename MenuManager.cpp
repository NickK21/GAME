#include "MenuManager.hpp"

MenuManager::MenuManager()
{
    g_CurrentMenu = 0;
    g_Menu = std::vector<Menu*>{};
}
void MenuManager::handleInput(int input)
    {
        auto response = g_Menu[g_CurrentMenu]->handleInput(input);

        switch (response.first) 
        {  
            case Menu::Event::InvalidInput:
                std::cout << "Invalid Input\n";
                break;
            case Menu::Event::ChangeLocation:
                g_CurrentMenu = response.second;
                break; 
            case Menu::Event::Exit:
                std::exit(0);
                break;
            default:
                break;   
        }
    }
    void MenuManager::addMenu(Menu& menu)
    {
        g_Menu.push_back(&menu);
    }
    void MenuManager::print() 
    {
        g_Menu[g_CurrentMenu]->print();
    }