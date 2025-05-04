#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<bool> row(100, false);
    for(int i = 0; i < 100; i++) if(i == 0 || i%4 == 3) row[i] = true;
    for(int x: row) cout << x;
    cout << '\n';
    fill(row.begin(), row.end(), false);
    for(int i = 0; i < 100; i++) if(i != 0 && i%4 != 2) row[i] = true;
    for(int x: row) cout << x;
    cout << '\n';
    for(int i = 4; i < 100; i += 4) row[i] = false;
    for(int k = 0; k < 96; k++){
        for(int x: row) cout << x;
        cout << '\n';
    }
    for(int i = 2; i < 100; i += 4) row[i] = true;
    for(int x: row) cout << x;
    cout << '\n';
    fill(row.begin(), row.end(), false);
    for(int i = 1; i < 100; i += 4) row[i] = true;
    for(int x: row) cout << x;
    return 0;
}