/*
ID: smoteva1
LANG: C++
TASK: beads
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main() {
	int N;
	string neck;
	ifstream my;
	my.open("beads.in");
	my >> N;
	my >> neck;
	my.close();
	int max = 0;
	for(int i=0;i<neck.length();i++) {
		int tempmax1 = 0;
		int tempmax2 = 0;
		char a = neck[i];
		int k;
		if(i != 0) k=i-1;
        else k=neck.length()-1;
		char b = neck[k];
		int flag = 1;
		int flag2 = 1;
		int flag3 = 1;
		int j = i;
        while( (neck[j] == a || neck[j] == 'w' || a == 'w') && flag != 0) {
        	tempmax1++;
        	cout << neck[j];
        	if( a == 'w' && neck[j] != 'w' && flag2 == 1) {
        		a = neck[j];
        		flag2=0;
        	}
        	j = (j+1)%neck.length();
        	if( j == i) flag = 0;
        }
        cout << endl;
        cout << "next" << endl;
        while( (neck[k] == b || neck[k] == 'w' || b == 'w') && flag != 0 )  {
        	tempmax2++;
        	if(j == k) flag = 0;
        	cout << neck[k];
        	if( b == 'w' && neck[k] != 'w' && flag3 == 1) {
        		b = neck[k];
        		flag3=0;
        	}
            if(k != 0) k--;
            else k=neck.length()-1;
        }
        cout << endl;
        cout << "complete" << endl;
        flag2 = 1;
        flag3 = 1;
        tempmax1 = tempmax1+tempmax2;
        if (tempmax1 > max) {
        	max = tempmax1;
        }
        cout << max << endl;
	}
	ofstream myfile;
	myfile.open("beads.out");
	myfile << max << endl;
	myfile.close();
}