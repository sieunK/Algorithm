#include <iostream>

using namespace std;

#define MAX 30

int res[MAX+1];
int fibo[MAX+1];

void preprocess(void)
{
	fibo[0] = 1;
	fibo[1] = 1;
	
	for(int i=2;i<=MAX;++i) 
		fibo[i] = fibo[i-1]+fibo[i-2];
	
	res[0] = 3;
	res[2] = 3;
	for(int i=4,j=1;i<=MAX && j<=MAX;i+=2,j+=2) 
		res[i]	= res[i-2]*res[2]+2*fibo[j];
}

int main(void)
{
	preprocess();
	
	int N;
	cin >> N;
	
	if(N%2==0)
		cout << res[N] << endl;
	else
		cout << 0 << endl;	
	return 0;
}
