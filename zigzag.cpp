#include <iostream>
#define n 3

using namespace std;

int diagonally_down(int mat[n][n])
{
   int i, j, row, col;
   //printing above elements
   for (i = 0; i < n; i++)
   {
    	row = 0;
   		col = i;
      	while(col >= 0) //Moving downwards from the first row{
        	cout<<mat[row++][col--];
      	}
   //printing below elements
   for (j = 1; j < n; j++)
   {
        row = j;
        col = n-1;
      	while(row<n) //Moving from the last column{
        	cout<<mat[row++][col--];
      
   }
}
int main()
{
   int mat[n][n];
   cout<<"Enter element in 3x3 matrix : ";
   for(int i=0;i<n;i++)
   {
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}
   }
   diagonally_down(mat);
   return 0;
}
