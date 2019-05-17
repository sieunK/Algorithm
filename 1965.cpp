#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_max(int n, const vector<int>& boxes, const vector<int>& max_vc)
{
	int max_v = 1;
	for(int i=0;i<n;++i)
		if(max_vc[i] >= max_v) { 
			if(boxes[i] < boxes[n])
				max_v = max_vc[i] + 1;
			else if(boxes[i] == boxes[n])
				max_v = max_vc[i];	
		}
	return max_v;	
}

int main(void)
{
	int N;
	cin >> N;
	
	vector<int> boxes(N);
	for(int n=0;n<N;++n)
		cin >> boxes[n];
	
	vector<int> max_vc(N);
	for(int n=0;n<N;++n)
		max_vc[n] = find_max(n,boxes,max_vc);
		
	int answer = *max_element(max_vc.begin(), max_vc.end());
	cout << answer << endl;	 	
	return 0;
}
