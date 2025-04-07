Homework
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS_A 2
#define COLS_A 3
#define ROWS_B 3
#define COLS_B 2

void printMatrix(int matrix[ROWS_A][COLS_A], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int matrix[ROWS_A][COLS_A], int transposed[COLS_A][ROWS_A], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    srand(time(0)); 

    
    int A[ROWS_A][COLS_A];
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_A; j++) {
            A[i][j] = rand() % 10; 
        }
    }

    
    int B[ROWS_B][COLS_B];
    for (int i = 0; i < ROWS_B; i++) {
        for (int j = 0; j < COLS_B; j++) {
            B[i][j] = rand() % 10; // 0-9 arası rastgele sayılar
        }
    }

    
    printf("Matris A (2x3):\n");
    printMatrix(A, ROWS_A, COLS_A);
    
    printf("Matris B (3x2):\n");
    printMatrix(B, ROWS_B, COLS_B);

    
    printf("Toplama işlemi mümkün değil (2x3 + 3x2)\n");

    
    int C[ROWS_A][COLS_B] = {0}; // 2x2 matris
    for (int i = 0; i < ROWS_A; i++) {
        for (int j = 0; j < COLS_B; j++) {
            for (int k = 0; k < COLS_A; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    
    printf("Matris A ve B'nin çarpımı (C = A * B):\n");
    printMatrix(C, ROWS_A, COLS_B);

    
    int transposedA[COLS_A][ROWS_A];
    int transposedB[COLS_B][ROWS_B];

    transposeMatrix(A, transposedA, ROWS_A, COLS_A);
    transposeMatrix(B, transposedB, ROWS_B, COLS_B);

    
    printf("Matris A'nın transpozu:\n");
    printMatrix(transposedA, COLS_A, ROWS_A);

    printf("Matris B'nin transpozu:\n");
    printMatrix(transposedB, COLS_B, ROWS_B);

    return 0;
}
