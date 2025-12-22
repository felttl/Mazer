/* Graphs.c */
#include "./Graphs.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

struct Point2D{
    int x, y;
};

enum Cell {
    c_way = 0,
    c_wall = 1,
    c_home = 2,
    c_exit = 3,
    c_visited = 7,
    c_forbiden = 8
};

Point2D* pt_random_shuffle(Point2D* dynamic_arr, int len){
    if (len <= 0){
        perror("lenght not enough (too short value, close to 0)");
        return NULL;
    }
    srand( time( NULL ) ); // init random func
    Point2D** temp=dynamic_arr;
    Point2D* tem;
    int i=0,rd,j;
    while(i < len-1){
        j = rand()%(i+1);
        tem = temp[i];
        temp[i] = temp[j];
        temp[j] = tem;
        i++;
    }
    return temp;
}

char** pt_generate_DFS_maze(
 int matr_lines, int matr_cols, Point2D start, Point2D stop){
    // construction d'une matrice avec que des murs
    char** matr = (char**)malloc(sizeof(char*)*matr_lines);
    if (!matr) {
        perror("malloc matr");
        return NULL;
    }
    for (unsigned int i = 0; i < matr_lines; i++){
        matr[i] = (char*) malloc (sizeof(char)*matr_cols);
        for (unsigned int j = 0; j < matr_cols; j++){
            matr[i][j] = '1'; // 1 = murs; 0 = passage
        }
    }
    Point2D current_p = start;
    Point2D end_p = stop;
    return Po_generate_DFS_maze_rec(
        matr, matr_lines, matr_cols, current_p, end_p
    );
}

char** pt_generate_DFS_maze_rec(char** matr,
 int matr_lines, int matr_cols, Point2D start, Point2D stop){
    // mark
    matr[start.x][start.y] = '0';
    Point2D directions[4] = {{0,-1},{0,1},{-1,0},{1,0}};

    
}


// end page