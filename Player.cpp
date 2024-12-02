//
//  Player.cpp
//  Project 2
//
//  Created by Alex Mayer on 11/7/24.
//

#include "Player.hpp"
#include "Enemy.hpp"


//constructor
Player::Player() {
    maxHealth = 100;
    currHealth = maxHealth;
    maxMana = 80;
    currMana = maxMana;
    strength = 10;
    treasure = 0;
    xp = 0;
    level = 0;
}
Player::Player(string name) {
    this->name = name;
    maxHealth = 100;
    currHealth = maxHealth;
    maxMana = 80;
    currMana = maxMana;
    strength = 10;
    treasure = 0;
    xp = 0;
    level = 0;
}

// getters and setters
void Player::setName(string n) {
    name = n;
}

string Player::getName() {
    return name;
}

void Player::setStrength(int str) {
    strength = str;
}

int Player::getStrength() {
    return strength;
}

void Player::setTreasure(int t) {
    treasure = t;
}

int Player::getTreasure() {
    return treasure;
}

void Player::setXP(int xp) {
    this->xp = xp;
}

int Player::getXP() {
    return xp;
}

void Player::setLevel(int level) {
    this->level = level;
}

int Player::getLevel() {
    return level;
}

Weapon& Player::getWeapon() {
    return weapon;
}
void Player::setMaxHealth(int amount) {
    maxHealth = amount;
}
int Player::getMaxHealth() {
    return maxHealth;
}
void Player::setCurrHealth(int amount) {
    currHealth = amount;
}
int Player::getCurrHealth() {
    return currHealth;
}
void Player::setMaxMana(int amount) {
    maxMana = amount;
}
int Player::getMaxMana() {
    return maxMana;
}
void Player::setCurrMana(int amount) {
    currMana = amount;
}
int Player::getCurrMana() {
    return currMana;
}


// functions

//calls Weapon class to attack target of Enemy class
void Player::attack(Enemy& target) {
    weapon.attack(target, strength, currMana);
}

//Subtracts a certain amount of damage from player health
void Player::takeDamage(int damage) {
    currHealth -= damage;
    //if less than 0 it becomes 0
    if (currHealth < 0) {
        currHealth = 0;
    }
    cout << name << "'s updated health: " << currHealth << "/" << maxHealth << endl;
}

//subtracts amount from max player mana can be
void Player::loseMana(int amount) {
    currMana -= amount;
    //if less than 0 it becomes 0
    if (currMana < 0) {
        currMana = 0;
    }
    cout << name << "'s updated mana amount: " << currMana << "/" << maxMana << endl;
}
//Subtracts a certain amount of treasure from player treasure amount.
void Player::loseTreasure(int amount) {
    treasure -= amount;
    //if less than 0 it becomes 0
    if (treasure < 0) {
        treasure = 0;
    }
    cout << name << "'s updated treasure amount: " << treasure << endl;
}

//Adds an amount to player's treasure count
void Player::collectTreasure(int amount) {
    treasure += amount;
    cout << name << "'s updated treasure amount: " << treasure << endl;
}

//Prints out current stats
void Player::printStats() {
    cout << "---Stats---" << endl;
    cout << "Health: " << currHealth << "/" << maxHealth << endl;
    cout << "Strength: " << strength << endl;
    cout << "Mana: " << currMana << "/" << maxMana << endl;
    cout << "Treasure: " << treasure << endl;
    cout << "Weapon: " << weapon.getWeaponType() << endl;
    cout << "------------" << endl;
}
//Adds amount to players health
void Player::healHealth(int amount) {
    currHealth += amount;
    if (currHealth > maxHealth) {
        currHealth = maxHealth;
    }
    cout << name << "'s updated health: " << currHealth << "/" << maxHealth << endl;
}
//Adds mana to player's mana count
void Player::healMana(int amount) {
    currMana += amount;
    if (currMana > maxMana) {
        currMana = maxMana;
    }
    cout << name << "'s updated mana amount: " << currMana << "/" << maxMana << endl;
}
//Adds mana to player's mana count
void Player::regenerateMana(int amount) {
    currMana += amount;
    if (currMana > maxMana) {
        currMana = maxMana;
    }
    cout << name << " regenerates " << amount << " mana. Current Mana: " << currMana << "/" << maxMana << endl;
}
