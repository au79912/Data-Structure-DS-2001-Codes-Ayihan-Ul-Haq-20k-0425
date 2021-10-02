#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{

	fstream myfile1;
	string fname;

	fname=argv[1];

	myfile1.open(fname.c_str());

	if (myfile1.is_open())
	{}
	else
	{
		cout<<"an error has occured";
	}

	cout<<"File : "<<fname<<" has been created"<<endl;

	string data;
	
	cout<<"Enter the contents : "<<data;

	myfile1<<data;

	cout<<myfile1.rdbuf()<<" has been written into file : "<<fname;

	fstream myfile2;
	if (myfile2.is_open())
	{}
	else
	{
		cout<<"an error has occured";
	}

	fname=argv[2];

	myfile2.open(fname.c_str());
	string temp;

	myfile1>>temp;

	myfile2<<temp;


	myfile1.close();
	myfile2.close();


	return 0;
}