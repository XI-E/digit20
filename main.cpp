#include <iostream>
#include <math.h>
#include <ctype.h>
#include <thread>
#include "rlutil.h"

using namespace std;

int freq[10], num_digits;

void gen_nums(int curr_place, unsigned long long curr_num = 0);
void esc_exit();

int main(void)
{
	for(int i = 0; i < 10; i++)
	{
		freq[i] = 0;
	}

	int a;
	while(true)
	{
		cin >> a;
		if(a <= 9 && a >= 0)
		{
			freq[a]++;
		}
		else if(a == -1)
		{
			break;
		}
		else
		{
			cout << "\nInput Skipped - " << a << endl;
		}
	}
	
	int total_digits = 0;
	cout << endl;
	for(int i = 0; i < 10; i++)
	{
		total_digits += freq[i];
		if(freq[i] != 0)
		{
			cout << i << ' ';
		}
	}
	cout << endl;
	
	cout << "Total Number of digits: " << total_digits << endl;
		
	do
	{
		cout << "Enter the number of digits for which numbers are to be generated: ";
		cin >> num_digits;
	}
	while(num_digits > total_digits || num_digits < 0);
	
	std::thread p = std::thread(esc_exit);
	gen_nums(num_digits);		
	cout << endl;
}

void gen_nums(int curr_place, unsigned long long curr_num)
{	
	if(curr_place == 0)
	{
		cout << curr_num << "\n";
		return;
	}

	for(int i = (curr_place == num_digits ? 1 : 0); i < 10; i++)
	{
		if(freq[i] != 0)
		{
			freq[i]--;
			
			unsigned long long temp = curr_num + i * pow(10, curr_place - 1);
			
			gen_nums(curr_place - 1, temp);
			
			freq[i]++;
		}
	}
}

void esc_exit()
{
	std::cin.ignore(1000, '\n');
	while(true)
	{
		if(kbhit())
		{
			std::cout.flush();
			exit(1);
		}
	}
}
