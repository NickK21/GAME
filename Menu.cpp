#include "Menu.hpp"

Menu::Menu()
{
    g_Title = "";
    options = std::vector<std::string>{};

}
void Menu::print() const
{
    
    std::cout << g_Title << "\n";

    for (int i = 0; i < options.size(); i++) 
    {
        std::cout << (i + 1) << ")" << options[i] << "\n";
    }
}
void Menu::setTitle (const std::string& title) 
{
    g_Title = title;    
}
std::string Menu::getTitle() const{
    return g_Title;
}
void Menu::addOption(const std::string& option) 
{
    options.push_back(option);
}