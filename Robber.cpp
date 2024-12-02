//
//  Robber.cpp
//  Project 2
//
//  Created by Alex Mayer on 11/7/24.
//

#include "Robber.hpp"
#include "Player.hpp"

Robber::Robber() {
    name = "Robber";
    weakness = "Physical";
    resistance = "fire";
    damage = 12;
    health = 80;
    treasureDropped = 150;
    xp = 100;
    manaDropped = 15;
}

void Robber::attack(Player &target) {
    this->draw();
    // 20% chance of getting robbed
    int random = (rand() % 100) + 1;
    if (random <= 20) {
        this->steal(target);
    }
    else {
        //attacking player
        cout << "The Robber slashes at " << target.getName() << "'s weak point causing damage" << endl;
        target.takeDamage(damage);
    }
}

void Robber::draw() {
    cout << R"( 
        ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣿⣿⣦⡀⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀⠀⠀⠉⠛⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⣷⡄⠀⣀⣀⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⣠⣶⣦⣈⠻⣦⠈⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀**** Whhoooosh ****
        ⠀⠀⢻⣿⣿⣿⣿⣿⣿⡿⠁⣼⡿⠻⣿⣿⣷⣄⣠⣴⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⠻⣿⣿⣿⣿⡟⠀⢸⣿⣿⣦⣄⡉⠛⠛⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⠀⠈⠛⠿⠋⠀⠀⢻⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⣀⣀⣤⣶⣄⠀⠀⠈⠿⢿⣿⣿⣿⣿⣿⣶⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠸⠟⠛⠉⠻⣿⣧⡀⣼⣶⣤⣄⠉⠉⠛⠛⠻⢿⣿⣦⡀⠀⠀⠀⣠⡀⠀⠀
        ⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⡿⠋⠁⠀⠀⠀⠀⠀⠀⠙⢿⣿⣆⣠⣾⠟⠁⠀⠀
        ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⡿⠁⠀⠀⠀⠀
        ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    )" << endl;
}

//takes player treasure
void Robber::steal(Player &target) {
    int randomAmount = (rand() % 50) + 150;
    cout << "Your pockets suddenly feel lighter" << endl;
    if (target.getTreasure() < randomAmount) {
        cout << "**The Robber has taken " << target.getTreasure() << " from you**" << endl;
    }
    else {
        cout << "**The Robber has taken " << randomAmount << " from you**" << endl;
    }
    target.loseTreasure(randomAmount);
}

void Robber::printInfo() {
    cout << "Name: " << name << endl;
    cout << name << " is weak to " << weakness << " type attacks and strong against " << resistance << " attacks" << endl << endl;
    cout << "Skill: " << name << " has a chance to steal some of your treasure" << endl;
    cout << "Health:  " << health << endl;
    cout << "Damage: " << damage << endl;
}
