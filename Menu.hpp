#pragma once
#include "std::lib.hpp"

class Menu
{
public:
    enum class Event
    {
        InvalidInput = 0,
        ChangeLocation = 1,
        Exit = 2,
        None = 3
    };

    Menu();
    virtual std::pair<Event, int> handleInput(int input) = 0;
    void print() const;
    void setTitle (const std::string& title);
    std::string getTitle() const;
    void addOption(const std::string& option);
    
private:
    std::string g_Title;
    std::vector<std::string> options;
};