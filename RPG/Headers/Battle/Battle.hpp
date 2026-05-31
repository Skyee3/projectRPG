#pragma once
#include "Miscellaneous.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

void Battle(Player &player, Enemy &enemy, std::vector<question> &questions);
void check_after_player_turn(Player &player, Enemy &enemy);