#include <iostream>
#include <random>
#include <vector>

using namespace std;

mt19937 rng(random_device{}());
uniform_real_distribution<double> dist(0.0, 1.0);
    
int random_draw(vector<double>);

int main()
{
    vector<double> distribution = {0.4, 0.2, 0.2, 0.2};
    int nums[4] = {0, 0, 0, 0};
    int trials = 10000;

    for (int n = 0; n < trials; n++) {
        nums[random_draw(distribution)]++;
    }

    cout << "Doing " << trials << " trials yields:" << endl;
    for (int n = 0; n < 4; n++) {
        cout << "Index " << n << ": " << (double)nums[n] / trials << endl;
    }


    return 0;
}

int random_draw(vector<double> distribution)
{
    double r = dist(rng);
    
    vector<double> culumative;
    double total = 0;
    
    for(int n = 0; n < distribution.size(); ++n)
    {
        total += distribution.at(n);
        culumative.push_back(total);
    }
    
    for (int n = 0; n < culumative.size(); n++) {
        if (culumative[n] >= r) {
            return n;
        }
    }

    return culumative.size() - 1;
}