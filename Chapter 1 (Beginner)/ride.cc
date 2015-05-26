/*
ID: smoteva1
LANG: C++
TASK: ride
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;


int main() {
	string comet;
	string group;
	ifstream my;
    my.open ("ride.in");
	my >> comet;
	my >> group;
	my.close();
	int a = 1; // mod 47 of comet
	int b = 1; // mod 47 of group
	for(int i=0;i< comet.length();++i) {
		int s = comet[i] - 'A' +1;
		a = (s%47)*a;
	}
	for(int i=0;i< group.length();++i) {
		int s = group[i] - 'A' +1;
		b = (s%47)*b;
	}
	if( (a%47) == (b%47) ) {
		cout << "GO" << endl;
	}
	else {
		cout << "STAY" << endl;
	}
	ofstream myfile;
    myfile.open ("ride.out");
    if( (a%47) == (b%47) ) {
		myfile << "GO" << endl;
	}
	else {
		myfile << "STAY" << endl;
	}
    myfile.close();
]]//http://angelmonroe.ca/photo_albums/2247