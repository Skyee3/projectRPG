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
    player.name_choice();
    Class_choose(player);
    player.Show_playerstats();
    Enemy enemy;
    while(true){
        if(enemy.counter % 7 == 0 && enemy.counter != 0){
            Enemy enemy1;
            Enemy enemy2;
            do{
                Choose_enemy(enemy1);
                Choose_enemy(enemy2);
            }while(enemy1.name == enemy2.name || enemy2.Type == 4 || enemy1.Type == 4); //snad to funguje tak jak má :D
            std::cout << "Tohle nebude normální fight teď budeš bojovat proti " << enemy1.name << " a " << enemy2.name << " najednou\n";
            Battle_two_enemies(player, enemy1, enemy2, questions);
            if(!player.is_alive()){
                Dead_screen(player);
            }
            check_gold_reward(player, enemy1, 25, 25);
            check_gold_reward(player, enemy2, 25, 25);
            count_level(player, 13, 17);
            enemy1.reset_stats();
            enemy2.reset_stats();
            player.reset_stats();
        }
        else if(enemy.counter % 12 == 0 && enemy.counter != 0){
            Enemy enemy1;
            Enemy enemy2;
            Enemy enemy3;
            do{
                Choose_enemy(enemy1);
                Choose_enemy(enemy2);
                Choose_enemy(enemy3);
            }while(enemy1.Type == 4 || enemy2.Type == 4 || enemy3.Type == 4); // toto je featurka, ne bug (určitě není)
            std::cout << "Tohle bude zábavička :D jdeš proti třem enemákům na jednou\n";
            std::cout << "Bojuješ proti následujícím enemákům: " << enemy1.name << ", " << enemy2.name << ", " << enemy3.name << "\n";
            Battle_three_enemies(player, enemy1, enemy2, enemy3, questions);
            if(!player.is_alive()){
                Dead_screen(player);
            }
            win();
            check_gold_reward(player, enemy1, 25, 25);
            check_gold_reward(player, enemy2, 25, 25);
            check_gold_reward(player, enemy3, 25, 25);
            count_level(player, 16, 20);
            enemy1.reset_stats();
            enemy2.reset_stats();
            enemy3.reset_stats();
            player.reset_stats();
        }
        else if(enemy.counter == 15){
            Enemy boss;
            boss.set_enemy("Shuffler", 7, 350, 30, 10, 0);
            std::cout << "No jo čeká tě finální boss jménem: Shuffler (absolutní gamber :D)\n";
            std::cout << "takže se dobře připrav a užívej\n";
            Final_battle(player, boss);
            if(player.HP <= 0){
                Dead_screen(player);
                break;
            }
            win();
            count_level(player, 15, 20);
            std::cout << "Získáváš 100 goldů za final bosse\n";
            player.Gold += 100;
            int choice;
            std::cout << "Gratuluji, porazil si finálního bosse. Chceš zapnout endless mód ? (1 - ano, 0 - ne)\n";
            Input_checker("Výběr: ", choice, 0, 1);
            if(choice == 0){
                std::cout << "Tak zas příště\n";
                return 0;
            }
            std::cout << "Užívej endless mód\n";
        }
        else{
            Choose_enemy(enemy);
            Battle(player, enemy, questions);
            if(player.HP <= 0){
                Dead_screen(player);
                break;
            }
            win();
            check_gold_reward(player, enemy, 8, 14);
            count_level(player, 5, 10);
            player.reset_stats();
            enemy.reset_stats();
            
        }
        enemy.counter++;
        if(enemy.counter % 2 == 0){
            Village_choice(player);
        }
    }
    return 0;
}