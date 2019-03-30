/*
 * Author: Гнатюк Ярослав Сергійович
 *
 * Created on 6 2016 р., 22:03
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Matrix.h"

int main()
{
    int i,j;
    double *v, *m, *n;
    CreateVector(&v,6);
    CreateVector(&m,6);
    for(i=0;i<6;i++)
    {
        v[i]=i+1;
        m[i]=i+2;
    }

    DisplayVector(v,6);
    DisplayVector(m,6);
    printf("%g\n\n",VectorScalar(m,6,v,6));
    n=VectorAdd(v,6,m,6);
    DisplayVector(n,6);
    n=VectorDiff(v,6,m,6);
    DisplayVector(n,6);
    n=VectorMultConst(v,6,5);
    DisplayVector(n,6);

    double **mA, **mB, **mC;
    CreateMatrix(&mA,6,6);
    CreateMatrix(&mB,6,6);
    for(i=0;i<6;i++)
        for(j=0;j<6;j++)
        {
           mA[i][j]=(i+1)*j+1;
           mB[i][j]=(i+i)*j+3;
        }
    DisplayMatrix(mA,6,6);
    DisplayMatrix(mB,6,6);
    mC=MatrixMMAdd(mA,6,6,mB,6,6);
    DisplayMatrix(mC,6,6);
    mC=MatrixMMMult(mA,6,6,mB,6,6);
    DisplayMatrix(mC,6,6);
    n=MatrixMVMult(mA,6,6,n,6);
    DisplayVector(n,6);
    n=VectorOutFile("1.txt");
    DisplayVector(n,6);
    n=VectorFun(sin,n,6);
    VectorInFile("file.txt",n,6);
    DisplayVector(n,6);

    return 0;
}
