// Roy Howie
// Wed Apr 8 23:39:14 EDT 2015

#include <stdio.h>
#include <stdlib.h>

typedef char String[256];
typedef enum { false, true } bool;

double * input_matrix   (int * rows, int * columns, char * name);
void output_matrix      (double * matrix, int rows, int columns);
bool matrix_multiply    (double * m1, int m1_rows, int m1_columns, double * m2, int m2_rows, int m2_columns, double * m3);

int main(void) {
    double * m1, * m2, * m3;
    int m1_rows, m1_columns;
    int m2_rows, m2_columns;

    if (((m1 = input_matrix(&m1_rows,&m1_columns,"Matrix 1")) != NULL) &&
        ((m2 = input_matrix(&m2_rows,&m2_columns,"Matrix 2")) != NULL) &&
        ((m3 = malloc(m1_rows*m2_columns*sizeof(double))) != NULL)) {

            printf("Matrix 1\n");
            output_matrix(m1,m1_rows,m1_columns);
            printf("Matrix 2\n");
            output_matrix(m2,m2_rows,m2_columns);
            if (matrix_multiply(m1,m1_rows,m1_columns,m2,m2_rows,m2_columns,m3)) {
                printf("Product\n");
                output_matrix(m3,m1_rows,m2_columns);
                free(m1);
                free(m2);
                free(m3);
                return(0);
            } else {
                printf("Error in dimensions\n");
                free(m1);
                free(m2);
                free(m3);
                return(-1);
            }
    } else {
        free(m1);
        free(m2);
        free(m3);
        printf("Error allocating memory\n");
        return(-2);
    }
}

double * input_matrix (int * rows, int * columns, char * name) {
    double * matrix;
    int i, j;

    printf("# of rows in %s:\t", name);
    scanf("%d", rows);
    printf("# of cols in %s:\t", name);
    scanf("%d", columns);

    matrix = (double *)(malloc((*rows * *columns) * sizeof(double)));

    for (i = 0; i < *rows; i++) {
        for (j = 0; j < *columns; j++) {
            printf("Enter row %d col %d:\t", i+1, j+1);
            scanf("%lf", matrix + (i * *columns) + j);
        }
    }

    return matrix;
}
void output_matrix (double * matrix, int rows, int columns) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%4.2f\t", *(matrix + (i * columns) + j));
        }
        printf("\n");
    }
}
bool matrix_multiply (double * m1, int m1_rows, int m1_columns, double * m2, int m2_rows, int m2_columns, double * m3) {
    int i, j, k;
    double n, m, sum;

    // given matrix A that is m by n and matrix B that is n by p,
    // the AB will have dimensions m by p, or
    // the # of rows in A by the # of cols in B
    if (m1_columns != m2_rows) {
        return false;   // if the dimensions don't work, we can't multiply, so return false
    } else {
        // the resultant matrix is m1_rows by m2_columns
        // hence, iterate i up to m1_rows and j up to m2_columns
        for (i = 0; i < m1_rows; i++) {
            for (j = 0; j < m2_columns; j++) {
                // result[i][j] is the ith row of A [dot product] the jth column of B
                // the ith row of A and the jth column of B both have m1_columns (or m2_rows)
                // elements, so we need to iterate `k == m1_columns` times:
                sum = 0.0;
                for (k = 0; k < m1_columns; k++) {
                    // m is m1[i][k]
                    m = *(m1 + (i*m1_columns) + k);
                    // n is m2[k][j]
                    n = *(m2 + (k*m2_columns) + j);
                    sum += (n * m);
                }
                // m3[i][j] = sum of the elements
                *(m3 + i*m2_columns + j) = sum;
            }
        }
        return true;
    }
}