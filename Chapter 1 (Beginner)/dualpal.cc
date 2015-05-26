/*
ID: smoteva1
LANG: C++
TASK: dualpal
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;
int n[1000];
int i =0;


void base(int m, int B) {
	int q = m/B;
	int r = m%B;
	n[i] = r;
	i = i+1;
	if(q != 0) {
		base(q,B);
	}
}

bool pol(int k) {
	int m = k/2;
	int val = true;
	for(int j=0;j<m;j++) {
		int a = n[j];
		int b = n[k-1-j];
		if(a != b) {
			val = false;
			break;
		}
	}
	return val;
}



int main() {
	ifstream my;
	my.open ("dualpal.in");
	int N;
	int S;
	my >> N;
	my >> S;
	my.close();



    ofstream myfile;
    myfile.open("dualpal.out");
    int num = 0;
    int stuff = 0;
	for(int j=S+1;true;j++) {
		if(stuff == N) {
			break;
		}
		for(int k=2;k<11;k++) {
			i=0;
			base(j,k);
			if(pol(i)) {
				num = num + 1;
			}
		}
		if(num >= 2) {
			myfile << j << endl;
			stuff = stuff + 1;
		}
		num = 0;
	}
	myfile.close();
	return 0;
}