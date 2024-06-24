#pragma once
#include "std::lib.hpp"

class Stats
{
public:
    Stats();

    void setName(std::string name);
    std::string getName();
    void setHealth(int health);
    int getHealth();
    void setMinDamage(int minDamage);
    int getMinDamage();
    void setMaxDamage(int maxDamage);
    int getMaxDamage();

private:
    std::string name_;
    int health_;
    int minDamage_;
    int maxDamage_;
};