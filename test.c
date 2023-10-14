#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <Windows.h>

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

int pos[2] = {5, 2};
int dir[2] = {1, 0};
int mapSize[2] = {10, 5};

void update(){
    clear();
    printf("enter e to exit the game\n");
    for (int y = 0; y<mapSize[1]; y++){
        for(int x = 0; x<mapSize[0]; x++){
            pos[0] == x && pos[1] == y ? printf("X") : printf("#");
        }
        printf("\n");
    }
    pos[0] = pos[0]+dir[0]>=mapSize[0] ? 0 : (pos[0]+dir[0]<0 ? mapSize[0]-1:pos[0]+dir[0]);
    pos[1] = pos[1]+dir[1]>=mapSize[1] ? 0 : (pos[1]+dir[1]<0 ? mapSize[1]-1:pos[1]+dir[1]);
}

int main() {
    char key;
    while(key!='e'){
        update();
        key = getchar();
        switch (key)
        {
        case 'w':
            dir[0]=0;
            dir[1]=-1;
            break;
        case 'a':
            dir[0]=-1;
            dir[1]=0;
            break;
        case 's':
            dir[0]=0;
            dir[1]=1;
            break;
        case 'd':
            dir[0]=1;
            dir[1]=0;
            break;
        default:
            break;
        }
        Sleep(700);
    }
    return 0;
}