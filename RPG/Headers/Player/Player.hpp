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
    int Burn_duration = 0;
    float damage_multiplier = 1;
    int stun_duration = 0;
    bool skip_turn = false;
    bool is_upgraded = false;
    bool is_sprcha_active = false;

    int cvv = 0;
    std::string number_of_cart = "";
    std::string expiration_date = "";

    int upgrade_hp_counter = 0;
    int upgrade_mana_counter = 0;
    int upgrade_dmg_counter = 0;
    int upgrade_dfns_counter = 0;



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
    bool is_stunned(){
        if(stun_duration > 0){
            std::cout << "======================STUN=======================\n\n";
            std::cout << "[STAV]  Jste omráčen a nemůžete útočit\n";
            std::cout << "\n==================================================\n\n";
            stun_duration--;
            return true;
        }
        return false;
    }
    void set_mana_cost(int C1, int C2, int C3){
        mana_cost[0] = C1;
        mana_cost[1] = C2;
        mana_cost[2] = C3;
    }
    bool is_alive(){
        if(HP <= 0) return false;
        return true;
    }
    void reset_stats(){
        HP = Max_HP;
        Mana = Max_Mana;
        damage_multiplier = 1;
        damage_multiplier_duration = 0;
        jedinec_buff_duration = 0;
        jedinec_cooldown = 0;
        Burn_duration = 0;
        buldozer_debuff_duration = 0;
        stun_duration = 0;
        skip_turn = false;
        is_upgraded = false;
        is_sprcha_active = false;
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
        std::cout << "============ STATUS POSTAVY ============\n\n";

        std::cout << "  HP:         " << HP << " / " << Max_HP << "\n";
        std::cout << "  MANA:       " << Mana << " / " << Max_Mana << "\n";

        
        std::cout << "\n========================================\n\n";
    }
    void name_choice(){
        std::cout << "Vítej bro... zvol si své jméno, které tě bude doprovázet do konce života (už ho v životě neuslišíš)\n";
        std::cout << "Jméno: ";
        if(std::cin.peek() == '\n'){
            std::cin.ignore(); 
        }
        std::getline(std::cin, name);
        std::cout << "Budiš. Od teď se jmenuješ: " << name << '\n';
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
void count_level(Player &player, int min, int max);
void Choose_stat_upgrade(Player &player);
void calculate_mana(Player &player, int m);
void win();