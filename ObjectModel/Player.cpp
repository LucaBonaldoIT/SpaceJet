#include "Player.hpp"

Player* Player::_instance = nullptr;

Player* Player::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new Player();
    }
    return _instance;
}