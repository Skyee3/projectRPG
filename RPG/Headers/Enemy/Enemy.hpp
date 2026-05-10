#pragma once
#include "player.hpp"

struct Enemy{
    std::string name;
    int Type;
    int HP, Max_HP;
    int Damage;
    int Defense;
    int stun_duration = 0;
    int damage_reduction_duration = 0;
    int damage_reduction_percentage = 0;

    void set_enemy(std::string name_c, int Type_c, int Max_HP_c, int Damage_c, int Defense_c){
        name = name_c;
        Type = Type_c;
        HP = Max_HP_c;
        Max_HP = Max_HP_c;
        Damage = Damage_c;
        Defense = Defense_c;
    }
    
};



void Choose_enemy(Enemy &enemy);