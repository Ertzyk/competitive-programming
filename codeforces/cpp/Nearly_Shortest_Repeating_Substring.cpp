#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        vector<int> div;
        for(int i = 1; i*i <= n; i++){
            if(n%i == 0){
                div.push_back(i);
            }
        }
        for(int i = div.size() - 1; i > 0; i--) if(div[i]*div[i] != n) div.push_back(n/div[i]);
        bool flag = false;
        for(int d: div){
            int cnt_diff = 0;
            for(int i = 0; i < d; i++){
                char root = 'X';
                if(s[i] != s[i + d]){
                    cnt_diff++;
                    if(i + 2*d < n){
                        if(s[i + 2*d] == s[i] || s[i + 2*d] == s[i + d]) root = s[i + 2*d];
                        else cnt_diff++;
                    }
                } else root = s[i];
                if(cnt_diff >= 2) break;
                for(int j = 2; i + j*d < n; j++) if(root != s[i + j*d]) cnt_diff++;
                if(cnt_diff >= 2) break;
            }
            if(cnt_diff < 2){
                cout << d << '\n';
                flag = true;
                break;
            }
        }
        if(!flag) cout << n << '\n';
    }
    return 0;
}