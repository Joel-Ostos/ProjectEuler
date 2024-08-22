#include <iostream>
#include <string>
using namespace std;

bool isp(int p) {
  string a = to_string(p);
  int i = 0, j= a.size()-1;
  if (i <0 or j<0) return 0;
  while(i<j) {
    if (a[i]!=a[j]) return 0;
    i++;
    j--;
  }
  return 1;
}

int main() {
  int max = 0;
  for (int i= 999; i >= 100; i--) {
    for (int j = 999; j >= 100; j--) {
      int p = i*j;
      if (isp(p) and p > max) {
	max = p;
      }
    }
  }
  cout << max << '\n';
}
