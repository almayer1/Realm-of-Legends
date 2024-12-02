//
//  main.cpp
//  Project 2
//
//  Created by Alex Mayer on 11/7/24.
//
#include "Player.hpp"
#include "Ghost.hpp"
#include "Robber.hpp"
#include "EvilMage.hpp"

#include <iostream>
#include <ctime>
#include <fstream>

int introScreen (Player &player);
void chooseWeapon(Player &player);
void handleCommonTreasure(Player &player);
void handleSpecialTreasure(Player &player);
bool handleEnemy(Player &player);
void playerTurn(Player &player, Enemy *enemy);
Enemy* randomEnemy();
bool handlePath(Player &player, string path);
void handleLevelUp(Player &player, int xpDropped);
int inputFile(Player &player);
bool outputFile(Player &player);
void clearSaveFile();

int main(int argc, const char * argv[]) {
    const int GOAL = 1000;
    string name = "";
    Player player;
    
    int gameType = introScreen(player);
    //Start from scratch
    if (gameType == 1) {
        cout << "Welcome " << player.getName() << endl;
        player.printStats();
        chooseWeapon(player);
    }
    //Start from save
    else if (gameType == 2) {
        cout << "Welcome Back " << player.getName() << endl;
        cout << "Here are your stats from last time" << endl;
        cout << endl;
        player.printStats();
        cout << endl;
    }
    //Exit game
    else {
        return 2;
    }
    
    //seed of random function used later in the game loop
    srand(time(0));
    
    //initilizing variables used in game loop
    int i = 0;
    bool gameRunning = true;
    string continuePlaying = "";
    string path = "";
    
    //game loop
    while (gameRunning) {
        //asks which path to go down
        cout << "Please pick a path to go down >>> Left, Straight, or Right" << endl;
        cin >> path;
        cout << endl;
        
        if (i % 2 == 0) {
            gameRunning = handlePath(player, path);
            if (!gameRunning) {
                break;
            }
        }
        else {
            cout << "You have walked down the " << path << " path with ease and arrived at a new intersection" << endl;
        }
        
        if (player.getTreasure() >= GOAL) {
            cout << "Congrats you have reached the treasure amount of " << GOAL << ", and have won the game!!!!" << endl;
            gameRunning = false;
            continue;
        }
        
        // regenerates some mana
        int manaRegenAmount = 5; // Define how much mana to regenerate
        if (player.getMaxMana() > player.getCurrMana()) {
            if (player.getMaxMana() - player.getCurrMana() < manaRegenAmount) {
                player.regenerateMana(player.getMaxMana() - player.getCurrMana());
            }
            else {
                player.regenerateMana(manaRegenAmount);
            }
        }
        
        //handles if player wants to continue playing
        cout << endl;
        cout << "Type \"q\" to quit playing, type \"c\" to continue, or type \"s\" to save progress and exit" << endl;
        cin >> continuePlaying;
        cout << endl;
        
        if (continuePlaying == "q") {
            gameRunning = false;
        }
        else if (continuePlaying == "c") {
            continue;
        }
        else if (continuePlaying == "s"){
            bool savedGame = outputFile(player);
            if (savedGame) {
                cout << "Successfully saved progress thanks for playing!" << endl;
            }
            else {
                cout << "Unable to properly open file" << endl;
            }
            gameRunning = false;
        }
        i++;
    }
    cout << "Thanks for playing. Your final treasure total was: " << player.getTreasure() << endl;
    
    return 0;
}

int introScreen (Player &player) {
    cout << R"(
    
      ██████╗  ██████╗  ██████╗ ██████╗     ██╗     ██╗   ██╗ ██████╗██╗  ██╗
     ██╔════╝ ██╔═══██╗██╔═══██╗██╔══██╗    ██║     ██║   ██║██╔════╝██║ ██╔╝
     ██║  ███╗██║   ██║██║   ██║██║  ██║    ██║     ██║   ██║██║     █████╔╝ 
     ██║   ██║██║   ██║██║   ██║██║  ██║    ██║     ██║   ██║██║     ██╔═██╗ 
     ╚██████╔╝╚██████╔╝╚██████╔╝██████╔╝    ███████╗╚██████╔╝╚██████╗██║  ██╗
      ╚═════╝  ╚═════╝  ╚═════╝ ╚═════╝     ╚══════╝ ╚═════╝  ╚═════╝╚═╝  ╚═╝
                                                                           
                              ╔══════════════════════╗ 
                              ║   Realm of Legends   ║
                              ╚══════════════════════╝
                                    
                 ~ Where Heroes Are Forged in Fire and Magic ~
                        
                ~ Collect 1000 tokens to cleanse the Kingdom  ~
    

    ╔════════════════════════════════╗
    ║   1. Start A New Adventure     ║
    ║   2. Load Saved Adventure      ║
    ║   3. Exit game                 ║
    ╚════════════════════════════════╝

    )" << endl;
    
    string name = "";
    int input = 0;
    cin >> input;
    //Start from scratch
    if (input == 1) {
        clearSaveFile();
        cout << "What is your Adventure's name?" << endl;
        cin >> name;
        player.setName(name);
        cout << endl;
        return 1;
    }
    //Start from save
    else if (input == 2) {
        int error = inputFile(player);
        //if file doesn't exist
        if (error == 1) {
            cout << "Couldn't open file" << endl;
            return 3;
        }
        //if file exists but doesn't have anything saved/
        else if (error == 2) {
            cout << "There is no file saved" << endl;
            cout << "Try Again!" << endl;
            introScreen(player);
        }
        return 2;
    }
    //Exit game
    else {
        cout << "Goodbye Now" << endl;
        return 3;
    }
}

void chooseWeapon(Player& player) {
    // asks player to pick a weapon
    int weaponNumber = 0;
    cout << endl;
    cout << "Please choose a weapon to fight enemies with!!" << endl;
    cout << "Each weapon has a special added damage boost that it achieves by consuming mana" << endl << endl;
    
    //shows options
    cout << "Option 1:" << endl;
    player.getWeapon().drawWeapon("Vilethorn");
    cout << endl;
    
    cout << "Option 2:" << endl;
    player.getWeapon().drawWeapon("Pyrofang");
    cout << endl;
    
    cout << "Option 3:" << endl;
    player.getWeapon().drawWeapon("Bonker");
    cout << endl << endl;
    
    cout << "Type 1, 2, or 3" << endl;
    cout << "This will become you weapon for life so be smart about it :) " << endl;
    cin >> weaponNumber;
    cout << endl;
    
    //reads input
    if (weaponNumber == 1) {
        player.getWeapon().setWeapon("Vilethorn");
    }
    else if (weaponNumber == 2) {
        player.getWeapon().setWeapon("Pyrofang");
    }
    else if (weaponNumber == 3) {
        player.getWeapon().setWeapon("Bonker");
    }
    else {
        cout << "You didn't select one of the three provided weapons" << endl;
    }
    cout << "Your weapon of choice is " << player.getWeapon().getWeaponType() << endl << endl;
}

void handleCommonTreasure(Player &player) {
    //Introduces treasure and asks if player wants it
    string decision = "";
    int amount = (rand() % 11) + 10;
    cout << "Congratulations you've encountered a common treasure worth: " << amount << endl;
    cout << "Type (p) to pick it up or Type any other key to skip it" << endl;
    cin >> decision;
    cout << endl;
    if (decision == "p") {
        //generates random number: [50, 100]
        cout << "You have collected " << amount << " treasure" << endl;
        player.collectTreasure(amount);
    }
    else {
        cout << "You have chosen to skip the treasure" << endl << endl;
    }
}

void handleSpecialTreasure(Player &player) {
    string decision = "";
    //generates value between 10-30
    int amount = (rand() % 11) + 20;
    cout << "Congradulations you've encountered a special treasure worth: " << amount << " mana" << endl;
    cout << "Type (p) to pick it up or Type any other key to skip it" << endl;
    cin >> decision;
    cout << endl;
    if (decision == "p") {
        cout << "You have collected " << amount << " mana" << endl;
        player.regenerateMana(amount);
    }
    else {
        cout << "You have chosen to skip the treasure" << endl << endl;
    }
}
//returns true if enemy defeated, and false if player defeated
bool handleEnemy(Player &player) {
    cout << "You've have encounter an enemy" << endl << endl;
    //pointer to a random enemy type
    Enemy* enemy = randomEnemy();
    
    int i = 0;
    bool enemyAlive = true;
    bool playerAlive = true;
    string cont;
    
    while (enemyAlive && playerAlive) {
        //player turn
        if (i % 2 == 0) {
            playerTurn(player, enemy);
            cout << "Type anything to continue" << endl;
            cin >> cont;
        }
        //enemy turn
        else {
            enemy->attack(player);
            cout << endl;
            cout << "Type anything to continue" << endl;
            cin >> cont;
        }
        
        //checks player and enemy health and cancels loop if equal to 0
        if (enemy->getHealth() == 0) {
            enemy->dropTreasure(player);
            handleLevelUp(player, enemy->getXP());
            enemyAlive = false;
        }
        if (player.getCurrHealth() == 0) {
            playerAlive = false;
        }
        i++;
    }
    
    if (!enemyAlive && playerAlive) {
        return true; // Enemy defeated
    }
    else {
        return false; // Player died
    }
}

void playerTurn(Player &player, Enemy *enemy) {
    string decision = "";
    enemy->draw();
    enemy->printInfo();
    cout << endl;
    
    cout << "Type \"A\" to attack the enemy" << endl;
    cout << "Type \"H\" to heal 25% of your health for 10 mana" << endl << endl;
    player.printStats();
    cin >> decision;
    cout << endl;
    
    if (decision == "A") {
        player.attack(*enemy);
    }
    else if (decision == "H") {
        if (player.getCurrMana() >= 10) {
            cout << "You heal your health for 10 mana" << endl;
            player.loseMana(10);
            player.healHealth(player.getMaxHealth() / 4);
            playerTurn(player, enemy);
        }
        else {
            cout << "You don't have enough mana to heal your health. Please select another option!" << endl;
            playerTurn(player, enemy);
            return;
        }
    }
    else {
        cout << "Invalid input. Please try again." << endl;
        playerTurn(player, enemy);
        return;
    }
}

//generates a random enemy
Enemy* randomEnemy() {
    int random = (rand() % 10) + 1;
    //30% to get a Evil Mage, %30 to get a Robber, %40 to get a ghost
    if (random <= 3) {
        return new EvilMage();
    }
    else if (random <= 6) {
        return new Robber();
    }
    else {
        return new Ghost();
    }
}

bool handlePath(Player &player, string path) {
    int ENEMY_PROBABILITY = 60;
    
    string correctPath[3] = {"Left", "Straight", "Right"};
    int random = rand() % 3;
    
    //If you guess the randomly generated path you get a special treasure
    if (path == correctPath[random]) {
        handleSpecialTreasure(player);
    }
    
    // if you get it wrong you can either encounter an enemy or a common treasure... there's a 60% chance to encounter an enemy
    else {
        random = (rand() % 100) + 1;
        if (random <= ENEMY_PROBABILITY) {
            bool enemyDefeated = handleEnemy(player);
            if (enemyDefeated) {
                cout << "You defeated enemy" << endl;
            }
            else {
                cout << "You lost" << endl;
                return false;
            }
        }
        else {
            handleCommonTreasure(player);
        }
    }
    return true;
}
//checks if a player can level up and if so levels that player up
void handleLevelUp(Player &player, int xpDropped) {
    string selection = "";
    const int XP_FOR_LEVEL = 200;
    int nextThreshold = (player.getLevel() + 1) * XP_FOR_LEVEL;
    
    player.setXP(player.getXP() + xpDropped);
    cout << "You gained " << xpDropped << " XP!" << endl;
    
    if (player.getXP() >= nextThreshold) {
        player.printStats();
        cout << "You have unlocked a new level" << endl;
        cout << "You can add +20 to Health :: type \"H\"" << endl;
        cout << "You can add +10 to Mana :: type \"M\"" << endl;
        cout << "You can add +5 to Damage :: type \"D\"" << endl;
        cin >> selection;
        if (selection == "H") {
            //upgrades max health
            player.setMaxHealth(player.getMaxHealth() + 20);
            //heals 25% of max health
            player.healHealth(player.getMaxHealth() / 4);
        }
        else if (selection == "M") {
            //upgrades max mana
            player.setMaxMana(player.getMaxMana() + 10);
            // heals 20% of mana capacity
            player.healMana(player.getMaxMana() / 5);
        }
        else if (selection == "D") {
            //upgrades base damage
            player.setStrength(player.getStrength() + 5);
        }
        else {
            cout << "You have entered an invalid input!" << endl;
            cout << "Please try again" << endl;
            handleLevelUp(player, xpDropped);
            return;
        }
        player.setLevel(player.getLevel() + 1);
        cout << "Your Updated Stats:" << endl;
        player.printStats();
    }
    else {
        cout << "You need " << nextThreshold - player.getXP() << " more XP to level up." << endl;
    }
}

int inputFile(Player& player) {
    //creates ifstream
    string filename = "Save1.txt";
    ifstream fin(filename);
    if(!fin.is_open()) {
        return 1;
    }
    
    //The first input is a test to see if the game has anything saved or is empty
    int test;
    fin >> test;
    if (test == 0) {
        return 2;
    }
    
    int maxHealth, currHealth, maxMana, currMana, strength, treasure, xp, level;
    string name;
    string weaponChoice;

    fin >> name >> maxHealth >> currHealth >> maxMana >> currMana >> strength >> treasure >> xp >> level >> weaponChoice;
    
    player.setName(name);
    player.setMaxHealth(maxHealth);
    player.setCurrHealth(currHealth);
    player.setMaxMana(maxMana);
    player.setCurrMana(currMana);
    player.setStrength(strength);
    player.setTreasure(treasure);
    player.setXP(xp);
    player.setLevel(level);
    player.getWeapon().setWeapon(weaponChoice);
    
    fin.close();
    return 0;
}

bool outputFile(Player& player) {
    string fileName = "Save1.txt";
    ofstream fout(fileName);
    if (!fout.is_open()) {
        return false;
    }
    fout << "1 ";
    fout << player.getName() << " ";
    fout << player.getMaxHealth() << " ";
    fout << player.getCurrHealth() << " ";
    fout << player.getMaxMana() << " ";
    fout << player.getCurrMana() << " ";
    fout << player.getStrength() << " ";
    fout << player.getTreasure() << " ";
    fout << player.getXP() << " ";
    fout << player.getLevel() << " ";
    fout << player.getWeapon().getWeaponType() << " ";
    
    fout.close();
    return true;
}

void clearSaveFile() {
    ofstream fout("Save1.txt"); // by default clears when opens file
    if (fout.is_open()) {
        //0 tells the game that the file is empty
        fout << "0" << endl;
    }
    else {
        cout << "Failed to open the file." << endl;
    }
    fout.close();
}
