#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	
	vector<int> num(N+1,0);
	for(int n=1;n<=N;++n) {
		int min_v = -1;
		for(int r=1;r<=sqrt(n);++r)
			if(min_v==-1 || min_v > num[n-r*r]) {
				min_v = num[n-r*r];
			}	
		num[n] = min_v + 1;	
	}
	cout << num[N] << endl;
	return 0;
}
