#include "String.h"
#include "String.h"
String::String() {
	chars = new char[0];
}

int String::length()const {
	int count = 0;
	while (chars[count] != '\0') {
		count++;
	}
	return count;
}

void String::clear() {
	chars = new char[0];
}




std::ostream& operator << (std::ostream& os, const String& s)
{
	for (int i = 0; i < s.length(); ++i)
	{
		os << s.chars[i];
	}
	return os;
}

String::String(const String& b) {
	int length = b.length();
	chars = new char[length + 1];
	for (int i = 0; i < length; ++i)
	{
		chars[i] = b.chars[i];
	}
	chars[length] = '\0';
}

String::String(String&& a) :chars{ a.chars } {
	std::cout << "Move Constructor for "
		<< *a.chars << std::endl;
	a.chars = nullptr;
}

String::String(const char* b) {
	int count = 0;
	while (b[count] != '\0') {
		count++;
	}
	chars = new char[count + 1];
	for (int i = 0; i < count + 1; i++)
	{
		chars[i] = b[i];
	}
	chars[count + 1] = '\0';
}