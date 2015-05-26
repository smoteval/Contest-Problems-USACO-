/*
ID: smoteva1
LANG: C++
TASK: friday
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main() {
	int N;
	ifstream my;
	my.open("friday.in");
	my >> N;
	my.close();
	int week[7] = {0,0,0,0,0,0,0};
	int year;
	int day  = 1;
	for(year = 1900;year<1900+N;year++) {
		for(int j=0;j<12;j++) {
			if(j==0 || j== 2 || j==4 || j==6 || j==7 || j==9 || j==11) {
				for(int j1=0;j1<31;j1++) {
					if(j1 == 12) {
						week[day] = week[day]+1;
					}
					day = ((day+1)%7);
				}
			}
			if(j==3 || j==5 || j==8 || j==10) {
				for(int j2=0;j2<30;j2++) {
					if(j2 == 12) {
						week[day] = week[day]+1;
					}
					day = ((day+1)%7);
				}
			}
			if(j== 1) {
				if((year%400 == 0) || (year%100 !=0 && year%4 == 0) ) {
					for(int j3=0;j3<29;j3++) {
						if(j3 == 12) {
							week[day] = week[day]+1;
						}
						day = ((day+1)%7);
					}
				}
				else {
					for(int j4=0;j4<28;j4++) {
						if(j4 == 12) {
							week[day] = week[day]+1;
						}
						day = ((day+1)%7);
					}
				}
			}
		}
	}
	ofstream myfile;
	myfile.open("friday.out");
	myfile << week[6] << " "<< week[0] << " "<< week[1] << " "<< week[2] << " "<< week[3] << " "<< week[4] << " "<< week[5] << endl; 
	myfile.close();
}