/*
ID: smoteva1
LANG: C++
TASK: ariprog
*/
#include <iostream>
#include <map>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

bool is(int a, int M) {
	bool val = false;
	for(int i=0;i<=M;i++) {
		for(int j=i;j<=M;j++) {
			int n = (i*i) + (j*j);
			if(n == a) {
				val = true;
				break;
			}
		}
	}
	return val;
}

int main() {
	ifstream my;
	my.open ("ariprog.in");
	int N;
	int M;
	my >> N >> M;
	my.close();


    int res = 0;
	ofstream myfile;
	myfile.open("ariprog.out");
	int max = 2*M*M-N;
	int max2 = (2*M*M+1)/N +3*N;


    /////////////////////TRUE FALSE FO ALL NUMBERS
    int h = 2*M*M;
	bool what[h];
	for(int i=0;i<h;i++) {
		what[i] = false;
	}
	for(int i=0;i<=M;i++) {
		for(int j=0;j<=M;j++) {
			int n = (i*i)+(j*j);
			what[n] = true;
		}
	}
	//////////////////////////////////////////



	for(int i=1;i<max;i++) {
		for(int j=0;j<max;j++) {
			bool val = true;
			if(j+(N-1)*i > max+N+1) {
				break;
			}
			for(int k=0;k<N;k++) {
				int a = j+ (k*i);
				if( a > max+N ) {
					val = false;
					break;
				}
				else if( !what[a] ) {
					val = false;
					break;
				}
			}
			if(val) {
				myfile << j << " " << i << endl;
				res = res+1;
			}
		}
	}
	if(res == 0) {
		myfile << "NONE" << endl;
	}
	myfile.close();
}