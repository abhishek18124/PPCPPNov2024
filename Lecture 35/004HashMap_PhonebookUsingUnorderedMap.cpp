/*

	Implement a phonebook storing mapping between person's name and
	their phone numbers using an unordered_map.

*/

#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	unordered_map<string, vector<string>> phoneMap;

	phoneMap["Sanya"].push_back("12345");
	phoneMap["Sanya"].push_back("67890");
	phoneMap["Vansh"].push_back("00000");
	phoneMap["Aryan"].push_back("11111");
	phoneMap["Aditi"].push_back("22222");
	phoneMap["Aditi"].push_back("33333");

	phoneMap.insert({"Chinmay", {"12", "23", "45"}});

	for (pair<string, vector<string>> contact : phoneMap) {

		string contactName = contact.first;
		vector<string> phoneNums = contact.second;
		cout << contactName << " ";
		for (string num : phoneNums) {
			cout << num << " ";
		}
		cout << endl;

	}

	return 0;
}