#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<int> brackets (N);

    for (int i = 0; i < N; i++)
    {
        cin >> brackets[i];
    }

    int currentDepth = 0, maxDepth = 0, firstMaxDepth = 0;
    int currentLength = 0, maxLength = 0, firstMaxLength = 0;

    for (int i = 0; i < N; i++)
    {
        if (brackets[i] == 1)
        {
            currentDepth++;
            currentLength++;
        }
        else
        {
            currentDepth--;
            currentLength++;
            if (currentDepth == 0)
            {
                if (currentLength > maxLength)
                {
                    maxLength = currentLength;
                    firstMaxLength = i + 1;
                }
                currentLength = 0;
            }
        }
        if (currentDepth > maxDepth)
        {
            maxDepth = currentDepth;
            firstMaxDepth = i + 1;
        }

        if (currentLength > maxLength)
        {
            maxLength = currentLength;
            firstMaxLength = i + 1;
        }
    }
    //cout << "firstMaxLength: " << firstMaxLength << '\n' << "maxLength: " << maxLength << '\n';
    firstMaxLength = firstMaxLength - maxLength + 1;

    cout << maxDepth << ' ' << firstMaxDepth << ' ' << maxLength << ' ' << firstMaxLength << '\n';
    
}