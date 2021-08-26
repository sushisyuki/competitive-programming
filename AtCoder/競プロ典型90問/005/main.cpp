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

vvl modmul(const vvl &a, const vvl &b)
{
    vvl t(a.size(), vl(b[0].size(), 0));
    REP(i, (int)a.size())
    {
        REP(j, (int)b[0].size())
        {
            ll s = 0;
            REP(k, (int)a[0].size())
            {
                s += (a[i][k] * b[k][j]) % MOD;
            }
            t[i][j] = s % MOD;
        }
    }
    return t;
}

vvl modpow(const vvl &m, ll n)
{
    vvl a = vvl(m);
    vvl ret(m.size(), vl(m[0].size(), 0));
    REP(i, (int)m.size()) ret[i][i] = 1;
    while(n > 0)   
    {
        if(n & 1) ret = modmul(ret, a);
        a = modmul(a, a);
        n >>= 1;
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, B, K; cin >> N >> B >> K;
    vl c(K); REP(i, K) cin >> c[i];
    vvl m(B, vl(B, 0));
    REP(i, B) REP(k, K) m[(i*10+c[k])%B][i]++;
    m = modpow(m, N-1);
    vl b(B, 0); REP(k, K) b[c[k]%B]++;
    vl ans(B, 0);
    REP(i, B)
    {
        ll s = 0;
        REP(j, B) s += (m[i][j] * b[j]) % MOD;
        ans[i] = s % MOD;
    }
    cout << ans[0] << endl;
}