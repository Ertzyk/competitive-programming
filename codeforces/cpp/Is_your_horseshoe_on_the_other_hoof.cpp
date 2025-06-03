#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    unordered_set<int> horseshoes;
    for(int i = 0; i < 4; i++){
        int s;
        cin >> s;
        horseshoes.insert(s);
    }
    cout << 4 - horseshoes.size() << '\n';
    return 0;
}