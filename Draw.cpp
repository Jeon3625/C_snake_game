#include "snake.h"
void snake::Draw() // draw a game map
{
    clear();
    // Score Board
    mvprintw(1,width+2,"Score Board");
    mvprintw(2,width+2,"B: %d / %d",nTail+1,99);
    mvprintw(3,width+2,"+: %d",Count_Growth_item);
    mvprintw(4,width+2,"-: %d",Count_Poison_item);
    mvprintw(5,width+2,"G: %d",Count_Used_Gate);
    mvprintw(6,width+2,"Time: %d",(int)(time(NULL)-start)  );

    // Mission
    mvprintw(8,width+2,"Mission");
    mvprintw(9,width+2,"B: %d (%c)",Goal_len,Check_len);
    mvprintw(10,width+2,"+: %d (%c)",Goal_Growth_item,Check_Growth_item);
    mvprintw(11,width+2,"-: %d (%c)",Goal_Posion_item,Check_Posion_item);
    mvprintw(12,width+2,"G: %d (%c)",Goal_Used_Gate,Check_Used_Gate);

    for(int i=1;i<height-1;i++){
        for(int j=1;j<width-1;j++)
            mvprintw(i,j,"%c",data1[i][j]);
    }
    mvprintw(GrowItemx,GrowItemy,"O");
    mvprintw(PosionGrowItemx,PosionGrowItemy,"X");
    mvprintw(Gate1X,Gate1Y," ");
    mvprintw(Gate2X,Gate2Y," ");
    mvprintw(x,y,"3");
    for(int i=0;i<nTail; i++)
        mvprintw(TailX[i],TailY[i],"4");

    mvprintw(height+1, 0, "%d, %d", GrowItemx,GrowItemy);
    mvprintw(height+5, 0 ,"%d ,%d",Gate1X,Gate1Y);
    mvprintw(height+6, 0 ,"%d ,%d",Gate2X,Gate2Y);
    mvprintw(height+7, 0 ,"%d ,%d",x,y);
    mvprintw(height+8, 0 ,"%d ",gatepushcount);
    refresh();
}