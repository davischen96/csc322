// Roy Howie
// Thu Mar 26 01:20:23 EDT 2015

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 3

typedef int ** matrix;

void getMatrixFromInput(int ** a, char name);
void multiplyMatrices (int ** a, int ** b, int ** result);
void printMatrix (int ** m, char name);

int main (void) {
    matrix a;
    matrix b;
    matrix c;

    printf("When entering rows, delimit numbers with spaces.\n");
    
    getMatrixFromInput(a, 'A');
    // getMatrixFromInput(b, 'B');

    printMatrix(a, 'A');
    // printMatrix(b, 'B');
    printf("If C = AB, then ");
    // multiplyMatrices(a, b, c);
    // printMatrix(c, 'C');

    return 0;
}

void getMatrixFromInput(int ** a, char name) {
    int i;
    int k;
    a = (int **)malloc(3 * sizeof(int *));
    for (i = 0; i < 3; i++) {
        *(a + i) = (int *)malloc(3 * sizeof(int));
        printf("Enter row %d of matrix %c: ", i + 1, name);
        // scanf("%d %d %d", (*(a+i)), (*(a+i)+1), (*(a+i)+2));
        scanf("%d %d %d", &*(*(a+i)), &*(*(a+i)+1), &*(*(a+i)+2));
        for (k = 0; k < 3; k++) {
            printf("%c[%d][%d]: %d\n", name, i, k, *(*(a+i)+k));
        }
    }
    printf("\n");
}

void multiplyMatrices (int ** a, int ** b, int ** result) {
    int i, j, k, sum;
    int m, n;
    for (i = 0; i < 3; i++) {
        *(result + i) = (int *)malloc(3 * sizeof(int));
        for (j = 0; j < 3; j++) {
            // result[i][j] is the ith row of A times [dot product] the jth column of B
            sum = 0;
            /*
                there are 3 elements in each row, column
                result[i][j] = ∑a[i][k]*b[k][j] for k = 0...2
                or: result[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j] + a[i][2]*b[2][j]
                let m = a[i][k] and n = b[k][j]
                therefore, result[i][j] = sum = ∑(m*n)
            */
            for (k = 0; k < 3; k++) {
                m = *(*(a+i)+k);
                n = *(*(b+k)+j);
                sum += (n * m);
            }
            *(*(result + i) + j) = sum;
        }
    }
}

void printMatrix (int ** m, char name) {
    int i, j;
    printf("matrix %c is:\n", name);
    // segmentation fault here
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            // printf("%d\t", *(*(m+i)+j));
            printf("%c[%d][%d]: %d\n", name, i, j, *(*(m+i)+j));
        }
        printf("\n");
    }
}