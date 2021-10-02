#include<iostream>
using namespace std;

class DummyClass
{
private:
 int num1, num2;
 int *ptr;
 
public:
 DummyClass()
 {
  ptr = new int;
 }
 
 void setData(int x, int y, int z)
 {
  num1 = x;
  num2 = y;
  *ptr = z;
 }
 
 void showData()
 {
  cout << "A = " << num1 << " B = " << num2 << endl;
 }
 
 DummyClass(DummyClass &D)
 {
  num1 = D.num1;
  num2 = D.num2;
  *ptr = *(D.ptr);
 }
 
 ~DummyClass()
 {
  delete ptr;
 }
};

int main()
{
 DummyClass D1;
 D1.setData(3, 5, 11);
 D1.showData();
 
 DummyClass D2 = D1;
 D2.showData();
}