#include <iostream>
#include <algorithm>

using namespace std;
int maximum_toys(int cost[], int N, int K)
{
	int count = 0, sum = 0;

	sort(cost, cost + N);
	for (int i = 0; i < N; i++) {

		if (sum +cost[i] <= K)
		{
			sum = sum + cost[i];
			count++;
		}
	}
	return count;
}

// Driver Code
int main()
{
	int cost[] = {20, 30, 50};
	int N = sizeof(cost) / sizeof(cost[0]);
	int K = 100;

	cout << maximum_toys(cost, N, K) << endl;
	return 0;
}