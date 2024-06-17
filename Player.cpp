#include "Player.hpp"

Player::Player()
    : 
    Stats()
{
    logs_ = 0;
    money_ = 0;
}
void Player::setMoney(int money)
{
    money_ = money;
}
int Player::getMoney() const
{
    return money_;
}
void Player::setLogs(int logs)
{
    logs_ = logs;
}
int Player::getLogs() const 
{
    return logs_;
}
void Player::addLogs()
{
    logs_++;
}
void Player::addMoney()
{
    money_++;
}
void Player::print() const
{
    std::cout << "*************************\n";
    std::cout << "You have " 
    << money_ << " monies and " << logs_ << " logs\n";
    std::cout << "*************************\n";
}