#include "Stats.hpp"
#include "Util.hpp"

    Stats::Stats()
    {
        name_ = "";
        health_ = 0;
        minDamage_ = 0;
        maxDamage_ = 0;
    }
    
    void Stats::setName(std::string name) 
    {
        name_ = name;
    }
    void Stats::setHealth(int health) 
    {
        health_ = health;
    }
    void Stats::setMaxDamage(int maxDamage)
    {
        maxDamage_ = maxDamage;
    }
    void Stats::setMinDamage(int minDamage)
    {
        minDamage_ = minDamage;
    }
    std::string Stats::getName() 
    {
        return name_;
    }
    int Stats::getHealth() 
    {
        return health_;
    }
    int Stats::getMinDamage()
    {
        return minDamage_;
    }
    int Stats::getMaxDamage()
    {
        return maxDamage_;
    }