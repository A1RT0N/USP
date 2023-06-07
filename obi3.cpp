#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int a,b, j = 0, res =0;;
    cin >> a >> b;

    int v[a];

    int v2[b];

    for(int i = 0; i<a; i++) cin >> v[i];

    for(int i = 0; i<b; i++) cin >> v2[i];

    for (int i = 0; i<a; i++){
        if(v[i] == v2[j]){
            j++;
            res++;
        }

    }

    if (res == b) cout << "sim" << endl;
    else cout << "nao" << endl;

    

}