#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define n 5
void TaoMang(int A[]){
	int n = 0;
	srand(time(NULL));
	while(n<MAX)
	{
		A[n++] = rand();
	}
}

int count_run(int A[]) {
	int count = 0, i = 0;
	while (i < n) {
		while (A[i] < A[i+1] && i < n-1)
			i++;
		count++;
		i++;
	}
	return count;	
}
void Merge(int A[], int B[], int C[], int &m, int &n, int &nA)
{
	int i = 0, j = 0;
	while(i<m && j<n)
	{
		if(B[i]<C[j])
			A[nA++] = B[i++];
		else
			A[nA++] = C[j++];
	}
	while(i<m)
		A[nA++] = B[i++];
	while(j<n)
		A[nA++] = C[j++];
	m = 0;
	n = 0;
}
void PhanPhoiVaoMang(int A[], int B[], int C[])
{
	int i = 0, dem = 0, nA = 0;
	int m = 0, n = 0;
	while(i<MAX)
	{
		int tmp = i;
		while(A[i]<A[i+1] && i<MAX-1)
			i++;
		if(dem%2==0)
			for(int j = tmp; j<=i; j++)
				B[m++] = A[j];
		else
		{
			for(int j = tmp; j<=i; j++)
				C[n++] = A[j];
			Merge(A, B, C, m, n, nA);
		}
		i++;
		dem++;
	}
	if(m!=0)
		for(int k = 0; k<m; k++)
			A[nA++] = B[k];
}
void NaturalMergeSort(int A[], int B[], int C[])
{
	while(SoDuongChay(A)>=2)
		PhanPhoiVaoMang(A, B, C);
}
void PhanPhoiTheoK(int A[], int B[], int C[], int &m, int &n, const int &k)
{
	int i = 0;
	while(i<MAX)
	{
		for(int j = 0; j<k; j++)
			B[j] = A[i++];
		for(int q = 0; q<k; q++)
			C[q] = A[i++];
	}
}
void InMang(int A[], int n)
{
	for(int i = 0; i<n; i++)
		printf(" %d ", A[i]);
	printf("\n");
}
int _tmain(int argc, _TCHAR* argv[])
{
	int A[MAX], B[MAX], C[MAX];
	int m = 0, n = 0, k = 0;
	TaoMang(A);
	printf("Mang vua duoc tao ra theo ramdom la: \n");
	InMang(A, MAX);
	NaturalMergeSort(A, B, C);
	printf("Mang A sau khi duoc sap xep bang giai thuat NaturalMergeSort: \n");
	InMang(A, MAX);
