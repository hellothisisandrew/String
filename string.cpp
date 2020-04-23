//Andrew Rodman Fink

#include <cstring>
#include "string.h"

using namespace std;

String::String() : the_string(NULL) {
	
	the_string = new char[strlen("") + 1];
	strcpy(the_string, "");	
	
	
	
}//set the string to NULL

//reuse the assignment operator
String::String(const String& to_copy) : the_string(NULL)
 {
	 the_string = new char[strlen(to_copy.the_string) + 1];
	 strcpy(the_string, to_copy.the_string);//copy the string
}

//copy the char *
String::String(const char * to_copy) : the_string(NULL)
{
	*this = to_copy;
}

//destructor deletes the char *
String::~String() { delete [] the_string; }

//overloaded == operator
bool operator==(const String& left, const String& right)
{
	//check the strings
	if(!strcmp(left.the_string, right.the_string))
		return true;
	else
		return false;//Return false otherwise
}

//overloaded to compare with a char * ==
bool operator==(const String& left, const char * right)
{
	if(!strcmp(right,left.the_string))//if true return true
		return true;
	else 
		return false;

}

//friend overloaded operator 
bool operator==(const char* left, const String& right) 
{
	if(!left) return false;//if the char is null return false

	return !(strcmp(left,right.the_string));//compare right and left
}

//overlaoded = operator for char *
String& String::operator=(const char * to_copy) {
	
	if(the_string) delete [] the_string;//if the string exists
	
	the_string = NULL;
	
	the_string = new char[strlen(to_copy) + 1];//intalize the string
	strcpy(the_string, to_copy);	//copy
	
	return *this;

}

//copies the value from string to main string
String& String::operator=(const String& to_copy) {

	if(to_copy == *this) return *this;	
		
	//if not empty delete the string	
	if(the_string) delete [] the_string;
	the_string = NULL;

	the_string = new char[strlen(to_copy.the_string) + 1];
	strcpy(the_string, to_copy.the_string);

	return *this;
}

//overload the << operator for an ostream variable on the left
ostream& operator<<(ostream& out, const String& data) 
{
	out << data.the_string;
	return out;
}



//`````````````````````````````````````````````string '+' ``````````````````````````````````````````````

String String::operator+(const String& right) const
{
	String object;//declare string object

	//remember to add functionality to check for ""
	
	//intalize a char pointer to the size of both of them
	char * temp = new char[ strlen(the_string) + strlen(right.the_string) + 1];
	
	char * right_str = &temp[strlen(the_string)];//get a list 1 past the length of the first string

	strcpy(temp,the_string);//strcpy the left side
	
	strcpy(right_str, right.the_string);//the right size	
	
	object = temp;//set object to temp
	
	delete [] temp;//delete temp	
	temp = NULL;
		
	return object; //return the object
}


//char * on the right + operator
String String::operator+(const char *& to_copy) const
{
	String object;//create a string object
	
	object = to_copy;//copy char * 

	return *this + object; //return the object
}

//non member '+' overloaded operator
String operator+(const char * char_star, const String& a_string) 
{
	String object; //create the object

	object = char_star;//set object to char *	

	return object + a_string;//add a_string to the right side
}

//plus equals operator
String& String::operator+=(const String& object)
{
	*this = *this + object;//use previously defined + operators 
	return *this;
}

//plus equals with char *
String& String::operator+=(const char * object)
{
	*this = *this + object;//use perviously defined + operator
	return *this;
}

//friend char * > operation
bool  operator>(const char * left, const String& right)
{
	int left_length = strlen(left);
	int right_length = strlen(right.the_string);
	
	//check if the chars are equal	
	for(int i = 0; i < left_length && i < right_length; ++i)
	{
		//if greater than
		if(left[i] < right.the_string[i])
			return true;	

		//if less than
		if(right.the_string[i] < left[i])//we use the oppisite value because it needs to be in alphabetical order
			return false;		
	}	
		
	if(left_length < right_length)// return true if left is shorter
		return true;
	else
		return false;	
}

//<= is ~ to > to evaluate with >
bool operator<=(const char* left, const String& right)
{
	if(left > right)
		return false;
	else
		return true;
}

//use == and <= to determine <
bool operator<(const char * left, const String& right)
{
	if( left <= right && !(right == left))//if it is <= to and it is not equal to
		return true;
	else
		return false;	

}

bool operator>=(const char* left, const String& right)
{
	if(left < right)
		return false;
	else 
		return true;
}

//string on the right with char * on the right
bool operator>(const String& left, const char * right)
{
	if(right < left)
		return true;
	else 
		return false;//us previosuly defined < to determine truth

}

//string on right
bool operator<(const String& left, const char * right)
{
	if(right > left) 
		return true;
	else
		return false;
}

//string of right
bool operator<=(const String& left, const char * right)
{
	if(right >= left)
		return true;
	else 
		return false;

}

bool operator>=(const String& left, const char * right)
{
	if(right <= left)
		return true;
	else
		return false;

}

//reusing previous operators
bool operator<(const String& left, const String& right)
{
	if(left < right.the_string)
		return true;
	else
		return false;

}

bool operator>(const String& left, const String& right)
{
	if(left > right.the_string)
		return true;
	else
		return false;
}

bool operator<=(const String& left, const String& right)
{
	if(left <= right.the_string)
		return true;
	else
		return false;
}

bool operator>=(const String& left, const String& right)
{
	if(left >= right.the_string)
		return true;
	else
		return false;
}

//overloaded brackets takes an int and returns the address of the operator
char& String::operator[](unsigned int i)
{	
	return the_string[i];
}

//incrament operator makes every letter a capital letter
String& String::operator++()
{
	int length = strlen(the_string);

	for(int i = 0; i < length; ++i)
	{
		if(the_string[i] < 123 && the_string[i] > 96)//if it is a lowercase letter make it upper case
			the_string[i] -= 32;
	}

	return *this;
}

//overlaoded decrament operator 
//changes everything to lower case
String& String::operator--()
{
	int length = strlen(the_string);
	
	//loop thorugh check for upper case
	for(int i = 0; i < length; ++i)
		if(the_string[i] > 64 && the_string[i] < 91)//if uppercase change to lower version
			the_string[i] += 32;


	return *this;//return this
}

//get function asks user for input on a line
//'\n' is believed to be immidete
void String::getline(int size, char dil)
{
	char temp[size];

	if(the_string) delete [] the_string;
	the_string = NULL;
	
	cin.get(temp, size, dil);//pass in delimeter and size along with temporary array
	cin.ignore(size, dil);

	the_string = new char[strlen(temp) + 1];//copy and intalize
	strcpy(the_string, temp);

	return;

}

//this function returns the length of the string
int String::length() { return strlen(the_string); }

//cin >> name
//input stream on right
istream& operator>>(istream& cin, String& object)
{
	char temp[500];

	cin >> temp;//read into temp
	
	object = temp;

	return cin;//return istream object
}

//overloaded != oeprator uses == to determine truthe
bool operator!=(const String& left, const String& right)
{
	if(!(left == right))//if it does equal return true else return false
		return true;
	else
		return false;
}

//overloaded != for char *
bool operator!=(const String& left, const char * right)
{
	if(!(left == right))//if this evalautes false return true
		return true;
	else
		return false;


}

//overloaded as friend with char * on the right
bool operator!=(const char * left, String& right)
{
	if(!(right == left))//rreturn true if == evaluates false
		return true;
	else
		return false;
}

//overloaded >> operator takes input from file and loads it into 
//~~~~~~~~WARNING ONLY ADDS THE NEW STRING WITH A SPACE~~~~~~~~~~
//~~~~~~~~~~~~DOES NOT REMOVE THE ORGINAL STRING~~~~~~~~~~~~~~~~~~~~
ifstream& operator>>(ifstream& in, String& to_load)
{
	char temp[1000];

	in >> temp;//load into temp

	if(to_load != "")	//if something exists within the string add a space
		to_load += " ";//add a space
		
	to_load += temp;//load into temp		
	
	return in;//return fstream object	
	
} 

//resets the string to nothing
void String::clear() {
	
	delete [] the_string;//delete the string
	the_string = NULL;

	*this = "";//set equal to empty string
}

//test if the string is empty
bool String::empty() {

	if(*this == "")//if it is equal to "" return true else return false;
		return true;
	else
		return false;

}
