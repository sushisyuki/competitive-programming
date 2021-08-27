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

int H, W;
vi g;

int root(int x)
{
    if(g[x] == x) return x;
    return g[x] = root(g[x]);
}

void unite(int x, int y)
{
    int rx = root(x);
    int ry = root(y);
    g[rx] = ry;
}

bool same(int x, int y)
{
    return root(x) == root(y);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> H >> W;
    g.resize(H*W);
    REP(i, H*W) g[i] = i;

    vector<vb> color(H, vb(W, 0));
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    int Q; cin >> Q;
    vb ans;
    REP(i, Q)
    {
        int n; cin >> n;
        if(n==1)
        {
            int r, c; cin >> r >> c;
            r--; c--;
            color[r][c] = 1;
            REP(j, 4)
            {
                int nr = r+dr[j];
                int nc = c+dc[j];
                if(0 <= nr && nr < H && 0 <= nc && nc < W && color[nr][nc]) unite(r*W+c, nr*W+nc);
            }
        }
        else
        {
            int ra, ca, rb, cb; cin >> ra >> ca >> rb >> cb;
            ra--; ca--; rb--; cb--;
            if(color[ra][ca] && color[rb][cb] && same(ra*W+ca, rb*W+cb)) ans.pb(true);
            else ans.pb(false);
        }
    }
    REP(i, (int)ans.size())
    {
        if(ans[i]) Yes;
        else No;
    }
}