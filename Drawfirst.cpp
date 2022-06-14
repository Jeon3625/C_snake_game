#include "snake.h"
void snake::Drawfirst(int i){
    std::ifstream readFile;
    string src = "map" + to_string(i) + ".txt";

    readFile.open(src);
    int h = 0;

    while (!readFile.eof())
    {
        char temp[240];
        readFile.getline(temp, 240);

        for (int i = 0; i < strlen(temp); i++)
        {
            data1[h][i] = temp[i];
            if(temp[i] == '1'){
                gatelistx.push_back(h);
                gatelisty.push_back(i);
            }
        }

        h++;
    }
}