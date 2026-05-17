#include "Enemy.hpp"
#include "Player.hpp"


void Choose_enemy(Enemy &enemy){
    int random = rand() % 4;
    switch(random){
        case 0:
            enemy.set_enemy("Buldozer", 1, 50, 10, 5);
            break;
        case 1:
            enemy.set_enemy("Kostík", 2, 80, 15, 8);
            break;
        case 2:
            enemy.set_enemy("e3", 3, 120, 20, 10);
            break;
        case 3:
            enemy.set_enemy("e4", 4, 200, 30, 15);
            break;
        default:
            break;
    }
}

void Enemy_turn(Player &player, Enemy &enemy){
    std::cout << "\n========================================\n";
    std::cout << "             TAH" << enemy.name << "a\n";
    std::cout << "========================================\n";
    switch(enemy.Type){
        case 1:
            Buldozer_turn(player, enemy);
            break;
        case 2:
            kostik_turn(player, enemy);
        default:
            break;
    }
}

void Buldozer_turn(Player &player, Enemy &enemy){ //debuffer
    int ability = rand() % 4;
    switch(ability){
        case 0:
            std::cout << "Buldozer tě shodil a dal ti " << enemy.Damage - 2 << " poškození a oslabil tě na další kolo o 15%\n";
            player.HP -= enemy.Damage - 2;
            break;
        case 1:
            std::cout << "Buldozer zvolil útok ohňem a dal ti " << enemy.Damage + 5 << " poškození.\n";
            std::cout << "Po dobu 2 kol budeš hořet a dostavat 5 poškození navíc.\n";
            player.HP -= enemy.Damage + 5;
            break;
        default:
            std::cout << "Buldozer zvolil basic útok a kopl tě za" << enemy.Damage << " poškození.\n";
            player.HP -= enemy.Damage;
            break;
    }
}

void kostik_turn(Player &player, Enemy &enemy){
    int ability = rand() % 10;
    if(ability >= 8){
        int arrow_count = check_dodge_kostik(player);
        std::cout << "Kostík do svého luku dal 10 šípů a vystřelil do vzduchu, každopádně každý dává jen 50% poškození\n";
        int final_damage = (enemy.Damage * 0.50) * arrow_count;
        std::cout << "Celkem si dostal " << final_damage << " poškození\n";
        player.HP -= final_damage;
    }
    else if(ability == 7 && !enemy.is_kostik_upgraded){
        std::cout << "Kostík vylepšil svůj luk a jeho útoky teď dávají o 5 poškození navíc.\n";
        std::cout << "Toto kolo si nedostal žádné poškození.\n";
        enemy.Damage += 5;
        enemy.is_kostik_upgraded = true;
    }
    else{
        std::cout << "Kostík vytasil svůj luk a trefil ti za " << enemy.Damage << " poškození.\n";
        player.HP -= enemy.Damage;
    }
}

int check_dodge_kostik(Player &player){
    int Arrow_hitted = 0;
    switch(player.Dodge){
        case 0:
            Arrow_hitted = rand() % 2 + 7;
            std::cout << "Jelikož ještě nemáš vylepšený dodge tak tě trefil " << Arrow_hitted << " šípama\n";
            break;
        case 1:
            Arrow_hitted = rand() % 2 + 6;
            std::cout << "Vzhledem k tomu že máš alespoň trošičku vylepšnený dodge tak tě trefil " << Arrow_hitted << " šípama\n";
            break;
        case 2:
            Arrow_hitted = rand() % 2 + 4;
            std::cout << "Vzhledem k tomu že máš vylepšený dodge tak tě trefil  " << Arrow_hitted << " šípama\n";
            break;
        case 3:
            Arrow_hitted = rand() % 2 + 3;
            std::cout << "Vzhledem k tomu že máš velmi dobře vylepšený dodge tak tě trefil jenom " << Arrow_hitted << " šíppama\n";
            break;
    }
    return Arrow_hitted;
}
