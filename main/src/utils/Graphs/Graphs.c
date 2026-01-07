/* Graphs.c */
#include "../../include/utils/Graphs/Graphs.h"
#include "../../include/utils/err_manager.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

Point2D* pt_random_shuffle(Point2D* dynamic_arr, int len){
    if (len <= 0)
        ERR_TERROR("length not enough (too short value, close or eq to 0)");
    Point2D** temp=&dynamic_arr; // duplicate ? (must be true)
    Point2D* tem;
    int i=0,j;
    while(i < len-1){
        j = rand()%(i+1);
        tem = temp[i];
        temp[i] = temp[j];
        temp[j] = tem;
        i++;
    }
    return *temp;
}

char** pt_generate_DFS_maze(
 int matr_lines, int matr_cols, Point2D start, Point2D stop){
    // construction d'une matrice avec que des murs
    char** matr = (char**)malloc(sizeof(char*)*matr_lines);
    Point2D current_p = start;
    Point2D end_p = stop;    
    if (!matr) {
        perror("malloc matr");
        return NULL;
    }
    bool visited[matr_lines*matr_cols];    
    for (unsigned int i = 0; i < matr_lines; i++){
        matr[i] = (char*) malloc (sizeof(char)*matr_cols);
        for (unsigned int j = 0; j < matr_cols; j++){
            matr[i][j] = '1'; // 1 = murs; 0 = passage
            visited[j+i*matr_cols] = false;
        }
    }
    return __pt_generate_DFS_maze_rec(
        matr, matr_lines, matr_cols, current_p, end_p, visited
    );
}

char** __pt_generate_DFS_maze_rec(char** matr,
 int matr_lines, int matr_cols, Point2D start, Point2D stop,
 bool visitedCoors[]){
    int idx = start.x + start.y * matr_cols;
    visitedCoors[idx] = true;
    matr[start.x][start.y] = '0';
    if (start.x == stop.x && start.y == stop.y)
        return matr;

    Point2D directions[4] = {{0,-1},{0,1},{-1,0},{1,0}};
    /* mélange aléatoire des directions */
    for (int i = 3; i > 0; i--) {
        int j = rand() % (i + 1);
        Point2D tmp = directions[i];
        directions[i] = directions[j];
        directions[j] = tmp;
    }

    for (int i = 0; i < 4; i++) {
        Point2D next = {
            start.x + directions[i].x,
            start.y + directions[i].y
        };

        /* bornes */
        if (next.x < 0 || next.x >= matr_lines ||
            next.y < 0 || next.y >= matr_cols)
            continue;

        int next_idx = next.x + next.y * matr_cols;
        if (visitedCoors[next_idx]) continue;

        __pt_generate_DFS_maze_rec(
            matr, matr_lines, matr_cols,
            next, stop, visitedCoors
        );
    }
    return matr;
}


// end page