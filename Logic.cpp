#include "snake.h"
void snake::Logic() {
    if(dir != STOP)
    {



        if(x == Gate1X && y == Gate1Y || x == Gate2X && y == Gate2Y)
        {
            Count_Used_Gate++;
            gatepushcount = nTail;
            int prevX;
            int prevY;
            int prev2X, prev2Y;
            
            if(x ==  Gate1X && y == Gate1Y){
                
                x = Gate2X;
                y = Gate2Y;

                switch(dir){
                    case LEFT:
                        if(data1[x][y-1]==' ') dir  = LEFT;
                        else if(data1[x-1][y]==' ') dir = UP;
                        else if(data1[x+1][y]==' ') dir = DOWN;
                        else dir=RIGHT;
                        break;
                    case UP:
                        if(data1[x-1][y]==' ')dir = UP;
                        else if(data1[x][y+1]==' ') dir = RIGHT;
                        else if(data1[x][y-1]==' ') dir = LEFT;
                        else dir = DOWN;
                        break;
                    case DOWN:
                        if(data1[x+1][y]==' ') dir = DOWN;
                        else if(data1[x][y-1]==' ') dir = LEFT;
                        else if(data1[x][y+1]==' ') dir = RIGHT;
                        else dir = UP;
                        break;
                    case RIGHT:
                        if(data1[x][y+1]==' ') dir = RIGHT;
                        else if(data1[x+1][y]==' ') dir = DOWN;
                        else if(data1[x-1][y]==' ') dir = UP;
                        else dir=LEFT;
                        break;
                }
                prevX = TailX[0];
                prevY = TailY[0];
                TailX[0] = Gate1X;
                TailY[0] = Gate1Y;
            }
            else if(x ==  Gate2X && y == Gate2Y) {
                x = Gate1X;
                y = Gate1Y;
                switch (dir) {
                    case LEFT:
                        if (data1[x][y - 1] == ' ') dir = LEFT;
                        else if (data1[x - 1][y] == ' ') dir = UP;
                        else if (data1[x + 1][y] == ' ') dir = DOWN;
                        else dir = RIGHT;
                        break;
                    case UP:
                        if (data1[x - 1][y] == ' ') dir = UP;
                        else if (data1[x][y + 1] == ' ') dir = RIGHT;
                        else if (data1[x][y - 1] == ' ') dir = LEFT;
                        else dir = DOWN;
                        break;
                    case DOWN:
                        if (data1[x + 1][y] == ' ') dir = DOWN;
                        else if (data1[x][y - 1] == ' ') dir = LEFT;
                        else if (data1[x][y + 1] == ' ') dir = RIGHT;
                        else dir = UP;
                        break;
                    case RIGHT:
                        if (data1[x][y + 1] == ' ') dir = RIGHT;
                        else if (data1[x + 1][y] == ' ') dir = DOWN;
                        else if (data1[x - 1][y] == ' ') dir = UP;
                        else dir = LEFT;
                        break;
                
                }
                prevX = TailX[0];
                prevY = TailY[0];
                TailX[0] = Gate2X;
                TailY[0] = Gate2Y;
            }
            for (int i = 1; i < nTail; i++) {

                prev2X = TailX[i];
                prev2Y = TailY[i];
                TailX[i] = prevX;
                TailY[i] = prevY;
                prevX = prev2X;
                prevY = prev2Y;
            }
            switch (dir) {
                case LEFT:
                    y--;
                    break;
                case RIGHT:
                    y++;
                    break;
                case UP:
                    x--;
                    break;
                case DOWN:
                    x++;
                    break;
                default:
                    break;
            }
            return;
        }

        if (data1[x][y] == '1' ||  nTail <2)
            gameOver = true;



        int prevX = TailX[0];
        int prevY = TailY[0];
        int prev2X, prev2Y;
        TailX[0] = x;
        TailY[0] = y;
        for (int i = 1; i < nTail; i++) {

            prev2X = TailX[i];
            prev2Y = TailY[i];
            TailX[i] = prevX;
            TailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;

        }
        switch (dir) {
            case LEFT:
                y--;
                break;
            case RIGHT:
                y++;
                break;
            case UP:
                x--;

                break;
            case DOWN:
                x++;
                break;
            default:
                break;
        }




        //----------------------------------------------------------------
        // 커지는것과 작아지는 아이템 구현과 일정 시간이 지나면 사라지는 코드
        // 아이템이 벽이나 벽밖에 생기는 경우가 있어 rand() % (height-2)로 수정
        if ((x == GrowItemx && y == GrowItemy)) {
            Count_Growth_item++;
            Growcount =0;
            GrowItemx = (rand() % (height-7)) + 5;
            GrowItemy = (rand() % (width-7)) + 5;
            while(data1[GrowItemx][GrowItemy] == '1'){
                GrowItemx = (rand() % (height-7)) + 5;
                GrowItemy = (rand() % (width-7)) + 5;
            }
            nTail++;
        }
        else if(Growcount/40 == 1){
            Growcount =0;
            GrowItemx = (rand() % (height-7)) + 5;
            GrowItemy = (rand() % (width-7)) + 5;
            while(data1[GrowItemx][GrowItemy] == '1'){
                GrowItemx = (rand() % (height-7)) + 5;
                GrowItemy = (rand() % (width-7)) + 5;
            }
        }
        if(x==PosionGrowItemx && y == PosionGrowItemy) {
            Count_Poison_item++;
            Posioncount = 0;
            PosionGrowItemx = (rand() % (height-7)) + 5;
            PosionGrowItemy = (rand() % (width-7)) + 5;
            while(data1[PosionGrowItemx][PosionGrowItemy] == '1'){
                PosionGrowItemx = (rand() % (height-7)) + 5;
                PosionGrowItemy = (rand() % (width-7)) + 5;
            }
            nTail--;
        }
        else if(Posioncount/40 == 1){
            Posioncount = 0;
            PosionGrowItemx = (rand() % (height-7)) + 5;
            PosionGrowItemy = (rand() % (width-7)) + 5;
            while(data1[PosionGrowItemx][PosionGrowItemy] == '1'){
                PosionGrowItemx = (rand() % (height-7)) + 5;
                PosionGrowItemy = (rand() % (width-7)) + 5;
            }
        }
        
            
        Posioncount++;
        Growcount++;
        //----------------------------------------------------------------
        //----------------------------------------------------------------
        //----------------------------------------------------------------
        // 게이트 등장 로직
        if(Gatecount /50 ==1 && gatepushcount <0){
            Gatecount =0;
            gatetemp1 = rand()%gatelistx.size();
            gatetemp2 = rand()%gatelistx.size();
            if(gatetemp1 == gatetemp2)
                gatetemp2 = rand()%gatelistx.size();
            Gate1X = gatelistx[gatetemp1];
            Gate1Y = gatelisty[gatetemp1];
            Gate2X = gatelistx[gatetemp2];
            Gate2Y = gatelisty[gatetemp2];
        }
        Gatecount++;
        //----------------------------------------------------------------

        for (int i = 0; i < nTail; i++)
            if (TailX[i] == x && TailY[i] == y) {
                gameOver = true; // 수정필요
            }
    // Mission Check
        if(Check_len == 'X'){
            if(nTail+1 == Goal_len)
                Check_len = 'O';
        }
        else if(Check_len == 'O'){
            if(nTail+1 < Goal_len)
                Check_len = 'X';
        }
        if(Check_Growth_item =='X'){
            if(Count_Growth_item == Goal_Growth_item)
                Check_Growth_item ='O';
        }
        if(Check_Posion_item == 'X'){
            if(Count_Poison_item == Goal_Posion_item)
                Check_Posion_item = 'O';
        }
        if(Check_Used_Gate == 'X'){
            if(Count_Used_Gate == Goal_Used_Gate)
                Check_Used_Gate = 'O';
        }
        if(Check_Growth_item == 'O' && Check_Posion_item == 'O' && Check_Used_Gate == 'O' && Check_len == 'O'){
            gameOver = true;
        }
    }
    gatepushcount--;

}