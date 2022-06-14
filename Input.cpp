#include "snake.h"
void snake::Input() {

    keypad(stdscr, true);
    halfdelay(5);

    int c = getch();
    // 진행 방향과 반대 방향을 입력할경우 무시하는 코드 추가
    // 진행 방향과 반대 방향일 경우 break 를 통해 나감
    // 꼬리 방향으로 이동시 게임오버라고 나와있는건 꼬리로 갈 경우인지 꼬리가 있는 방향인지 의미가 모호
    switch (c) {
        case KEY_LEFT:
            // if(dir == RIGHT)
            //     break;
            dir = LEFT;
            break;
        case KEY_RIGHT:
            // if(dir == LEFT)
            //     break;
            dir = RIGHT;
            break;
        case KEY_UP:
            // if(dir == DOWN)
            //     break;
            dir = UP;
            break;
        case KEY_DOWN:
            // if(dir==UP)
            //     break;

            dir = DOWN;
            break;

        case 'q':
            gameOver = true;
            break;
        default:
            dir = dir;
            break;


    }

}