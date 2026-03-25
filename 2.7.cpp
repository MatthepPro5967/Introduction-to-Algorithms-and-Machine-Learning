#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> encode_string(string, int, int);
string decode_string(vector<int>, int, int);


int main()
{
    vector<int> encoded = {377, 717, 71,
                            513, 105, 921, 581, 547, 547, 105, 377, 717,
                            241, 71, 105, 547, 71, 377, 547, 717, 751, 683,
                            785, 513, 241, 547, 751};
    string decoded;
    
    //encoded = encode_string("a dog", 2, 1);
    
    for(int a = 0; a <= 100; ++a)
    {
        for(int b = 0; b <= 100; ++b)
        {
            decoded = decode_string(encoded, a, b);
            if(decoded != "fail")
                cout << decoded << endl;
        }

    }
    //decoded = decode_string(encoded, 2, 1);
    

    
    
    return 0;
}

vector<int> encode_string(string decoded, int a, int b)
{
    vector<int> encode;
    
    for(int n = 0; n < decoded.size(); ++n)
    {
        if(decoded.at(n) == ' ')
            encode.push_back(b);
        else
            encode.push_back(a * ((int)decoded.at(n) - 96) + b);
    }
    
    return encode;
}

string decode_string(vector<int> encoded, int a, int b)
{
    string decode;
    
    for(int n = 0; n < encoded.size(); ++n)
    {
        if(encoded.at(n) == b && b != 0)
            decode += ' ';
        else
        {
            
            if(a == 0)
            {
                int num = encoded.at(n) - b;
                if(num > 0 && num < 26)
                    decode += char( (encoded.at(n) - b) + 96);
                else
                    return "fail";
            }
            else
            {
                int num = (encoded.at(n) - b) / a;
                if(num > 0 && num < 26)
                    decode += char( (encoded.at(n) - b) / a + 96);
                else
                    return "fail";
            }
        }
    }
    
    return decode;
}