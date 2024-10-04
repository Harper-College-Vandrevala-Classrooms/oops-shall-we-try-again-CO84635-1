#include <iostream>
#include <climits>

using namespace std;

bool is_valid_input(int lower, int upper, int value) {
    if (lower != INT_MIN && value < lower) return false;
    if (upper != INT_MAX && value > upper) return false;
    return true;
}

void print_result(int result) {
    cout << "The value selected by the user: " << result << endl;
}

int menu_valid_integer_checker(string prompt, string errorMessage, int lower = INT_MIN, int upper = INT_MAX) {
    
    while(true) {
        int input;
        cout << prompt << endl;
        cin >> input;

        if (is_valid_input(lower, upper, input)) {
            print_result(input);
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

    result = menu_valid_integer_checker(prompt, errorMessage);
    
    result = menu_valid_integer_checker("Please enter a number (0-1000):", errorMessage, 0, 1000);
  
    result = menu_valid_integer_checker("Please enter a number < 500:", errorMessage, INT_MIN, 500);
   
    result = menu_valid_integer_checker("Please enter a number > -500:", errorMessage, -500, INT_MAX);
   
    result = menu_valid_integer_checker("Please enter a number larger > 7:", errorMessage, 7, INT_MAX);
   
    result = menu_valid_integer_checker("Please enter a number between -1000 and 1000:", errorMessage, -1000, 1000);
  
    return 0;
}