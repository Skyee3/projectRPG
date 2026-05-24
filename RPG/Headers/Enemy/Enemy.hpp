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
    int damage_reduction_duration = 0;
    int damage_reduction_percentage = 0;

    bool is_upgraded = false;

    void set_enemy(std::string name_c, int Type_c, int Max_HP_c, int Damage_c, int Defense_c){
        name = name_c;
        Type = Type_c;
        HP = Max_HP_c;
        Max_HP = Max_HP_c;
        Damage = Damage_c;
        Defense = Defense_c;
        is_upgraded = false;
    }

    //pak smazat
    void show_all_enemy_stats_testing(){
        std::cout << "Name: " << name << "\n";
        std::cout << "Type: " << Type << "\n";
        std::cout << "HP: " << HP << "\n";
        std::cout << "Max_HP: " << Max_HP << "\n";
        std::cout << "Damage: " << Damage << "\n";
        std::cout << "Defense: " << Defense << "\n";
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