#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{       
    int N1, N2, N3;
    cin >> N1 >> N2 >> N3;

    //vector<int> voters1 (N1), voters2 (N2), voters3 (N3);

    map<int, int> discrepancy;

    int current;

    for (int i = 0; i < N1; i++)
    {
        cin >> current;
        discrepancy[current] = 1;
    }

    for (int i = 0; i < N2; i++)
    {
        cin >> current;
        if (discrepancy[current] == 1)
        {
            discrepancy[current]++;
        }
        else
        {
            discrepancy[current] = 1;
        }        
    }

    for (int i = 0; i < N3; i++)
    {
        cin >> current;
        if (discrepancy[current] == 1 || discrepancy[current] == 2)
        {
            discrepancy[current]++;
        }
    }

    int num = 0;
    vector<int> ids;

    for (map<int,int>::iterator it = discrepancy.begin(); it != discrepancy.end(); ++it)
    {
        if (it -> second >= 2)
        {
            num++;
            ids.push_back(it->first);
        }
    }

    cout << num << endl;
    for (vector<int>::iterator it = ids.begin(); it != ids.end(); it++)
    {
        cout << *it << endl;
    }
}