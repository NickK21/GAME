#include "std::lib.hpp"
#include "Player.hpp"
#include "MenuManager.hpp"
#include "Menu.hpp"
#include "MapMenu.hpp"
#include "GameMenu.hpp"


class Enemy : public Stats
{
public:
    Enemy()
    {
        std::string name_ = "";
        int health_ = 0;
    }


private:
};

int main() 
{

    auto player1 = Player{};

    auto goblin = Enemy{};
    goblin.setHealth(5);

    // auto troll = Enemy{};


    auto forest = GameMenu{};
    forest.setTitle("Forest");
    forest.addOption("Cut Tree");
    forest.addOption("Go To Map");
    forest.addOption("Exit");
    forest.function = [&player1]()
    {
        player1.addLogs();
        std::cout << "You Have " << player1.getLogs() << " Log(s)\n";
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
            std::cout << "You Can't Sell Shit You Don't Have, Stupid\n";
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
    
    auto thunderdome = GameMenu{};
    thunderdome.setTitle("Welcome to The ThunderDome");
    thunderdome.addOption("Fight Monster");
    thunderdome.addOption("Go To Map");
    thunderdome.addOption("Exit");
    thunderdome.function = [&goblin]()
    {   
        while (goblin.getHealth() > 0) 
        {

            std::cout << "\nThe Goblin's Health is: " << goblin.getHealth() << "\n";
            std::cout << "You Attacked The Goblin, -1 health\n";
            goblin.setHealth(goblin.getHealth() -  1);
            std::cout << "The Goblin's Health Is Now " << goblin.getHealth() << "\n\n";
        }
    };

    auto map = MapMenu{};
    map.setTitle("Map");
    map.addOption("Go Home");
    map.addOption("Go To Town");
    map.addOption("Go To Forest");
    map.addOption("Go To ThunderDome");
    map.addOption("Exit");

    auto manager = MenuManager{};
    manager.addMenu(map);
    manager.addMenu(home);
    manager.addMenu(town);
    manager.addMenu(forest);
    manager.addMenu(thunderdome);


    auto input = 0;
    while (true)
    {
        manager.print();
        std::cin >> input;
        manager.handleInput(input);

    }

    return 0;
}
