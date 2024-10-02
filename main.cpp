#include <iostream>
#include <climits>

using namespace std;

bool isValidInput(int lower, int upper, int value) {
    if (lower != INT_MIN && value < lower) return false;
    if (upper != INT_MAX && value > upper) return false;
    return true;
}

int menuValidIntegerChecker(string prompt, string errorMessage, int lower = INT_MIN, int upper = INT_MAX) {
    
    while(true) {
        int input;
        cout << prompt << endl;
        cin >> input;

        if (isValidInput(lower, upper, input)) {
            return input;
        } else {
            cout << errorMessage << endl;
        }
    }
}

int main () {
    string prompt = "Please enter a value";
    string errorMessage = "Your value is invalid.";

    int result;

    result = menuValidIntegerChecker(prompt, errorMessage);
    cout << result << endl;

    result = menuValidIntegerChecker("Please enter a number (0-1000):", errorMessage, 0, 1000);
    cout << result << endl;

    result = menuValidIntegerChecker("Please enter a number < 500:", errorMessage, INT_MIN, 500);
    cout << result << endl;

    result = menuValidIntegerChecker("Please enter a number > -500:", errorMessage, -500, INT_MAX);
    cout << result << endl;

    result = menuValidIntegerChecker("Please enter a number larger > 7:", errorMessage, 7, INT_MAX);
    cout << result << endl;

    result = menuValidIntegerChecker("Please enter a number between -1000 and 1000:", errorMessage, -1000, 1000);
    cout << result << endl;

    return 0;
}