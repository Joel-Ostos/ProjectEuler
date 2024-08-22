#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	vector<int> lp(15+1);
	vector<int> pr;
	const int N = 15;
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; i * pr[j] <= 15; ++j) {
			lp[i * pr[j]] = pr[j];
			if (pr[j] == lp[i]) {
				break;
			}
		}
	}
	cout << pr[10000] << '\n';
	for (int i = 10; i != 1; i/=lp[i]) {
		cout << lp[i] << '\n';
	}
}
