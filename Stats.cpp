#include "Stats.hpp"
#include "Util.hpp"

Stats::Stats()
{
    name_ = "";
    health_ = 0;
    minDamage_ = 0;
    maxDamage_ = 0;
}
void Stats::setName(const std::string& name) 
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
const std::string& Stats::getName() const
{
    return name_;
}
int Stats::getHealth() const
{
    return health_;
}
int Stats::getMaxDamage() const
{
    return maxDamage_;
}
int Stats::getMinDamage() const
{
    return minDamage_;
}