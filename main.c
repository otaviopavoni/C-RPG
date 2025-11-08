/*

This game is intended to be a small training about C's features, such as variables, conditionals,
loops, structures and pointers. Hope you like it!

Created by Otávio Pavoni

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct character {
    int hearts;
    int coins;
    int xp;
};

void welcome() {
    printf("\nWelcome to C-RPG. This is intended to be a simple, fast and fun terminal game for RPG fans.\nHere, you'll create your own story by opening doors of a dungeon, collecting coins, buying armour and slashing monsters.\n\nWe wish you good luck!\n");
}

void separator() {
    printf("\n============================================\n");
}

int openDoor() {
    int answer = 0;
    separator();
    printf("\nDo you wish to open a door? Type a number: \n1 for YES /\n2 for NO /\n3 for STATS /\n4 for STORE /\n0 for QUIT /\n\n");
    scanf("%d", &answer);
    return answer;
}

void kickDoor() {
    int random_number = rand() % 100;
    if (random_number <= 25) {
        printf("\nYou kick the door to the ground!\n");
    } else if (random_number <= 50 && random_number > 25) {
        printf("\nYou slightly open a door!\n");
    } else if (random_number <= 75 && random_number > 50) {
        printf("\nYou slash another door to the ground!\n");
    } else {
        printf("\nYou explode the door!\n");
    }
}

void getCoins(int *coins) {
    int random_number = rand() % 100;
    *coins += random_number;
    printf("You found %d coins!\n\n", random_number);
}

int fightEnemy() {
    int answer = 0;
    separator();
    printf("\nDo you wish to fight the enemy?\n1 for YES /\n2 for NO /\n0 for QUIT/\n\n");
    scanf("%d", &answer);
    return answer;
}

void loseCoins(int *coins) {
    int random_number = rand() % 100;
    if (*coins > random_number) {
        *coins -= random_number;
        separator();
        printf("\nYou lost %d coins as you tried to run!\n", random_number);
    } else {
        *coins -= *coins;
        separator();
        printf("\nYou lost all coins as you tried to run!\n");
    }
    
}

void fight(int *hearts, int *xp) {
    int random_number = rand() % 5;
    *hearts -= random_number;
    *xp += random_number;

    separator();

    switch (random_number) {
        case 0:
            printf("\nMonsters roared, spells blazed—the dungeon trembled as victory screamed through dust.");
            break;
        case 1:
            printf("\nBlades flashed, monsters fell—echoes of courage rang through the shadowed crypt.");
            break;
        case 2:
            printf("\nDragons soared, fire rained—only steel and will kept the heroes standing tall.");
            break;
        case 3:
            printf("\nZombies swarmed, armour cracked—yet one sword's light cut through the endless night.");
            break;
        case 4:
            printf("\nSteel clashed, dragons roared—heroes rose from fire and fury, armour blazing, victory claimed.");
            break;
    }
    printf("\n\nYou lost %d hearts as you tried to fight!\n", random_number);
    printf("You won %d XP as you tried to fight!\n", random_number);
}

void showStats(struct character p) {
    separator();
    printf("\nHearts: %d\n", p.hearts);
    printf("Coins: %d\n", p.coins);
    printf("XP: %d\n", p.xp);
}

int checkHearts(struct character p) {
    if (p.hearts <= 0) {
        return 0;
    } else {
        return 1;
    }
}

void store(int *hearts, int *coins){
    separator();
    printf("\nWelcome to the store! Where your dreams come true!\n");
    separator();
    printf("\nWEAK HEARTS POTION (restores 5 hearts) - 50 coins\n");
    printf("\nHEARTS POTION (restores 10 hearts) - 150 coins\n");
    printf("\nSTRONG HEARTS POTION (restores 20 hearts) - 300 coins\n");
    separator();

    int answer = 0;

    do {
        
        printf("\nDo you buy something from the store?\n1 for WEAK HEARTS POTION /\n2 for HEARTS POTION /\n3 for STRONG HEARTS POTION\n0 for NO /\n\n");
        scanf("%d", &answer);

        switch (answer)
        {
        case 1:
            if (*coins >= 50){
                *hearts += 5;
                *coins -= 50;
                printf("\nYou bought a weak hearts potion! Current hearts: %d\nCurrent coins: %d\n", *hearts, *coins);
                break;
            } else {
                printf("\nYou should try getting more coins.\n");
                break;
            }
        case 2:
            if (*coins >= 150){
                *hearts += 10;
                *coins -= 150;
                printf("\nYou bought a hearts potion! Current hearts: %d\nCurrent coins: %d\n", *hearts, *coins);
                break;
            } else {
                printf("\nYou should try getting more coins.\n");
                break;
            }
        case 3:
            if (*coins >= 300){
                *hearts += 20;
                *coins -= 300;
                printf("\nYou bought a strong hearts potion! Current hearts: %d\nCurrent coins: %d\n", *hearts, *coins);
                break;
            } else {
                printf("\nYou should try getting more coins.\n");
                break;
            }
        case 0:
            break;
            
        default:
            printf("\nPlease, type a valid number!\n");
        }

    } while (answer != 0);
}

int main() {

    srand(time(NULL));

    welcome();

    struct character Player;
    Player.hearts = 10;
    Player.coins = 0;
    Player.xp = 0;

    while (1) {
        switch (openDoor()) {
            case 0:
                return 0;
            case 1:
                kickDoor();
                getCoins(&Player.coins);
                switch (fightEnemy()) {
                    case 1:
                        fight(&Player.hearts, &Player.xp);
                        if (checkHearts(Player)){
                            continue;
                        } else {
                            int random_number = rand() % 5;
                            separator();
                            switch (random_number) {
                                case 0:
                                    printf("\n********** You die. Your legend ends here... **********\n");
                                    separator();
                                    return 0;
                                case 1:
                                    printf("\n********** You die. The dungeon claims another soul. **********\n");
                                    separator();
                                    return 0;
                                case 2:
                                    printf("\n********** Game Over - better luck next time! **********\n");
                                    separator();
                                    return 0;
                                case 3:
                                    printf("\n********** You die. Your courage was not enough today. **********\n");
                                    separator();
                                    return 0;
                                case 4:
                                    printf("\n********** You die. Your adventure ends here... **********\n");
                                    separator();
                                    return 0;
                            }
                        }
                        break;
                    case 2:
                        loseCoins(&Player.coins);
                        break;
                    case 3:
                        return 0;
                    default:
                        printf("Type a valid number!");
                        break;
                }
            
            case 2:
                continue;
            case 3:
                showStats(Player);
                break;
            case 4:
                store(&Player.hearts, &Player.coins);
                break;
            default:
                printf("\nType a valid number!\n");
        }
        }

    return 0;
}