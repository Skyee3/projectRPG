#include <iostream>
#include "Enemy.hpp"

Enemy Freddy_fazbear(){
    Enemy freddy; // Zhasne světla a bude težší ho trefit
    freddy.Type = 1;
    freddy.Max_HP = 80;
    freddy.HP = freddy.Max_HP;
    freddy.Damage = 10;
    return freddy;
}

Enemy Zdenek_Pohlreich(){
    Enemy zdenek; 
    zdenek.Type = 2;
    zdenek.Max_HP = 20;
    zdenek.HP = 20;
    zdenek.Damage = 5;
    return zdenek;
}

Enemy Gnome(){
    Enemy gnome;
    gnome.Type = 3;
    gnome.Max_HP = 28;
    gnome.HP = 28;
    gnome.Damage = 7;
    return gnome;
}

Enemy Ricardo(){
    Enemy ricardo;
    ricardo.Type = 4;
    ricardo.Max_HP = 50;
    ricardo.HP = 50;
    ricardo.Damage = 10;
    return ricardo;
}

Enemy Discord_mod(){
    Enemy discord;
    discord.Type = 5;
    discord.Max_HP = 100;
    discord.HP = 100;
    discord.Damage = 15;
    return discord;
}

Enemy Walter_White(){
    Enemy walter;
    walter.Type = 6;
    walter.Max_HP = 120;
    walter.HP = 120;
    walter.Damage = 20;
    return walter;
}

Enemy Frodo_pytlik(){
    Enemy frodo;
    frodo.Type = 7;
    frodo.Max_HP = 80;
    frodo.HP = 80;
    frodo.Damage = 12;
    return frodo;
}

Enemy Gandalf(){
    Enemy gandalf;
    gandalf.Type = 8;
    gandalf.Max_HP = 150;
    gandalf.HP = 150;
    gandalf.Damage = 25;
    return gandalf;
}

Enemy Alzak(){
    Enemy alzak;
    alzak.Type = 9;
    alzak.Max_HP = 200;
    alzak.HP = 200;
    alzak.Damage = 30;
    return alzak;
}

void Choose_enemy(Enemy &enemy){
    int random = rand() % 9;
    switch(random){
        case 0:
            enemy = Freddy_fazbear();
            break;
        case 1:
            enemy = Zdenek_Pohlreich();
            break;
        case 2:
            enemy = Gnome();
            break;
        case 3:
            enemy = Ricardo();
            break;
        case 4:
            enemy = Discord_mod();
            break;
        case 5:
            enemy = Walter_White();
            break;
        case 6:
            enemy = Frodo_pytlik();
            break;
        case 7:
            enemy = Gandalf();
            break;
        case 8:
            enemy = Alzak();
            break;
    }
}