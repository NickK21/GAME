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

private:
    std::string name_;
    int health_;
};