#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int sim_probability(int, int);

int main()
{
    srand(time(0));

    int trials = 1000;
    int success = 0;
    
    for(int n = 0; n < trials; ++n)
    {
        success += sim_probability(1, 5); // can test multiple values
    }
    
    cout << (double)success/trials << endl;
    

    return 0;
}

int sim_probability(int num_heads, int num_flips)
{

    int landed_heads = 0;
    
    for(int n = 0; n < num_flips; ++n)
    {
        
        int random_num = rand() % 100;

        if(random_num < 50)
            ++landed_heads;
    }
    
    if(landed_heads == num_heads)
        return 1;

    return 0;
    
}