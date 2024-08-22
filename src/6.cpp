#include <iostream>
using namespace std;

int main() 
{
	int r1 = 0;
	int r2 = (100*101)/2;
	for (int i = 1; i < 101; i++) 
		r1+=(i*i);
	r2 *= r2;
	cout << r2-r1 << '\n';
}
