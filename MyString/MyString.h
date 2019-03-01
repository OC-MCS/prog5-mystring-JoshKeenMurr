#pragma once
#include <ostream>
using namespace std;
// MyString class declaration goes here

//class used to replace string class
// function prototypes
class myString
{
private:
	char* str; // private str to hold the cstring
public:
	myString();
	myString(const char*);
	myString(const myString &other);
	~myString();
	const char* c_str() const;

	myString operator =(const myString &other);
	myString operator +(const myString &other);
	bool operator ==(const myString &other);
};

ostream &operator << (ostream &, const myString &);