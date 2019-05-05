#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	
	vector<int> stairs(N+3,0);
	for(int n=3;n<N+3;++n)
		cin >> stairs[n];
	
	vector<int> res(N+3,0);
	for(int n=3;n<N+3;++n) {
		int v1 = res[n-3]+stairs[n-1]+stairs[n];
		int v2 = res[n-2]+stairs[n];
		res[n] = v1 > v2 ? v1 : v2;
	}
	
	cout << res[N+2] << endl;		
	return 0;
}
