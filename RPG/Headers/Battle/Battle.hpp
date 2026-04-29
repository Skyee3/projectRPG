#pragma once
#include "Miscellaneous.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

void Battle(Player &player, Enemy &enemy);
void Player_turn(Player &player, Enemy &enemy);
void User_choice_ability(Player &player, int &choice_ability);
void Warrior_atack(Player &player, Enemy &enemy, int choice_ability);
void Ranger_atack(Player &player, Enemy &enemy, int choice_ability);
void Mage_atack(Player &player, Enemy &enemy, int choice_ability);
void check_mana_cost(Player &player, int &choice_ability, int mana_cost[]);
int gamba_mage(Player &player);