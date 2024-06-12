#include <vector>
#include <iostream>
#include <string>

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

    Menu()
{
    g_Title = "";
    options = std::vector<std::string>{};

}

virtual std::pair<Event, int> handleInput(int input) = 0;

// std::pair<Location, std::string> handleInput(int input) const
//     {
//         if (input < 0 || input > 3) 
//         {
//             return std::make_pair(Location::InvalidInput, "");
//         } 
//         else if (input == 1) 
//         {
//             return std::make_pair(Location::Forest, "");
//         } 
//         else if (input == 2) 
//         {
//             return std::make_pair(Location::Town, "");
//         } 
//         else if (input == 3)
//         {
//             return std::make_pair(Location::Home, "");
//         } 
//         else 
//         {
//             return std::make_pair(Location::Exit, "");
//         }
//     }
void print() const
{
    
    std::cout << g_Title << "\n";

    for (int i = 0; i < options.size(); i++) 
    {
        std::cout << (i + 1) << ")" << options[i] << "\n";
    }
}
void setTitle (const std::string& title) 
{
    g_Title = title;    
}
std::string getTitle() {
    return g_Title;
}
void addOption(const std::string& option) 
{
    options.push_back(option);
}
private:
    std::string g_Title;
    std::vector<std::string> options;

};

class MapMenu : public Menu
{
public:

    std::pair<Event, int> handleInput(int input) override
    {
        if (input < 0 || input > 3) 
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
        else if (input == 3) 
        {
            return std::make_pair(Event::ChangeLocation, 3);
        } else {
            return std::make_pair(Event::None, 0);
        }
    }
private:

};

class GameMenu : public Menu
{
public:

    std::pair<Event, int> handleInput(int input) override
    {
         if (input < 0 || input > 3) 
        {
            return std::make_pair(Event::InvalidInput, 0);
        // }  else if (input == 1) 
        // {
        //     return std::make_pair(Location::Forest, "");
        }
        else if (input == 2) 
        {
            return std::make_pair(Event::ChangeLocation, 0); 
        }
        else if (input == 3)
        {
            return std::make_pair(Event::Exit, 0);
        } else 
        {
            return std::make_pair(Event::None, 0);
        }
    }
private:

};

class MenuManager
{
public:
    MenuManager()
    {
        g_CurrentMenu = 0;
        g_Menu = std::vector<Menu*>{};
    }

    void handleInput(int input)
    {
        auto response = g_Menu[g_CurrentMenu]->handleInput(input);

        switch (response.first) 
        {
            
            case GameMenu::Event::InvalidInput:
                std::cout << "Invalid Input";
                break;
            case GameMenu::Event::ChangeLocation:
                g_CurrentMenu = response.second;
                break; 
            case GameMenu::Event::Exit:
                std::exit(0);
                break;
            default:
                break;
        
        }
    }

    void addMenu(Menu& menu)
    {
        g_Menu.push_back(&menu);
    }

    void print() {
        g_Menu[g_CurrentMenu]->print();
    }

private:
    std::size_t g_CurrentMenu;
    std::vector<Menu*> g_Menu;
};



int main() 
{

    auto forest = GameMenu{};
    forest.setTitle("Forest");
    forest.addOption("Cut Tree");
    forest.addOption("Go To Map");
    forest.addOption("Exit");

    auto town = GameMenu{};
    town.setTitle("Town");
    town.addOption("Sell Log");
    town.addOption("Go To Map");
    town.addOption("Exit");
    
    auto home = GameMenu{};
    home.setTitle("Home");
    home.addOption("Print Stats");
    home.addOption("Go to Map");
    home.addOption("Exit");
    
    auto map = MapMenu{};
    map.setTitle("Map");
    map.addOption("Go Home");
    map.addOption("Go To Town");
    map.addOption("Go To Forest");

    auto manager = MenuManager{};
    manager.addMenu(map);
    manager.addMenu(home);
    manager.addMenu(town);
    manager.addMenu(forest);

    auto input = 0;
    while (true)
    {
        manager.print();
        std::cin >> input;
        manager.handleInput(input);

    }

    return 0;
}
