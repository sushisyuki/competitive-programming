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

const long double PI = acosl(-1);
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 1e9 + 7;
const ll  INFL = 1e18;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

class vec
{
public:
    vec(long double x, long double y, long double z)
    :x(x), y(y), z(z)
    {

    }
    long double x, y, z;
    void normalize()
    {
        long double l = sqrtl(dot(*this, *this));
        x /= l; y /= l; z /= l;
    }
    static long double dot(const vec &a, const vec&b)
    {
        return a.x*b.x + a.y*b.y + a.z*b.z;
    }
    static vec sub(const vec &a, const vec&b)
    {
        return vec(a.x-b.x, a.y-b.y, a.z-b.z);
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    long double T, L, X, Y; cin >> T >> L >> X >> Y;
    vec q(X, Y, 0.0);
    int Q; cin >> Q;
    vector<long double> ans(Q);
    cout << endl;
    REP(i, Q)
    {
        long double E; cin >> E;
        vec p(0.0, -L/2*sinl(2*PI/T*E), L/2+L/2*-cosl(2*PI/T*E));
        //cout << p.x << " " << p.y << " " << p.z << endl;
        long double angle = atan2l(p.z, sqrtl(q.x*q.x+(p.y-q.y)*(p.y-q.y))) * 180.0 / PI;
        ans[i] = angle;
    }
    REP(i, Q) cout << ans[i] << endl;
}