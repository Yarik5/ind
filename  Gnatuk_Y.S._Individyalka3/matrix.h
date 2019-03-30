#ifndef __MATRIX_H
#define __MATRIX_H
int CreateMatrix(double ***matrix,int row,int col);
void DisplayMatrix(double **matrix,int row,int col);
void MakeEMatrix(double **matrix,int row,int col);
double **MatrixMMMult(double **A,int RowA,int ColA,double **B,int RowB,int ColB);
double **MatrixMMAdd(double **A,int RowA,int ColA,double **B,int RowB,int ColB);
double  *MatrixMVMult(double **A,int RowA,int ColA,double *B,int RowB);

void CreateVector(double **vector,int NumElement);
void DisplayVector(double *vector,int NumElement);
double *VectorAdd(double *vectorA,int AElement,double *vectorB,int BElement);
double *VectorDiff(double *vectorA,int AElement,double *vectorB,int BElement);
double VectorScalar(double *vectorA,int AElement,double *vectorB,int BElement);
double *VectorMultConst(double *vectorA,int AElement,double MyConst);

void VectorInFile(char *f,double *vector,int NumElement);
double *VectorOutFile(char *f);
double *VectorFun(double(*f)(double),double *ar,int NumElement);

void DestroyedVector(double *x);
void DestroyedMatrix(double **x,int row);
#endif

