#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	
	vector<int> ropes(N);
	for(int n=0;n<N;++n)
		cin >> ropes[n];
	
	sort(ropes.begin(), ropes.end(), greater<int>());
	
	int creteria = ropes[0];
	int num = 1;
	
	for(int n=1;n<N;++n) {
		if(creteria == ropes[n]) {
			num++;
		}
		else if( creteria*num < ropes[n]*(n+1)) {
			creteria = ropes[n];
			num = n+1;
		}
	}	

	cout << creteria*num << endl;
	return 0;
}
