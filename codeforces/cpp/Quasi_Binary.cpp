#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> result;
    while(n > 0){
        int p = 0;
        string c = to_string(n);
        c.insert(0, 7 - c.size(), '0');
        for(char ch: c){
            p *= 10;
            if(ch != '0') p++;
        }
        result.push_back(p);
        n -= p;
    }
    cout << result.size() << '\n';
    for(int x: result) cout << x << ' ';
    return 0;
}