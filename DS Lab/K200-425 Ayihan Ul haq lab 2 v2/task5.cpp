#include <iostream>

using namespace std;

int main()
{
	// float **arr[5][]={
	// 				{3.66,3.33,4.0,3.0,2.66},
	// 				{3.33,3.0,3.66,3.0},
	// 				{4.0,3.66,2.66},
	// 				{2.66,2.33,4.0},
	// 				{3.33,3.66,4.0,3.0,3.33}
	// 			};


	cout<<"Enter the number of rows : ";
	int rows;
	cin>>rows;

	int *col =new int[rows];
	float **arr = new float*[rows];

	int n=rows;
	
	for(int i=0; i<n; i++)
	{
		cout<<"enter no. of coloums in row"<< i << " : ";
		cin >>col[i];
		arr[i]=new float[col[i]];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col[i]; j++)
		{
			cout<<"row"<<i<<" enter value "<<i*col[i]+j<<" : ";
			cin >> arr[i][j];
		}
	}
	int Tch;
	//for sem 1
	float total_sem1;
	for (int i = 0;i<2;i++)
	{
		for(int j=0;j<sizeof(arr[i][j]);j++)
		{
				total_sem1+=arr[i][j];
				Tch++;
		}
	}
	
	//for sem 2
	float total_sem2;
	for (int i = 1;i<2;i++)
	{
		for(int j=0;j<sizeof(arr[i][j]);j++)
		{
				total_sem2+=arr[i][j];
				Tch++;
		}
	}
	
	//for sem 3
	float total_sem3;
	for (int i = 2;i<2;i++)
	{
		for(int j=0;j<sizeof(arr[i][j]);j++)
		{
				total_sem3+=arr[i][j];
				Tch++;
		}
	}
	

	//for sem 4
	float total_sem4;
	for (int i = 3;i<2;i++)
	{
		for(int j=0;j<sizeof(arr[i][j]);j++)
		{
				total_sem4+=arr[i][j];
				Tch++;
		}
	}
	
	//for sem 5
	float total_sem5;
	for (int i = 4;i<2;i++)
	{
		for(int j=0;j<sizeof(arr[i][j]);j++)
		{
				total_sem5+=arr[i][j];
				Tch++;
		}
	}
	
	float totalgpa=total_sem1+total_sem2+total_sem3+total_sem4+total_sem5;

	float gpa=totalgpa/Tch;

	cout<<"Cgpa is : "<<gpa;
}