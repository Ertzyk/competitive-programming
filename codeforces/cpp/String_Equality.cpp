#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        string a, b;
        cin >> n >> k >> a >> b;
        vector<int> a_let(26, 0), b_let(26, 0);
        for(char ch: a) a_let[ch - 'a']++;
        for(char ch: b) b_let[ch - 'a']++;
        bool found = false;
        for(int i = 0; i < 25; i++){
            if(a_let[i] >= b_let[i] && (a_let[i] - b_let[i])%k == 0) a_let[i + 1] += a_let[i] - b_let[i];
            else {
                cout << "No\n";
                found = true;
                break;
            }
        }
        if(!found) cout << "Yes\n";
    }
    return 0;
}