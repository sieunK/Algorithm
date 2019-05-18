#include <iostream>
#include <vector>

using namespace std;

struct Cleaner {
	int r,c;
public:
	void input(int _r, int _c) {
		r = _r;
		c = _c;
	}	
};

void print(const vector<vector<int> >& vc)
{
	for(int r=0;r<vc.size();++r) {
		for(int c=0;c<vc[r].size();++c)
			cout << vc[r][c] << ' ';
		cout << endl;	
	}
	cout << endl;
}

bool is_valid(int r, int c, int row, int col)
{
	return
		0<=r && r<row &&
		0<=c && c<col;
}

bool not_cleaner(int r, int c, const vector<Cleaner>& air_cleaner)
{
	for(int i=0;i<air_cleaner.size();++i) {
		if(air_cleaner[i].r==r && air_cleaner[i].c==c)
			return false;
	}
	return true;
}

void clean(vector<vector<int> >& vc,
	const vector<Cleaner>& air_cleaner)
{
	int col = vc[0].size();
	int row = air_cleaner[0].r;
	for(int r=row-1;r>0;--r)
		vc[r][0] = vc[r-1][0];
	
	for(int c=0;c<col-1;++c)
		vc[0][c] = vc[0][c+1];
	
	for(int r=0;r<row;++r)
		vc[r][col-1] = vc[r+1][col-1];
	
	for(int c=col-1;c>1;--c)
		vc[row][c] = vc[row][c-1];	
	vc[row][1] = 0;	
	
	row = air_cleaner[1].r;
	for(int r=row+1;r<vc.size()-1;++r)
		vc[r][0] = vc[r+1][0];
	
	for(int c=1;c<col;++c)
		vc[vc.size()-1][c-1] = vc[vc.size()-1][c];
	
	for(int r=vc.size()-1;r>row;--r)
		vc[r][col-1] = vc[r-1][col-1];
	
	for(int c=col-1;c>1;--c)
		vc[row][c] = vc[row][c-1];
	vc[row][1] = 0;						
}

vector<vector<int> > diffusion(vector<vector<int> > const& vc, 
	const vector<Cleaner>& air_cleaner)
{
	int num;
	vector<vector<int> > copy_vc(vc.size(),vector<int>(vc[0].size(),0));
	
	for(int r=0;r<vc.size();++r) {
		for(int c=0;c<vc[r].size();++c) {
			if(vc[r][c] > 0) {
				num = 0;
				int amount = vc[r][c]/5;
				if(is_valid(r-1,c,vc.size(),vc[r].size()) &&
					not_cleaner(r-1,c,air_cleaner)) {
					copy_vc[r-1][c] += amount;
					num++;
				}
				if(is_valid(r+1,c,vc.size(),vc[r].size()) &&
					not_cleaner(r+1,c,air_cleaner)) {
					copy_vc[r+1][c] += amount;
					num++;
				}
				if(is_valid(r,c-1,vc.size(),vc[r].size()) &&
					not_cleaner(r,c-1,air_cleaner)) {
					copy_vc[r][c-1] += amount;
					num++;
				}
				if(is_valid(r,c+1,vc.size(),vc[r].size()) &&
					not_cleaner(r,c+1,air_cleaner)) {	
					copy_vc[r][c+1] += amount;
					num++;			
				}
			}
			copy_vc[r][c] += vc[r][c]-vc[r][c]/5*num;
		}
	}
	return copy_vc;
}

int total_dust(const vector<vector<int> >& vc)
{
	int sum = 0;
	for(int r=0;r<vc.size();++r)
		for(int c=0;c<vc[r].size();++c)
			if( vc[r][c] > 0 )
				sum += vc[r][c];
	
	return sum;		
}

int main(void)
{
	int R, C, T;
	cin >> R >> C >> T;
	
	vector<Cleaner> air_cleaner(2);
	int num = 0;
	vector<vector<int> > info(R,vector<int>(C));
	for(int r=0;r<R;++r)
		for(int c=0;c<C;++c) {
			cin >> info[r][c];
			if(info[r][c] == -1)
				air_cleaner[num++].input(r,c);
		}		
	
	for(int t=0;t<T;++t) {
		info = diffusion(info,air_cleaner);
		clean(info,air_cleaner);
	}
	
	int answer = total_dust(info);
	cout << answer << endl;
	return 0;
}
