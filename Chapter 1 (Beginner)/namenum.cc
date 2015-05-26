/*
ID: smoteva1
LANG: C++
TASK: namenum
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;


int main() {
	char a[10][3];
	a[2][0] = 'A'
	/// Gettting Input
	ifstream my;
	my.open ("namenum.in");
	char s;
	char n[12];
	int size;
	for(size=0;my >> s;size++) {
		n[size] = s;
	}
	my.close();
	/// DONE getting input
	ifstream dict;
	dict.open(dict.txt);
	string s;
	int k =  0;
	int r = 0;
	for(int i=0;dict >> s;) {
		if(a[n[k]][r] = s[k]) {
			if(size != s.length()) {

			}
			else {
				k = k+1;
			}
		}
	}
    
}