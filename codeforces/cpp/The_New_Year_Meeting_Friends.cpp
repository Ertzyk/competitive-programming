#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> x(3);
    for(int &p: x) cin >> p;
    sort(x.begin(), x.end());
    cout << x[2] - x[0] << '\n';
    return 0;
}