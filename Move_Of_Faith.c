#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void Intro_Rules (int *ptr) ;
void Print_Arena (int *Arena , int n) ;


int main () {

    srand(time(0)) ;

    int no_of_tnt ;
    int *ptr = &no_of_tnt ;

    Intro_Rules (ptr) ;

    printf("\nYou have chosen Level %d.\n", no_of_tnt);
    printf("Hidden TNT awaits - every move from now on could be your last.\n\n");

    // Taking Two Players Name 

    char Player_1[50] , Player_2[50] ;

    printf("\nTwo players will enter the Deadly Arena.\n");
    printf("Enter the name of Player 1: ");
    scanf("%49s", Player_1);

    printf("\nEnter the name of Player 2: ");
    scanf("%49s", Player_2);

    printf("\n%s and %s, your fate is now bound to the ground beneath you.\n", Player_1, Player_2);
    printf("Only one of you will rise above the other.\n");

    // -------------Over-------------

    int Arena[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16} ;
    int TNT[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16} ;

    int P1_Score = 0 , P2_Score = 0 ;

    // Shuffeling TNT Location For Player 1

    int n , x ; // Here x is Temp Variable & can be used to store values temperorly in the code in future too

    // Fisher–Yates Method To Shuffel Array

    for(int i = 15 ; i >= 0 ; i--) {

        n = (rand() % (i + 1)) ;

        x = TNT[i] ;
        TNT[i] = TNT[n] ;
        TNT[n] = x ;

    }
    
    // -------------Over-------------

    // -------------Over-------------

    int die = -100 ; // marks players death {-100 is any random value nothing to do}

    // Player 1 Turn Begains

    int r = 1 ; // r = round

    printf("\n%s, step forward. Your turn begins now.\n", Player_1);
    printf("Choose your moves wisely.\n");

    for(int k = 1 ; k <= 16 ; k++) {

        Print_Arena (Arena , 16) ;

        printf("Make your move. Choose a square to step on warrior: ");
        scanf("%d" , &x) ;

        while (x < 1 || x > 16 || Arena[x-1] == 0) {

            printf("Invalid move!\n");
            printf("Make your move. Choose a square to step on warrior: ");
            scanf("%d", &x);

        }

        for(int i = 0 ; i < no_of_tnt ; i++) {

            if(TNT[i] == x) { // checks the location is TNT or not

                die = 1 ;

                for(int j = 0 ; j < no_of_tnt ; j++) {

                    Arena[TNT[j]-1] = -1 ;

                }

                P1_Score -= (int) (round(0.35 * P1_Score)) ;

                Print_Arena (Arena , 16) ;

                printf("\nBOOM! You stepped on TNT!\n");
                printf("Final Score: %d\n", P1_Score);

                printf("\n#---  THE ARENA SPEAKS  ---#\n");
                printf("You stepped forward... and the arena has claimed its victim.\n");
                printf("A deafening blast shakes the ground. Your journey ends here.\n\n");

                printf("As the dust settles, strange patterns (-1) emerge across the battlefield...\n");
                printf("Squares glow faintly - but beware: these are not confirmations.\n");
                printf("They are **probability echoes**, hints of where danger could have been, or might still be.\n");
                printf("No square is truly safe, and no square reveals the full truth.\n\n");

                printf("#--- Probability Density of Deadly Zones ---#\n");
                printf("The arena whispers these numbers to your mind:\n");
                printf("These numbers are NOT exact TNT locations.\n");
                printf("They represent where danger could have been... \n");
                printf("No one knows the true locations - and till today, no one ever will.\n");
                printf("Your step may have been fateful, but the arenas secrets remain unsolved.\n");
                printf("Game Over. \n\nThe Deadly Arena never tells the truth.\n\n");

                break ;

            }

        }

        if(die == 1) {

            break ;

        }

        P1_Score += (r*100) ; // If not then incresed the point in Arena Array
        Arena[x-1] = 0 ;

        printf("Safe square!\n");
        printf("You survived this move.\n");
        printf("Current Score: %d\n", P1_Score);

        char choice = 'z'; // choice for player to continue or not

        printf("\n  RISK WARNING  \n");
        printf("Continuing may cost you up to 35%% of your score if you hit TNT.\n");
        printf("Current Score: %d\n", P1_Score);

        printf("\nDo you want to continue or cash out?\n");
        printf("C - Continue playing (Risky)\n");
        printf("X - Cash out and secure your points\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if (choice == 'C' || choice == 'c') {

            printf("\nYou chose to continue!\n");
            printf("Higher risk... higher reward!\n\n");

        }else if (choice == 'X' || choice == 'x') {

            printf("\nYou cashed out successfully!\n");
            printf("Final Secured Score: %d\n", P1_Score);
            printf("Thanks for playing!\n");

            break ;

            // end game / break loop here

        }else {

            printf("\n  INVALID INPUT DETECTED!\n");
            printf("You entered an unauthorized option.\n");
            printf("This attempt is considered a rule violation.\n");
            printf("For game integrity, the match has been terminated.\n");
            printf("Your final score is LOCKED at: %d\n", P1_Score);
            printf("Game Over.\n\n");
                    
            break ;

        }
        
        r++ ;

    }

    // -------------Over-------------

    // Resetting The Value Of TNT[] Array

    for(int i = 0 ; i < 16 ; i++) {

        Arena[i] = (i+1) ;
        TNT[i] = (i+1) ;

    }

    // -------------Over-------------

    // Shuffeling TNT Location For Player 2

    // Fisher–Yates Method To Shuffel Array

    for(int i = 15 ; i >= 0 ; i--) {

        n = (rand() % (i + 1)) ;

        x = TNT[i] ;
        TNT[i] = TNT[n] ;
        TNT[n] = x ;

    }
    
    // -------------Over-------------

    // -------------Over-------------

    // Player 2 Turn Begains

    die = -100 ;

    r = 1 ; // r = round

    printf("\n%s, step forward. Your turn begins now.\n", Player_2);
    printf("Choose your moves wisely.\n");

    for(int k = 1 ; k <= 16 ; k++) {

        Print_Arena (Arena , 16) ;

        printf("Make your move. Choose a square to step on warrior: ");
        scanf("%d" , &x) ;

        while (x < 1 || x > 16 || Arena[x-1] == 0) {

            printf("Invalid move!\n");
            printf("Make your move. Choose a square to step on warrior: ");
            scanf("%d", &x);

        }

        for(int i = 0 ; i < no_of_tnt ; i++) {

            if(TNT[i] == x) { // checks the location is TNT or not

                die = 1 ;

                for(int j = 0 ; j < no_of_tnt ; j++) {

                    Arena[TNT[j]-1] = -1 ;

                }

                P2_Score -= (int) (round(0.35 * P2_Score)) ;

                Print_Arena (Arena , 16) ;

                printf("\nBOOM! You stepped on TNT!\n");
                printf("Final Score: %d\n", P2_Score);

                printf("\n#---  THE ARENA SPEAKS  ---#\n");
                printf("You stepped forward... and the arena has claimed its victim.\n");
                printf("A deafening blast shakes the ground. Your journey ends here.\n\n");

                printf("As the dust settles, strange patterns (-1) emerge across the battlefield...\n");
                printf("Squares glow faintly - but beware: these are not confirmations.\n");
                printf("They are **probability echoes**, hints of where danger could have been, or might still be.\n");
                printf("No square is truly safe, and no square reveals the full truth.\n\n");

                printf("#--- Probability Density of Deadly Zones ---#\n");
                printf("The arena whispers these numbers to your mind:\n");
                printf("These numbers are NOT exact TNT locations.\n");
                printf("They represent where danger could have been... \n");
                printf("No one knows the true locations - and till today, no one ever will.\n");
                printf("Your step may have been fateful, but the arenas secrets remain unsolved.\n");
                printf("Game Over. \n\nThe Deadly Arena never tells the truth.\n\n");

                break ;

            }

        }

        if(die == 1) {

            break ;

        }

        P2_Score += (r*100) ; // If not then incresed the point in Arena Array
        Arena[x-1] = 0 ;

        printf("Safe square!\n");
        printf("You survived this move.\n");
        printf("Current Score: %d\n", P2_Score);

        char choice = 'z'; // choice for player to continue or not

        printf("\n  RISK WARNING  \n");
        printf("Continuing may cost you up to 35%% of your score if you hit TNT.\n");
        printf("Current Score: %d\n", P2_Score);

        printf("\nDo you want to continue or cash out?\n");
        printf("C - Continue playing (Risky)\n");
        printf("X - Cash out and secure your points\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if (choice == 'C' || choice == 'c') {

            printf("\nYou chose to continue!\n");
            printf("Higher risk... higher reward!\n\n");

        }else if (choice == 'X' || choice == 'x') {

            printf("\nYou cashed out successfully!\n");
            printf("Final Secured Score: %d\n", P2_Score);
            printf("Thanks for playing!\n");

            break ;

            // end game / break loop here

        }else {

            printf("\n  INVALID INPUT DETECTED!\n");
            printf("You entered an unauthorized option.\n");
            printf("This attempt is considered a rule violation.\n");
            printf("For game integrity, the match has been terminated.\n");
            printf("Your final score is LOCKED at: %d\n", P2_Score);
            printf("Game Over.\n\n");
                    
            break ;

        }
        
        r++ ;

    }

    // -------------Over-------------

    // Full Game Over :- Just The Final Verdict & Comparision & Winner Delecration

    printf("\n\n========== THE FINAL VERDICT ==========\n\n");

    if(P1_Score > P2_Score) {

        printf("%s rises from the ashes of fallen warriors!\n", Player_1);
        printf("With cunning and courage, %s outshines %s by %d points!\n", Player_1, Player_2, P1_Score - P2_Score);
        printf("The Deadly Arena, built upon the tombs of many, claims no mercy but marks the one who outlasted the rest.\n");

    } else if(P2_Score > P1_Score) {

        printf("%s conquers the Deadly Arena!\n", Player_2);
        printf("Against all peril, %s triumphs over %s by %d points!\n", Player_2, Player_1, P2_Score - P1_Score);
        printf("The Deadly Arena, built upon the tombs of many, claims no mercy but marks the one who outlasted the rest.\n");

    } else {
        printf("Both warriors fall in equal measure!\n");
        printf("%s and %s earned %d points each, yet the Deadly Arena demands no pause, no mercy.\n", Player_1, Player_2, P1_Score);
        printf("Its tombstones whisper the fates of all who dared step here.\n");
    }

    printf("\n#--- The MOVE OF FATE ends, but the Deadly Arena endures forever. ---#\n\n");

    // -------------Over-------------

    return 0 ;

}

void Intro_Rules (int *ptr) {

    printf("\n========================================\n");
    printf("           WELCOME TO MOVE OF FATE\n");
    printf("========================================\n\n");

    printf("Two fearless players enter.\n");
    printf("Every move forward is a gamble - rewards grow, but so does danger.\n\n");

    printf("Hidden TNT waits to punish the reckless.\n");
    printf("One wrong step can cost you dearly.\n\n");

    printf("Survive, take risks, and outscore your opponent.\n");
    printf("Only one player will claim victory in this arena.\n\n");

    printf("Brace yourselves. The deadly challenge begins now...\n\n");

    printf("============= How to Play =============\n\n");

    printf("You will enter a deadly ground divided into 16 parts.\n");
    printf("Some parts are safe, while a few contain bombs (TNT).\n\n");

    printf("To move, simply enter the address of the square you want to step on.\n\n");

    printf("Each time you step on a safe area, you earn points.\n");
    printf("Every next safe move gives you more points than the previous one.\n\n");

    printf("Be careful! If you step on a TNT, the game ends immediately.\n\n");

    printf("After every correct move, you will be given a choice:\n");
    printf("1. Continue playing and earn more points.\n");
    printf("2. End the game and cash out your points.\n\n");

    printf("The decision is yours.\n");
    printf("Step wisely... one wrong move can end everything!\n");

    printf("\n========== MOVE REWARDS ==========\n\n");

    printf("Move  1  :-  Earn  100 points  (Safe start)\n");
    printf("Move  2  :-  Earn  200 points\n");
    printf("Move  3  :-  Earn  300 points\n");
    printf("Move  4  :-  Earn  400 points\n");
    printf("Move  5  :-  Earn  500 points  (Risk begins to rise)\n");

    printf("\n");

    printf("Move  6  :-  Earn  600 points\n");
    printf("Move  7  :-  Earn  700 points\n");
    printf("Move  8  :-  Earn  800 points\n");
    printf("Move  9  :-  Earn  900 points  (Danger zone)\n");

    printf("\n");

    printf("Move 10  :-  Earn 1000 points\n");
    printf("Move 11  :-  Earn 1100 points\n");
    printf("Move 12  :-  Earn 1200 points  (High risk!)\n");

    printf("\n");

    printf("Move 13  :-  Earn 1300 points\n");
    printf("Move 14  :-  Earn 1400 points\n");
    printf("Move 15  :-  Earn 1500 points  (LEGENDARY MOVE!)\n");

    printf("\n=================================\n");
    printf("Each move increases both risk and reward.\n");
    printf("You may cash out after any safe move.\n");
    printf("Greed can be rewarding - or deadly.\n");

    printf("\n========== TNT PENALTY ==========\n\n");

    printf("Hidden among the ground are deadly TNT tiles.\n");
    printf("Stepping on a TNT ends the game instantly.\n\n");

    printf("If a TNT is triggered:\n");
    printf("::-- 35%% of your total points will be deducted.\n");
    printf("::-- The game will end immediately.\n\n");

    printf("The further you move, the more painful the loss becomes.\n");
    printf("Greed can cost you everything.\n");

    printf("\n========================================\n");
    printf("        WELCOME TO THE DEADLY ARENA\n");
    printf("========================================\n\n");

    printf("This is a two-player survival game.\n");
    printf("Both players will enter a deadly ground filled with hidden TNT.\n");
    printf("Every move forward increases both the reward and the danger.\n\n");

    printf("Each safe move earns points.\n");
    printf("The further you go, the more valuable each move becomes.\n");
    printf("But one wrong move can cost you dearly.\n\n");

    printf("Hidden TNT tiles can end your run instantly.\n");
    printf("Triggering a TNT will deduct 35%% of your total points.\n");
    printf("Once a TNT is triggered, the game ends for that player.\n\n");

    printf("Each player may choose to stop and cash out after any safe move.\n");
    printf("Greed may lead to glory - or total loss.\n\n");

    printf("When both players have finished their turns\n");
    printf("their total points will be compared.\n");
    printf("The player with the highest score will be declared the WINNER.\n\n");

    printf("Choose your moves wisely.\n");
    printf("This arena shows no mercy.\n\n");

    printf("\n==================== CHOOSE YOUR LEVEL ====================\n\n");

    printf("The Deadly Arena awaits, but danger increases with your ambition.\n");
    printf("Each level has hidden TNT, and the higher the level, the greater the risk -\n");
    printf("but the rewards value grows as well.\n\n");

    printf("Level selection:\n\n");

    printf("Level 1  -  1 TNT  (Easy, safe start)\n");
    printf("Level 2  -  2 TNT\n");
    printf("Level 3  -  3 TNT\n");
    printf("Level 4  -  4 TNT\n");
    printf("Level 5  -  5 TNT  (Noticeable risk begins)\n");
    printf("Level 6  -  6 TNT\n");
    printf("Level 7  -  7 TNT\n");
    printf("Level 8  -  8 TNT  (Half the arena is deadly!)\n");
    printf("Level 9  -  9 TNT\n");
    printf("Level 10 - 10 TNT  (High-risk zone)\n");
    printf("Level 11 - 11 TNT\n");
    printf("Level 12 - 12 TNT  (Most squares are deadly!)\n");
    printf("Level 13 - 13 TNT\n");
    printf("Level 14 - 14 TNT  (Only a few safe squares left!)\n");
    printf("Level 15 - 15 TNT  (LEGENDARY RISK - almost everything is TNT!)\n\n");

    printf("Choose wisely - the higher the level, the higher the rewards, but one misstep can cost you dearly.\n");
    printf("The arena shows no mercy.\n\n");

    printf("Choose your deadly challenge! Enter a level (1-15) - the higher the level, the greater the risk and reward: ");
    scanf("%d", ptr);

    while(*ptr < 1 || *ptr > 15) {

        printf("\n\nlevel %d Comming Soon...\n\n" , *ptr) ;
        printf("Choose your deadly challenge! Enter a level (1-15) - the higher the level, the greater the risk and reward: ");
        scanf("%d", ptr);

    }

}

void Print_Arena (int *Arena , int n) {

    printf("\n========== DEADLY GROUND ==========\n\n");

    printf("+----+----+----+----+\n");
    printf("|  %d |  %d |  %d |  %d |\n" , Arena[0] , Arena[1] , Arena[2] , Arena[3]);
    printf("+----+----+----+----+\n");
    printf("|  %d |  %d |  %d |  %d |\n" , Arena[4] , Arena[5] , Arena[6] , Arena[7]);
    printf("+----+----+----+----+\n");
    printf("|  %d | %d | %d | %d |\n" , Arena[8] , Arena[9] , Arena[10] , Arena[11]);
    printf("+----+----+----+----+\n");
    printf("| %d | %d | %d | %d |\n" , Arena[12] , Arena[13] , Arena[14] , Arena[15]);
    printf("+----+----+----+----+\n");

    printf("\n\n") ;

}