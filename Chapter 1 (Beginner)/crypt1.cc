/*
ID: smoteva1
LANG: C++
TASK: crypt1
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

bool isin(int arr[], int N, int n) {
	bool val = false;
	for(int i=0;i<N;i++) {
		if(arr[i] == n) {
			val = true;
			break;
		}
	}
	return val;
}


int main() {
	ifstream my;
	my.open ("crypt1.in");
	int N;
	my >> N;
	int digits[N];
	for(int i=0;i<N;i++) {
		int n;
		my >> n;
		digits[i] = n;
	}
	my.close();
	/////////////End of input
	int res = 0;
	//// sorting the array
	for(int i=0;i<N;i++) {
		for(int j=i;j<N;j++) {
			if(digits[j] < digits[i]) {
				int a = digits[i];
				int b = digits[j];
				digits[i] = b;
				digits[j] = a;
			}
		} 
	}
	/// End of sorting




	for(int j1=0;j1<N;j1++) {
		for(int j2=0;j2<N;j2++) {
			for(int i1=0;i1<N;i1++) {
				for(int i2=0;i2<N;i2++) {
					for(int i3=0;i3<N;i3++) {
						int n1 = digits[j1]*(digits[i3]+10*digits[i2]+100*digits[i1]);
						int n2 = digits[j2]*(digits[i3]+10*digits[i2]+100*digits[i1]);
						int n = n1 + 10*n2;
						if(n%10000 == n && n1%1000 == n1 && n2%1000 == n2) {
							int a = n%10;
							n = n - a;
							n = n / 10;
							int b = n%10;
							n = n - b;
							n = n/10;
							int c = n%10;
							n = n - c;
							int d = n / 10;
							////
							int a1 = n1%10;
							n1 = n1 - a1;
							n1 = n1 /10;
							int a2 = n1%10;
							n1 = n1 - a2;
							n1 = n1/10;
							int a3 = n1;

							///
							int b1 = n2%10;
							n2 = n2 - b1;
							n2 = n2 /10;
							int b2 = n2%10;
							n2 = n2 - b2;
							n2 = n2/10;
							int b3 = n2;


							if(isin(digits,N,a) && isin(digits,N,b) && isin(digits,N,c) && isin(digits,N,d)
								&& isin(digits,N,a1) && isin(digits,N,a2) && isin(digits,N,a3)
								&& isin(digits,N,b1) && isin(digits,N,b2) && isin(digits,N,b3)) {
								res = res+1;
							}
						}
						else {
							break;
						}
					}
				}
			}
		}
	}



	ofstream myfile;
	myfile.open("crypt1.out");
	myfile << res << endl;
	myfile.close();
}