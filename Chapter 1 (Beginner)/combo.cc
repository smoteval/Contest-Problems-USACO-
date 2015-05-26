/*
ID: smoteva1
LANG: C++
TASK: combo
*/
#include <iostream>
#include <map>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
bool within(int arr[],int a,int b, int c, int N) {
	bool val = true;
	if( abs(arr[0]-a) > 2 ) {
		if(arr[0] < a) {
			int l = arr[0] + N;
			if( abs(l - a) > 2 ) {
				val = false;
			}
		}
		else {
			a = a + N;
			if( abs(arr[0] - a) > 2 ) {
				val = false;
			}
		}
	}


	if( abs(arr[1]-b) > 2 ) {
		if(arr[1] < b) {
			int l = arr[1] + N;
			if( abs(l - b) > 2 ) {
				val = false;
			}
		}
		else {
			b = b + N;
			if( abs(arr[1] - b) > 2 ) {
				val = false;
			}
		}
	}


	if( abs(arr[2]-c) > 2 ) {
		if(arr[2] < c) {
			int l = arr[2] + N;
			if( abs(l - c) > 2 ) {
				val = false;
			}
		}
		else {
			c = c + N;
			if( abs(arr[2] - c) > 2 ) {
				val = false;
			}
		}
	}
	return val;
}


int main() {
	ifstream my;
	my.open ("combo.in");
	int N;
	my >> N;
	int farmer[3];
	int master[3];
	for(int i=0;i<3;i++) {
		int n;
		my >> n;
		farmer[i] = n;
	}
	for(int i=0;i<3;i++) {
		int n;
		my >> n;
		master[i] = n;
	}
	/// End of INPUT
	int res = 0;

	for(int i1=1;i1<=N;i1++) {
		for(int i2=1;i2<=N;i2++) {
			for(int i3=1;i3<=N;i3++) {
				if(within(farmer,i1,i2,i3,N) || within(master,i1,i2,i3,N)) {
					res = res+1;
				}
				else {
					//cout << i1 << " " << i2 << " " << i3 << endl;
				}
			}
		}
	}

	ofstream myfile;
	myfile.open("combo.out");
	myfile << res << endl;
	myfile.close();

}