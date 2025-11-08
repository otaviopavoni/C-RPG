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
    int level;
    int defense_boost;
};

char* tips[] = {
    "\nTip: Buy potions before you're low on health!\n",
    "\nTip: Running costs coins, but saves hearts!\n",
    "\nTip: The more you fight, the more XP you get!\n",
    "\nTip: Explore many doors to find treasures!\n"
};

void separator() {
    printf("\n========================================================================================\n");
}

void welcome() {
    separator();
    printf("\nWelcome to C-RPG. This is intended to be a simple, fast and fun terminal game for RPG fans.\nHere you'll create your own story by opening doors of a dungeon, collecting coins, buying armour and slashing monsters.\n\nWe wish you good luck!\n");
    printf("%s", tips[rand() % 4]);
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
        separator();
        printf("\nYou kick the door to the ground!");
    } else if (random_number <= 50 && random_number > 25) {
        separator();
        printf("\nYou slightly open a door!");
    } else if (random_number <= 75 && random_number > 50) {
        separator();
        printf("\nYou slash another door to the ground!");
    } else {
        separator();
        printf("\nYou explode the door!");
    }
}

void getCoins(int *coins) {
    int random_number = rand() % 100;
    *coins += random_number;
    printf("\nYou found %d coins!\n", random_number);
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

char* enemy_types[] = {"Goblin", "Skeleton", "Orc", "Zombie"};

void encounterEnemy() {
    printf("\nA wild %s appears!", enemy_types[rand() % 4]);
}

void fight(int *hearts, int *xp, int *defense_boost) {
    int random_number = rand() % 5;
    *xp += random_number;

    separator();

    encounterEnemy();

    int damage = (rand() % 3 + 1) - (*defense_boost / 4);
    if (damage < 0) damage = 0;
    *hearts -= damage;

    switch (random_number) {
        case 0:
            printf("\nMonsters roared, spells blazed—the dungeon trembled as victory screamed through dust.");
            break;
        case 1:
            printf("\nBlades flashed, monsters fell—echoes of courage rang through the shadowed crypt.");
            break;
        case 2:
            printf("\nFire rained—only steel and will kept the heroes standing tall.");
            break;
        case 3:
            printf("\nZombies swarmed, armour cracked—yet one sword's light cut through the endless night.");
            break;
        case 4:
            printf("\nSteel clashed, dragons roared—heroes rose from fire and fury, armour blazing, victory claimed.");
            break;
    }
    
    printf("\n\nYou lost %d hearts as you tried to fight!\n", damage);
    printf("You won %d XP as you tried to fight!\n", random_number);
}

void showStats(struct character p) {
    separator();
    printf("\nHearts: %d\n", p.hearts);
    printf("Coins: %d\n", p.coins);
    printf("XP: %d\n", p.xp);
    printf("Level: %d\n", p.level);
    printf("Defense boost: %d\n", p.defense_boost);
}

int checkHearts(struct character p) {
    if (p.hearts <= 0) {
        return 0;
    } else {
        return 1;
    }
}

void store(int *hearts, int *coins, int *defense_boost){
    separator();
    printf("\nWelcome to the store! Where your dreams come true!\n");
    separator();
    printf("\nWEAK HEARTS POTION (restores 5 hearts) - 50 coins\n");
    printf("\nHEARTS POTION (restores 10 hearts) - 150 coins\n");
    printf("\nSTRONG HEARTS POTION (restores 20 hearts) - 300 coins\n");
    separator();
    printf("\nWEAK DEFENSE BOOST (defense boost +5) - 100 coins\n");
    printf("\nDEFENSE BOOST (defense boost +10) - 500 coins\n");
    printf("\nSTRONG DEFENSE BOOST (defense boost +15) - 1000 coins\n");
    printf("\nNote: to maintain the challenge, you're limited to only 15 defense boost!\n");
    separator();

    int answer = 0;

    do {
        
        printf("\nDo you want to buy something from the store?\n");
        separator();
        printf("\nHEARTS POTIONS\n\n");
        printf("1 for WEAK HEARTS POTION /\n2 for HEARTS POTION /\n3 for STRONG HEARTS POTION\n");
        separator();
        printf("\nDEFENSE BOOST POTIONS\n\n");
        printf("4 for WEAK DEFENSE BOOST\n5 for DEFENSE BOOST\n6 for STRONG DEFENSE BOOST\n0 for NO /\n");
        separator();
        printf("\n");
        scanf("%d", &answer);

        switch (answer) {
        case 1:
            if (*coins >= 50){
                *hearts += 5;
                *coins -= 50;
                printf("\nYou bought a weak hearts potion! Current hearts: %d\nCurrent coins: %d\n", *hearts, *coins);
                break;
            } else {
                printf("\n********** You should try getting more coins. **********\n");
                break;
            }
        case 2:
            if (*coins >= 150){
                *hearts += 10;
                *coins -= 150;
                printf("\nYou bought a hearts potion! Current hearts: %d\nCurrent coins: %d\n", *hearts, *coins);
                break;
            } else {
                printf("\n********** You should try getting more coins. **********\n");
                break;
            }
        case 3:
            if (*coins >= 300){
                *hearts += 20;
                *coins -= 300;
                printf("\nYou bought a strong hearts potion! Current hearts: %d\nCurrent coins: %d\n", *hearts, *coins);
                break;
            } else {
                printf("\n********** You should try getting more coins. **********\n");
                break;
            }
        case 4:
            if (*coins >= 100) {
                if (*defense_boost < 15) {
                    *defense_boost += 5;
                    *coins -= 100;
                    printf("\nYou bought a weak defense boost! Current defense boost: %d\nCurrent coins: %d\n", *defense_boost, *coins);
                } else {
                    printf("\nYou just reach the maximum amount of defense boost (15)!\n");
                }
                    
            } else {
                printf("\n********** You should try getting more coins. **********\n");
                break;
            }
            break;
        
        case 5:
            if (*coins >= 500) {
                if (*defense_boost < 15) {
                    *defense_boost += 10;
                    *coins -= 500;
                    printf("\nYou bought a defense boost! Current defense boost: %d\nCurrent coins: %d\n", *defense_boost, *coins);
                } else {
                    printf("\nYou just reach the maximum amount of defense boost (15)!\n");
                }
                    
            } else {
                printf("\n********** You should try getting more coins. **********\n");
                break;
            }
            break;

        case 6:
            if (*coins >= 1000) {
                if (*defense_boost < 15) {
                    *defense_boost += 15;
                    *coins -= 1000;
                    printf("\nYou bought a strong defense boost! Current defense boost: %d\nCurrent coins: %d\n", *defense_boost, *coins);
                } else {
                    printf("\nYou just reach the maximum amount of defense boost (15)!\n");
                }
                    
            } else {
                printf("\n********** You should try getting more coins. **********\n");
                break;
            }
            break;            

        case 0:
            break;
            
        default:
            printf("\nPlease, type a valid number!\n");
        }

    } while (answer != 0);
}

void deathMessage() {
    int random_number = rand() % 5;
    separator();
    switch (random_number) {
        case 0:
            printf("\n********** You die. Your legend ends here... **********\n");
            separator();
            break;
        case 1:
            printf("\n********** You die. The dungeon claims another soul. **********\n");
            separator();
            break;
        case 2:
            printf("\n********** Game Over - better luck next time! **********\n");
            separator();
            break;
        case 3:
            printf("\n********** You die. Your courage was not enough today. **********\n");
            separator();
            break;
        case 4:
            printf("\n********** You die. Your adventure ends here... **********\n");
            separator();
            break;
    }
}

void checkLevelUp(struct character *p) {
    if (p->xp >= p->level * 10) {
        p->level++;
        p->hearts += 5;
        printf("\nCongrats! You've just advanced one level! Your current level: %d\n", p->level);
    }
}

void randomEvent(struct character *p) {
    if (rand() % 8 == 0) {
        printf("\nYou found a hidden treasure! +30 coins!\n");
        p->coins += 30;
    }
}

int main() {

    srand(time(NULL));

    int doors_opened = 0;

    welcome();

    struct character Player;
    Player.hearts = 10;
    Player.coins = 0;
    Player.xp = 0;
    Player.level = 1;
    Player.defense_boost = 0;

    while (1) {
        switch (openDoor()) {
            case 0:
                return 0;
            case 1:
                kickDoor();
                doors_opened++;
                printf("\nDoors opened: %d.\n", doors_opened);
                getCoins(&Player.coins);
                randomEvent(&Player);
                switch (fightEnemy()) {
                    case 1:
                        fight(&Player.hearts, &Player.xp, &Player.defense_boost);
                        checkLevelUp(&Player);
                        if (checkHearts(Player)){
                            continue;
                        } else {
                            deathMessage();
                            return 0;
                            }
                        break;
                    case 2:
                        loseCoins(&Player.coins);
                        break;
                    default:
                        printf("\nType a valid number!\n");
                        break;
                }
                break;
            
            case 2:
                continue;
            case 3:
                showStats(Player);
                break;
            case 4:
                store(&Player.hearts, &Player.coins, &Player.defense_boost);
                break;
            default:
                printf("\nType a valid number!\n");
        }
        }

    return 0;
}