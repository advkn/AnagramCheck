//Check if two strings are anagrams.
/*
1. Check the string length.
2. Create and Initialize a frequency table (array) to keep a count of the character frequency.
3. Scan the first string and INCREMENT the frequency table.
4. Scan the second thread and DECREMENT the frequency table.
5. Check if the frequency table has a count of MORE THAN ZERO in any of the locations.  If so, NOT and anagram.*/

#include <iostream>
#include<cstring>
#include <array>

using namespace std;

#define MAX_ASCII 127

int main() {

	char s1[] = "orchestra";
	char s2[] = "carthorse";

	//Check the string lengths
	if(strlen(s1) != strlen(s2)) {
		cout << "Not an anagram" << endl;
		return 0;
	}

	//Create and initialize frequency table
	int freqTable[MAX_ASCII+1];
	for(int i = 0; i < MAX_ASCII+1; i++) {
		freqTable[i] = 0;
	}

	//scan the first string and increment the frequency table
	char *ptr1 = s1;	//use a pointer to iterate through the string
	while(*ptr1 != '\0') {
		char c = (char)tolower(*ptr1);	//retrieve the indiviual character, lowercase it and store it in a char
		freqTable[(int)c]++;	//INCREMENT the count of the individual character
		ptr1++;		//move the pointer to the next character in the string
	}

	//scan the second string and decrement the frequency table
	char *ptr2 = s2;
	while(*ptr2 != '\0') {
		char c = (char)tolower(*ptr2);
		freqTable[(int)c]--;	//DECREMENT the count of the individual character
		ptr2++;	
	}

	//check the frequency count of the characters
	for(int i = 0; i < MAX_ASCII+1; i++) {
		if(freqTable[i] > 0) {
			cout << "Not an anagram" << endl;
			getchar();
			return 0;
		}
		else {
			continue;
		}
	}

	cout << "Anagram" << endl;

	getchar();
	return 0;
	

}

