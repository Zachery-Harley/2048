/* 
 * File:   main.c
 * Author: zachery
 *
 * Created on 14 October 2016, 13:11
 * 
 * Created while learning C, the project is a console
 * based  version of the popular 2048 game where the goal
 * it to make the total 2048 by combining the number together
 * by shifting the grid.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */


/* This will take the table and randomly generate the number 2
 * in a random location, it will attempt random 5 times, then it
 * will check each cell for a free space, and add it there.
 * 
 * Returns 1 if a space was found,
 * Returns 0 is 2 was not added to the table
 */
int randomeGenTwo(int table[4][4]){
    int x, y;
    
    /*Try 5 times to get a random spot for the 2*/
    for(int i = 0; i < 5; i++){
        x = rand() % 4;
        y = rand() % 4;
        /*Check the cell is free*/
        if(table[x][y] == 0){
            /*Set the position to 2*/
            table[x][y] = 2;
            return 1;
        }
    }
    
    /*Go through and add 2 to the first place found*/
    for(int x = 0; x < 4; x++){
        for(int y = 0; y < 4; y++){
            /*Check the cell is free*/
            if(table[x][y] == 0){
                /*Set the position to 2*/
                table[x][y] = 2;
                return 1;
            }
        }
    }
    
    /*Not possible to add*/
    return 0;
}

void initTable(int table[4][4]){
    for(int x = 0; x < 4; x++){
        for(int y = 0; y < 4; y++){
            /*Check the cell is free*/
            table[x][y] = 0;
        }
    }
}

void printTable(int table[4][4]){
    /*Loop through all values*/
    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){
            char cell[4] = "";
            sprintf(cell, "%d", table[x][y]);/*Convert the table too a string*/
            
            switch(strlen(cell)){
                case 1:
                    printf("[  %s ]", cell);
                    break;
                case 2:
                    printf("[ %s  ]", cell);
                    break;
                case 3:
                    printf("[%s ]", cell);
                    break;
                case 4:
                    printf("[%s ]", cell);
                    break;
                default:
                    printf("Something went wrong!");
            }
            /*End of switch*/
        }
        /*End of the y loop go down a line*/
        printf("\n");
    }
    
}

int isFree(int table[4][4],int x,int y){
    if(table[x][y] == 0)
        return 1;
    else
        return 0;
}



int main(int argc, char** argv) {
    /*Create a 2D array to store the table inside of*/
    int table[4][4];
    
    /*Init the table*/
    initTable(table);
    randomeGenTwo(table);
    randomeGenTwo(table);
    
    
    int option = 0;
    do{
        printf("\n\n\n\n\n\n\n\n");
        printTable(table);
        printf("Up:8, Down:2, Left:4, Right:6, Quit:9 ::");
        scanf("%d", &option);
        
        switch(option){
            case 8:
                shiftAllUp(table);
                break;
            case 2:
                shiftAllDown(table);
                break;
            case 4:
                shiftAllLeft(table);
                break;
            case 6:
                shiftAllRight(table);
                break;
        }
        
        printTable(table);
        randomeGenTwo(table);
        
    }while(option != 9);
    return (EXIT_SUCCESS);
}



