#pragma once
#include <string>

struct Player{
    std::string name;
    int HP, Max_HP;
    int Mana, Max_Mana;
    int Gold = 20;
    int Level, XP;
    // dodělat attack a schopnosti!!!!!
};