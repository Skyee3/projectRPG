#pragma once
#include "Miscellaneous.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

void Battle(Player &player, Enemy &enemy, std::vector<question> &questions);
void Battle_two_enemies(Player &player, Enemy &enemy1, Enemy &enemy2, std::vector<question> &questions);
void Before_player_turn(Player &player, Enemy &enemy);
bool Before_enemy_turn(Player &player, Enemy &enemy);
void After_enemy_turn(Player &player, Enemy &enemy);
void Dead_screen(Player &player);