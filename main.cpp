#include <iostream>

// Module 2: Calculate damage while preventing negative numbers
int CalculateDamage(int attack, int defense) {
    int finalDamage = attack - defense;
    if (finalDamage < 0) {
        finalDamage = 0;
    }
    return finalDamage;
}

// Module 3: Pass-by-reference modifies health directly in memory
void ApplyDamage(int& targetHealth, int damage) {
    targetHealth -= damage;
    if (targetHealth < 0) {
        targetHealth = 0;
    }
}

// Module 2: Simple menu function to capture user intent
int GetPlayerChoice() {
    int choice = 0;
    std::cout << "\nChoose an action:\n";
    std::cout << "1. Normal Attack (Safe)\n";
    std::cout << "2. Heavy Attack (High Risk / High Reward)\n";
    std::cout << "Enter choice (1 or 2): ";
    std::cin >> choice;
    return choice;
}

int main() {
    // Module 1: Primitive tracking variables
    int playerHP = 100;
    int monsterHP = 60;
    int goblinDefense = 5;
    int turn = 1;

    std::cout << "=== DUNGEON ENCOUNTER: GOBLIN ===\n";

    // Module 3: Turn-based game loop
    while (playerHP > 0 && monsterHP > 0) {
        std::cout << "\n--- Turn " << turn << " ---" << std::endl;
        std::cout << "Player HP: " << playerHP << " | Goblin HP: " << monsterHP << std::endl;

        int choice = GetPlayerChoice();
        int playerAttackPower = 0;
        int monsterRetaliationBonus = 0;

        if (choice == 1) {
            playerAttackPower = 25;
            monsterRetaliationBonus = 0;
        } else if (choice == 2) {
            playerAttackPower = 45;
            monsterRetaliationBonus = 8; // Heavy swing leaves player exposed
        } else {
            std::cout << "Invalid action! You stumbled and missed your turn.\n";
        }

        // Player turn execution
        if (playerAttackPower > 0) {
            int damageDealt = CalculateDamage(playerAttackPower, goblinDefense);
            ApplyDamage(monsterHP, damageDealt);
            std::cout << "You struck the goblin for " << damageDealt << " damage!\n";
        }

        // Enemy turn execution (only if goblin is still standing)
        if (monsterHP > 0) {
            int goblinBaseAttack = 15;
            int totalMonsterDamage = goblinBaseAttack + monsterRetaliationBonus;
            ApplyDamage(playerHP, totalMonsterDamage);
            std::cout << "Goblin counter-attacks dealing " << totalMonsterDamage << " damage!\n";
        }

        turn++;
    }

    // End-game resolution
    std::cout << "\n================================\n";
    if (playerHP > 0) {
        std::cout << "VICTORY! The goblin was slain.\n";
    } else {
        std::cout << "DEFEAT... You fell in battle.\n";
    }
    std::cout << "================================\n";

    return 0;
}