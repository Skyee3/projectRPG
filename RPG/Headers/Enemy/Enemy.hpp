#pragma once

struct Enemy{
    int Type;
    int HP, Max_HP;
    int Damage;
    int XP_reward;
    int Gold_reward;
    int Defense;
    int stun_duration = 0;
    int damage_reduction_duration = 0;
    int damage_reduction_percentage = 0;
};

Enemy Freddy_fazbear();
Enemy Zdenek_Pohlreich();
Enemy Gnome();
Enemy Ricardo();
Enemy Discord_mod();
Enemy Walter_White();
Enemy Frodo_pytlik();
Enemy Gandalf();
Enemy Alzak();

void Choose_enemy(Enemy &enemy);