#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_t=(b); i<=_t; i++)
#define FORD(i,a,b) for(int i=(a),_t=(b); i>=_t; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(a) cerr << #a << " = " << (a) << endl;
#define DBGA(a,b) { cerr << #a << " = "; REP(_,n) cerr << a[_] << "; "; cerr << endl; }

#define CTOI(a) a-48
#define SQ(x) ((x) * (x))
#define SZ(x) ((int) ((x.).size()))
#define ll long long
#define INF 1000000000

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

void solve() {

}

int main() {
  ios::sync_with_stdio(false);
  std::cout.precision(11);
  int cases; cin >> cases;
  REP(i, cases)
    solve();
  cout << endl;
  return 0;
}

