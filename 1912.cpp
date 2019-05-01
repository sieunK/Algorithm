#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	
	vector<int> vc(N);
	for(int n=0;n<N;++n)
		cin >> vc[n];
	
	vector<int> res(N,0);
	res[0] = vc[0];
	for(int n=1;n<N;++n)
		if(res[n-1] > 0)
			res[n] = res[n-1] + vc[n];
		else
			res[n] = vc[n];
	
	int answer = *max_element(res.begin(), res.end());
	cout << answer << endl;				
	return 0;
}
