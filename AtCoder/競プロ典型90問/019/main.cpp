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
    vl A(2*N); REP(i, 2*N) cin >> A[i];
    vvl dp(2*N+1, vl(2*N+1, INFL));
    REP(i, 2*N+1) dp[i][i] = 0;
    for(int gap = 2; gap <= 2*N; gap += 2)
    {
        for(int l = 0; l+gap <= 2*N; l++)
        {
            int r = l+gap;
            if(l+1 <= r-1) chmin(dp[l][r], dp[l+1][r-1]+abs(A[l]-A[r-1]));
            for(int i = l; i <= r ; i+=2)
            {
                chmin(dp[l][r], dp[l][i] + dp[i][r]);
            }
        }
    }
    cout << dp[0][2*N] << endl;
}