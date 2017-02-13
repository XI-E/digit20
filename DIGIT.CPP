#include <iostream.h>
#include <math.h>
#include <conio.h>

int aff[10] = {0,0,0,0,0,0,0,0,0,0};      // aff[i] = affinity of digit i
int d;           // d is no. of digits to be printed

void main(){

	int spool(int, double, double);

	clrscr();

		//////////////////////////////////
		//	Input

		cout << "Enter digits in succession (enter -1 to end input) : \n";

		for(int i=0; i<1;  ){
			int lol;
			cin >> lol;

				if(lol == -1){
					i++;
				}

				else if(lol>9 || lol<0){
					cout << "\n" << lol <<" - Input skipped\n";  	 // Ignores any invalid input
				}

				else{
					aff[lol]++;
				}
		}

		cout << "\n ";

		for(int j=0; j<10; j++){
			if(aff[j]!=0){
				cout << j << " ";
			}
		}

		int max = aff[0]+aff[1]+aff[2]+aff[3]+aff[4]+aff[5]+aff[6]
				  +aff[7]+aff[8]+aff[9];

		cout << "\nTotal entered digits : " << max;

		// Input ends
		//////////////////////////////////
		// Real Sh*t begins

		digitcount:

		cout << "\nEnter no. of digits in numbers to be printed : ";
		cin >> d;

		if(d>max || d<1){
			cout << "\nInvalid input, plz try again";
			goto digitcount;
		}

		spool(0,0,0);

	getch();
}

int spool(int rc, double m, double mn){          	// rc = run-count
	if(rc==d){
		cout.precision(d);
		cout << m << ' '; //<< "     " << mn;       // Testing stuff
	}
	else{
		for(int t = (rc==0 ? 1 : 0); t<10; t++){
			if(aff[t]!=0){
				aff[t]--;
				int n = d - rc - 1;
				mn = m;
				m += t*(pow(10,n));
				rc++;
				///////////////////////////
				rc = spool(rc, m, mn);
				m = mn;
				///////////////////////////

				aff[t]++;
			}
		}
	}
	rc--;
	return rc;
}

