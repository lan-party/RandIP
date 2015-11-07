#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randInt(int min, int max, int token){
    srand(token);
    return rand() % max + min;
}

bool validIP(int ip[4]){
    bool test = 1;
    int c = 0;
    int excepts[][4] = {{0, 0, 0, 0},
                       {255, 255, 255, 255},
                       {127, 0, 0, 1}};
    int exceptr[][4] = {{10, 0, 0, 0},
                        {10, 255, 255, 255},
                        {172, 16, 0, 0},
                        {172, 31, 255, 255},
                        {192, 168, 0, 0},
                        {192, 168, 255, 255}};

    for(int a=0; a <=sizeof excepts / sizeof excepts[0]; a++){
        c = 0;
        for(int b=0; b <= 3; b++){
            if(ip[b] == excepts[a][b]){
                c++;
            }
        }
        if(c == 4){
            test = 0;
        }
    }

    for(int a=0; a <= sizeof exceptr / sizeof exceptr[0] / 2; a+=2){
        c = 0;
        for(int b=0; b <= 3; b++){
            if(ip[b] >= exceptr[a][b] && ip[b] <= exceptr[a+1][b]){
                c++;
            }
        }
        if(c == 4){
            test = 0;
        }
    }
    return test;
}

int main(int argc, char * argv[])
{
    int block[4];
    bool test=0;

    while(test == 0){
        for(int a=0; a <= 3; a++){
            block[a] = randInt(0, 255, time(NULL)+block[a]);
        }
        if(validIP(block)){
            test = 1;
        }
    }

    std::cout << block[0] << "."
              << block[1] << "."
              << block[2] << "."
              << block[3] << std::endl;
}
