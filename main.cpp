#include <iostream>
#include <math.h>
#include <ctype.h>

typedef long long ll;

using namespace std;

int aff[10] = {0,0,0,0,0,0,0,0,0,0};        // aff[i] = affinity of digit i
int d;                                      // d is no. of digits to be printed

int main(void){

	int spool(int = 0, ll = 0, ll = 0);

	//clrscr();

		//////////////////////////////////
		//	Input

		start:
		cout << "Enter digits in succession (enter -1 to end input) : \n";

		for(int i=0; i<1;  ){
			int inp;
			cin >> inp;
                if(isdigit(inp)){
                    goto skip;
                }
				if(inp == -1){
					i++;
				}
				else{
					aff[inp]++;
				}
            goto inp_end;
            skip:
            {
                cout << "\n" << inp <<" - Input skipped\n";  	 // Ignores any invalid input
            }
            inp_end:
                ;
		}

		cout << "\n ";

		for(int j=0; j<10; j++){
			if(aff[j]!=0){
				cout << j << " ";
			}
		}

		int max = aff[0]+aff[1]+aff[2]+aff[3]+aff[4]+aff[5]+aff[6]
				  +aff[7]+aff[8]+aff[9];

        if(max==0){
            cout << "No valid input\n";
            goto start;
        }

		cout << "\nTotal entered digits : " << max;

		// Input ends
		//////////////////////////////////
		// Real Sh*t begins

		digitcount:

		cout << "\nEnter no. of digits in numbers to be printed : ";
		cin >> d;

		if(d>max || d<1){
			cout << "\nInvalid input, please try again";
			goto digitcount;
		}

		spool();

	return 0;
}

int spool(int rc, ll m, ll mn){                 	/* rc = run-count, signifies (n+1)th recursion
                                                       of function, printing (n+1)th digit
                                                    */
	if(rc==d){
		cout << m << ' ';
	}
	else{
		for(int t = (rc==0 ? 1 : 0); t<10; t++){
			if(aff[t]!=0){
				aff[t]--;
				int n = d - rc - 1;
				mn = m;
				m += t*(pow(10,n));
				rc++;

				rc = spool(rc, m, mn);
				m = mn;                             /* Returns the number to value before printing next digit
                                                            For example,
                                                                for digits 1 1 2 3
                                                                passes 110
                                                                prints 112
                                                                needs to print 113 as well,
                                                                so, returns 110 to next recursion
                                                    */

				aff[t]++;
			}
		}
	}
	rc--;                                           // When function completes, returns to previous recursion with lesser run count
	return rc;
}

