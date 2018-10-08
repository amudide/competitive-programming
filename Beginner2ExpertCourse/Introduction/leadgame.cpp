#include <iostream>

using namespace std;

int main()
{
    int player1 = 0, player2 = 0;
    int rounds;

    cin >> rounds;

    int currentRound1, currentRound2;
    int lead;

    int max1 = 0, max2 = 0;

    for (int i = 0; i < rounds; i++)
    {
        cin >> currentRound1>> currentRound2;

        player1 += currentRound1;
        player2 += currentRound2;

        if (player1 >= player2)
        {
            lead = player1 - player2;
            if (lead > max1)
            {
                max1 = lead;
            }
        }
        else
        {
            lead = player2 - player1;
            if (lead > max2)
            {
                max2 = lead;
            }
        }
    }
    
    if (max1 > max2)
    {
        cout << 1 << ' ' << max1;
    }
    else
    {
        cout << 2 << ' ' << max2;    
    }
}