#include "String.h"
String::String() {
	chars = new char[1];
	chars[0] = '\0';
}

int String::length()const {
	int count = 0;
	while (chars[count] != '\0') {
		count++;
	}
	return count;
}

void String::clear() {

	if (chars != nullptr) {
		delete[] chars;
	}

	//delete chars;
	chars = new char[1];
	chars[0] = '\0';
}


String::~String() {
	if (chars != nullptr) {
		delete[] chars;
	}
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

	int length = b.length(); //Length without the '\0' at the end
	chars = new char[length + 1];
	for (int i = 0; i < length + 1; ++i)
	{
		chars[i] = b.chars[i];
	}
	//chars[length] = '\0';
}

String::String(String&& a)noexcept :chars{ a.chars } {
	a.chars = nullptr;
}

String::String(const char* b) {
	int charCount = 0;

	//charCount equals the amount of characters found plus 1 (last is \0)
	while (b[charCount] != '\0') {
		charCount++;
	}
	charCount++;
	chars = new char[charCount];
	for (int i = 0; i < charCount; i++)
	{
		chars[i] = b[i];
	}
	chars[charCount - 1] = '\0';
}