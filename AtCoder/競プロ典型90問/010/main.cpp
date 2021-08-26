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
    vl s1(N+2, 0), s2(N+2, 0);
    REPS(i, N)
    {
        ll C, P; cin >> C >> P;
        if(C == 1) s1[i] = P;
        else s2[i] = P;
    }
    REPS(i, N)
    {
        s1[i+1] += s1[i];
        s2[i+1] += s2[i];
    }

    int Q; cin >> Q;
    vl a1(Q), a2(Q);
    REP(i, Q)
    {
        ll L, R; cin >> L >> R;
        L--; R--;
        a1[i] = s1[R+1]-s1[L];
        a2[i] = s2[R+1]-s2[L];
    }
    REP(i, Q)
    {
        cout << a1[i] << " " << a2[i] << endl;
    }
}