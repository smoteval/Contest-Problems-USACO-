/*
ID: smoteva1
LANG: C++
TASK: transform
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

void printarr(int arr[][1000],int N) {
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void reflect(int arr[][1000],int N) {
	int m = N/2;
	for(int i=0;i<N;i++) {
		for(int j=0;j<m;j++) {
			int a = arr[i][j];
			int b = arr[i][N-j-1];
			arr[i][j] = b;
			arr[i][N-j-1] = a;
		}
	}
}

bool equal(int first[][1000],int second[][1000],int N) {
	bool val = true;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			if(first[i][j] != second[i][j]) {
				val = false;
				break;
			}
		}
	}
	return val;
}

void degree(int arr[][1000],int N) {
	int newarr [N][N];
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			newarr[i][j]=arr[i][j];
		}
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			arr[i][j] = newarr[N-j-1][i];
		}
	}
}

int main() {
	int N;
	ifstream my;
	my.open ("transform.in");
	my >> N;
	int first[N][1000];
	for(int i=0;i < N;i++) {
		for(int j=0;j < N;j++) {
			char s;
			my >> s;
			if (s == '-') {
				first[i][j] = 1;
			}
			if(s == '@') {
				first[i][j] = 2;
			}
		}
	}
	int second[N][1000];
	for(int i=0;i < N;i++) {
		for(int j=0;j < N;j++) {
			char s;
			my >> s;
			if (s == '-') {
				second[i][j] = 1;
			}
			if(s == '@') {
				second[i][j] = 2;
			}
		}
	}
	my.close();
	//**************************************END OF GETTING THE INPUT ***************************************
	ofstream myfile;
	myfile.open("transform.out");
	degree(first,N);
	if(equal(first,second,N)) {
		myfile << "1" << endl;
		myfile.close();
		return 0;
	}

	degree(first,N);
	if(equal(first,second,N)) {
		myfile << "2" << endl;
		myfile.close();
		return 0;
	}

	degree(first,N);
	if(equal(first,second,N)) {
		myfile << "3" << endl;
		myfile.close();
		return 0;
	}

	degree(first,N);
	if(equal(first,second,N)) {
		myfile << "6" << endl;
		myfile.close();
		return 0;
	}

	reflect(first,N);
	if(equal(first,second,N)) {
		myfile << "4" << endl;
		myfile.close();
		return 0;
	}

	degree(first,N);
	if(equal(first,second,N)) {
		myfile << "5" << endl;
		myfile.close();
		return 0;
	}

	degree(first,N);
	if(equal(first,second,N)) {
		myfile << "5" << endl;
		myfile.close();
		return 0;
	}

	degree(first,N);
	if(equal(first,second,N)) {
		myfile << "5" << endl;
		myfile.close();
		return 0;
	}


	myfile << "7" << endl;
	myfile.close();
	return 0;



}