#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#if __cplusplus > 201103L
#include <initializer_list>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#ifndef ONLINE_JUDGE
#define DEBUG
#endif

#define inf 0x3F3F3F3F
#define fst first
#define snd second
#define PB push_back
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int _end_ = (b), i = (a); i <= _end_; ++i)
#define ROF(i, a, b) for (int _end_ = (b), i = (a); i >= _end_; --i)

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;

int64 fpm(int64 b, int64 e, int64 m) { int64 t = 1; for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0; return t; }
template<class T> inline bool chkmin(T &a, T b) {return a > b ? a = b, true : false;}
template<class T> inline bool chkmax(T &a, T b) {return a < b ? a = b, true : false;}
template<class T> inline T sqr(T x) {return x * x;}
template <typename T> T gcd(T x, T y) {for (T t; x; ) t = x, x = y % x, y = t; return y; }

template<class edge> struct Graph {
    vector<vector<edge> > adj;
    Graph(int n) {adj.clear(); adj.resize(n + 5);}
    Graph() {adj.clear(); }
    void resize(int n) {adj.resize(n + 5); }
    void add(int s, edge e){adj[s].push_back(e);}
    void del(int s, edge e) {adj[s].erase(find(iter(adj[s]), e)); }
    vector<edge>& operator [](int t) {return adj[t];}
};

const int n = 25, N = n + 10;

real f[N], g[N], P[N];

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);

    cout << setprecision(20);
    real ans = 0;
    for (int _ = 10; _ <= 10; ++_) {
        
        real p = _ / (real)100.0;
        f[1] = 1, g[1] = 0, g[0] = 1e300;
        for (int i = 0; i <= n; ++i)
            P[i] = pow(1 - p, i);

        for (int i = 2; i <= n; ++i) {
            f[i] = g[i] = i;

            int a = i, b = i;
            for (int k = 1; k < i; ++k) {
                real t = (P[k] - P[i]) / (1 - P[i]); cout << t << endl;
                if (chkmin(g[i], (1 - t) * (f[i - k] + g[k]) + t * g[i - k] + 1))
                    a = k;
            }
            for (int k = 1; k <= i; ++k) {
                real t = P[i];
                if (chkmin(f[i], f[i - k] + (1 - t) * g[k] + 1))
                    b = k;
            }
            cout << i << " " << f[i] << " " << g[i] << " " << a << " " << b << endl;
            // cout << f[i] - f[i - 1] << endl;
        }
        // cout << p << " " << f[n] << endl;
        ans += f[n];
    }
    cout << ans << endl;

    return 0; 
}

