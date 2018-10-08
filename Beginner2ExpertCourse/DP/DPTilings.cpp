#include <iostream> 
#include <vector>

using namespace std;

vector<int> answers;

int tilings(int N)
{
    answers.push_back(1);
    answers.push_back(2);

    for (int i = 2; i < N; i++)
    {
        answers.push_back(answers[i - 1] + answers[i - 2]);
    }

    return answers[N - 1];
}

int main()
{
    int N;
    cout << "Enter N: ";
    cin >> N;

    cout << "# of Tilings: " << tilings(N) << '\n';
}