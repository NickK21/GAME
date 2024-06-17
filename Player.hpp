#pragma once
#include "std::lib.hpp"
#include "Stats.hpp"

class Player : public Stats
{

public:
    
    Player();
    void setMoney(int money);
    int getMoney() const;
    void setLogs(int logs);
    int getLogs() const;
    void addLogs();
    void addMoney();
    void print() const;

private:
    int logs_;
    int money_;
};
