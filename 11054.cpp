#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_inc(const vector<int>& vc, const vector<int>& inc, int n)
{
	int max_ind = -1, max_v = 0;
	for(int i=0;i<n;++i) {
		if(vc[i] < vc[n] && max_v < inc[i]) {
			max_ind = i;
			max_v = inc[i];
		}
	}
	return max_v;
}

int find_dec(const vector<int>& vc, const vector<int>& dec, int n, int N)
{
	int max_ind = -1, max_v = 0;
	for(int i=N-1;i>n;--i) {
		if(vc[i] < vc[n] && max_v < dec[i]) {
			max_ind = i;
			max_v = dec[i];
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
	
	vector<int> inc_vc(N,0);
	for(int n=0;n<N;++n) {
		inc_vc[n] = find_inc(vc,inc_vc,n) + 1;
	}	
	
	vector<int> dec_vc(N,0);
	vector<int> res(N,0);
	for(int n=N-1;n>=0;--n) {
		dec_vc[n] = find_dec(vc,dec_vc,n,N) + 1;
		res[n] = inc_vc[n]+dec_vc[n] - 1;
	}
	
	int answer = *max_element(res.begin(), res.end());
	cout << answer << endl;
	return 0;
}
