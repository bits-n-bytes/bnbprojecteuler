#include <iostream>
#include <set>
#include <cmath>
#include <ostream>
using namespace std;



unsigned int getTriNumber(unsigned int numInSequence);
set<unsigned int> getFactors(unsigned int number);
void printset(set<unsigned int> s);


int main()
{
	/*
	cout << "these are the 1st 10 triangular numbers:" << endl;
	for(int i = 1; i <= 10; i++)
	{
		cout << getTriNumber(i) << endl << "Factors: ";
		printset(getFactors(getTriNumber(i)));
	}
	*/
	for(unsigned int i = 0; i < UINT_MAX; i++)
	{
		cout << "\r" << i;
		if(getFactors(getTriNumber(i)).size() >= 500)
		{
			cout << endl << "We have a winner: It's " << getTriNumber(i) << endl;
			cout << "Factors: ";
			printset(getFactors(getTriNumber(i)));
			break;
		}
	}



	cout << "Press enter to close window" << endl;
	cin.get();
}




//triangular numbers
unsigned int getTriNumber(unsigned int numInSequence)
{
	unsigned int result = 1;
	for(unsigned int i = 2; i <= numInSequence; i++)
		result += i;
	return result;
}

set<unsigned int> getFactors(unsigned int number)
{
	set<unsigned int> result;
	for(unsigned int i = 1; i < sqrt(number); i++)
	{
		if (number % i == 0) //it's divisible
		{
			result.insert(i);
			result.insert(number/i);
		}
	}

	return result;
}

void printset(set<unsigned int> s)
{
	set<unsigned int>::iterator iter;
	for(iter=s.begin(); iter!=s.end();++iter)
	{
		cout<<(*iter)<< " ";
	}
	cout << endl;
}

