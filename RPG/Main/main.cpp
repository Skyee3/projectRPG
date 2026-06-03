#include <iostream>
#include <cmath>
#include <clocale>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Village.hpp"
#include "Miscellaneous.hpp"
#include "Battle.hpp"

////////////////////////////////////////////////////////////////////////
// Přeji hodně štěstí při čtení tohoto absolutního bordel kódu (enjoy)//
/////////////////(ani já sám nevím co jsem to vytvořil)/////////////////
////////////////////////////////////////////////////////////////////////

int main(){
    std::setlocale(LC_ALL, "cs_CZ.UTF-8");
    srand(time(0));
    Player player;
    std::vector<question> questions = initialize_questions();
    
    player.Gold = 0;
    player.Level = 1;
    player.XP = 0;
    
    Show_start_menu();
    Class_choose(player);
    player.Show_playerstats();
    
    Enemy enemy;
    while(true){
        if(enemy.counter == 4){
            Enemy enemy1;
            Enemy enemy2;
            do{
                Choose_enemy(enemy1);
                Choose_enemy(enemy2);
            }while(enemy1.name == enemy2.name || enemy2.Type == 4 || enemy1.Type == 4);
            std::cout << "Tohle nebude normální fight teď budeš bojovat proti " << enemy1.name << " a " << enemy2.name << " najednou\n";
            Battle_two_enemies(player, enemy1, enemy2, questions);
            enemy.counter++;
            enemy1.reset_stats();
            enemy2.reset_stats();
            player.reset_stats();
        }
        else if(enemy.counter == 0){
            Enemy enemy1;
            Enemy enemy2;
            Enemy enemy3;
            do{
                Choose_enemy(enemy1);
                Choose_enemy(enemy2);
                Choose_enemy(enemy3);
            }while(enemy1.Type == 4 || enemy2.Type == 4 || enemy3.Type == 4);
            std::cout << "Tohle bude zábavička :D jdeš proti třem enemákům na jednou\n";
            std::cout << "Bojuješ proti následujícím enemákům: " << enemy1.name << ", " << enemy2.name << ", " << enemy3.name << "\n";
            Battle_three_enemies(player, enemy1, enemy2, enemy3, questions);
            enemy.counter++;
            enemy1.reset_stats();
            enemy2.reset_stats();
            enemy3.reset_stats();
            player.reset_stats();
        }
        else{
            Choose_enemy(enemy);
            Battle(player, enemy, questions);
            if(player.HP <= 0){
                Dead_screen(player);
                break;
            }
            player.reset_stats();
            enemy.reset_stats();
            if(enemy.counter % 2 == 0){
                Village_choice(player);
            }
        }
    }
    return 0;
}