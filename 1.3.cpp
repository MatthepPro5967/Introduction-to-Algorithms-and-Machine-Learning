#include <iostream>
#include <vector>

using namespace std;

vector<int> generate_with_5(int);
int recursive_generate_with_5(int);

vector<int> generate_with_25(int);
int recursive_generate_with_25(int);

vector<int> generate_with_01(int);
int recursive_generate_with_01(int);

vector<int> generate_with_23(int);
int recursive_generate_with_23(int);

int main()
{
    vector<int> numbers; 
    int num;
    
    
    cout << "test case 1" << endl;

    numbers = generate_with_5(5);
    num = recursive_generate_with_5(5);

    cout << num << endl;
    
    cout << "test case 2" << endl;

    numbers = generate_with_25(5);
    num = recursive_generate_with_25(5);
    
    cout << num << endl;
    
    cout << "test case 3" << endl;
    
    numbers = generate_with_01(8);
    num = recursive_generate_with_01(7);
    
    cout << num << endl;
    
    cout << "test case 4" << endl;
    
    numbers = generate_with_23(8);
    num = recursive_generate_with_23(8);
    
    cout << num << endl;

    return 0;
}

vector<int> generate_with_5(int limit)
{
    vector<int> numbers = {5};
    
    for(int n = 1; n < limit; ++n)
    {
        numbers.push_back((numbers.at(n - 1) * 3) - 4);
        cout << numbers.at(n) << endl;
    }
    
    return numbers;
}

int recursive_generate_with_5(int n)
{
    if(n == 1)
        return 5;
    else
    {
        int prev = recursive_generate_with_5(n - 1);
        return (3 * prev) - 4;
    }
}

vector<int> generate_with_25(int limit)
{
    vector<int> numbers = {25};
    
    for(int n = 1; n < limit; ++n)
    {
        numbers.push_back((numbers.at(n - 1) % 2 == 0) ? (numbers.at(n - 1) / 2) : (numbers.at(n - 1) * 3 + 1));
        cout << numbers.at(n) << endl;
    }
    
    return numbers;
}

int recursive_generate_with_25(int n)
{
    if(n == 1)
        return 25;
    else
    {
        int prev  = recursive_generate_with_25(n - 1);
        return prev % 2 == 0 ? prev / 2 : prev * 3 + 1;
    }
    
}

vector<int> generate_with_01(int limit)
{
    vector<int> numbers = {0, 1};
    
    cout << numbers.at(0) << endl << numbers.at(1) << endl;

    
    for(int n = 2; n < limit; ++n)
    {
        numbers.push_back(numbers.at(n - 2) + numbers.at(n - 1));
        cout << numbers.at(n) << endl;
    }
    
    return numbers; 
}

int recursive_generate_with_01(int n)
{
    if(n == 1)
        return 0;
    else if(n == 2)
        return 1;
    else
    {
        int prev2 = recursive_generate_with_01(n - 2);
        int prev1 = recursive_generate_with_01(n - 1);
        return prev1 + prev2;
    }
}

vector<int> generate_with_23(int limit)
{
    vector<int> numbers = {2, -3};
    
    cout << numbers.at(0) << endl << numbers.at(1) << endl;

    
    for(int n = 2; n < limit; ++n)
    {
        numbers.push_back(numbers.at(n - 2) * numbers.at(n - 1));
        cout << numbers.at(n) << endl;
    }
    
    return numbers; 
}

int recursive_generate_with_23(int n)
{
    if(n == 1)
        return 2;
    else if(n == 2)
        return -3;
    else
    {
        int prev2 = recursive_generate_with_23(n - 2);
        int prev1 = recursive_generate_with_23(n - 1);
        return prev2 * prev1;
    }
}

