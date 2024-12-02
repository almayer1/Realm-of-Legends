//
//  Weapon.cpp
//  Project 2
//
//  Created by Alex Mayer on 11/7/24.
//

#include "Weapon.hpp"

Weapon::Weapon() {
    weaponType = "fists";
    affinity = "none";
    damage = 0;
    manaCost = 5;
    addedDamage = 2;
}

string Weapon::getWeaponType() {
    return weaponType;
}

void Weapon::attack(Enemy &target, int playerDamage, int &mana) {
    string input = "";
    int totalDamage = playerDamage + damage; // Base damage from player strength and weapon

    if (mana >= manaCost) {
        cout << "You can use your special attack | Mana Available: " << mana
             << " | Mana Cost: " << manaCost << endl;
        cout << "Type 'y' to use special attack and 'n' to do a base attack: ";
        cin >> input;

        // Special attack
        if (input == "y" || input == "Y") {
            totalDamage += addedDamage; // Add extra damage for this attack
            mana -= manaCost;          // Deduct mana cost
            cout << "You used a special attack! Extra " << addedDamage << " damage added." << endl;
        }
    }
    else {
        cout << "Not enough mana for a special attack. Performing a base attack." << endl;
    }
    cout << endl;
    // Apply the calculated total damage to the enemy
    target.takeDamage(totalDamage, affinity);
    cout << endl;
}

void Weapon::setWeapon(string name) {
    if (this->weaponType == name) {
        return;
    }
    else if (name == "Vilethorn") {
        weaponType = "Vilethorn";
        damage = 5;
        manaCost = 20;
        addedDamage = 10;
        affinity = "Magic";
    }
    else if (name == "Pyrofang") {
        weaponType = "Pyrofang";
        damage = 6;
        manaCost = 15;
        addedDamage = 8;
        affinity = "Fire";
    }
    else if (name == "Bonker") {
        weaponType = "Bonker";
        damage = 8;
        manaCost = 10;
        addedDamage = 6;
        affinity = "Physical";
    }
    else {
        cout << "Invalid Weapon Type" << endl;
    }
}

void Weapon::drawWeapon(string name) {
    if (name == "Vilethorn") {
        cout << R"(
      ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣤⣄⣀⣀⠀⠀⠀⠀⠀⠀⠀
      ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡾⠟⠛⣛⣻⣿⣿⣿⣿⣶⣤⡀⠀⠀⠀
      ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡿⠁⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀
      ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡟⢀⣾⠟⢫⣿⠟⢉⣉⣉⠙⠻⣿⣿⢿⣿⡆⠀   **** Vilethorn ****
      ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣇⣾⡏⢠⡿⠁⣴⣿⣿⣿⣿⣆⠘⣿⠀⣿⡇⠀
      ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⠀⢸⡇⢸⣿⣿⣿⠛⠿⠟⢀⣿⠀⣿⡇⠀
      ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⠀⢸⣧⠈⣿⣿⣿⣷⣶⣶⣟⣃⣴⠟⠀⠀
      ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⡿⠀⣿⡿⠀⠈⠻⢿⣿⣿⣿⡿⠟⠃⠀⠀⠀
      ⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⠃⣸⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
      ⠀⠀⠀⠀⠀⠀⢀⣴⡟⢩⣿⡿⢃⣼⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
      ⠀⠀⠀⠀⠀⣠⡿⠋⣠⣿⣿⣷⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
      ⠀⠀⠀⣠⡾⠋⢀⣾⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
      ⠀⣠⡾⠋⣀⣴⣿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
      ⠀⠋⣠⣾⡿⢻⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
      ⠀⠛⠛⠁⠐⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
        )" << endl << endl;
        cout << "-Stats-" << endl;
        cout << "Name: Vilethorn" << endl;
        cout << "Affinity: Magic" << endl;
        cout << "Base Damage: 5" << endl;
        cout << "Speacial Damage Added: 10" << endl;
        cout << "Mana Cost: 20" << endl;
        
    
    
    }
    else if (name == "Pyrofang") {
        cout << R"(
                        _
                       (_)
                       |=|
                       |=|
                   /|__|_|__|\        **** Pyrofang ****
                  (    ( )    )
                   \|\/\"/\/|/
                     |  Y  |
                     |  |  |
                     |  |  |
                    _|  |  |
                 __/ |  |  |\
                /  \ |  |  |  \
                   __|  |  |   |
                /\/  |  |  |   |\
                 <   +\ |  |\ />  \
                  >   + \  | LJ    |
                        + \|+  \  < \
                  (O)      +    |    )
                   |             \  /\ 
                 ( | )   (o)      \/  )
                _\\|//__( | )______)_/ 
                        \\|//
        )" << endl << endl;
        cout << "-Stats-" << endl;
        cout << "Name: Pyrofang" << endl;
        cout << "Affinity: Fire" << endl;
        cout << "Base Damage: 6" << endl;
        cout << "Speacial Damage Added: 8" << endl;
        cout << "Mana Cost: 15" << endl;
    }
    else if (name == "Bonker") {
        cout << R"(
                    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡄⠀⠀⠀⡀⠠⣴⣶⣶⣄⠐⠃⠀⠀
                    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣠⣶⡇⠀⣿⡄⠹⣿⣿⡿⠀⠀⠀⠀
                    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢤⣀⠀⠺⣿⣿⣷⣄⡉⢁⣼⣿⣿⣣⡇⠀⠀⠀ **** Bonker ****
                    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⠆⢸⣿⣿⣿⣿⣿⡿⠋⣉⣉⣁⣀⠀⠀
                    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣄⣁⣴⣿⣿⣿⣿⣿⣿⣇⠸⣿⡿⠋⠁⠀⠀
                    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⣿⠿⠻⢿⣿⣿⣿⣷⠄⠀⠀⠀⠀⠀
                    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣄⣿⣿⣿⣿⡇⢰⣶⡄⢹⠿⠛⠁⠀⠀⠀⠀⠀⠀
                    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⠁⣸⡟⠀⠀⠐⠶⠀⠀⠀⠀⠀⠀⠀
                    ⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣿⠿⠋⠀⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                    ⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                    ⠀⠀⠀⠀⢀⣴⣿⣿⣿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                    ⠀⠀⠀⣠⠿⣫⡾⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                    ⠀⠠⠞⣡⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                    ⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

        )" << endl << endl;
        cout << "-Stats-" << endl;
        cout << "Name: Bonker" << endl;
        cout << "Affinity: Physical" << endl;
        cout << "Base Damage: 8" << endl;
        cout << "Speacial Damage Added: 6" << endl;
        cout << "Mana Cost: 10" << endl;
    }
    else {
        cout << "invalid name" << endl;
    }
}
