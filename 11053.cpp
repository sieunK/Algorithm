#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1001];

int find_index(int i,const vector<int>& res)
{
	int max_i = 0, max_v = 0;
	for(int j=0;j<i;++j)
		if(arr[i] > arr[j] && max_v < res[j]) {
			max_v = res[j];
			max_i = j;
		}
	return max_i;		
}

int main(void)
{
	int N;
	cin >> N;
	
	for(int n=1;n<=N;++n)
		cin >> arr[n];
		
	vector<int> res(N+1,0);
	int index = 0;
	for(int i=1;i<=N;++i) {
		index = find_index(i,res);
		res[i] = res[index]+1;	
	}
	
	int answer = *max_element(res.begin()+1,res.end());
	cout << answer << endl;
	return 0;
}
