#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int main()
{
	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);

	int N, M, R;
	int milk = 0;
	vector<int> cows(N);
	vector<pi> stores(M);



	cin >> N >> M >> R;

	for (int i = 0; i < N; i++)
	{
		cin >> cows[i];
		milk += cows[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> stores[i].second >> stores[i].first;
	}

	return 0;
}