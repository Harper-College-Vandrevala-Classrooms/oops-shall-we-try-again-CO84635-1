#include <iostream>
#include <climits>

using namespace std;

const int EXIT_VALUE = INT_MIN;
const string EXIT_STRING = "";

bool is_valid_input(int lower, int upper, int value) {
    if (lower != INT_MIN && value < lower) return false;
    if (upper != INT_MAX && value > upper) return false;
    return true;
}

bool is_integer(const string & input_str, int & output_value) {
    try {
        output_value = stoi(input_str);
        return true;
    } catch (invalid_argument&) {
        return false;
    } catch (out_of_range&) {
        return false;
    }
}

void print_result(int validated_value) {
    if (validated_value != EXIT_VALUE) {
        cout << "The value selected by the user: " << validated_value << endl;
    }
}

void print_result(string validated_value) {
    if (validated_value != EXIT_STRING) {
        cout << "The value selected by the user: \"" << validated_value << "\"" << endl;
    }
}

int menu_checker(string prompt, string error_message, int lower = INT_MIN, int upper = INT_MAX, int default_value = EXIT_VALUE) {
    while(true) {
        string user_input;
        cout << prompt << endl;

        if (default_value != INT_MIN) {
            cout << " Enter \"default\" to use the default value of " << default_value;
        }

        cout <<  " Enter \"exit\" to leave the menu. " << endl;
        cin >> user_input;

        if (user_input == "exit") {
            return EXIT_VALUE;
        }

         if (user_input == "default" && default_value != EXIT_VALUE) {
            if (is_valid_input(lower, upper, default_value)) {
                return default_value;
            } else {
                cout << error_message << endl;
                continue;
            }
        }

        int input_value;
        if (is_integer(user_input, input_value)) {
            if (is_valid_input(lower, upper, input_value)){
                return input_value;
            } else {
                cout << error_message << endl;
            }
        } else {
            cout << error_message << endl;
        }
    }
}

string menu_checker(string prompt, string error_message, string default_value = EXIT_STRING) {
    
    while(true) {
        string user_input;
        cout << prompt << endl;

        if (default_value != EXIT_STRING) {
            cout << " Enter \"default\" to use the default string of \"" << default_value << "\"." << endl;
        }

        cout <<  " Enter \"exit\" to leave the menu. " << endl;
        getline(cin, user_input);

        if (user_input == "exit") {
            return EXIT_STRING;
        }

        if (user_input == "default" && default_value != EXIT_STRING && !default_value.empty()) {
            return default_value;
        }

        if (!user_input.empty()) {
            return user_input;
        } else {
            cout << error_message << endl;
        }
    }
}

int main () {
    string prompt = "Please enter a value: ";
    string error_message = "Your value is invalid.";

    int validated_int;

    /*For the test in our driver program where we just have this signature below for our integer. Where no upper and lower bounds are present, and no default is passed, it meets the same signature as the overloaded string menu checker?
    I will still provide examples if we have no upper or no lower bounds if the default is present, but I cannot figure out how to not have this be ambigous. I think the only way would be having a default argumement for error message, or different function names, 
    but that isn't in the directions*/
    // validated_int = menu_checker(prompt, error_message); 
    // print_result(validated_int);

    validated_int = menu_checker(prompt, error_message, 100); 
    print_result(validated_int);
    
    validated_int = menu_checker("Please enter a number (0-1000):", error_message, 0, 1000);
    print_result(validated_int);
    
    validated_int = menu_checker("Please enter a number < 500:", error_message, INT_MIN, 500);
    print_result(validated_int);

    validated_int = menu_checker("Please enter a number > -500:", error_message, -500, INT_MAX);
    print_result(validated_int);

    validated_int = menu_checker("Please enter a number larger > 7:", error_message, 7, INT_MAX);
    print_result(validated_int);

    validated_int = menu_checker("Please enter a number between -1000 and 1000:", error_message, -1000, 1000);
    print_result(validated_int);

    validated_int = menu_checker(prompt, error_message, 0, 1000, 100);
    print_result(validated_int);

    validated_int = menu_checker(prompt, error_message, INT_MIN, 500, 200);
    print_result(validated_int);

    validated_int = menu_checker(prompt, error_message, -500, INT_MAX, 0);
    print_result(validated_int);

    validated_int = menu_checker(prompt, error_message, 7, INT_MAX, 10);
    print_result(validated_int);

    validated_int = menu_checker(prompt, error_message, -1000, 1000, 0);
    print_result(validated_int);

    string prompt2 = "Please enter a string value: ";
    string error_message2 = "Your string value is invalid!";
    
    string validated_string;

    validated_string = menu_checker(prompt2, error_message2, "Default String");
    print_result(validated_string);

    validated_string = menu_checker(prompt2, error_message2, "Default Value");
    print_result(validated_string);

    validated_string = menu_checker(prompt2, error_message2, "Another Default String");
    print_result(validated_string);

    return 0;
}