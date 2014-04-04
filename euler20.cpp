#include <iostream>
using namespace std;

/*
 * BigIntegerLibrary.hh is a library I downloaded from https://mattmccutchen.net/bigint/index.html.
 * It appears to work well for these projects, although I haven't tested it extensively.
 * Using this library, the code to solve this problem is very simple, and can be written very quickly.
 * It could come in very handy for future Project Euler problems.
 * But if you don't want to use that code, I found another solution, using an array of short ints.
 */
#include "BigIntegerLibrary.hh"


const int ARRAY_SIZE= 160;
const int LIMIT = 100;
const int DIGITS_IN_LIMIT = 3;
const int BASE = 10;

void fixDigits(short int* const, const short int* const);

int main()
{
	//Solve the problem using the BigInteger class:
	#ifdef BIGINTEGER_H
	{
		BigInteger myBigInt(1);
		//Figure out 100!, by multiplication:
		for(int i = 1; i <= LIMIT; i++)
		{ 
			myBigInt *= i; 
		}
		cout << LIMIT << "! is:\n  " << myBigInt << endl;

		//Now add up the digits:
		BigInteger result = 0;
		while(myBigInt != 0)
		{
			result += (myBigInt % BASE);
			myBigInt /= BASE;
		}

		cout << "Result is: " << result << endl;

	}
	#endif

	//Solve it again without BigIntegers:
	//This solution uses an array of short ints to model one big integer.
	
	short int intArray[ARRAY_SIZE] = {};	//holds digits
	intArray[0] = 1;				//first element is 1

	for (int i = 1; i <= LIMIT; i++)	//multiply the number represented in intArray by 'i' 100 times
	{
		//Starting with the highest end of the number, multiply each digit by 2,
		//and fix that digit and all leading digits so they still fit into one digit.
		for (int currentDigit = ARRAY_SIZE-1; currentDigit >= 0; currentDigit--)
		{
			intArray[currentDigit] *= i;
			fixDigits(&intArray[currentDigit], &intArray[ARRAY_SIZE-1]);	
		}
	}

	//Print the intarray:
	cout << endl << "Contents of intArray loaded with " << LIMIT << "!:\n";
	for (int i = ARRAY_SIZE - 1; i >= 0; i--)
		cout << intArray[i];


	//Add up the contents of the array:
	int int32result = 0;
	for (int i = ARRAY_SIZE - 1; i >= 0; i--)
		int32result += intArray[i];

	cout << endl << endl << "Result of adding up all digits in intArray: " << int32result << endl;
	
	cin.get();
}

//This is a recursive function; I found that it was a lot easier to write the recursive solution to this problem
//than to write an iterative solution. I'm sure it's possible to do it iteratively, but I got confused doing it that way.
//Basically, this function takes a number that exists in an array (ptrDigitToFix), cuts out everything that doesn't fit 
//into one digit, and distrubutes everything that doesn't fit into the next elements of the array.
//The other parameter (dontGoPastHere) exists as a sentry to prevent this function from writing to memory it shouldn't have access to.
void fixDigits(short int* const ptrDigitToFix, const short int* const dontGoPastHere)
{
	if(*ptrDigitToFix / BASE == 0){ return; }	//If the digit to fix is only one digit, we're done.
										//Otherwise we need to move the excess to the next digit, 
	else if(ptrDigitToFix < dontGoPastHere)		//but don't run off the end of the array!
	{
		*(ptrDigitToFix+1) += (*ptrDigitToFix / BASE);	//Push everthing that's not in the first digit into the next digit
		fixDigits(ptrDigitToFix+1, dontGoPastHere);		//And fix the digits we just added to
		*ptrDigitToFix %= BASE;						//Now truncate the integer we're working with so it fits in one digit
	}
	else
	{
		*ptrDigitToFix %= BASE; //just throw the excess away
		return;
	}
}
