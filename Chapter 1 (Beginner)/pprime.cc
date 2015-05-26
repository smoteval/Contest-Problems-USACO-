/*
ID: smoteva1
LANG: C++
TASK: pprime
*/
#include <iostream>
#include <map>
#include <fstream>
#include <algorithm> 
#include <math.h>
using namespace std;


bool isPrime (int num)
{
    if (num <=1)
        return false;
    else if (num == 2)         
        return true;
    else if (num % 2 == 0)
        return false;
    else
    {
        bool prime = true;
        int divisor = 3;
        double num_d = static_cast<double>(num);
        int upperLimit = static_cast<int>(sqrt(num_d) +1);
        
        while (divisor <= upperLimit)
        {
            if (num % divisor == 0)
                prime = false;
            divisor +=2;
        }
        return prime;
    }
}

int main() {
	ifstream my;
	my.open ("pprime.in");
	int a,b;
	my >> a >> b;
	my.close();
	ofstream myfile;
	myfile.open("pprime.out");


     
    //1 digits
    for(int d1=1;d1<10;d1+=2) {
    	int n =  d1;
    	if( (n >= a) && n <=b) {
    		if(isPrime(n)) {
    			myfile << n << endl;
    		}
    	}
    }

    //2 digits
    for(int d1=1;d1<10;d1+=2) {
    	int n = 10*d1 + d1;
    	if(n >=a && n <=b) {
    		if(isPrime(n)) {
    			myfile << n << endl;
    		}
    	}
    }
    
    //3 digits
    for(int d1=1;d1<10;d1+=2) {
    	for(int d2=0;d2<10;d2++) {
    		int n = 100*d1 + 10*d2 + d1;
    		if(n >= a && n <= b) {
    			if(isPrime(n)) {
    				myfile << n << endl;
    			}
    		}
    	}
    }
   
    //4 digits
    for(int d1=1;d1<10;d1+=2) {
    	for(int d2=0;d2<10;d2++) {
    		int n = 1000*d1 + 100*d2 + 10*d2 + d1;
    		if(n >= a && n <= b) {
    			if(isPrime(n)) {
    				myfile << n << endl;
    			}
    		}
    	}
    }


    //5 digits
	for(int d1=1;d1<10;d1+=2) {
		for(int d2=0;d2<10;d2++) {
			for(int d3=0;d3<10;d3++) {
				int n = 10000*d1 + 1000*d2 + 100*d3 + 10*d2 + d1;
				if(n >=a && n <=b) {
					if( isPrime(n) ) {
						myfile << n << endl;
					}
				}
			}
		}
	}

    //6 digits
	for(int d1=1;d1<10;d1+=2) {
		for(int d2=0;d2<10;d2++) {
			for(int d3=0;d3<10;d3++) {
				int n = 100000*d1 + 10000*d2 + 1000*d3 + 100*d3 + 10*d2 + d1;
				if(n >=a && n <=b) {
					if( isPrime(n) ) {
						myfile << n << endl;
					}
				}
			}
		}

	}





    //7 digits
	for(int d1=1;d1<10;d1+=2) {
		for(int d2=0;d2<10;d2++) {
			for(int d3=0;d3<10;d3++) {
				for(int d4=0;d4<10;d4++) {
					int n = 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4 + 100*d3 + 10*d2 + d1;
					if(n >=a && n<= b) {
						if( isPrime(n) ) {
							myfile << n << endl;
						}
					}
				}
			}
		}
	}
    
    //8 digits
	for(int d1=1;d1<10;d1+=2) {
		for(int d2=0;d2<10;d2++) {
			for(int d3=0;d3<10;d3++) {
				for(int d4=0;d4<10;d4++) {
					int n = 10000000*d1 + 1000000*d2 + 100000*d3 + 10000*d4 +1000*d4 + 100*d3 + 10*d2 + d1;
					if(n >=a && n<= b) {
						if( isPrime(n) ) {
							myfile << n << endl;
						}
					}
				}
			}
		}
	}
	myfile.close();

}



