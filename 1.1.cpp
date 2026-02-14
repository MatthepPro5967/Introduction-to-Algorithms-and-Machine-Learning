#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cctype>

using namespace std;

void check_if_symmetric(string);

void convert_to_numbers(string);

void convert_to_letters(vector<int>);

void get_intersection(vector<int>, vector<int>);

void get_union(vector<int>, vector<int>);

void  count_characters(string);

void is_prime(int);

int main()
{
    check_if_symmetric("anna");
    check_if_symmetric("leo");

    convert_to_numbers("a cat");
    
    convert_to_letters({1, 0, 3, 1, 20});

    get_intersection({1,2,3}, {2,3,4});
    
    get_union({1,2,3}, {2,3,4});
    
    count_characters("A cat!!!");
    
    is_prime(67);
    is_prime(18);

    return 0;
}

void check_if_symmetric(string word)
{
    int count1 = 0;
    int count2 = word.length() - 1;
    
    while(count1 < count2)
    {
        if(word.at(count1) != word.at(count2))
        {
            cout<<"String "<<word<<" is not symmetric."<<endl;
            return;
        }
        ++count1;
        --count2;
    }
    
    cout << "String "<< word <<" is symmetric." << endl;
}

void convert_to_numbers(string word)
{
    vector<int> nums;
    int index;
    
    string alphabet = " abcdefghijklmnopqrstuvwxyz";
    
    cout << "[";
    
    for(int n = 0; n < word.size(); ++n)
    {
        index = (int)alphabet.find(word.at(n));
        nums.push_back(index);
        cout << index << ",";
    }
    
    cout << "]" << endl;
    
}

void convert_to_letters(vector<int> nums)
{
    
    string alphabet = " abcdefghijklmnopqrstuvwxyz";
    
    cout << "'";
    for(int n = 0; n < nums.size(); ++n)
    {
        cout << alphabet.at(nums.at(n));
        
    }
    
    cout << "'" << endl;
    
}

void get_intersection(vector<int> arr1, vector<int> arr2)
{
    cout << "[";
    string numbers = "";
    
    for(int n = 0; n < arr1.size(); ++n)
    {
        for(int i = 0; i < arr2.size(); ++i)
        {
            if(arr1.at(n) == arr2.at(i) && (numbers.find(arr1.at(n)) == string::npos))
            {
                numbers += (char)arr1.at(n);
                cout << arr1.at(n) << ",";
            }
        }
    }
    
    cout << "]" << endl;
}

void get_union(vector<int> arr1, vector<int> arr2)
{
    cout << "[";
    string numbers = "";
    
    for(int n = 0; n < arr1.size(); ++n)
    {
        if(numbers.find(arr1.at(n)) == string::npos)
        {
            cout << arr1.at(n) << ", ";
            numbers += arr1.at(n);
        }
    }
    
    for(int n = 0; n < arr2.size(); ++n)
    {
        if(numbers.find(arr2.at(n)) == string::npos)
        {
            cout << arr2.at(n) << ", ";
            numbers += arr2.at(n);
        }
    }
    
    cout << "]" << endl;
}

void count_characters(string word)
{
    map<char, int> my_map;
    
    for(int n = 0; n < word.size(); ++n)
    {
        my_map[tolower(word.at(n))] += 1;
    }
    
    for(auto &pair : my_map) {
        cout << pair.first << ": " << pair.second << "\t";
    }
    
    cout << endl;
}

void is_prime(int num)
{
    int divisor = num / 2;
    
    for(divisor; divisor > 1; --divisor)
    {
        if(num % divisor == 0)
        {
            cout << num << " is not prime" << endl;
            return;
        }
        
    }
    cout << num << " is prime" << endl;

}