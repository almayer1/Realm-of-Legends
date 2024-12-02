//
//  EvilMage.hpp
//  Project 2
//
//  Created by Alex Mayer on 11/7/24.
//

#ifndef EvilMage_hpp
#define EvilMage_hpp

#include "Enemy.hpp"
#include <stdio.h>

// they could cast a spell that permanently reduce's your mana capacity

class EvilMage : public Enemy {
public:
    EvilMage();
    void attack(Player &target) override;
    void draw() override;
    void steal(Player &target);
    void printInfo() override;

private:
    int stolenMana = 25;
};

#endif /* EvilMage_hpp */
