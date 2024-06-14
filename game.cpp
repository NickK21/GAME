#include <vector>
#include <iostream>
#include <string>
#include <functional>

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
        } 
        else 
        {
            return std::make_pair(Event::None, 0);
        }
    }
private:

};

class GameMenu : public Menu
{
public:
    std::function<void(void)> function;


    std::pair<Event, int> handleInput(int input) override
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
                std::cout << "Invalid Input\n";
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

class Player
{

public:
    Player()
    {
        logs_ = 0;
        money_ = 0;
    }

    void setMoney(int money)
    {
        money_ = money;
    }
    int getMoney() const
    {
        return money_;
    }
    void setLogs(int logs)
    {
        logs_ = logs;
    }
    int getLogs() const 
    {
        return logs_;
    }
    void addLogs()
    {
        logs_++;
    }
    void addMoney()
    {
        money_++;
    }
    void print() const
    {
        std::cout << "*************************\n";
        std::cout << "You have " 
        << money_ << " monies and " << logs_ << " logs\n";
        std::cout << "*************************\n";
    }

private:
    int logs_;
    int money_;
};

int main() 
{
    auto player1 = Player{};


    auto forest = GameMenu{};
    forest.setTitle("Forest");
    forest.addOption("Cut Tree");
    forest.addOption("Go To Map");
    forest.addOption("Exit");
    forest.function = [&player1]()
    {
        player1.addLogs();
        std::cout << "You have " << player1.getLogs() << " log(s)\n";
    };

    auto town = GameMenu{};
    town.setTitle("Town");
    town.addOption("Sell Logs");
    town.addOption("Go To Map");
    town.addOption("Exit");
    town.function = [&player1]()
    {
        if (player1.getLogs() < 1)
        {
            std::cout << "You can't sell shit you don't have, stupid\n";
        } else
        {
            player1.addMoney();
            player1.setLogs(player1.getLogs() - 1);
            std::cout << "You have " << player1.getMoney() << " monies\n";
        }    

    };
    
    auto home = GameMenu{};
    home.setTitle("Home");
    home.addOption("Print Stats");
    home.addOption("Go to Map");
    home.addOption("Exit");
    home.function = [&player1]()
    {
        player1.print();
    };
    
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
