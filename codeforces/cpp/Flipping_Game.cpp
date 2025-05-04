#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, cur = 0, max_add = INT_MIN;
    cin >> n;
    vector<int> a(n), b(n + 1);
    for(int &x: a) cin >> x;
    b[0] = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0) cur++;
        else cur--;
        b[i + 1] = cur;
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n + 1; j++){
            max_add = max(max_add, b[j] - b[i]);
        }
    }
    cout << count(a.begin(), a.end(), 1) + max_add;
    return 0;
}