#include <iostream>
#include "Player.hpp"
#include "Enemy.hpp"

void Class_choose(Player &player){
    std::cout << "\n /===================\\\n";
    std::cout << " |  VYBER SI CLASSU  |\n";
    std::cout << " |===================|\n";
    std::cout << " |  [1] Warrior      |\n";
    std::cout << " |  [2] Ranger       |\n";
    std::cout << " |  [3] Gandalf      |\n";
    std::cout << " \\===================/\n";
    
    do{
        int choice;
        Input_checker("Vaše volba: ", choice, 1, 3);
        switch(choice){
            case 1:
                player.set_class_stats("Warrior", 1, 130, 40, 15, 0, 10);
                player.set_mana_cost(0, 20, 35);
                break;
            case 2:
                player.set_class_stats("Ranger", 2, 80, 40, 30, 1, 5);
                player.set_mana_cost(0, 20, 30);
                break;
            case 3:
                player.set_class_stats("Gandalf", 3, 50, 60, 10, 1, 15);
                player.set_mana_cost(10, 20, 40);
                break;
            default:
                break;
        }
        Class_preview(player);
        if(Confirm_class_choice(player)){
            break;
        }
    }while(true);
    std::cout << "Zvolili jste classu: " << player.Class << "\n";
}

bool Confirm_class_choice(Player &player){
    int confirm_choice;
    Input_checker("Potvrďte výběr classy (1 - Ano, 0 - Ne): ", confirm_choice, 0, 1);
    if(confirm_choice == 1){
        return true;
    }
    else{
        std::cout << "Znovu zvolte classu\n";
        return false;
    }
}

void Class_preview(Player &player){
    std::cout << "Class: "<< player.Class << "\n\n";
    std::cout << "STATISTIKY: \n";
    std::cout << "  HP: " << player.HP << "/" << player.Max_HP << "\n";
    std::cout << "  MANA: " << player.Mana << "/" << player.Max_Mana << "\n";
    std::cout << "  Defense: " << player.Defense << "\n";
    std::cout << "  Poškození: " << player.Damage << "\n\n";
    Show_class_abilities(player);
}

void Show_class_abilities(Player &player){
    switch(player.Class_ID){
        case 1:
            std::cout << "Prostě boring warrior ale stane se z tebe dominantní jedinec\n";
            std::cout << "SCHOPNOSTI: \n";
            std::cout << " 1. Útok mečem\n";
            std::cout << "   V základu " << player.Damage << " poškození\n";
            std::cout << " 2. Silný úder (Mana: " << player.mana_cost[1] << ")\n";
            std::cout << "   V základu " << player.Damage - 2 << " poškození\n";
            std::cout << "   Omráčí nepřítele na 1 kolo\n\n";
            std::cout << " 3. Dominantní jedinec (Mana: " << player.mana_cost[2] << ")\n";
            std::cout << "   V základu " << player.Damage - 1 << " poškození\n";
            std::cout << "   Snižuje poškození nepřítele o 50% na 2 kola\n";
            std::cout << "   Zvýší poškození o 20% na 3 kola\n\n";
            break;
        case 2:
            std::cout << "Vysoký dodge a nízké HP\n";
            std::cout << "SCHOPNOSTI: \n";
            std::cout << " 1. Útok lukem\n";
            std::cout << "s   V základu " << player.Damage << " poškození\n";
            std::cout << "   Při útoku vás nepřítel nemůže zasáhnout\n\n";
            std::cout << " 2. Jedovatý šíp (Mana: " << player.mana_cost[1] << ")\n";
            std::cout << "   V základu " << player.Damage << " poškození\n";
            std::cout << "   Nepřitel dostane jed, který způsobí 3 poškození za kolo, po dobu 3 kol\n\n";
            std::cout << " 3. Šípová sprcha (Mana: " << player.mana_cost[2] << ")\n";
            std::cout << "   Vystřelíš salvu šípů na všechny nepřítele\n";
            std::cout << "   Zasáhne více nepřátel najednou\n";
            std::cout << "   Každý zásah dává 75% poškození\n\n";
            break;
        case 3:
            std::cout << "Absolutní Gambler (nízké HP ale gamba)\n";
            std::cout << "SCHOPNOSTI: \n";
            std::cout << " 1. Flákanec (Mana: " << player.mana_cost[0] << ")\n";
            std::cout << "   Objeví se magicka pazoura pana Lubomíra Volného, a ten dá nepříteli flákanec, který způsobí " << player.Damage << " poškození\n\n";
            std::cout << " 2. Gamba (Mana: " << player.mana_cost[1] << ")\n";
            std::cout << "  Je to gamba, buď dáš vysoké nebo malé poškození (prostě gamba lol)\n\n";
            std::cout << " 3. Karma (Mana: " << player.mana_cost[2] << ")\n";
            std::cout << "   V příštím kole nepřítel zautočí sám na sebe\n\n";
            break;
        default:
            break;
    }
}
void Player_turn(Player &player, Enemy &enemy){
    int choice_ability;
    User_choice_ability(player, choice_ability);
    switch(player.Class_ID){
       case 1:
            Warrior_atack(player, enemy, choice_ability);
            break;
        case 2:
            Ranger_atack(player, enemy, choice_ability);
            break;
        case 3:
            Gandalf_atack(player, enemy, choice_ability);
            break;
        default:
            break;
    }
}

void User_choice_ability(Player &player, int &choice_ability){
    std::cout << "\n========================================\n";
    std::cout << "             TVŮJ TAH              \n";
    std::cout << "========================================\n";
    switch(player.Class_ID){
        case 1:
            std::cout << "1. Útok mečem\n";
            std::cout << "2. Silný úder (Mana: " << player.mana_cost[1] << ")\n";
            std::cout << "3. Dominantní jedinec (Mana: " << player.mana_cost[2] << ")\n";
            break;
        case 2:
            std::cout << "1. Útok lukem\n";
            std::cout << "2. Jedovatý šíp (Mana: " << player.mana_cost[1] << ")\n";
            std::cout << "3. Šípová sprcha (Mana: " << player.mana_cost[2] << ")\n";
            break;
        case 3:
            std::cout << "1. Flákanec (Mana: " << player.mana_cost[0] << ")\n";
            std::cout << "2. Gamba (Mana: " << player.mana_cost[1] << ")\n";
            std::cout << "3. Karma (Mana: " << player.mana_cost[2] << ")\n";
            break;
        default:
            break;
    }
    check_mana_cost(player, choice_ability);
    player.Mana -= player.mana_cost[choice_ability - 1];
}

void Warrior_atack(Player &player, Enemy &enemy, int choice_ability){
    int final_damage = 0;
    switch(choice_ability){
        case 1:
            final_damage = player.Damage - enemy.Defense;
            std::cout << "Zvolili jste útok mečem\n";
            std::cout << "Zasáhli jste nepřítele a způsobili mu " << final_damage << " poškození\n";
            enemy.HP -= final_damage;
            break;
        case 2:
            final_damage = player.Damage + 5 - enemy.Defense;
            std::cout << "Zvolili jste silný úder\n";
            std::cout << "Zasáhli jste nepřítele a způsobili mu " << final_damage << " poškození\n";
            std::cout << "Nepřítel je omráčen a nemůže útočit v příštím kole\n";
            enemy.HP -= final_damage;
            enemy.stun_duration = 1;
            break;
        case 3:
            final_damage = player.Damage + 10 - enemy.Defense;
            std::cout << "Zvolili jste dominantní jedinec\n";
            std::cout << "Zasáhli jste nepřítele a způsobili mu " << final_damage << " poškození\n";
            std::cout << "Snižujete poškození nepřítele o 50% na 2 kola\n";
            std::cout << "Zvýšíte poškození o 20% na 3 kola\n";
            enemy.HP -= final_damage;
            enemy.damage_reduction_duration = 2;
            enemy.damage_reduction_percentage = 50;
            player.Damage += player.Damage * 0.2;
            player.damage_multiplier_duration = 3;
            break;
        default:
            break;
    }
    final_damage = 0;

}

void Ranger_atack(Player &player, Enemy &enemy, int choice_ability){
    int final_damage = 0;
    switch(choice_ability){
        case 1:
            final_damage = player.Damage - enemy.Defense;
            std::cout << "Zvolili jste útok lukem\n";
            std::cout << "Zasáhli jste nepřítele a způsobili mu " << final_damage << " poškození\n";
            enemy.HP -= final_damage ;
            break;
        case 2:
            final_damage = player.Damage - enemy.Defense;
            std::cout << "Zvolili jste jedovatý šíp\n";
            std::cout << "Zasáhli jste nepřítele a způsobili mu " << final_damage << " poškození\n";
            std::cout << "Nepřitel dostal jed, který způsobí 3 poškození za kolo, po dobu 3 kol\n";
            enemy.HP -= final_damage;
            break;
        case 3:{
            int random = rand() % 4 + 3; 
            final_damage = (player.Damage * 0.75 - enemy.Defense) * random;
            std::cout << "Zvolili jste šípovou sprchu\n";
            std::cout << "Vystřelili jste salvu šípů na všechny nepřítele\n";
            std::cout << "Každý zásah dává 75% poškození\n";
            enemy.HP -= final_damage;
            break;
        }
        default:
            break;
    }
    final_damage = 0;
}

void Gandalf_atack(Player &player, Enemy &enemy, int choice_ability){
    int final_damage = 0;
    switch(choice_ability){
        case 1:
            final_damage = player.Damage - enemy.Defense;
            std::cout << "Zvolili jste flákanec\n";
            std::cout << "Objevil se pan Lubimírek a plesknul mu za " << player.Damage << " poškození\n";
            enemy.HP -= player.Damage;
            break;
        case 2:
            final_damage = gamba_Gandalf(player, enemy, final_damage);
            std::cout << "GAMBAAAAAAAAAAAAA (absolutní gigachad si po dnešku za zvolení tohoto útoku :D)\n";
            enemy.HP -= final_damage;
            break;
        case 3:
            std::cout << "Karma\n";
            std::cout << "V příštím kole se nepřítel zautočí sám na sebe\n";
            break;
        default:
            break;
    }
    player.Mana += 15;
    if(player.Mana > player.Max_Mana){
        player.Mana = player.Max_Mana;
    }
    final_damage = 0;
}

void check_mana_cost(Player &player, int &choice_ability){
    do{
        Input_checker("Zadejte číslo schopnosti, kterou chcete použít: ", choice_ability, 1, 3);
        if(player.Mana < player.mana_cost[choice_ability - 1]){
            std::cout << "Nemáte dostatek many pro tuto schopnost. Zvolte jinou schopnost.\n";
            continue;
        }
        break;
    }while(true);
}
int gamba_Gandalf(Player &player, Enemy &enemy, int final_damage){
    int random = rand() % 2;
    int random2;
    switch(random){
        case 0:
            random2 = rand() % 3 + 1;
            final_damage = random2 - enemy.Defense;
            std::cout << "No níc gamba nevyšla a dal si mu jenom " << final_damage << " poškození (tomu říkam skill issue ale určitě to zkus zas :D)\n";
            player.Gamba_counter--;
            if(player.Gamba_counter < -3){
                std::cout << "Teď si říkáš, že to je riggnutý. Je to možný, ale určitě nepřestávej gamblit\n";
            }
            break;
        case 1:
            random2 = rand() % 3 + 5;
            final_damage = random2 - enemy.Defense;
            std::cout << "Ty si rozený gambler normálně. Vyhrál si gambu a dal si mu za " << final_damage << " poškození\n";
            player.Gamba_counter++;
            if(player.Gamba_counter > 4){
                std::cout << "vypni ty cheaty bro je to jenom hra (anyway dneska si docela lucky a dostaneš buff na jedno kolo)\n";
            }
            std::cout << "Tvoje gamba skóre je: " << player.Gamba_counter << "\n";
            break;
        default:
            break;
    }
    return final_damage;
}
