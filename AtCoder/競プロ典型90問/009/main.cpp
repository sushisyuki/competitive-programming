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

#define PI acosl(-1)

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const int INF = 1e9 + 7;
const ll  INFL = 1e18;

template<class T> bool chmax(T &a, const T &b) { if(a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if(a > b) { a = b; return true; } return false; }

pair<long double, long double> sub(const pair<long double, long double> &p, const pair<long double, long double> &q)
{
    return mp(p.first-q.first, p.second-q.second);
}

pair<long double, long double> normalize(const pair<long double, long double> &p)
{
    return mp(p.first / sqrtl(p.first*p.first+p.second*p.second), p.second / sqrtl(p.first*p.first+p.second*p.second));
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N; cin >> N;
    vector<pair<long double, long double>> p(N); REP(i, N) cin >> p[i].first >> p[i].second;

    long double ans = 0.0;
    REP(i, N)
    {
        vector<pair<long double, long double>> q;
        REP(j, N) 
        {
            if(i==j) continue;
            q.pb(normalize(sub(p[j], p[i])));
        }
        // cout << endl;
        // cout << i << endl;
        // REP(j, N-1) cout << q[j].first << " " << q[j].second << endl;
        vector<pair<long double, int>> t(N-1);
        REP(j, N-1)
        {
            long double angle = acosl(q[j].first);
            if(q[j].second < 0) angle = 2.0*PI - angle;
            t[j] = mp(angle, j);
        }
        sort(ALL(t));
        vector<pair<long double, int>> s(2*(N-1));
        REP(j, N-1)
        {
            s[j] = t[j];
            s[N-1+j] = mp(t[j].first+2.0*PI, t[j].second);
        }
        sort(ALL(s));
        //REP(j, 2*(N-1)) cout << s[j].first << " " << s[j].second << endl;
        REP(j, N-1)
        {
            int idx = lower_bound(ALL(s), mp(s[j].first+PI, -1)) - s.begin();
            long double d = s[j].first;

            if(s[j].second != s[idx].second)
            {
                long double a = s[idx].first;
                if(a >= 2.0*PI) a -= 2.0*PI;
                long double angle = abs(a-d);
                angle = min(angle, 2.0*PI-angle);
                chmax(ans, angle);
            }

            if(idx-1>=0 && s[j].second != s[idx-1].second)
            {
                long double b = s[idx-1].first;
                if(b >= 2.0*PI) b -= 2.0*PI;
                long double angle = abs(b-d);
                angle = min(angle, 2.0*PI-angle);
                chmax(ans, angle);
            }

            if(idx+1<2*(N-1) && s[j].second != s[idx+1].second)
            {
                long double c = s[idx+1].first;
                if(c >= 2.0*PI) c -= 2.0*PI;
                long double angle = abs(c-d);
                angle = min(angle, 2.0*PI-angle);
                chmax(ans, angle);
            }
        }
    }
    cout << ans * 180.0 / PI << endl;
}