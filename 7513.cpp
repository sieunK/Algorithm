#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	
	for(int test_case=0;test_case<T;++test_case) {
		int N;
		cin >> N;
		
		vector<string> vc(N);
		for(int n=0;n<N;++n)
			cin >> vc[n];
		
		int K;
		cin >> K;
		
		vector<string> answers(K,"");
		for(int k=0;k<K;++k) {
			int len;
			cin >> len;
			
			for(int l=0;l<len;++l) {
				int ind;
				cin >> ind;
				
				answers[k]+=vc[ind];
			}
		}	
		cout << "Scenario #" << test_case+1 << ":" << endl;
		for(int k=0;k<K;++k)
			cout << answers[k] << endl;
		cout << endl;	
	}
	return 0;
}
