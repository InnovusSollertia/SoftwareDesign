#include "matmul.h"

void matmul(mat_a a[a_rows][a_cols], mat_b b[b_rows][b_cols], mat_r r[a_rows][b_cols]) {
    Row: for(int i = 0;i < a_rows; i++) {
        Col: for(int j = 0; j < b_cols; j++) {
        r[i][j]=0;
        Product: for(int k = 0; k < b_rows; k++){
            r[i][j] +=a[i][k] * b[k][j];
            }
        }
    }
}