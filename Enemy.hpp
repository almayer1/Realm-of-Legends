//
//  Enemy.hpp
//  Project 2
//
//  Created by Alex Mayer on 11/7/24.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <string>
#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace std;

class Player;

class Enemy {
public:
    //constructors
    Enemy();
    
    //getters and setters
    string getName();
    int getHealth();
    int getXP();
    int getManaDropped();
    
    //functions
    virtual void attack(Player &target);
    virtual void draw() = 0;
    virtual void printInfo() = 0;
    void printHealth();
    void takeDamage(int damage, string damageType);
    void dropTreasure(Player &target) const;

protected:
    string name;
    string weakness;
    string resistance;
    int damage;
    int health;
    int treasureDropped;
    int xp;
    int manaDropped;
};

#endif /* Enemy_hpp */
