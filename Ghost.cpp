//
//  Ghost.cpp
//  Project 2
//
//  Created by Alex Mayer on 11/7/24.
//

#include "Player.hpp"
#include "Ghost.hpp"

Ghost::Ghost() {
    name = "Ghost";
    weakness = "Magic";
    resistance = "Physical";
    damage = 10;
    health = 40;
    treasureDropped = 50;
    xp = 50;
    manaDropped = 10;
}

void Ghost::attack(Player& target) {
    this->draw();
    cout << "A chill goes down " << target.getName() << "'s spine as the Ghost sucks away their life force" << endl;
    target.takeDamage(damage);
}

void Ghost::draw() {
    cout << R"(  
             .-.
            (o o)    *Whhooooomph*
           (  O  )
          .-'   '-.
         /         \
         |         |
        /           \
       (_.-' `-._)
    )" << endl;
}

void Ghost::printInfo() {
    cout << "Name: " << name << endl;
    cout << name << " is weak to " << weakness << " type attacks and strong against " << resistance << " attacks" << endl << endl;
    cout << "Health: " << health << endl;
    cout << "Damage: " << damage << endl;
}
