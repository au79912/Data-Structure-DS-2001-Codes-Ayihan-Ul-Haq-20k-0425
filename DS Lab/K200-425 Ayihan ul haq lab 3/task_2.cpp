#include <iostream>

using namespace std;

int Fib(int n);

int main() {
int i;

for(i=1;i<=20;i++) {
cout << "Fib(" << i << ") = " << Fib(i) << endl;
}

return 0;
}

int Fib(int n) {
int returnValue;

// handle the base case first;
if (n == 1 || n == 2) {
returnValue = 1;
} else {
returnValue = Fib(n-1) + Fib(n-2);
}
return returnValue;
}

