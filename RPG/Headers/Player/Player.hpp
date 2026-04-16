#pragma once
#include <string>

struct Player{
    std::string name;
    std::string Class;
    int HP, Max_HP;
    int Mana, Max_Mana;
    int Gold;
    int Level, XP;
    int Damage;
    // dodělat attack a schopnosti!!!!!
};

void Class_choose(Player &player);
void Class_warrior(Player &player);
void Class_ranger(Player &player);
void Class_mage(Player &player);
void Show_playerstats(Player &player);