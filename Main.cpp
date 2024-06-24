#include "std::lib.hpp"
#include "Player.hpp"
#include "MenuManager.hpp"
#include "Menu.hpp"
#include "MapMenu.hpp"
#include "GameMenu.hpp"
#include "Util.hpp"

class Enemy : public Stats
{
public:
    Enemy()
    {
        std::string name_ = "";
        int health_ = 0;
        int minDamage_ = 0;
        int maxDamage_ = 0;
    }


private:
};

void FightScene(Player& p, Enemy& e) 
{
    int input = 0;

     while (e.getHealth() > 0 && input != 2 && p.getHealth() > 0)
    {
        
        int eDamage = RNG(e.getMinDamage(), e.getMaxDamage());
        int pDamage = RNG(p.getMinDamage(), p.getMaxDamage());
        
        std::cout << "\nThe " << e.getName() << "'s Health is: " << e.getHealth() << "\n";
        std::cout << "Your Health Is " << p.getHealth() << "\n";

        std::cout << e.getName() << ": Attack or Flee?\n";
        std::cout << "Press 1 To Attack, 2 To Flee\n";
        std::cin >> input;
        std::cout << "\n";

        switch (input)
        {
        case 1:
            std::cout << "You attacked the " << e.getName() << ", -" << eDamage << " health\n";
            e.setHealth(e.getHealth() - eDamage);
            std::cout << "The " << e.getName() << "'s Health Is Now " << e.getHealth() << "\n\n";
            std::cout << "The " << e.getName() << " Attacked Back" << ", -" << pDamage << " health!\n";
            p.setHealth(p.getHealth() - pDamage);
            std::cout << "Your Health Is Now " << p.getHealth() << "\n\n";
            break;
        case 2:
            std::cout << "Run\n";
            break;
        default:
            std::cout << "Invalid Input, Try Again\n";
            break;
        }
    }
    if (p.getHealth() <= 0)
    {
        std::cout << "YOU DIED\n";
    }
    if (e.getHealth() <= 0) 
    {
        std::cout << "The " << e.getName() << " Is Dead, Hooray!\n\n";
        e.setHealth(5);
        p.addMoney();

        std::cout << "You have " << p.getMoney() << " monies\n\n";
    }
}
int main() 
{

    srand(std::chrono::system_clock::now().time_since_epoch().count());

    auto player1 = Player{};
    player1.setHealth(10);
    player1.setName(player1.getName());
    player1.setMinDamage(4);
    player1.setMaxDamage(6);

    auto goblin = Enemy{};
    goblin.setHealth(5);
    goblin.setName("Goblin");
    goblin.setMinDamage(3);
    goblin.setMaxDamage(5);


    auto troll = Enemy{};
    troll.setHealth(8);
    troll.setName("Troll");
    troll.setMinDamage(7);
    troll.setMaxDamage(10);


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
        } 
        else
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
    thunderdome.function = [&goblin, &player1, &troll]()
    {   
        int decision = RNG(0,1);
        if (decision == 0) {
            FightScene(player1, goblin);
        } 
        else
        {
            FightScene(player1, troll);    
        }
        player1.setHealth(10);
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
