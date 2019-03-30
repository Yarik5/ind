#include <stdlib.h>
#include <stdio.h>

int CreateMatrix(double ***matrix,int row,int col)
{
  int i;
  (*matrix)=calloc(row,sizeof(double*));
  for(i=0;i<row;i++)
    (*matrix)[i]=calloc(col,sizeof(double));

}

void DisplayMatrix(double **matrix,int row,int col)
{
   int i,j;
   for(i=0;i<row;i++)
     {
       for(j=0;j<col;j++)
          printf("%g\t",matrix[i][j]);
       printf("\n");
     }
}

void MakeEMatrix(double **matrix,int row,int col)
{
   int i,j;
   for(i=0;i<row;i++)
     for(j=0;j<col;j++)
        matrix[i][j]=((i==j)? 1.0:0.0);
}

double **MatrixMMMult(double **A,int RowA,int ColA,double **B,int RowB,int ColB)
{
 if(RowA!=ColB)
        return 0;
    double **C;
    int i,j,k;
    CreateMatrix(&C,RowA,ColB);
        for(k=0;k<ColB;k++)
          for(i=0;i<RowA;i++)
          {
             C[k][i]=0;
             for(j=0;j<ColB;j++)
                 C[k][i]+=A[k][j]*B[j][i];
          }
    return C;
}

double **MatrixMMAdd(double **A,int RowA,int ColA,double **B,int RowB,int ColB)
{
   if(RowA!=RowB||ColA!=ColB)
        return 0;
    double **C;
    int i, j;
    CreateMatrix(&C,RowA,ColA);
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            C[i][j]=A[i][j]+B[i][j];
    return C;
}

double  *MatrixMVMult(double **A,int RowA,int ColA,double *B,int RowB)
{
if(RowA!=RowB)
        return 0;
    double *C;
    CreateVector(&C, RowB);
    int i,j;
    for(i=0;i<RowB;i++)
    {
        C[i]=0;
        for(j=0;j<ColA;j++)
            C[i]+=A[i][j]*B[j];
    }
    return C;
}

void CreateVector(double **vector,int NumElement)
{
    (*vector)=calloc(NumElement,sizeof(double));
}


void DisplayVector(double *vector,int NumElement)
{
  int i;
    for(i=0;i<NumElement;i++)
        printf("%g\t",vector[i]);
        printf("\n\n");
}


double *VectorAdd(double *vectorA,int AElement,double *vectorB,int BElement)
{
     if(AElement!=BElement)
        return 0;
    double *vectorC;
    CreateVector(&vectorC,AElement);
    int i;
    for(i=0;i<AElement;i++)
        vectorC[i]=vectorA[i]+vectorB[i];
    return vectorC;
}


double *VectorDiff(double *vectorA,int AElement,double *vectorB,int BElement)
{
   if(AElement!=BElement)
        return 0;
    double *vectorC;
    CreateVector(&vectorC,AElement);
    int i;
    for(i=0;i<AElement;i++)
        vectorC[i]=vectorA[i]-vectorB[i];
    return vectorC;
}


double VectorScalar(double *vectorA,int AElement,double *vectorB,int BElement)
{
  if(AElement!=BElement)
        return 0;
    double res=0;
    int i;
    for(i=0;i<AElement;i++)
        res+=vectorA[i]*vectorB[i];
    return res;
}


double *VectorMultConst(double *vectorA,int AElement,double MyConst)
{
   double *vectorC;
    CreateVector(&vectorC,AElement);
    int i;
    for(i=0;i<AElement;i++)
        vectorC[i]=vectorA[i]*MyConst;
    return vectorC;
}


void VectorInFile(char *f,double *vector,int NumElement)
{
  unsigned int  i;
    FILE *myFile;
    if((myFile=fopen(f,"w"))==NULL)
    {
        printf("Can not open file");
        exit(1);
    }
    fprintf(myFile,"%d ",NumElement);
    for(i=0;i<NumElement;i++)
        fprintf(myFile,"%g ",vector[i]);
    fclose(myFile);
}


double *VectorOutFile(char *f)
{
     unsigned int  i=0, NumElement=0;
    double *c;
    FILE *myFile;
    if((myFile=fopen(f,"r"))==NULL)
    {
        printf("Can not open file");
        exit(1);
    }
    fscanf(myFile,"%d",&NumElement);
    if(!NumElement)
        exit(1);
    CreateVector(&c,NumElement);
    while(!feof(myFile))
    {
        fscanf(myFile,"%lf",&c[i]);
        i++;
    }
    fclose(myFile);
    return c;
}


double *VectorFun(double(*f)(double),double *ar,int NumElement)
{
    double *c;
    int i;
    CreateVector(c,NumElement);
    for(i=0;i<NumElement;i++)
        c[i]=(*f)(ar[i]+10);
    return c;
}

void DestroyedVector(double *x)
{
    free(x);
}

void DestroyedMatrix(double **x,int row)
{
    int i;
    for(i=0;i<row;i++)
        free(x[i]);
    free(x);
}
