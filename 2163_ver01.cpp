#include <iostream>

using namespace std;

#define MAX 300

int arr[MAX+1][MAX+1];

void preprocess(void)
{
	for(int i=1;i<=MAX;++i)
		for(int j=1;j<=MAX;++j) {
			if(i==1)
				arr[i][j] = j-1;
			else if(j==1)
				arr[i][j] = i-1;	
			else	
				arr[i][j] = arr[i][1] + arr[i][j-1] + 1;
		}
}

//void print(void)
//{
//	for(int i=1;i<=MAX;++i) {
//		for(int j=1;j<=MAX;++j)
//			cout << arr[i][j] << ' ';
//		cout << endl;	
//	}
//}

int main(void)
{
	preprocess();
	//print();
	int N, M;
	cin >> N >> M;
	cout << arr[N][M] << endl;
	return 0;
}
