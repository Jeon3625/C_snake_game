#include "snake.h"
void snake :: Setup()
{
    srand(time(NULL));
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    start = time(NULL);
    gameOver = false;
    dir = STOP;
    y = width / 2;
    x = height / 2;
    nTail=2;
    TailX[0] = x;
    TailY[0] = y+1;
    TailX[1] = x;
    TailY[1] = y+2;
    Gatecount = 0;

    GrowItemx = (rand() % (height-7)) + 5;
    GrowItemy = (rand() % (width-7)) + 5;
    while(data1[GrowItemx][GrowItemy] == '1'){
        GrowItemx = (rand() % (height-7)) + 5;
        GrowItemy = (rand() % (width-7)) + 5;
    }
        
        
    PosionGrowItemx = (rand() % (height-7)) + 5;
    PosionGrowItemy = (rand() % (width-7)) + 5;
    while(data1[PosionGrowItemx][PosionGrowItemy] == '1'){
        PosionGrowItemx = (rand() % (height-7)) + 5;
        PosionGrowItemy = (rand() % (width-7)) + 5;
    }

    gatepushcount = 0;
    Gate1X = Gate1Y = Gate2X = Gate2Y = 500; 

    Growcount   = 0;
    Posioncount = 0;

    //Score Board

    Count_Growth_item = 0;
    Count_Poison_item = 0;
    Count_Used_Gate =0;
    // Mission
    Goal_len = 5;
    Goal_Growth_item = 5;
    Goal_Posion_item = 1;
    Goal_Used_Gate = 1;

    // Mission Check
    Check_len = 'X';
    Check_Growth_item = 'X';
    Check_Posion_item ='X';
    Check_Used_Gate = 'X';
}