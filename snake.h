// #include <iostream>
// #include <cstdlib>
#include <cstring>
#include <ncurses.h>
#include <fstream>
#include <time.h>
#include <vector>
using namespace std;
class snake{
public:
    bool gameOver;
    const int width = 62;
    const int height = 32;
    int x, y, GrowItemx, GrowItemy,PosionGrowItemx,PosionGrowItemy,Growcount,Posioncount;
    int Gate1X,Gate1Y,Gate2X,Gate2Y,Gatecount,gatetemp1,gatetemp2,gatepushcount;
    enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN,CEN};
    eDirection dir,OutGate1Dir,OutGate2Dir;
    clock_t start, end;
    // Score Board
    int Count_Growth_item;
    int Count_Poison_item;
    int Count_Used_Gate;

    //mision
    int Goal_len=0;
    int Goal_Growth_item;
    int Goal_Posion_item;
    int Goal_Used_Gate;
    // mission check
    char Check_len;
    char Check_Growth_item;
    char Check_Posion_item;
    char Check_Used_Gate;

    vector<int> gatelistx;
    vector<int> gatelisty;
    int TailX[100], TailY[100];
    int nTail;
    char data1[32][62];

    void Setup();
    void Drawfirst(int i);
    void Draw();
    void Input();
    void Logic();
};