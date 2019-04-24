#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	
	vector<int> wine(N+1,0);
	for(int n=1;n<=N;++n)
		cin >> wine[n];
		
	vector<int> res(N+3,0);
	int prev_max = 0;
	for(int i=3,j=1,k=0;i<N+3;++i,++j,++k) {	
		res[i] = res[i-2] + wine[j];
		if(res[k] > prev_max)
			prev_max = res[k];
		if(res[i] < prev_max + wine[j] + wine[j-1])
			res[i] = prev_max + wine[j] + wine[j-1];							
	}	
	
	int max = res[N+2];
	if( max < res[N+1])
		max = res[N+1];
	
	cout << max << endl;
			
	return 0;
}

