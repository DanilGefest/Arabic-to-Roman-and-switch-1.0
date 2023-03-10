#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

const string oneToTenDigits[10] = {
  "", "I", "II", "III", "IV", "V",
  "VI", "VII", "VIII", "IX"
},
tenToNintyDigits[10] = {
  "", "X", "XX", "XXX", "XL", "L",
  "LX", "LXX", "LXXX", "XC"
},
oneToNineHundertDigits[10] = {
  "", "C", "CC", "CCC", "CD", "D",
  "DC", "DCC", "DCCC", "CM"
};

int arabicEquivalentToRomanNumeral(string Digit) {
    int quickReturn;

    if (Digit != "M") {
        for (int IndexByDigits = 0; IndexByDigits < 10; ++IndexByDigits) {
            if (Digit == oneToTenDigits[IndexByDigits]) {
                quickReturn = IndexByDigits;
                return quickReturn;
            }
            if (Digit == tenToNintyDigits[IndexByDigits]) {
                quickReturn = IndexByDigits * 10;
                return quickReturn;
            }
            if (Digit == oneToNineHundertDigits[IndexByDigits]) {
                quickReturn = IndexByDigits * 100;
                return quickReturn;
            }
        }
    }
    else {
        return 1000;
    }
    return 0;
}

int main() {
    bool choice;

    cout << "Arabic->Roman/Roman->Arabic = 1/0 ";
    cin >> choice;

    int arabicDigit;
    string arabicToRomanResult = "";
    int currentDigit;
    int digitIndex;

    string romanDigit;
    int characterIndex;
    string currentCharacter;
    string previousCharacter;
    int romanToArabicResult;                                    

    switch (choice) {
    case true:
        cout << "Enter an Arabic Digit: ";
        cin >> arabicDigit;

        digitIndex = 0;

        while (arabicDigit) {
            currentDigit = arabicDigit % 10;

            switch (digitIndex) {
            case 0:
                arabicToRomanResult = oneToTenDigits[currentDigit] + arabicToRomanResult;
                break;

            case 1:
                arabicToRomanResult = tenToNintyDigits[currentDigit] + arabicToRomanResult;
                break;

            case 2:
                arabicToRomanResult = oneToNineHundertDigits[currentDigit] + arabicToRomanResult;
                break;

            default:
                while (arabicDigit) {
                    arabicToRomanResult = "M" + arabicToRomanResult;
                    --arabicDigit;
                }
            }

            arabicDigit /= 10;
            ++digitIndex;
        }

        cout << arabicToRomanResult;
        break;

    case false:
        cout << "Enter a Roman Digit: ";
        cin >> romanDigit;
        transform(romanDigit.begin(), romanDigit.end(), romanDigit.begin(), ::toupper);

        characterIndex = 0;
        currentCharacter = romanDigit[characterIndex];
        romanToArabicResult = arabicEquivalentToRomanNumeral(currentCharacter);
        ++characterIndex;

        while (characterIndex < romanDigit.size()) {
            previousCharacter = currentCharacter;
            currentCharacter = romanDigit[characterIndex];

            if (arabicEquivalentToRomanNumeral(currentCharacter) > arabicEquivalentToRomanNumeral(previousCharacter)) {
                romanToArabicResult = romanToArabicResult + arabicEquivalentToRomanNumeral(currentCharacter) - arabicEquivalentToRomanNumeral(previousCharacter) * 2;
            }
            else {
                romanToArabicResult += arabicEquivalentToRomanNumeral(currentCharacter);
            }
            ++characterIndex;
        }
        cout << romanToArabicResult;
        break;

    default:
        return 0;
    }
}