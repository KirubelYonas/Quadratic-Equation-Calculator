#include <iostream>
#include <string>
#include <cmath>
#include <regex>
#include <algorithm>

using namespace std;

// Function to parse the coefficients from the input string
bool parseQuadraticCoefficients(const string& input, double& a, double& b, double& c) {
    // Regular expression pattern to match the quadratic equation format
    regex pattern(R"(([-+]?\d*\.?\d*)x\^2\s*([-+]\s*\d*\.?\d*)x\s*([-+]\s*\d+\.?\d*)\s*=\s*0)");
    smatch matches;

    // Match the input string against the regex pattern
    if (regex_match(input, matches, pattern)) {
        // Extract the coefficients as strings from the regex match
        string aStr = matches[1].str();
        string bStr = matches[2].str();
        string cStr = matches[3].str();

        // Remove spaces from the coefficient strings
        aStr.erase(remove(aStr.begin(), aStr.end(), ' '), aStr.end());
        bStr.erase(remove(bStr.begin(), bStr.end(), ' '), bStr.end());
        cStr.erase(remove(cStr.begin(), cStr.end(), ' '), cStr.end());

        // Convert coefficient strings to doubles, handling default values
        // Default for 'a' is 1 if it's missing or just '+' or empty
        a = aStr.empty() || aStr == "+" ? 1 : (aStr == "-" ? -1 : stod(aStr));
        // Default for 'b' is 1 if it's missing or just '+' or empty
        b = bStr.empty() || bStr == "+" ? 1 : (bStr == "-" ? -1 : stod(bStr));
        // Default for 'c' is 0 if it's missing
        c = cStr.empty() ? 0 : stod(cStr);

        return true;
    }

    // Return false if the input format does not match the expected pattern
    return false;
}

int main() {
    string input;
    double a, b, c;
    bool validInput = false;

    // Loop until a valid quadratic equation is provided
    while (!validInput) {
        cout << "Enter a quadratic equation in the form 'ax^2 + bx + c = 0'.\nPlease be informed the solution my not work if you forgot space between the equation.\n Example :-\n        '4x^2 - 5x - 12 = 0'\nEnter the value here:";
        getline(cin, input);

        // Parse the quadratic coefficients from the input string
        if (parseQuadraticCoefficients(input, a, b, c)) {
            validInput = true; // Input is valid, exit the loop
        } else {
            // Inform the user of the invalid input and prompt to try again
            cout << "Invalid input format. Please try again." << endl;
        }
    }

    // Display the parsed coefficients
    cout << "Parsed coefficients:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    // Calculate the discriminant to determine the nature of the roots
    double discriminant = b * b - 4 * a * c;
    cout << "Discriminant (Δ) = " << discriminant << endl;

    // Determine and display the roots based on the discriminant
    if (discriminant > 0) {
        // Two distinct real roots
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Two distinct real roots:" << endl;
        cout << "x1 = " << root1 << endl;
        cout << "x2 = " << root2 << endl;
    } else if (discriminant == 0) {
        // One real root (repeated)
        double root = -b / (2 * a);
        cout << "One real root (repeated):" << endl;
        cout << "x = " << root << endl;
    } else {
        // Complex roots
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "Two complex roots:" << endl;
        cout << "x1 = " << realPart << " + " << imaginaryPart << "i" << endl;
        cout << "x2 = " << realPart << " - " << imaginaryPart << "i" << endl;
    }

    return 0;
}
