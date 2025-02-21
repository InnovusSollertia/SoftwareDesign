#ifndef __MATHMUL_H__
#define __MATHMUL_H__

#include <cmath>
using namespace std;

#define HW_COSIM

#define a_rows 2
#define a_cols 3
#define b_rows 3
#define b_cols 2

typedef char mat_a;
typedef char mat_b;
typedef short mat_r;

void matmul(
    mat_a a[a_rows][a_cols],
    mat_b b[b_rows][b_cols],
    mat_r res[a_rows][b_cols]);

#endif