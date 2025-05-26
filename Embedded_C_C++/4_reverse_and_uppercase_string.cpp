#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Arduino-style setup function
void setup()
{
    cout << "Enter a string: ";
}

// Arduino-style loop function
void loop()
{
    string input;
    getline(cin, input);

    // Reverse the string
    reverse(input.begin(), input.end());

    // Convert to uppercase
    for (char &c : input)
    {
        c = toupper(c);
    }

    // Output the result
    cout << "Processed string: " << input << endl;
}

int main()
{
    setup();
    loop();
    return 0;
}
