#include<iostream>
using namespace std;

int main()
{
	int i, j, rows, columns, flag = 1;
	
	cout << "\nPlease Enter Matrix rows and Columns to find Identity Matrix =  ";
	cin >> i >> j;
	
	int identMatrix[i][j];
	
	cout << "\nPlease Enter the Identity Matrix Items\n";
	for(rows = 0; rows < i; rows++)	{
		for(columns = 0; columns < i; columns++) {
			cin >> identMatrix[rows][columns];
		}		
	}

 	for(rows = 0; rows < i; rows++)
  	{
   		for(columns = 0; columns < j; columns++)
    	{
    		if(rows == columns && identMatrix[rows][columns] != 1)
    		{
    			flag = 0;
			}
			else if(rows != columns && identMatrix[rows][columns] != 0)
			{
				flag = 0;
			}
   	 	}
  	}
  	if(flag == 1)
  	{
  		cout << "\nThe Matrix that you entered is an Identity Matrix";
	}
	else
	{
		cout << "\nThe Matrix that you entered is Not an Identity Matrix";
	}  	

 	return 0;
}