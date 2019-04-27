#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_max(const vector<int>& vc, const vector<int>& res, int n)
{
	int max_i = 0, max_v = 0;
	for(int i=0;i<n;++i) {
		if(vc[n] < vc[i] && res[i] > max_v) {
			  max_i = i;
			  max_v = res[i];
		}
	}
	return max_v;
}

int main(void)
{
	int N;
	cin >> N;
	
	vector<int> vc(N);
	for(int n=0;n<N;++n)
		cin >> vc[n];
	
	vector<int> res(N,0);
	for(int n=0;n<N;++n) {
		res[n] = find_max(vc,res,n)+1;
	}	
	
	int answer = *max_element(res.begin(), res.end());
	cout << answer << endl;
	return 0;
}
