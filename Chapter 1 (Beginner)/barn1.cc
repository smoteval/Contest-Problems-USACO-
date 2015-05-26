/*
ID: smoteva1
LANG: C++
TASK: barn1
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

bool isin(int arr[], int C, int n) {
	bool val = false;
	for(int i=0;i<C;i++) {
		if(arr[i] = n) {
			val = true;
			break;
		}
	}
	return val;
}

int main() {
	ifstream my;
	my.open ("barn1.in");
	int M; // maximum number of boards that can be purchased
	int S; // The total number of stalls
	int C; // The number of cows
	my >> M >> S >> C;
	int cows[C];
	for(int i=0;i<C;i++) {
		int n;
		my >> n;
		cows[i] = n;
	}
	////// End of input
	int start[S];
	int skips[S];
	int skip = 0;
	int j = 0;
	int k = 0;
	for(int i=0;i<S;i++) {
		if( !bool(i) ) {
			if (skip == 0) {
				start[j] = i;
				j = j+1;
			}
			skip =  skip + 1;
			skips[k] = skip;
		}
		else {
			if( skip != 0) {
				k = k+1;
				skip = 0;
			}
		}
	}
	for(int i=0;i<M-1;i++) {
		int index = 0;
		if(skips[i] > skips[index]) {
			index = i;
		}
		S = S - skips[index];
		skips[index] = 0;
	}
	ofstream myfile;
	myfile.open("barn1.out");
	myfile << S;
	myfile.close();
}