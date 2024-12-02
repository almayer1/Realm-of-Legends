//
//  Ghost.hpp
//  Project 2
//
//  Created by Alex Mayer on 11/7/24.
//

#ifndef Ghost_hpp
#define Ghost_hpp

#include "Enemy.hpp"

class Ghost : public Enemy {
public:
    Ghost();
    void attack(Player& target) override;
    void draw() override;
    void printInfo() override;
};
#endif /* Ghost_hpp */
