#include <iostream>

using namespace std;

int main(void)
{
	int max_val = 0;
	int max_num = 0;
	for(int i=1;i<=5;++i) {
		int sum = 0;
		for(int j=0;j<4;++j) {
			int val;
			cin >> val;
			sum += val;
		}
		if(sum > max_val) {
			max_val = sum;
			max_num = i;
		}
	}
	
	cout << max_num << ' ' << max_val << endl;
	return 0;
}
