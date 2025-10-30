#include <iostream>
using namespace std;

class solution {
public:
    int firstuniquecharacter(string s) {
        int freq[26] = {0};

        //Count frequency of each character
        for (int i = 0; s[i] != '\0'; i++) {
            freq[s[i] - 'a']++;
        }

        // Find first index with frequency 1
        for (int i = 0; s[i] != '\0'; i++) {
            if (freq[s[i] - 'a'] == 1)
                return i;
        }

        return -1; //no unique character
    }
};

int main() {
    solution sol;
    string s;
    cout << "enter string you want to check it for ";
    cin >> s;

    int index = sol.firstuniquecharacter(s);
    if (index != -1)
        cout << "the first non-repeating character is at index " << index << endl;
    else
        cout << "No non-repeating character has been found" << endl;

    return 0;
}
