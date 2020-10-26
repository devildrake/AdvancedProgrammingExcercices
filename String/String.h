#ifndef STRING_H
#define STRING_H
#include <iostream>

class String {
	char* chars;
public:
	int length() const;
	String();
	String(const String& b);
	String(String&& a)noexcept;
	String(const char*);
	~String();
	void clear();
	friend std::ostream& operator<<(std::ostream& os, const String& dt);

	String operator +(const String& b) {
		char* newChars;
		int totalLength = length() + b.length();
		newChars = new char[totalLength + 1];

		for (int i = 0; i < totalLength + 1; ++i) {
			newChars[i] = i < length() ? chars[i] : b.chars[i - length()];
		}
		//jibiri[totalLength] = '\0';
		return String(newChars);
	}


	bool operator ==(const String& b) {
		if (b.length() != length()) return false;
		for (int i = 0; i < length(); ++i)
			if (b.chars[i] != chars[i]) return false;

		return true;
	}

	static String GetMeAString() {
		return std::move(String{ "another string" });
	}


};


#endif