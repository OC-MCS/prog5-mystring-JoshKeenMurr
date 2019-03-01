//====================================================================
// Joshua Murray
// Due Friday, March 1
// Programming II: Assigment #5
// Description: Program that works as a string class with various functions
//====================================================================
#include <iostream>
#include "myString.h"
using namespace std;

int main()
{
	myString s1; // default constructor 
	myString s2("hello "); // constructor with hello initialized into it
	myString s3(s2); // copy contrsuctor that puts s2 into s3
	myString s4("world"); // constructor with world initialized into it
	myString s5; // default constructor 
	myString sn; // default constructor 


	cout << "Assingning " << s3 << " to " << s1 << endl;
	s1 = s3; // copying s3 to s1
	cout << s3 << endl;

	if (s1 == s3) // checking if s1 is equal to s3
	{
		cout << "they are equal\n";
	}
	if (!(s1 == s4)) // checking if s1 isn't equal to s5
	{
		cout << "they are not equal\n";
	}

	s5 = s2 + s4; // testing the + operator
	cout << s5; // display s5 is s2's and s3's contents

	return 0;
}