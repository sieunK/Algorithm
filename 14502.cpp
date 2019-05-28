#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input(vector< vector<int> >& map)
{
	for(int i=0;i<map.size();++i)
		for(int j=0;j<map[i].size();++j)
			cin >> map[i][j];
}

void print(vector< vector<int> > const& map)
{
	for(int i=0;i<map.size();++i) {
		for(int j=0;j<map[i].size();++j)
			cout << map[i][j] << ' ';
		cout << endl;	
	}
	cout << endl;
}

bool next(vector< vector<int> >&copy_map)
{
	int cnt = 0;
	//print(copy_map);
	for(int i=copy_map.size()-1;i>=0;--i) {
		for(int j=copy_map[i].size()-1;j>=0;--j) {
			if(i==0 && j==0)
				return false;
			if(copy_map[i][j]==0 && j-1 >= 0 && copy_map[i][j-1]==1) {
				copy_map[i][j]=1;
				copy_map[i][j-1]=0;
				
				int r = i;
				int c = j+1;
				for(int k=1;k<=cnt;++k) {
					if(c==copy_map[i].size()) {
						r = r+1;
						c = 0;
					}
					copy_map[r][c] = 1;
					c++;
				}
				return true;
			}
			else if(copy_map[i][j]==0 && j-1 < 0 &&copy_map[i-1][copy_map[i-1].size()-1]==1) {
				copy_map[i][j]=1;
				copy_map[i-1][copy_map[i-1].size()-1]=0;
				
				int r = i;
				int c = j+1;
				for(int k=1;k<=cnt;++k) {
					if(c==copy_map[i].size()) {
						r = r+1;
						c = 0;
					}
					copy_map[r][c] = 1;
					c++;
				}
				return true;
			}
			else if(copy_map[i][j]==1) {
				cnt++;
				copy_map[i][j]=0;
			}	
		}
	}
	return false;		
}

void init(vector< vector<int> >& vc)
{
	int count = 0;
	
	for(int i=0;i<vc.size();++i) {
		for(int j=0;j<vc[i].size();++j) {
			if(count == 3)
				return ;
			vc[i][j] = 1;
			count ++;
		}
	}
			
}

bool valid_map(vector< vector<int> >const& vc1,
	vector< vector<int> > const& vc2)
{
	for(int i=0;i<vc1.size();++i)
		for(int j=0;j<vc1[i].size();++j)
			if(vc1[i][j]!=0 && vc2[i][j]!=0) 
				return false;
	return true;			
}

void virus(vector< vector<int> >& safe_map,int i, int j)
{
	if(i+1 < safe_map.size() && safe_map[i+1][j] == 0) {
		safe_map[i+1][j] = 2;
		virus(safe_map,i+1,j);
	}
	if(j+1 < safe_map[i].size() && safe_map[i][j+1] == 0) {
		safe_map[i][j+1] = 2;
		virus(safe_map,i,j+1);
	}
	if(i-1 >=0 && safe_map[i-1][j] == 0) {
		safe_map[i-1][j] = 2;
		virus(safe_map,i-1,j);
	}
	if(j-1 >=0 && safe_map[i][j-1] == 0) {
		safe_map[i][j-1] = 2;	
		virus(safe_map,i,j-1);
	}
}

int safe_area(vector< vector<int> >const & map, vector< vector<int> >const&  input_map)
{
	vector< vector<int> > safe_map(map);
	for(int i=0;i<map.size();++i)
		for(int j=0;j<map[i].size();++j)
			safe_map[i][j]+=input_map[i][j];
	//print(safe_map);
	for(int i=0;i<map.size();++i)
		for(int j=0;j<map[i].size();++j)
			if(safe_map[i][j]==2)
				virus(safe_map,i,j);	
	//print(safe_map);
	int rev = 0;
	for(int i=0;i<safe_map.size();++i)
		for(int j=0;j<safe_map[i].size();++j)
			if(safe_map[i][j] == 0)
				rev++;
	return rev;					
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	
	vector< vector<int> > map(N,vector<int>(M));
	input(map);
	
	vector< vector<int> > input_map(N, vector<int>(M));
	init(input_map);
	
	int val, max = 0;

	do {
		if(valid_map(map,input_map)) {
			val = safe_area(map,input_map);
			if(val > max)
			max = val; 
		}
	} while(next(input_map));
	
	cout << max << endl;
	return 0;
}
