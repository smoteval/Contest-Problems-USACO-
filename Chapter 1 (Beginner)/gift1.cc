/*
ID: smoteva1
LANG: C++
TASK: gift1
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;


int main() {
	map <string, int> bank;
	map <string, int> ibank;
	ifstream my;
    my.open ("gift1.in");
    int j;
    my >> j;
    int r =0;
    map <int, string> shit;
    while(j != 0) {
    	string name;
    	my >> name;
    	bank[name]=0;
    	shit[r]=name;
    	r++;
    	j = j-1;
    }
    string s;
    while( my >> s) {
    	int a;
    	int b;
    	my >> a;
    	my >> b;
    	ibank[s]=a;
    	if(b!=0) {
    	bank[s] = bank[s] + (a%b);
    	int k = a/b;
    	for(int i =0; i< b;++i) {
    		string d;
    		my >> d;
    		bank[d] = bank[d] +  k;
    	} }
    }
	my.close();
	
	ofstream myfile;
	myfile.open("gift1.out"); 
    for(int i=0;i<r;i++) {
    	myfile << shit[i] << " " << bank[shit[i]] - ibank[shit[i]] << endl;
    }
    myfile.close();
}