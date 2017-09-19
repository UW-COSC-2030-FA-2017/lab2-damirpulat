// ListProcessor.cpp

// tom bailey   1540  30 sep 2011

// tom bailey   1030  27 jan 2012
// Exercise the List class with verbose Node constructor
//   and destructor.

// Damir Pulatov
// COSC 2030
// Lab2
// 09/18/17

#include "LinkedList.h"


int main()
{
	List cows;
	cout << "cows list  :  " << cows << endl << endl;

	cows.insertAsFirst(1.23);
	cows.insertAsFirst(2.34);

	cout << "cows list  :  " << cows << endl << endl;

	cows.removeFirst();
	cows.insertAsLast(2);

	// Test sum method
	cout << "sum of doubles inside the list: " << cows.sum() << endl;

	cout << "cows list  :  " << cows << endl << endl;
	
	// Test size method
	cout << "size of cows list: " << cows.size() << endl;

	
	List horses(cows);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl << endl;

	horses.removeFirst();
	horses.insertAsFirst(5.67);
	horses.insertAsLast(5.5978);
	cows.insertAsFirst(6.78);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl << endl;

	List pigs;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	pigs = cows;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	pigs = horses;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	cout << "End of code" << endl;


	List chicken;
	cout << "chicken size is  " << chicken.size() << endl;
	chicken.insertAsLast(2.65);
	chicken.insertAsLast(5.68);
	chicken.insertAsLast(9.51);
	cout << "chicken list:  " << chicken << endl;
	cout << "sum of values in chicken list is  " << chicken.sum() << endl;
	cout << "size of chicken list is " << chicken.size() << endl;


	return 0;
}
