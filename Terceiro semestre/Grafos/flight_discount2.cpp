#include <bits/stdc++.h>

#define MAXN 200000 + 10

using namespace std;

typedef long long int lli;
typedef pair<lli, int> pli;

#define INF INT64_MAX 

vector<pli> g[MAXN];
lli dist[MAXN];
int n, m;

void dijkstra(int A) {
    priority_queue<pli, vector<pli>, greater<pli>> fila;

    for(int i = 1; i <= 2 * n; i++) dist[i] = INF;

    fila.push({0, A});
    dist[A] = 0;

    while(!fila.empty()) {
        lli d = fila.top().first;
        int u = fila.top().second;
        
        fila.pop();
        if(d > dist[u]) continue;

        for(pli par: g[u]) {
            lli d2 = d + par.first;
            if(d2 < dist[par.second]) {
                dist[par.second] = d2;
                fila.push({d2, par.second});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        
        g[x].push_back({c, y});
        g[x].push_back({c/2, y+n});
        g[x+n].push_back({c, y+n});
    }

    dijkstra(1);

    cout << dist[2*n] << endl;
    
    return 0;
}
