#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <fstream>

long int ans1 = 0;
int ans2 = 0;
std::string ans3 = "\0";

int time1 =0;
int time2 =0;
int time3 =0;
int puzzle_3_fib(int n);

using namespace std;

//for thread 1
void puzzles(int n)
{
	auto start = chrono::high_resolution_clock::now();

	if (n == 0)//fib
	{
		//brute force fibonacci sequence
		long int num=0;
		do
		{
			long fib_0 = 0; 
			long fib_1 = 1;
			for(int i = 1;; i++)
			{
				int next_fib = fib_0 + fib_1;
				fib_0 = fib_1;
				fib_1 = next_fib;
				if(fib_1==ans1)
				{
					num=fib_1;
					break;
				}
			} 
		} while (num != ans1);
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		time1 = duration.count();
		//filing
		ofstream miner1;
		miner1.open("miner1.txt",std::ios_base::app);
		miner1<< "miner 1 found the answer of the fibonci : " << num << " in " <<time1<< " micro seconds"<<endl;
	}

	if (n == 1)//sum of numbers
	{
		//brute force a number between 1 and int max
		int ans;
		int sum;
		for(int i =0; i<=INT_MAX;i++)
		{
			if(sum==ans2)
			{
				break;
			}
			sum++;
			ans = sum;
		}
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		time1 = duration.count();
		//filing
		ofstream miner1;
		miner1.open("miner1.txt",std::ios_base::app);
		miner1<< "miner 1 found the answer of the number : " << ans << " in " <<time1<< " micro seconds"<<endl;
	}

	if(n == 2)//substring
	{
		//brute forcing a string of alphabets
		string str = "";
		int i = 0;
		//compare if a string exists within a string
		while (str.find(ans3) == string::npos)
		{
			str += (char)(i + 97);
			i++;
		}
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		time1 = duration.count();
		//filing
		ofstream miner1;
		miner1.open("miner1.txt");
		miner1<< "miner 1 found the string : " << str << " in " <<time1<< " micro seconds"<<endl;
	}
}

//for thread 2
void puzzles2(int n)
{
	auto start = chrono::high_resolution_clock::now();

	if (n == 0)//fib
	{
		//brute force fibonacci sequence
		long int num;
		do
		{
			num++;
		} while (num != ans1);
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		time2 = duration.count();
		// cout<<"\nminer 2 found the answer: "<<ans1<<endl;
		ofstream miner2;
		miner2.open("miner2.txt",std::ios_base::app);
		miner2<< "miner 2 found the answer of the fibonci : " << num << " in " <<time2<< " micro seconds"<<endl;
	}

	if (n == 1)//sum of number
	{
		//brute force a number between 1 and int max
		int ans;
		int sum;
		for(int i =10002; i<=INT_MAX;i++)
		{
			if(sum==ans2)
			{
				break;
			}
			sum++;
			ans = sum;
		}
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		time2 = duration.count();
		//filing
		ofstream miner2;
		miner2.open("miner2.txt",std::ios_base::app);
		miner2<< "miner 2 found the answer of the number : " << ans << " in " <<time2<< " micro seconds"<<endl;
	}

	if(n == 2)//substring
	{
		//brute forcing a string of alphabets
		string str = "";
		int i = 0;
		//compare if a string exists within a string
		while (str.find(ans3) == string::npos)
		{
			str += (char)(i + 97);
			i++;
		}
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		time2 = duration.count();
		//filing
		ofstream miner2;
		miner2.open("miner2.txt");
		miner2<< "miner 2 found the string : " << str << " in " <<time2<< " micro seconds"<<endl;
	}
}

//for thread 3
void puzzles3(int n)
{
	auto start = chrono::high_resolution_clock::now();

	if (n == 0)//fib
	{
		long int num;
		//brute force fibonacci sequence
		do
		{
			for(int i = 0;;i++)
			{
				num=puzzle_3_fib(i);
				if(num==ans1)
				{
					break;
				}
			}
		} while (num != ans1);
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		time3 = duration.count();
		// cout<<"\nminer 3 found the answer: "<<ans1<<endl;
		ofstream miner3;
		miner3.open("miner3.txt",std::ios_base::app);
		miner3<< "miner 3 found the answer of the fibonci : " << num << " in " <<time3<< " micro seconds"<<endl;
	}

	if (n == 1)//sum of numbers 
	{
		//brute force a number between 1 and int max
		int ans;
		int sum;
		for(int i =10222; i<=INT_MAX;i++)
		{
			if(sum==ans2)
			{
				break;
			}
			sum++;
			ans = sum;
		}
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		time3 = duration.count();
		//filing
		ofstream miner3;
		miner3.open("miner3.txt",std::ios_base::app);
		miner3<< "miner 3 found the answer of the number : " << ans << " in " <<time3<< " micro seconds"<<endl;
	}

	if(n == 2)//substring 
	{
		//brute forcing a string of alphabets
		string str = "";
		int i = 0;
		//compare if a string exists within a string
		while (str.find(ans3) == string::npos)
		{
			str += (char)(i + 97);
			i++;
		}
	}
}

int puzzle_3_fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return puzzle_3_fib(n - 1) + puzzle_3_fib(n - 2);
}

void puzzle_answer_1(int n)
{
	long int past = 0, prev = 1, curr = 0;
	for (int i = 3; i < n+2; i++)
	{
		curr = past + prev;
		past = prev;
		prev = curr;
	}
	ans1=curr;
}

void puzzle_answer_2(int j)
{
	int k;
	for(int i =0; i<=INT_MAX;i++)
	{
		if(k==j)
		{
			ans2=k;
			break;
		}
		k++;
	}
	// cout << "Answer 2: " << k << endl;
}

void puzzle_answer_3(string n)
{
	string str = "";
	for(int i=0; i<rand()%26; i++)
	{
		str += (char)(i + 97);
	}
	ans3=str;
}



int main(int argc, char const *argv[])
{
	string message="hello";
	int ID;

	srand(time(NULL));
	ID=rand()%1000;

	int min=1, max=100000;
	srand(time(NULL));
	int j = rand() % max-min +min;

	int min2 = 40 , max2 = 85;
	srand(time(NULL));
	int k = rand() % max2-min2 +min2; //random number generated for fibonoci sequence
	
	//solver thread
	thread solver1(puzzle_answer_1, 45);
	thread solver2(puzzle_answer_2,j);
	thread solver3(puzzle_answer_3,"abcdefghijklmnopqrstuvwxyz");
	
	srand(time(NULL));
	int n = rand() % 3;
	
	//miners
	thread miner1(puzzles,1);
	miner1.join();
	thread miner2(puzzles2,1);
	miner2.join();
	thread miner3(puzzles3,1);
	miner3.join();

	if(time1<time2 && time1<time3)
	{
		//append the answer to the file
		ofstream miner1;
		miner1.open("log.txt",std::ios_base::app);
		miner1<<"Miner 1\t\t"<<" ID : "<<ID<<"  time : "<<time1<<"\t\t"<<message<<endl;
		miner1.close();
		cout<<"\nminer 1 wins"<<endl;
	}
	else if(time2<time1 && time2<time3)
	{
		ofstream miner2;
		miner2.open("log.txt", std::ios_base::app);
		miner2<<"Miner 2\t\t"<<" ID : "<<ID<<"  time : "<<time2<<"\t\t"<<message<<endl;
		miner2.close();
		cout<<"\nminer 2 wins"<<endl;
	}
	else if(time3<time1 && time3<time2)
	{
		ofstream miner3;
		miner3.open("log.txt",std::ios_base::app);
		miner3<<"Miner 3\t\t"<<"  ID : "<<ID<<"  time : "<<time3<<"\t\t"<<message<<endl;
		miner3.close();
		cout<<"\n miner 3 wins"<<endl;
	}
	else
	{
		cout<<"\nIts a tie\n";
	}
	return 0;
}