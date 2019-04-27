#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_max(const vector<int>& r,const vector<int>& v, int n)
{
	int max_i = -1;
	int max_v = 0;
	for(int i=0;i<n;++i) {
		if(v[i] < v[n] && max_v < r[i]) {
			max_i = i;
			max_v = r[i];
		}
	}
	return max_i;
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
		int ind = find_max(res,vc,n);
		if(ind == -1)
			res[n] = vc[n];
		else
			res[n] = res[ind]+vc[n];	
	}
	
	int answer = *max_element(res.begin(), res.end());
	cout << answer << endl;
	return 0;
}
