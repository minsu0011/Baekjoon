#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define REPEAT 100

void test_matrix_performance() {
    // === Static Matrices ===
    static int staticA[SIZE][SIZE];
    static int staticB[SIZE][SIZE];
    static int staticC[SIZE][SIZE]; // result

    // === Stack-Dynamic Matrices ===
    int stackA[SIZE][SIZE];
    int stackB[SIZE][SIZE];
    int stackC[SIZE][SIZE]; // result

    // Fill with random values (1~100)
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            staticA[i][j] = rand() % 100 + 1;
            staticB[i][j] = rand() % 100 + 1;
            stackA[i][j] = rand() % 100 + 1;
            stackB[i][j] = rand() % 100 + 1;
        }
    }

    // === Static Matrix Multiplication Timing ===
    clock_t start = clock();
    for (int r = 0; r < REPEAT; r++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                staticC[i][j] = 0;
                for (int k = 0; k < SIZE; k++) {
                    staticC[i][j] += staticA[i][k] * staticB[k][j];
                }
            }
        }
    }
    clock_t end = clock();
    double static_time = (double)(end - start) / CLOCKS_PER_SEC;

    // === Stack-Dynamic Matrix Multiplication Timing ===
    start = clock();
    for (int r = 0; r < REPEAT; r++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                stackC[i][j] = 0;
                for (int k = 0; k < SIZE; k++) {
                    stackC[i][j] += stackA[i][k] * stackB[k][j];
                }
            }
        }
    }
    end = clock();
    double stack_time = (double)(end - start) / CLOCKS_PER_SEC;

    // === Result Output ===
    printf("Static matrix time:       %.4f seconds\n", static_time);
    printf("Stack-dynamic matrix time: %.4f seconds\n", stack_time);
    printf("Ratio (stack / static):    %.2f\n", stack_time / static_time);
}

int main() {
    test_matrix_performance();
    return 0;
}