#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() 
{
	const int N = 158'000'000;
	//const int N = 10;
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
	pair<long,long> max_divs = {0,0};
	for (int k = 10000; k < 15000; k++) {
		unordered_map<long, long> m;
		for (long long i = (k*(k+1))/2; i != 1; i/=lp[i]) {
			m[lp[i]]++;
			//cout << lp[i] << '\n';
		}
		long divs = 1;
		for (auto [f,s]: m) {
			if (!f)continue;
			divs*=s+1;
		}
		if (max_divs.second < divs) {
			max_divs.first = (k*(k+1))/2;
			max_divs.second = divs;
		}
		cout << max_divs.first << " " << max_divs.second << '\n';
		if (max_divs.second > (long)500) {
			cout << "RESULT "<< max_divs.first << '\n';
			return 1;
		}
	}
}
