#include <bits/stdc++.h>
using namespace std;

struct compare {
    bool operator()(pair<string, int>& a, pair<string, int>& b) {
        return a.second > b.second; 
    }
};

int main() {
    int n;
    cin >> n;

    vector<string> quartos(n);
    for(int i = 0; i < n; i++) {
        cin >> quartos[i]; 
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, compare> pq;

    string a;
    for(int i = 0; i < n; i++) {
        cin >> a;
        pq.push({a, i});
    }

    for(int i = 0; i < n; i++) {
        pair<string, int> min = pq.top();
        cout << min.first << " ";
        
        pq.pop();
        while (!pq.empty() && pq.top().first == quartos[i]) {
            pq.pop();
        }
    }

    cout << endl;

    return 0;
}