
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int binary_to_decimal(string);
int hexadecimal_to_decimal(string);
string decimal_to_binary(string);
string decimal_to_hexadecimal(string);
string binary_to_hexadecimal(string);
string hexadecimal_to_binary(string);

int main()
{
    cout << binary_to_decimal("11010") << endl;
    cout << hexadecimal_to_decimal("2F") << endl;
    cout << decimal_to_binary("10") << endl;
    cout << decimal_to_hexadecimal("255") << endl;
    cout << binary_to_hexadecimal("1010") << endl;
    cout << hexadecimal_to_binary("A") << endl;
    
    return 0;
}

int binary_to_decimal(string binary)
{
    int number = 0;
    int length = binary.length();
    
    int k = 0;

    for(int n = length - 1; n >= 0; --n)
    {
        if(binary.at(n) == '1')
            number += 1 << k;
        ++k;
    }
    
    return number;
    
}

int hexadecimal_to_decimal(string hex)
{
    int number = 0;

    for (char h : hex)
    {
        number *= 16;

        if (h >= '0' && h <= '9')
            number += h - '0';
        else if (h >= 'A' && h <= 'F')
            number += h - 'A' + 10;
        else if (h >= 'a' && h <= 'f')
            number += h - 'a' + 10;
    }

    return number;
}

string decimal_to_binary(string decimal)
{
    int num = 0;

    for (char d : decimal)
        num = num * 10 + (d - '0');

    if (num == 0) // edge case
        return "0";

    string number = "";

    while (num > 0)
    {
        number = char((num % 2) + '0') + number;
        num /= 2;
    }

    return number;
}

string decimal_to_hexadecimal(string decimal)
{
    int num = 0;

    for (char d : decimal)
        num = num * 10 + (d - '0');

    if (num == 0)
        return "0";

    string hex_chars = "0123456789ABCDEF";
    string number = "";

    while (num > 0)
    {
        number = hex_chars[num % 16] + number;
        num /= 16;
    }

    return number;
}

string binary_to_hexadecimal(string binary)
{
    int decimal = 0;
    
    for (char d : binary)
        decimal = decimal * 2 + (d - '0');

    return decimal_to_hexadecimal(to_string(decimal));
}

string hexadecimal_to_binary(string hex)
{
    int decimal = 0;
    
    for (char d : hex)
    {
        decimal *= 16;
        if (d >= '0' && d <= '9')
            decimal += d - '0';
        else if (d >= 'A' && d <= 'F')
            decimal += d - 'A' + 10;
        else if (d >= 'a' && d <= 'f')
            decimal += d - 'a' + 10;
    }

    return decimal_to_binary(to_string(decimal));
}
