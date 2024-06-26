#pragma once
#include "std::lib.hpp"

class Stats
{
public:
    Stats();
    void setName(const std::string& name);
    void setHealth(int health);
    void setMaxDamage(int maxDamage);
    void setMinDamage(int minDamage);
    const std::string& getName() const;
    int getHealth() const;
    int getMaxDamage() const;
    int getMinDamage() const;

private:
    std::string name_;
    int health_;
    int minDamage_;
    int maxDamage_;
};