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

    ll N, K, P; cin >> N >> K >> P;
    vl A(N); REP(i, N) cin >> A[i];
    ll ln = N/2, rn = N-ln;
    vector<pl> l, r;
    for(int b = 0; b < (1 << ln); b++)
    {
        ll k = 0, p = 0;
        REP(i, ln)
        {
            if((b >> i) & 1)
            {
                k++;
                p += A[i];
            }
        }
        if(p <= P) l.pb(mp(k, p));
    }
    for(int b = 0; b < (1 << rn); b++)
    {
        ll k = 0, p = 0;
        REP(i, rn)
        {
            if((b >> i) & 1)
            {
                k++;
                p += A[ln+i];
            }
        }
        if(p <= P) r.pb(mp(k, p));
    }

    sort(ALL(l));
    sort(ALL(r));

    ll ans = 0;
    REP(i, (int)l.size())
    {
        ans += upper_bound(ALL(r), mp(K-l[i].first, P-l[i].second)) - lower_bound(ALL(r), mp(K-l[i].first, 0LL));
    }
    cout << ans << endl;
}