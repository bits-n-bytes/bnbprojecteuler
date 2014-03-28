#include <iostream>
using namespace std;

const int ARRAY_SIZE= 320;
const int LIMIT = 1000;

int main()
{
	int intArray[ARRAY_SIZE] = {};	//holds digits

	int currentNumDigits = 0;

	intArray[0] = 1;				//first element is 1

	for (int i = 0; i < LIMIT; i++)	//multiply the first element by 2 1000 times
	{
		for (int j = ARRAY_SIZE-2; j >= 0; j--)
		{
			intArray[j] *= 2;

			//Check to see if intArray[i] is more than one digit:
			if(intArray[j] / 10 != 0)
			{
				//If it is, we need to move the tens place to the next digit:
				intArray[j+1] += intArray[j] / 10;
				intArray[j] %= 10;
			}
		}
	}

	//Print the intarray:
	cout << endl << "Contents of intArray loaded with 2^" << LIMIT << ":\n";
	for (int i = ARRAY_SIZE - 1; i >= 0; i--)
		cout << intArray[i];

	//Add up the contents of the array:
	int result = 0;
	for (int i = ARRAY_SIZE - 1; i >= 0; i--)
		result += intArray[i];

	cout << endl << endl << "Result of adding up all digits in intArray: " << result << endl;

}