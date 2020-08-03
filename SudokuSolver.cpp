#include<bits/stdc++.h>

using namespace std;

bool canbeplaced(int arr[][9], int n, int num, int i, int j)
{
	for(int l=0; l<n; l++)
	{
		if((arr[i][l]==num)||(arr[l][j]==num))
		return false;
	}

	int x = (i/3)*3;
	int y = (j/3)*3;
	for(int a=x; a<x+3; a++)
	for(int b=y; b<y+3; b++)
	{
		if(arr[a][b]==num)
		return false;
	}
	return true;
}

void sudoku(int arr[][9], int n, int i,int j)
{
	if(i==n)
	{
		for(int u=0; u<n; u++)
		{
			for(int q=0; q<n; q++)
			cout<<arr[u][q]<<" ";
			cout<<endl;
		}
		return;
	}
	if(j==n)
	sudoku(arr,n,i+1,0);
	else if(arr[i][j]!=0)
	sudoku(arr,n,i,j+1);
	else
	{
		for(int num=1; num<=9; num++)
		{
			if(canbeplaced(arr,n,num,i,j))
			{
				arr[i][j] = num;
				sudoku(arr,n,i,j+1);
				arr[i][j] = 0;
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n][n];
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
	cin>>arr[i][j];
	cout<<endl;
	sudoku(arr,n,0,0);
}
