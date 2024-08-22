#include <iostream>
using namespace std;

void calc() 
{
	long long mx = 0;
	for (long long i = 1; i < 1'000'000; i++) {
		long long t = i, ch = 1;
		while (t != 1) {
			ch++;
			if (t%2) {
				t = 3*t+1;
				continue;
			}
			else t /= 2;
		}
		if (ch > mx) mx = ch;
	}
	cout << mx << '\n';
}

int main()
{
	calc();
}
