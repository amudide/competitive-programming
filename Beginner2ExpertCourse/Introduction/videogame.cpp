#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, H;
    cin >> N >> H;

    int cranePosition = 0;
    bool isEmpty = true;

    vector<int> stacks (N);

    for (int i = 0; i < N; i++)
    {
        cin >> stacks[i];
    }

    int command = -1;

    while (command != 0)
    {
        cin >> command;
        
        switch (command)
        {
            case 1:
                if (cranePosition != 0)
                    --cranePosition;
                break;
            case 2:
                if (cranePosition != N - 1)
                    ++cranePosition;
                break;
            case 3:
                if (isEmpty && stacks[cranePosition] > 0)
                {
                    isEmpty = false;
                    stacks[cranePosition]--;
                }
                break;
            case 4:
                if (!isEmpty && stacks[cranePosition] < H)
                {
                    stacks[cranePosition]++;
                    isEmpty = true;
                }
                break;
            default:
                break;
        }
    }

    for (vector<int>::iterator it = stacks.begin(); it != stacks.end(); it++)
    {
        cout << *it << ' ';
    }
}