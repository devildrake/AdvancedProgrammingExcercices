#ifndef STRING_H
#define STRING_H
#include <iostream>

class String {
public:
	char* chars;
	int length() const;
	String();
	String(const String& b);
	String(String&& a);
	String(const char*);
	void clear();
	friend std::ostream& operator<<(std::ostream& os, const String& dt);
	



	String operator +(const String& b) {
		String ret;
		int totalLength = length() + b.length();
		ret.chars = new char[totalLength + 1];

		for (int i = 0; i < totalLength; ++i) {
			ret.chars[i] = i < length() ? chars[i] : b.chars[i - length()];
		}
		ret.chars[totalLength] = '\0';
		return ret;
	}


	bool operator ==(const String& b) {
		if (b.length() != length())return false;

		for (int i = 0; i < length(); ++i)
		{
			if (b.chars[i] != chars[i])return false;
		}

		return true;
	}



};


#endif