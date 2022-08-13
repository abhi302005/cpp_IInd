#include <iostream>
using namespace std;

int main ()
{
   int magicsq[5][5];
   int i, j, x;
   int size;
   cout<<"Enter size(odd number) of matrix : ";
   cin>>size;
   int row = 0;              // start position of row
   int col = size / 2;          // and column
 
   for ( i = 0; i < size ; i++ )
   {
      	for ( j = 0 ; j < size; j++ ) 
			magicsq[i][j] = 0;              //initialize to 0 your matrix
   }
 
   magicsq[row][col] = 1;         //position to start the counting
 
   for ( x = 2; x <= size * size; x++ )
   {
      	int r = row - 1, c = col - 1;    // test positions
      	if (r < 0) r += size;
      	if (c < 0) c += size;
      	if ( magicsq[r][c]>0)
      	{
        	row++;
         	if ( row >= size ) 
			 	row -= size;
      	}
      	else
      	{
        	row = r;
         	col = c;
      	}
      	magicsq[row][col] = x;
   }
 
   for ( i = 0; i < size; i++ )
   {
      	for ( j = 0; j < size; j++ ) 
			cout << magicsq[i][j] << " ";
     	cout<<endl;
   }
}
