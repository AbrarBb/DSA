#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n, m;
    cout<< "Nodes & Edges:";
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int c = 0; c < m; c++) 
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    
    cout<< "Node List\n";
    for (int i = 0; i < n; i++) 
    {
        cout << i << ": ";
        for (int v : g[i]) 
        {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
