#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int count = 0;
    int v[n+1][m+1];
    for (int i = 1; i<=n; i++) for (int j = 1; j<=m;j++) cin >> v[i][j];
    int p;
    cin >> p;
    for (int k = 0; k<p;k++){
        int x,y;
        cin >> x >> y;
        if(v[x][y] != 0){
            count++;
            v[x][y]--;
        }
    }
    cout << count << endl;
    return 0;
}