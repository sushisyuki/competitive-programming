#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

#define REP(i, n) for(int i=0; i < (n); i++)
#define REPS(i, n) for(int i=1; i <= (n); i++)

int N, L, K;
vi A;

bool c(int x)
{
    int s = 0;
    int cnt = 0;
    REPS(i, N+1)
    {
        s += A[i]-A[i-1];
        if(s >= x) cnt++, s = 0;
    }
    if(s >= x) cnt++, s = 0;
    return cnt >= K+1;
}

int main()
{
    cin >> N >> L >> K;
    A.resize(N+2);  
    A[0] = 0;
    REPS(i, N) cin >> A[i];
    A[N+1] = L;

    int l = 0, r = L;
    while(r-l > 1)
    {
        int m = (l+r) / 2;
        if(c(m)) l = m;
        else r = m;
    }
    cout << l << endl;
}