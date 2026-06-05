#pragma once
#include "Player.hpp"
#include <vector>

struct Player;

struct Enemy{
    std::string name;
    int Type;
    int HP, Max_HP;
    int Damage;
    int Defense;
    int stun_duration = 0;
    float Damage_multiplier = 1;
    int Damage_multiplier_duration = 0;
    int counter = 0;
    int poison_duration = 0;
    int player_debuff_by_buldozer = 0;
    bool was_quizler = false;
    bool is_upgraded = false;
    bool is_miniboss = false;
    bool karma_active = false;

    void set_enemy(std::string name_c, int Type_c, int Max_HP_c, int Damage_c, int Defense_c, bool miniboss_c){
        name = name_c;
        Type = Type_c;
        HP = Max_HP_c;
        Max_HP = Max_HP_c;
        Damage = Damage_c;
        Defense = Defense_c;
        is_upgraded = false;
        is_miniboss = miniboss_c;
    }
    bool is_alive(){
        if(HP <= 0) return false;
        return true;
    }

    void reset_stats(){
        HP = Max_HP;
        stun_duration = 0;
        Damage_multiplier = 1;
        Damage_multiplier_duration = 0;
        poison_duration = 0;
        player_debuff_by_buldozer = 0;
        karma_active = false;
        is_miniboss = false;
        is_upgraded = false;
    }


    void show_all_enemy_stats_testing(){
        std::cout << "========================================\n";
        std::cout << "             STATUS " << name << "a\n";
        std::cout << "========================================\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Type: " << Type << "\n";
        std::cout << "HP: " << HP << "\n";
        std::cout << "Max_HP: " << Max_HP << "\n";
        std::cout << "Damage: " << Damage << "\n";
        std::cout << "Defense: " << Defense << "\n";
        std::cout << "Is Miniboss: " << is_miniboss << "\n";
    }
};
struct question{
    std::string question_text;
    int correct_option;
};

std::vector<question> initialize_questions();


void Choose_enemy(Enemy &enemy);
void Enemy_turn(Player &player, Enemy &enemy, std::vector<question> &questions);
void Buldozer_turn(Player &player, Enemy &enemy);
void kostik_turn(Player &player, Enemy &enemy);
int check_dodge_kostik(Player &player);
void bohnican_turn(Player &player, Enemy &enemy);
void quizler_turn(Player &player, Enemy &enemy, std::vector<question> &questions);
void BOB_turn(Player &player, Enemy &enemy);
void Chief_turn(Player &player, Enemy &enemy);
void Boss_turn(Player &player, Enemy &boss, int &critical_chance, int &heal_chance);
void check_gold_reward(Player &player, Enemy &enemy, int min, int max);