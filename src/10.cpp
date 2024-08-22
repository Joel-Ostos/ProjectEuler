#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() 
{
	const int N = 2'000'000;
	vector<int> lp(N+1);
	vector<int> pr;
	long sm = 0;
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			sm += i;
			pr.push_back(i);
		}
		for (int j = 0; i * pr[j] <= N; ++j) {
			lp[i * pr[j]] = pr[j];
			if (pr[j] == lp[i]) {
				break;
			}
		}
	}
	cout << sm << '\n';
}
