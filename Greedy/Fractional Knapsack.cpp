#include <iostream>
using namespace std;

void knapsack(int capacity) 
{
    int values[] = {60, 100, 120}; 
    int weights[] = {10, 20, 30};  
    int n = 3;

    double totalValue = 0;

    for (int a = 0; a < n; a++) 
    {
        if (capacity >= weights[a]) 
        {
            totalValue += values[a];          
            capacity -= weights[a];
        } else {
            totalValue += (double)values[a] * capacity / weights[a]; 
            break;
        }
    }

    cout << "Maximum value: " << totalValue << endl;
}

int main() 
{
    knapsack(50); 
    return 0;
}
