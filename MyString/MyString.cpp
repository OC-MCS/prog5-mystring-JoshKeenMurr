#include <iostream>
#include <string>
#include <iomanip>
#include "MyString.h"
using namespace std;
// MyString implementation file

//===========================================================================
// myString: default constructor to initialize str
// parameters:
//		N/A
// return type: N/A
//===========================================================================
myString::myString()
{
	str = nullptr; // setting str to nothing
}

//===========================================================================
// myString: constructor to allow the user to initialize str
// parameters:
//	other: const char pointer variable that puts the cstring into str
// return type: N/A
//===========================================================================
myString::myString(const char* other)
{
	int size; // size var
	size = strlen(other) + 1; // setting size var
	str = new char[size]; // DAA to hold input from user
	strcpy_s(str, size, other); // putting data into str
}

//===========================================================================
// myString: copy constructor to allow the user to initialize str using another myString instance
// parameters:
//	other: const myString variable that puts the variable's str into str
// return type: N/A
//===========================================================================
myString::myString(const myString &other)
{
	int size; // size var
	size = strlen(other.str) + 1;// setting size var
	str = new char[size];// DAA to hold other myString data
	strcpy_s(str, size, other.str);// putting data into str
	cout << "Copy Constructed\n";
}

//===========================================================================
// ~myString: destructor that deletes dynamically allocated arrays
// parameters:
//	N/A
// return type: N/A
//===========================================================================
myString::~myString()
{
	delete[] str; // deleting DAA space
	cout << "Destructed\n";
}

//===========================================================================
// c_str: function that returns the private str's address to another function
// parameters:
//	N/A
// return type: const char*
//===========================================================================
const char* myString::c_str() const
{
	return str;
}

//===========================================================================
// operator <<: overloaded << operator to allow myString's c-strings to be displayed
// parameters:
//	other: pass by reference myString variable that holds the myString being displayed
//	strng: pass by reference ostream variable 
// return type: ostream
//===========================================================================
ostream &operator << (ostream &strng, const myString &other)
{	
	if (other.c_str() != nullptr) // if the str contains something, it will be displayed
		strng << other.c_str();
	return strng;
}

//===========================================================================
// operator =: overloaded = operator to allow myString's c-strings to be assigned to one another
// parameters:
//	other: pass by reference const variable that holds one of the myStrings being assigned
// return type: myString
//===========================================================================
myString myString::operator =(const myString &other)
{
	int size; // int var to hold size
	size = strlen(other.str) + 1; // setting size to the sign of the str's

	if (this != &other)
	{
		delete[] str;
		str = new char[size];
		strcpy_s(str, size, other.str);
	}
	return *this;
}

//===========================================================================
// operator ==: overloaded == to check whether things equal each other or not
// parameters:
//	other: pass by reference const variable that holds one of the myStrings being tested
// return type: bool
//===========================================================================
bool myString::operator ==(const myString &other)
{
	bool equal; // bool value to hold whether the values equal each other or not
	if (str == nullptr || other.str == nullptr) // checking for nullptrs
		equal = false;
	else if (*str == *other.str) // checking if they equal each other
	{
		equal = true;
	}
	else if (*str != *other.str)  // checking if they dont equal each other
	{
		equal = false;
	}
	return equal; // returning bool
}

//===========================================================================
// operator +: overloaded + operator to allow myString's c-strings to be added
// parameters:
//	other: pass by reference const variable that holds one of the myStrings being added
// return type: myString
//===========================================================================
myString myString::operator + (const myString& other)
{
	int size = strlen(str) + strlen(other.str) + 1; // finding size of new data
	char *temp = new char[size]; // DAA to hold new c-string

	
	strcpy_s(temp, size, this->str); // putting str's contents into the temp
	strcat_s(temp, size, other.str); // putting the passed variables contents into the temp
	
	return temp; // returning temp
}
