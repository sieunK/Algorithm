#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void print(vector<int> const& select, vector<int> const& numbers)
{
	for(int n=0;n<numbers.size();++n)
		if(select[n])
			cout << numbers[n] << ' ';
	cout << endl;		
}

bool next(vector<int>& select)
{
	int cnt = 0;
	int N = select.size();
	for(int n=N-1;n>0;--n) {
		if(select[n]==0 && select[n-1]==1) {
			select[n] = 1;
			select[n-1] = 0;
			for(int i=n+1;i<N;++i) {
				if(cnt > 0) {
					select[i] = 1;
					cnt--;
				}
				else {
					select[i] = 0;
				}	
			}
			return true;
		}
		else if(select[n]==1)
			cnt++;
	}
	return false;
}

int main(void)
{
	string str;
	while(getline(cin,str) && str[0]!='0') {
		istringstream iss(str);
		
		int N;
		iss >> N;
		
		vector<int> numbers(N);
		for(int n=0;n<N;++n)
			iss >> numbers[n];
		
		vector<int> select(N,0);
		for(int n=0;n<6;++n)
			select[n] = 1;
		
		print(select,numbers);	
		while(next(select))
			print(select,numbers);
		cout << endl;	
	}
	return 0;
}
