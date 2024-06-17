#include "Stats.hpp"
    
    Stats::Stats()
    {
        name_ = "";
        health_ = 0;
    }
    
    void Stats::setName(std::string name) 
    {
        name_ = name;
    }
    std::string Stats::getName() 
    {
        return name_;
    }
    void Stats::setHealth(int health) 
    {
        health_ = health;
    }
    int Stats::getHealth() 
    {
        return health_;
    }