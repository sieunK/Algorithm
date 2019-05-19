#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	
	if(N<=0) 
		return 0;
	
	vector<int> vc(N,0);
	for(int n=0;n<N;++n)
		cin >> vc[n];
	
	vector<int> res(N);
	res[0] = vc[0];
	for(int n=1;n<N;++n)
		if(res[n-1] > 0)
			res[n] = res[n-1]+vc[n];
		else
			res[n] = vc[n];	
			
	int max1 = *max_element(res.begin(),res.end());
	
	int i;
	vector<int> modified_res(res);
	for(int n=0;n<N-1;++n)
		if(vc[n] < 0)
			if(res[n+1]!=vc[n+1])
				for(i=n+1;i<N && vc[i]>=0;++i)
					modified_res[i] -= vc[n];	
			else if(n>=1) {
				for(i=n+1;i<N && vc[i]>=0;++i)
					modified_res[i] += res[n-1];
			}
			
	int max2 = *max_element(modified_res.begin(),modified_res.end());	
	int answer = max1 > max2 ? max1 : max2;
	
	cout << answer << endl;			
	return 0;
}
