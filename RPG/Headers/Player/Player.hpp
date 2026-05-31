#pragma once
#include <string>
#include "Miscellaneous.hpp"
#include "Enemy.hpp"

struct Enemy;

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
    int Defense;
    int Gamba_counter = 0;
    int damage_multiplier_duration = 0;
    int jedinec_buff_duration = 0;
    int jedinec_cooldown = 0;
    int buldozer_debuff_duration = 0;
    float damage_multiplier = 1;
    bool skip_turn = false;

    void set_class_stats(std::string Class_c, int ID_c, int Max_HP_c, int Max_Mana_c, int Damage_c, int Dodge_c, int Defense_c){
        Class = Class_c;
        Class_ID = ID_c;
        Max_HP = Max_HP_c; 
        HP = Max_HP_c;
        Max_Mana = Max_Mana_c;
        Mana = Max_Mana;
        Damage = Damage_c;
        Dodge = Dodge_c;
        Defense = Defense_c;
    }

    void set_mana_cost(int C1, int C2, int C3){
        mana_cost[0] = C1;
        mana_cost[1] = C2;
        mana_cost[2] = C3;
    }

    void Show_playerstats(){
        std::cout << "\n========================================\n";
        std::cout << "             STATUS POSTAVY             \n";
        std::cout << "========================================\n";
        
        std::cout << "  Jméno:      " << name << "\n";
        std::cout << "  Class:      " << Class << "\n";
        std::cout << "\n";
        std::cout << "  Level:     " << Level << "\n";
        std::cout << "  XP:        " << XP << "\n";
        std::cout << "\n";
        std::cout << "  HP:         " << HP << " / " << Max_HP << "\n";
        std::cout << "  MANA:       " << Mana << " / " << Max_Mana << "\n";
        std::cout << "  Poškození:  " << Damage << "\n";
        std::cout << "  ZLATO:      " << Gold << " ks\n";
        
        std::cout << "========================================\n";
    }

    void Show_Playerstats_short(){
        std::cout << "========================================\n";
        std::cout << "             STATUS POSTAVY             \n";
        std::cout << "========================================\n";

        std::cout << "  HP:         " << HP << " / " << Max_HP << "\n";
        std::cout << "  MANA:       " << Mana << " / " << Max_Mana << "\n";

        
        std::cout << "========================================\n";
    }

};

void Class_choose(Player &player);
bool Confirm_class_choice(Player &player);
void Class_preview(Player &player);
void Show_class_abilities(Player &player);
void Player_turn(Player &player, Enemy &enemy);
void User_choice_ability(Player &player, int &choice_ability);
void Warrior_atack(Player &player, Enemy &enemy, int choice_ability);
void Ranger_atack(Player &player, Enemy &enemy, int choice_ability);
void Gandalf_atack(Player &player, Enemy &enemy, int choice_ability);
void Input_ability(Player &player, int &choice_ability);
int gamba_Gandalf(Player &player, Enemy &enemy, int final_damage);
bool check_dodge_player(Player &player);