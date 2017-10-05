/*
*Created by: Connor Schultz
*Project5-2250.cpp
*May 10, 2017
*4:57:56 PM
*/
#include <iostream>
#include <string> //Needed for string methods
#include <cstdlib> //Needed for rand function
#include <ctime> //Needed for the time of computer
#include <utility> //Needed for the swap function

using namespace std;

//Create your prototypes of the four functions that are needed
void selectionSort(int [], int);
void bubbleSort(int [], int);
int reversal(int);
string sReversal(string);

int main()
{
	//Create a size variable so when your change the size your don't have to worry about
	//forgetting to change some of the loops
	int size = 20;
	int array1[size];
	int array2[size];


	//Create variables that will be read in later on in the code by the user
	int num;
	string word;
	string rWord;

	//set the rand to the computer's time
	srand(time(NULL));

	cout << "Please input a number to reverse" << endl;

	//Read in the number that the user wants to reverse
	cin >> num;

	//Call the reversal recursive function
	reversal(num);
	cout << endl;

	cout << "Please input a word to reverse" << endl;

	//Read in the word the user wants to reverse
	cin >> word;

	//Set a string variable to the recursive function
	rWord = sReversal(word);

	//Cout the new string variable
	cout << rWord << endl;

	cout << "Creating Array1" << endl;

	for(int i = 0; i < size; i++)
	{
		//Go through the array and set a random number between 1-100
		array1[i] = rand() % 101;

		//Print out each element as you set it
		cout << array1[i] << endl;
	}

	cout << "Sorting Array1" << endl;

	//Call the selectionSort recursive function to sort the array
	selectionSort(array1, size);

	for(int i = 0; i < size; i++)
	{
		//Print out the new array
		cout << array1[i] << endl;
	}

	cout << "Creating Array2" << endl;

	for(int i = 0; i < size; i++)
	{
		//Create array2 with numbers between 1 and 100
		array2[i] = rand() % 101;

		//Print out the unsorted array
		cout << array2[i] << endl;
	}

	cout << "Sorting Array2" << endl;

	//Call bubbleSort recursive function with array2
	bubbleSort(array2, size);

	for(int i = 0; i < size; i++)
	{
		//Print out the new array2
		cout << array2[i] << endl;
	}
}

void selectionSort(int array[], int size)
{
	//Set three values all to 0
	int maxVal = 0;
	int temp = 0;
	int i = 0;

	//Start a for loop with i = to another value of initial 0
	for(i = maxVal; i < size; i++)
	{
		//Have an if statement to check if the i value is greater than the maxValue
		if(array[i] > array[maxVal])
		{
			//Set the maxValue to the i value
			maxVal = i;
		}
	}

	//Set the temp var to the array[size - 1]
	temp = array[size - 1];
	//Set that new value to the maxValue subscript
	array[size - 1] = array[maxVal];
	//Then set the maxValue subscript to the temp
	array[maxVal] = temp;

	//Set an if statement if the size is still > 1 and then call selectionSort again with size - 1
	if(size > 1)
	{
		selectionSort(array, --size);
	}
}

void bubbleSort(int array[], int size)
{
	if(size == 1)
	{
		return;
	}

	//Start a for loop to go through the array of just the size
	for(int i = 0; i < size - 1; i++)
	{
		//Set a if statement to test if the i value is greater than i+1
		if(array[i] > array[i+1])
		{
			//If it is use the swap method to change out i subscript with i+1 subscript
			swap(array[i], array[i+1]);
		}
	}

	//Call the bubbleSort method with the array and size - 1
	bubbleSort(array, --size);
}


int reversal(int number)
{
	//Set a sum variable to 0
	int sum = 0;

	//If number is still true while looping
	if(number)
	{
		//print out the reversed number at the end
		cout << (number % 10);

		//Set the sum to the call of the method divided by 10
		sum = reversal(number / 10);
	}
	return sum;
}


string sReversal(string word)
{
	//If the length of the word is just a character return the letter
	if(word.length() == 1)
	{
		return word;
	}

	//Else call the method recursivley with the substr starting at location 1 and going to the the length of the rest
	//of the word at location 0
	else
	{
		return sReversal(word.substr(1, word.length())) + word.at(0);
	}

}
