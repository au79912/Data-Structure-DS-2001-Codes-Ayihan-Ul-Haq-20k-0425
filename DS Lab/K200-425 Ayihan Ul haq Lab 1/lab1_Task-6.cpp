#include <iostream>

using namespace std;


class animal
{
	string name;
	int id;
	
	public:
	animal()
	{
	}
	animal(string name, int id)
	{
		this -> name = name;
		this -> id = id;
	}
	string getname()
	{
		return name;
	}
	int getid()
	{
		return id;
	}
	void setid(int id)
	{
		this -> id= id;
	}
	void setname(string name)
	{
		this-> name = name;
	}
};



int main(int argc, char const *argv[])
{
	animal *arr;
	arr=new animal[5];

	arr[0]=animal("test", 123);
	arr[1]=animal("test1", 124);
	arr[2]=animal("test2", 125);
	arr[3]=animal("test3", 126);
	arr[4]=animal("test4", 127);\

	int n=5;
	
	for(int i=0; i<n; i++)
	{
		for(int j =0; j<5-i-1; j++)
		{
			if (arr[j].getid()>arr[j-1].getid())
			{
				animal temp=arr[j];
			}
			arr[j].setname(arr[j-1].getname());
			arr[j].setid(arr[j-1].getid());
		}
	}


	return 0;
}