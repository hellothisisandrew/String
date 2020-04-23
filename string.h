//Andrew Rodman Fink
//String class

#include <iostream>//Change this .h should not include libraries if possible
#include <fstream>


	




class String {
	
	public:
		//constructor sets values to NULL
		String();

		//char * constructor
		String(const char*);
		
		~String();//deletes the dynamic memory

		String(const String&);//takes string object
		
		//overloaded == operators	
		friend bool operator==(const String&,const String&);
		friend bool operator==(const String&, const char *);
		friend bool operator==(const char*, const String&);

		//overloaded != operator
		friend bool operator!=(const String&, const String&);
		friend bool operator!=( const String&, const char *);
		friend bool operator!=(const char*, const String&);

		//takes a char * on the left side or string
		String& operator=(const char *);		
		String& operator=(const String&);	

		//overloaded << operator using friend of class ostream
		friend std::ostream& operator<<(std::ostream&, const String&);
		
		//+ operator adds from right for both char * and string	
		String operator+(const String&) const;
		String operator+(const char *&) const;
		friend	String operator+(const char *, const String&);				

		//+= operator overloaded
		String& operator+=(const String&);
		String& operator+=(const char *);

		//overloaded > < => =< evaluates based on alphabetical order
		friend bool operator<(const String&, const String&);
		friend bool operator>(const String&, const String&);
		friend bool operator<=(const String&, const String&);
		friend bool operator>=(const String&, const String&);
		
		//overloaded with char * on the right
		friend bool operator<(const String&, const char *);
		friend bool operator>(const String&,const char *);
		friend bool operator>=(const String&, const char *);
		friend bool operator<=(const String&, const char*);

		//overloaded with char* on the left
		friend bool operator<(const char*, const String&);
		friend bool operator>(const char*, const String&);
		friend bool operator<=(const char*, const String&);
		friend bool operator>=(const char*, const String&);

		//overloaded the bracket opeartor
		char& operator[](unsigned int);

		//++ incarment operators capatlize every letter
		String& operator++();

		//-- decrament operator makes all upper case lowercase
		String& operator--();

		//istream overloaded operator
		//is a friend function
		friend std::istream& operator>>(std::istream&, String&);
		
		//overloaded ifstream >> input operator
		//~~~~~~WARNING ONLY ADDS TO THE ALREADY EXISTING STRING~~~~~~~
		//~~~~~~DOES NOT DELETE THE ORGINIAL STRING ~~~~~~~~~~~~~~
		friend std::ifstream& operator>>(std::ifstream&, String&);

		//get line function returns nothing only edits the object state
		//allows for input into the string
		void getline(int, char);
		
		//returns length of the string
		int length();

		//clear resets the string and remove the data
		void clear();
		
		//check if int is empty
		bool empty();

	private:
		char * the_string;


};
