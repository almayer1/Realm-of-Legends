//
//  Player.hpp
//  Project 2
//
//  Created by Alex Mayer on 11/7/24.
//

#ifndef Player_hpp
#define Player_hpp

#include "Weapon.hpp"
#include <string>
#include <stdio.h>

using namespace std;

class Enemy;

class Player {
public:
    //Constructor
    Player();
    Player(string name);
    
    //Getters and Setters
    void setName(string);
    string getName();
    void setMaxHealth(int);
    int getMaxHealth();
    void setCurrHealth(int);
    int getCurrHealth();
    void setMaxMana(int);
    int getMaxMana();
    void setCurrMana(int);
    int getCurrMana();
    void setStrength(int);
    int getStrength();
    
    void setTreasure(int);
    int getTreasure();
    void setXP(int);
    int getXP();
    void setLevel(int);
    int getLevel();
    Weapon& getWeapon();
    
    
    //functions
    void attack(Enemy& target);
    void takeDamage(int damage);
    void loseMana(int amount);
    void loseTreasure(int amount);
    void collectTreasure(int amount);
    void healHealth(int amount);
    void healMana(int amount);
    void regenerateMana(int amount);
    void printStats();
    
    
private:
    //data members
    string name;
    int maxHealth;
    int currHealth;
    int maxMana;
    int currMana;
    int strength;
    int treasure;
    int xp;
    int level;
    Weapon weapon;
};

#endif /* Player_hpp */
