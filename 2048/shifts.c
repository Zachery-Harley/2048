/*Shifts*/

int singleShiftRight(int table[4][4],int x,int y){
    int moved = 0;
    int stationary = 0;
    while(1){
        if(stationary == 1)
            break;
        stationary = 1;
        /*Check that the x is in range*/
        if(x <= 2){
            /*Read the value from the adjacent array position*/
            int adjacentPos = table[x+1][y];
            if(adjacentPos == 0){
                /*This cell is free therefor just move*/
                table[x+1][y] = table[x][y];
                table[x][y] = 0;
                moved = 1;
                stationary = 0;
            }
            else if(adjacentPos == table[x][y]){
                /*The next value is the same*/
                table[x+1][y] = table[x][y]*2;
                table[x][y] = 0;
                moved = 1;
                stationary = 0;
            }
            /*increment the x value*/
            x++;
        }
        else
            break;
    }
    /*End of the loop return moved*/
    return moved;
}

int shiftAllRight(int table[4][4]){
    int output = 0;
    for(int x = 3; x >= 0; x--){
        for(int y = 0; y < 4; y++){
            if(singleShiftRight(table, x, y)){
                output = 1;
            }
        }
    }
}

int singleShiftLeft(int table[4][4],int x,int y){
    int moved = 0;
    int stationary = 0;
    while(1){
        if(stationary == 1)
            break;
        stationary = 1;
        /*Check that the x is in range*/
        if(x >=1){
            /*Read the value from the adjacent array position*/
            int adjacentPos = table[x-1][y];
            if(adjacentPos == 0){
                /*This cell is free therefor just move*/
                table[x-1][y] = table[x][y];
                table[x][y] = 0;
                moved = 1;
                stationary = 0;
            }
            else if(adjacentPos == table[x][y]){
                /*The next value is the same*/
                table[x-1][y] = table[x][y]*2;
                table[x][y] = 0;
                moved = 1;
                stationary = 0;
            }
            /*decrement the x value*/
            x--;
        }
        else
            break;
    }
    /*End of the loop return moved*/
    return moved;
}

int shiftAllLeft(int table[4][4]){
    int output = 0;
    for(int x = 0; x < 4; x++){
        for(int y = 0; y < 4; y++){
            if(singleShiftLeft(table, x, y)){
                output = 1;
            }
        }
    }
}


int singleShiftUp(int table[4][4],int x,int y){
    int moved = 0;
    int stationary = 0;
    while(1){
        if(stationary == 1)
            break;
        stationary = 1;
        /*Check that the x is in range*/
        if(y >=1){
            /*Read the value from the adjacent array position*/
            int adjacentPos = table[x][y-1];
            if(adjacentPos == 0){
                /*This cell is free therefor just move*/
                table[x][y-1] = table[x][y];
                table[x][y] = 0;
                moved = 1;
                stationary = 0;
            }
            else if(adjacentPos == table[x][y]){
                /*The next value is the same*/
                table[x][y-1] = table[x][y]*2;
                table[x][y] = 0;
                moved = 1;
                stationary = 0;
            }
            /*decrement the y value*/
            y--;
        }
        else
            break;
    }
    /*End of the loop return moved*/
    return moved;
}

int shiftAllUp(int table[4][4]){
    int output = 0;
    for(int x = 0; x < 4; x++){
        for(int y =3; y >=0; y--){
            if(singleShiftUp(table, x, y)){
                output = 1;
            }
        }
    }
}

int singleShiftDown(int table[4][4],int x,int y){
    int moved = 0;
    int stationary = 0;
    while(1){
        if(stationary == 1)
            break;
        stationary = 1;
        /*Check that the x is in range*/
        if(y <=2){
            /*Read the value from the adjacent array position*/
            int adjacentPos = table[x][y+1];
            if(adjacentPos == 0){
                /*This cell is free therefor just move*/
                table[x][y+1] = table[x][y];
                table[x][y] = 0;
                moved = 1;
                stationary = 0;
            }
            else if(adjacentPos == table[x][y]){
                /*The next value is the same*/
                table[x][y+1] = table[x][y]*2;
                table[x][y] = 0;
                moved = 1;
                stationary = 0;
            }
            /*increment the y value*/
            y++;
        }
        else
            break;
    }
    /*End of the loop return moved*/
    return moved;
}

int shiftAllDown(int table[4][4]){
    int output = 0;
    for(int x = 0; x < 4; x++){
        for(int y = 3; y >= 0; y--){
            if(singleShiftDown(table, x, y)){
                output = 1;
            }
        }
    }
}


