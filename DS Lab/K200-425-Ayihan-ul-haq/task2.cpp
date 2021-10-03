#include <iostream>

using namespace std;


class date
{
	public:
	int day;
	int month;
	int year;
};

void selectionsort(date ob[3])
{
	for (int i=0; i<3; i++)
	{
		for (int j=i+1; j<3; j++)
		{
			if (ob[i].year > ob[j].year)
			{
				date temp = ob[i];
				ob[i] = ob[j];
				ob[j] = temp;
			}
			else if (ob[i].year == ob[j].year && ob[i].month > ob[j].month)
			{
				date temp = ob[i];
				ob[i] = ob[j];
				ob[j] = temp;
			}
			else if (ob[i].year == ob[j].year && ob[i].month == ob[j].month && ob[i].day > ob[j].day)
			{
				date temp = ob[i];
				ob[i] = ob[j];
				ob[j] = temp;
			}

		}
	}


	for(int i=0; i<3; i++)
	{
		cout<<ob[i].day<<" "<<ob[i].month<<" "<<ob[i].year;
		cout<<endl;
	}

}

int main(int argc, char const *argv[])
{
	date obj[3];
	for(int i=0; i<3; i++)
	{
		cin>>obj[i].day;
		cin>>obj[i].month;
		cin>>obj[i].year;
	}
	selectionsort(obj);
	return 0;
}