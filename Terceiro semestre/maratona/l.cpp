#include <bits/stdc++.h>
#include <iterator>
using namespace std;

bool compare(pair<string, int> i, pair<string, int> j) {
    return i.second < j.second;
}

int main () {
    int n;
    cin >> n;

    map<string, int> mp;
    vector<string> quartos(n);

    for(int i = 0; i < n; i++) {
        cin >> quartos[i];
    }

    string a;
    for(int i = 0; i < n; i++) {
        cin >> a;
        mp.insert({a, i});
    }

    pair<string, int> min;

    for(int i = 0; i < n; i++) {
        min = *min_element(mp.begin(), mp.end(), compare);  
        cout << min.first << " ";

        mp.erase(quartos[i]);
    }

    cout << endl;

    return 0;
}