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

template <typename Monoid>
class LazySegmentTree
{
private:
    int n;
    vector<Monoid> data;
    vector<Monoid> lazy;
    Monoid identity;
    function<Monoid(Monoid, Monoid)> op;
    function<Monoid(Monoid, Monoid)> ch;

    Monoid query(int a, int b, int k, int l, int r) 
    {
        eval(k);
        if(r <= a || b <= l) return identity;
        if(a <= l && r <= b) return data[k];
        Monoid c1 = query(a, b, 2*k+1, l, (l+r)/2);
        Monoid c2 = query(a, b, 2*k+2, (l+r)/2, r);
        return op(c1, c2);
    }

    void eval(int k)
    {
        if(lazy[k] == identity) return;
        if(k < n-1)
        {
            lazy[k*2+1] = lazy[k];
            lazy[k*2+2] = lazy[k];
        }
        data[k] = ch(data[k], lazy[k]);
        lazy[k] = identity;
    }

    void update(int a, int b, Monoid x, int k, int l, int r)
    {
        eval(k);
        if(a <= l && r <= b)
        {
            lazy[k] = x;
            eval(k);
        }
        else if(a < r && l < b)
        {
            update(a, b, x, k*2+1, l, (l+r)/2);
            update(a, b, x, k*2+2, (l+r)/2, r);
            data[k] = op(data[k*2+1], data[k*2+2]);
        }
    }

public:
    LazySegmentTree<Monoid>(int nodes, Monoid identity, function<Monoid(Monoid, Monoid)> op, function<Monoid(Monoid, Monoid)> ch)
    : identity(identity), op(op), ch(ch)
    {
        n = 1;
        while(n < nodes) n *= 2;
        data = vector<Monoid>(2*n-1, identity);
        lazy = vector<Monoid>(2*n-1, identity);
    }

    void update(int idx, Monoid new_value)
    {
        idx += n-1;
        data[idx] = ch(data[idx], new_value);
        while(idx > 0)
        {
            idx = (idx-1)/2;
            data[idx] = op(data[idx*2+1], data[idx*2+2]);
        }
    }

    void update(int a, int b, Monoid x)
    {
        update(a, b, x, 0, 0, n);
    }

    Monoid query(int a, int b)
    {
        return query(a, b, 0, 0, n);
    }

    Monoid operator[](int idx)
    {
        return data[idx+n-1];
    }
};

/*
SegmentTree<int> st(5, INF, 
    [](int a, int b) { return min(a, b); },
    [](int a, int b) { return b; }
);
*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int W, N; cin >> W >> N;    
    LazySegmentTree<int> t(W, 0,
    [](int a, int b) { return max(a, b); },
    [](int a, int b) { return b; });

    vi ans(N);
    REP(i, N)
    {
        int l, r; cin >> l >> r;
        l--; r--;
        int h = t.query(l, r+1);
        ans[i] = h+1;
        t.update(l, r+1, h+1);
    }
    REP(i, N) cout << ans[i] << endl;
}