//  Created by Hande Erdal on 15.02.2022.
/*
Craps
Rules:
 ▪ Two six-sided dice are thrown
 ▪ The sum of the dice is calculated
 ▪ If a 7 or 11 is rolled on the first roll, the player wins
 ▪ If 2, 3 or 12 is rolled on the first roll, the player loses
 ▪ If the first throw is 4,5,6,8,9,10, this is the player's score
 ▪ The player must reach his own score before rolling a 7
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char * argv[]) {
    int dice1=0,dice2=0,firstRoll=0;
    srand(time(NULL));
    dice1=1+rand()%6;
    dice2=1+rand()%6;
    printf("First dice %d,second dice %d.\n",dice1,dice2);
    firstRoll=dice1+dice2;
    
    if (firstRoll==7 || firstRoll==11)
        printf("Congrats you won\n");
    else if(firstRoll==2 || firstRoll==3 || firstRoll==12)
        printf("Unfortunately you lost\n");
    else
    {
        int lastRoll=0,score=dice1+dice2;
        printf("Your score %d.You will roll the dice again.\n",score);
        while (lastRoll!=7 && lastRoll!=score) {
            dice1=1+rand()%6;
            dice2=2+rand()%6;
            printf("Your dices are; %d ve %d\n",dice1,dice2);
            lastRoll=dice1+dice2;
            if(lastRoll==7)
                printf("Sorry not this time.\n");
            else if(lastRoll==score)
                printf("Congratss!!.\n");
            else
                printf("Lets keep rolling the dice\n");
        }
    }
        
    
    
    return 0;
}
