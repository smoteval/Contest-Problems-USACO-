/*
ID: smoteva1
LANG: C++
TASK: palsquare
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

string nemi(int p) {
	if(p >= 10) {
		if (p == 10) {
			return "A";
		}
		if (p == 11) {
			return "B";
		}
		if (p == 12) {
			return "C";
		}
		if (p == 13) {
			return "D";
		}
		if (p == 14) {
			return "E";
		}
		if (p == 15) {
			return "F";
		}
		if (p == 16) {
			return "G";
		}
		if (p == 17) {
			return "H";
		}
		if (p == 18) {
			return "I";
		}
		if (p == 19) {
			return "J";
		}
		if (p == 11) {
			return "B";
		}

	}
	else {
		return "";
	}
}


int main() {
	ifstream my;
	my.open ("palsquare.in");
	int B;
	my >> B;
	my.close();

    ofstream myfile;
    myfile.open("palsquare.out");


	for(int j=1;j<=300;j++) {
		i=0;
		int a = j*j;
		base(a,B);
		if(pol(i)) {
			i=0;
			base(j,B);
			for(int r=0;r<i;r++) {
				int t = n[i-1-r];
				if(t<10) {
					myfile << t;
				}
				else {
					myfile << nemi(t);
				}
			}
			myfile << " ";
			i=0;
			base(a,B);
			for(int r=0;r<i;r++) {
				int t = n[i-1-r];
				if(t<10) {
					myfile << t;
				}
				else {
					myfile << nemi(t);
				}
			}
			myfile << endl;
		}
	}
	myfile.close();
}
