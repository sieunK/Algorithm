#include <iostream>

using namespace std;

bool is_valid(int i, int j, int N)
{
	return
		0 <= i && i < N &&
		0 <= j && j <= i;
}

int max_val(int v1, int v2)
{
	return v1 > v2 ? v1 : v2;
}

int main(void)
{
	int N;
	cin >> N;
	
	int arr[N][N];
	
	for(int i=0;i<N;++i)
		for(int j=0;j<=i;++j)
			cin >> arr[i][j];

	for(int i=0;i<N;++i)
		for(int j=0;j<=i;++j) {
			int v1 = is_valid(i-1,j-1,N) ? arr[i-1][j-1] : 0; 
			int v2 = is_valid(i-1,j,N) ? arr[i-1][j] : 0;
			
			arr[i][j] += max_val(v1,v2);
		}
		
	int max = 0;	
	for(int i=0;i<N;++i)
		if(arr[N-1][i]	> max)
			max = arr[N-1][i];
	
	cout << max << endl;		
	return 0;
}
