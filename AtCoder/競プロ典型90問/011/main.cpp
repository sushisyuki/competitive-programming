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

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N; cin >> N;
    vector<tuple<ll, ll, ll>> t(N);
    REP(i, N)
    {
        ll D, C, S; cin >> D >> C >> S;
        t[i] = mt(D, C, S);
    }
    sort(ALL(t));

    // dp[i][j] := i日目, 合計使用日数jの報酬最大
    vvl dp(N+1, vl(5001, 0));
    REP(i, N)
    {
        ll D, C, S;
        tie(D, C, S) = t[i];
        REP(j, 5000)
        {
            if(j+C <= D) chmax(dp[i+1][j+C], dp[i][j]+S);
            chmax(dp[i+1][j], dp[i][j]);
        }
    }
    ll ans = 0;
    REP(i, 5001) chmax(ans, dp[N][i]);
    cout << ans << endl;
}