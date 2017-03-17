#include <iostream.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 21

int aff[10] = {0,0,0,0,0,0,0,0,0,0};      // aff[i] = affinity of digit i
int d;           // d is no. of digits to be printed

void generate(char current[], int place);

void main(){

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
		
		if(d > SIZE - 1)
		{
			cout << "\nWe currently support printing only " << SIZE - 1 << " digits in a numebr" << endl
				 << "Change SIZE in source code to print greater number of digits\n";
			goto digitcount;
		}

		char current[SIZE] = "";
		generate(current , 0);

	getch();
}

void generate (char current[], int place)
{
	if(place == d)
	{
		current[place] = '\0';
		printf("%s\n", current);
		return;
	}
	
	char temp[SIZE]; strcpy(temp, current);
	for(int i = (place == 0 ? 1 : 0) ; i <= 9; i++)
	{
		if (aff[i] == 0) continue;
		
		aff[i]--; 
		temp[place] = (char) (i + '0');
		generate (temp, place + 1);
		aff[i]++;
	}
}
