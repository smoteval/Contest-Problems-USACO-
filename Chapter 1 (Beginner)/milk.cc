/*
ID: smoteva1
LANG: C++
TASK: milk
*/
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main() {
	//// READING THE INPUT
	ifstream my;
	my.open ("milk.in");
	int N; // the amount of milk they want
	int M; //The number of farmers that make milk
	my >> N;
	my >> M;
	int price[M];
	int amount[M];
	for(int i=0;i<M;i++) {
		int p;
		int a;
		my >> p;
		my >> a;
		price[i] = p;
		amount[i] = a;
	}
	//// ENd oF INPut
	int cost = 0;

	while(N != 0) {
		int index = 0;
		for(int i=0;i<M;i++) {
			if(price[i] < price[index]) {
				index = i;
			}
		}
		if(N >= amount[index]) {
			N = N - amount[index];
			cost = cost + price[index]*amount[index];
		}
		else {
			cost = cost + N*price[index];
			N = 0;
		}
		price[index] = 100000000;
	}
	ofstream myfile;
	myfile.open("milk.out");
	myfile << cost << endl;;
	myfile.close();

}