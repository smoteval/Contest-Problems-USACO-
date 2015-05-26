/*
ID: smoteva1
LANG: C++
TASK: milk2
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main() {
	/////////////////////////////INPUT//////////////////
	int N;
	ifstream my;
	my.open("milk2.in");
	my >> N;
	int start[N];
	int end[N];
	for(int i=0;i<N;i++) {
		int a,b;
		my >> a;
		my >> b;
		start[i] = a;
		end[i] = b;
	}
	my.close();
	/////////////////////////ALG/////////////////////////////
	int imin = 0;
	int imax = 0;
	for(int i=0;i<N;i++) {
		if(start[i] < start[imin]) {
			imin = i;
		}
	}
	for(int i=0;i<N;i++) {
		if(end[i] > end[imax]) {
			imax = i;
		}
	}
	int range = end[imax]-(start[imin]-1)-1;
	int stuff[range];
	int min = start[imin];
	int max = end[imax];
	for(int i=0;i<range;i++) {
		stuff[i] = 0;
	}
	for(int i=0;i<N;i++) {
		for(int j =start[i]-min ;j<end[i] - min;j++) {
			stuff[j] = 1;
		}
	}
	//testing:
	/*for(int i=0;i<range;i++) {
		cout << stuff[i] << endl;
	}*/
	//endtesting
	int max1 = 0;
	int max2 = 0;
	for(int i=0;i<range;i++) {
		int j = 0;
		while(stuff[i] == 1) {
			j = j+1;
			i = i+1;
		}
		if(j>max1) {
			max1 = j;
		}
	}
	for(int i=0;i<range;i++) {
		int j = 0;
		while(stuff[i] == 0) {
			j = j+1;
			i = i+1;
		}
		if(j>max2) {
			max2 = j;
		}
	}
    ////////////////////////////output///////////////////////
	ofstream myfile;
	myfile.open("milk2.out");
	myfile << max1 << " " << max2 << endl;
	myfile.close();
}