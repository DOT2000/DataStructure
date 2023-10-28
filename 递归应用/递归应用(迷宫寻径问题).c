/**
 *  @author 小粥无敌辣
 *  2023/9/26 12:34
 *  DataStructures
 */
#define SIZE 10
#include <stdio.h>

void print(int maze[][SIZE],int mazeSize,int mazeColSize){
    for (int i = 0; i < mazeSize; ++i) {
        for (int j = 0; j < mazeColSize; ++j) {
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
    printf("\n--------------------------------\n");
}

void MazePrint(int maze[][SIZE],int mazeSize,int mazeColSize,int i,int j){
    if(i == mazeSize - 1 && j == mazeColSize - 1){
        maze[i][j] = 2;
        print(maze,mazeSize,mazeColSize);
        maze[i][j] = 0;
        return;
    } else if(i < mazeSize && j < mazeColSize && i >= 0 && j >= 0 && maze[i][j] == 0) {
        maze[i][j] = 2;
        MazePrint(maze, mazeSize, mazeColSize, i + 1, j);
        MazePrint(maze, mazeSize, mazeColSize, i, j + 1);
        MazePrint(maze, mazeSize, mazeColSize, i - 1, j);
        MazePrint(maze, mazeSize, mazeColSize, i, j - 1);
        maze[i][j] = 0;
    }
}

int main(){
    int Maze[SIZE][SIZE] = {{0,1,0,0,0,0,0,0,0,0},
                            {0,1,0,0,0,0,0,0,0,0},
                            {0,1,0,0,0,0,0,0,0,0},
                            {0,0,1,0,0,1,0,1,0,0},
                            {1,0,0,1,0,0,0,1,0,0},
                            {1,1,0,1,0,0,0,1,0,0},
                            {0,1,0,1,1,1,1,0,0,0},
                            {0,1,0,0,0,0,1,0,0,0},
                            {0,1,1,1,0,0,1,1,1,1},
                            {0,0,0,0,0,0,0,0,0,0}};
    MazePrint(Maze,SIZE,SIZE,0,0);
    return 0;
}