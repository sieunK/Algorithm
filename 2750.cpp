#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	
	vector<int> vc(N);
	for(int n=0;n<N;++n)
		cin >> vc[n];
	
	for(int i=0;i<N;++i)
		for(int j=i+1;j<N;++j)
			if(vc[j] < vc[i]) {
				int tmp = vc[j];
				vc[j] = vc[i];
				vc[i] = tmp;
			}	
	
	for(int n=0;n<N;++n)
		cout << vc[n] << endl;		
	return 0;
}
