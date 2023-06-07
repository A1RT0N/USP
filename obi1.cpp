#include <vector>
#include <iostream> 
#include <algorithm>

using namespace std;

int main(){
    int v,a,f,p;
    cin >> v >> a >> f >> p;
    vector<int> contas = {a,f,p};

    sort(contas.begin(), contas.end());

    int res = 0;

    for(int i =0; i<contas.size(); i++){
        if(v >= contas[i]) break;
        res++;
        v -= contas[i];
        
    }
    cout << res << endl;
    return 0;
    
}