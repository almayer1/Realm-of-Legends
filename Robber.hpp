//
//  Robber.hpp
//  Project 2
//
//  Created by Alex Mayer on 11/7/24.
//

#ifndef Robber_hpp
#define Robber_hpp

#include "Enemy.hpp"

class Robber : public Enemy {
public:
    Robber();
    void attack(Player &target) override;
    void draw() override;
    void steal(Player &target);
    void printInfo() override;
};

#endif /* Robber_hpp */
