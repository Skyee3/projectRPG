#pragma once
#include <string>
#include "Miscellaneous.hpp"

struct Player{
    std::string name;
    std::string Class;
    int Class_ID;
    int HP, Max_HP;
    int Mana, Max_Mana;
    int mana_cost[4] = {0};
    int Gold;
    int Level, XP;
    int Damage;
    int Dodge;
    int Gamba_counter = 0;
    int damage_multiplayer = 1;
    int damage_multiplier_duration = 0;
};

void Class_choose(Player &player);
bool Confirm_class_choice(Player &player);
void Class_warrior(Player &player);
void Class_ranger(Player &player);
void Class_mage(Player &player);
void Show_playerstats(Player &player);
void Class_preview(Player &player);
void set_mana_cost(Player &player, int C1, int C2, int C3, int C4);