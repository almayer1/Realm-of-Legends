//
//  Weapon.hpp
//  Project 2
//
//  Created by Alex Mayer on 11/7/24.
//

#ifndef Weapon_hpp
#define Weapon_hpp

#include "Enemy.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Weapon {
public:
    Weapon();
    string getWeaponType();
    void attack(Enemy& target, int playerDamage, int &mana);
    void setWeapon(string name);
    void drawWeapon(string name);
    
private:
    string weaponType;
    string affinity;
    int addedDamage;
    int manaCost;
    int damage;
};

#endif /* Weapon_hpp */
