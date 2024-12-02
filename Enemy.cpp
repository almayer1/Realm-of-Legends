//
//  Enemy.cpp
//  Project 2
//
//  Created by Alex Mayer on 11/7/24.
//

#include "Enemy.hpp"
#include "Player.hpp"

Enemy::Enemy() {
    health = 20;
    damage = 5;
    weakness = "";
    resistance = "";
    xp = 0;
    treasureDropped = 0;
    manaDropped = 0;
    name = "Unknown";
}

string Enemy::getName() {
    return name;
}

int Enemy::getHealth() {
    return health;
}

int Enemy::getXP() {
    return xp;
}

int Enemy::getManaDropped() {
    return manaDropped;
}

void Enemy::attack(Player &target) {
    target.takeDamage(damage);
}

void Enemy::takeDamage(int damageAmount, string damageType) {
    // checks if the damage type is the same as the weakness, if so enemy takes extra damage
    if (damageType == weakness) {
        damageAmount += 2;
        cout << "It's super effective! +" << 2 << " damage." << endl;
    }
    // checks if the damage type is the same as the resistance, if so enemy takes less damage
    else if (damageType == resistance) {
        damageAmount -= 2;
        cout << "It's not very effective... -" << 2 << " damage." << endl;
    }
    health -= damageAmount;
    if (health < 0) {
        health = 0;
    }
    cout << name << " takes " << damageAmount << " damage. Remaining Health: " << health << endl;
}

// called when enemy dies
void Enemy::dropTreasure(Player &target) const {
    target.collectTreasure(treasureDropped);
}

void Enemy::printHealth() {
    cout << "Health: " << health << endl;
}
