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

int N;
vvi G;
vi d;

void dfs(int n)
{
    for(int next: G[n])
    {
        if(chmin(d[next], d[n]+1)) dfs(next);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N;
    G.resize(N);
    d.resize(N, INF);
    REP(i, N-1)
    {
        int A, B; cin >> A >> B;
        A--; B--;
        G[A].pb(B);
        G[B].pb(A);
    }

    d[0] = 0;
    dfs(0);
    vector<pi> p(N);
    REP(i, N) p[i] = mp(d[i], i);
    sort(RALL(p));
    int c = 0;
    vi ans;
    REP(i, N)
    {
        if(p[i].first % 2 == 0)
        {
            c++;
            ans.pb(p[i].second);
        }
        if(c == N/2) break;
    }
    if(c != N/2)
    {
        c = 0;
        ans.erase(ALL(ans));
        REP(i, N)
        {
            if(p[i].first % 2 == 1)
            {
                c++;
                ans.pb(p[i].second);
            }
            if(c == N/2) break;
        }
    }
    REP(i, (int)ans.size()) cout << ans[i]+1 << " ";
    cout << endl;
}