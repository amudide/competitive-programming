#include <bits/stdc++.h>

using namespace std;
 
typedef pair<int, int> pi;

#define F0R(i, a) for (int i=0; i<(a); i++)

#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;

int main() {
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);
    
	int N; cin >> N;
	vector<pi> v(N);
	F0R(i,N) cin >> v[i].f >> v[i].s;
	sort(all(v)); v.pb({MOD,0});
	
	int mn = MOD, mx = 0, tot = 0;
	F0R(i,N) {
	    mn = min(mn,min(v[i].s,v[i+1].f)-max(mx,v[i].f));
	    tot += max(mx,v[i].s)-max(mx,v[i].f);
	    mx = max(mx,v[i].s);
	}
	
	cout << tot-max(mn,0);
}