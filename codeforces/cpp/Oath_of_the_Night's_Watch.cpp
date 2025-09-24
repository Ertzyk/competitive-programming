#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, result = 0;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    pair<vector<int>::iterator, vector<int>::iterator> mnmx;
    mnmx = minmax_element(a.begin(), a.end());
    for(int x: a) if(x != *mnmx.first && x != *mnmx.second) result++;
    cout << result << '\n';
    return 0;
}