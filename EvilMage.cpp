//
//  EvilMage.cpp
//  Project 2
//
//  Created by Alex Mayer on 11/7/24.
//

#include "EvilMage.hpp"
#include "Player.hpp"

EvilMage::EvilMage() {
    name = "Evil Mage";
    weakness = "Fire";
    resistance = "Magic";
    damage = 15;
    health = 100;
    treasureDropped = 300;
    xp = 200;
    manaDropped = 20;
}

void EvilMage::attack(Player &target) {
    this->draw();
    // 15% chance of stealing mana
    int random = (rand() % 100) + 1;
    if (random <= 15) {
        cout << endl;
        cout << "The evil mage has stolen " << random << " of your mana for themself" << endl;
        this->steal(target);
    }
    else {
        //attacking player
        cout << "The Evil Mage blasts you with an orb of magic" << endl;
        target.takeDamage(damage);
    }
}

void EvilMage::draw() {
    cout << R"(
                      _,-'|
                   ,-'._  |
         .||,      |####\ |
        \.`',/     \####| |
        = ,. =      |###| |
        / || \    ,-'\#/,'`.
          ||     ,'   `,,. `.
          ,|____,' , ,;' \| |
         (3|\    _/|/'   _| |
          ||/,-''  | >-'' _,\\
          ||'      ==\ ,-'  ,'
          ||       |  V \ ,|
          ||       |    |` |
          ||       |    |   \
          ||       |    \    \
          ||       |     |    \
          ||       |      \_,-'
          ||       |___,,--")_\
          ||         |_|   ccc/
          ||        ccc/
          ||                hjm
    )" << endl;
}

void EvilMage::steal(Player &target) {
    target.loseMana(stolenMana);
}

void EvilMage::printInfo() {
    cout << "Name: " << name << endl;
    cout << name << " is weak to " << weakness << " type attacks and strong against " << resistance << " attacks" << endl << endl;
    cout << "Skill: " << name << " has a chance to steal a portion of you mana" << endl;
    cout << "Health:  " << health << endl;
    cout << "Damage: " << damage << endl;
}

