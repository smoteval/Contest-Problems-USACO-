/*
ID: smoteva1
LANG: C++
TASK: numtri
*/
#include <iostream>
#include <map>
#include <fstream>
#include <algorithm> 
using namespace std;

int best[1001][1001];

int findmax(int tri[][1001],int R,int i, int j) {
	if(i == R-1) {
		return tri[i][j];
	}
	else {
		if(best[i][j] != -1) {
			return best[i][j];
		}
		int a = tri[i][j];
		int b = findmax(tri,R,i+1,j);
		int c = findmax(tri,R,i+1,j+1);
		int m = max(b,c);
		best[i][j] = a+m;
		return a+m;
	}
}



int main() {
	for(int i=0;i<1000;i++) {
		for(int j=0;j<1000;j++) {
			best[i][j] = -1;
		}
	}
	ifstream my;
	my.open ("numtri.in");
	int R;
	my >> R;
	int tri[R][1001];
	for(int i=0;i<R;i++) {
		for(int j=0;j<=i;j++) {
			int n;
			my >> n;
			tri[i][j] = n;
		}
	}
	my.close();



	ofstream myfile;
	myfile.open("numtri.out");

	int res = findmax(tri,R,0,0);
	cout << res << endl;
	myfile << res << endl;
	myfile.close();

}