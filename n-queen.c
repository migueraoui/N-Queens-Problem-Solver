#include <stdio.h>
#include <stdlib.h>

int** initializeTable(int n) { // By dynamic allocation for  chess table
    int** table = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        table[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            table[i][j] = 0; // Initialize all elements table with 0
        }
    }
    return table;
}


void freeTable(int** Table, int n) { //To free the dynamically allocated memory
    for (int i = 0; i < n; i++) {
        free(Table[i]);
    }
    free(Table);
}

int checkValid(int** table, int row, int col, int n){
    int i ,j;
    for (i = 0; i < col; i++) { //Checking if there is queen in same left row
        if (table[row][i] == 1) {
            return 0;
        }
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (table[i][j] == 1) { //Checking if there is queen in upper left diagonale
            return 0;
        }
    }

    for (i = row, j = col; i < n && j>= 0; i++,j--) {
        if (table[i][j] ==1) { //Checking if there is queen in down left diagonale
            return 0;
        }
    }

    return 1;
}

int replaceQueens(int** table, int col, int n) {
    //If all queens are placed so we add  current table to solutions
    if (col == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", table[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        return 1;
    }
    int countSolutions = 0;
    for (int i = 0; i < n; i++) {
        if (checkValid(table, i, col, n)) {
            table[i][col] = 1; //Recursif to place queens in the next columns
            countSolutions += replaceQueens(table, col + 1, n);
            table[i][col] = 0; // Backtrack (remove)
        }
    }
    return countSolutions;
}

int getSolutions(int n) {
    int** table = initializeTable(n);
    int countSolutions = replaceQueens(table, 0, n);
    freeTable(table, n); // Free the dynamically allocated memory
    return countSolutions;
}

void nQueens(){
    int n;
    printf("Enter  number of your queens : ");
    scanf("%d", &n);
    printf("\n");
    int countSolutions = getSolutions(n);
    if(countSolutions == 0){
        printf(" This is all possible solutions : \n");
    }else{
        printf("\n Solution number for your %d-Queens problem : %d \n", n, countSolutions);
    }
}

void main(int argc, char *argv){
    nQueens();
}
