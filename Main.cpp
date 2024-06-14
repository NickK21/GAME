#include "std::lib.hpp"
#include "Player.hpp"
#include "MenuManager.hpp"
#include "Menu.hpp"
#include "MapMenu.hpp"
#include "GameMenu.hpp"

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
