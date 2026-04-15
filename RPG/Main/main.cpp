#include <iostream>
#include <windows.h>
#include "Player.hpp"
#include "Village.hpp"

int main(){
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));
    Player player;
    Village_choice(player); //testovací
    return 0;
}