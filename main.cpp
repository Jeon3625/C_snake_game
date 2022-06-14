#include "snake.h"
int main() {
    snake A;
    for(int i=1;i<=3;i++){
        A.Drawfirst(i);
        A.Setup();
        while (!A.gameOver) {
            A.Draw(); 
            A.Input();
            A.Logic();
        }
        if(A.Check_len != 'O' || A.Check_Growth_item != 'O'|| A.Check_Posion_item != 'O'||A.Check_Used_Gate !='O')
            break;
    }
    getch();
    endwin();
    return 0;
}