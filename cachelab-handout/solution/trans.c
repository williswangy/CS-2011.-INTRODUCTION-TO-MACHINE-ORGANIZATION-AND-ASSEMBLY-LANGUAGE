//ywang22 Yizhen Wang
//
/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
  int temp0,temp1,temp2,temp3,temp4,temp5,temp6,temp7;
/*32*32
  *-------             *********......        
  *                    -
  *                    -
  *                    -
  *               <-   - 
  *                    -
  *                    -
  *                    -
  .
  .
  here we use 1set 8blocks to reduce the miss rate
*/
  
  if (M == 32){
     for (int i = 0; i < 32; i += 8)
       for (int j = 0; j < 32; j++){
         temp0 = A[j][i];
         temp1 = A[j][i+1];
         temp2 = A[j][i+2];
         temp3 = A[j][i+3];
         temp4 = A[j][i+4];
         temp5 = A[j][i+5];
         temp6 = A[j][i+6];
         temp7 = A[j][i+7];
         B[i][j] = temp0;
         B[i+1][j] = temp1;
         B[i+2][j] = temp2;
         B[i+3][j] = temp3;
         B[i+4][j] = temp4;
         B[i+5][j] = temp5;
         B[i+6][j] = temp6;
         B[i+7][j] = temp7;
       }
  }
/* similar as 32*32 but some changes 
   use some block of B to save temporary A data
   8blocksize
*/
  else if (M == 64){
    for (int i = 0; i < 64; i += 8)
      for (int j = 0; j < 64; j += 8){
        for (int k = j; k < j+4; k++){
          temp0 = A[k][i];
          temp1 = A[k][i+1];
          temp2 = A[k][i+2];
          temp3 = A[k][i+3];
          temp4 = A[k][i+4];//as follow 4 temporary data saved in B
          temp5 = A[k][i+5];//
          temp6 = A[k][i+6];//
          temp7 = A[k][i+7];//
          B[i][k] = temp0;
          B[i+1][k] = temp1;
          B[i+2][k] = temp2;
          B[i+3][k] = temp3;
          B[i][k+4] = temp4;
          B[i+1][k+4] = temp5;
          B[i+2][k+4] = temp6;
          B[i+3][k+4] = temp7;
        }
        for (int k = i; k < i+4; k++){
          temp0 = B[k][j+4];//as follow 4 get temporary data saved above
          temp1 = B[k][j+5];//
          temp2 = B[k][j+6];//
          temp3 = B[k][j+7];//
          B[k][j+4] = A[j+4][k];
          B[k][j+5] = A[j+5][k];
          B[k][j+6] = A[j+6][k];
          B[k][j+7] = A[j+7][k];
          B[k+4][j] = temp0;
          B[k+4][j+1] = temp1;
          B[k+4][j+2] = temp2;
          B[k+4][j+3] = temp3;
        }
        for (int k = i+4; k < i+8; k++){//fix tails
          temp0 = A[j+4][k];
          temp1 = A[j+5][k];
          temp2 = A[j+6][k];
          temp3 = A[j+7][k];
          B[k][j+4] = temp0;
          B[k][j+5] = temp1;
          B[k][j+6] = temp2;
          B[k][j+7] = temp3;
        }
    }
  }
// carve into blocks
  else if (M == 61 && N == 67){
    for (int i = 0; i < 61; i += 16)
      for (int j = 0; j < 67; j+= 16)
        for (int k = j; k < j+16 && k < 67; k++)
          for (int m = i; m < i+16 && m < 61; m++){
            temp1 = A[k][m];
            B[m][k] = temp1;
          }
  }
  
}       

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

