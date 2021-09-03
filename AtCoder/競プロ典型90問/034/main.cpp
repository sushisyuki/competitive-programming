#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for(int i = 0; i < (n); i++)
#define REPS(i, n)  for(int i = 1; i <= (n); i++)
#define RREP(i, n)  for(int i = (n)-1; i >= 0; i--)
#define RREPS(i, n) for(int i = (n); i > 0; i--)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl

using ll  = long long;
using pi  = pair<int, int>;
using pl  = pair<ll, ll>;
using vi  = vector<int>;
using vl  = vector<ll>;
using vs  = vector<string>;
using vb  = vector<bool>;
using vvi = vector<vi>;
using vvl = vector<vl>;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 1e9 + 7;
const ll  INFL = 1e18;
const double PI = 3.1415926535;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, K; cin >> N >> K;
    map<int, int> m;
    vi b(N); REP(i, N) cin >> b[i];
    vi a = b;
    sort(ALL(b));
    UNIQUE(b);
    REP(i, (int)b.size()) m[b[i]] = i;
    REP(i, N)
    {
        a[i] = m[a[i]];
    }
    int r = 0;
    int s = 0;
    vi c(N, 0);
    int ans = 0;
    REP(l, N)
    {
        while(r < N && !(s == K && c[a[r]] == 0))
        {
            if(c[a[r]] == 0) s++;
            c[a[r]]++;
            r++;
        }
        chmax(ans, r-l);
        if(c[a[l]] == 1) s--;
        c[a[l]]--;
    }
    cout << ans << endl;
}