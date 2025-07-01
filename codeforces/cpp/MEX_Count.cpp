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
        cin >> n;
        vector<int> count(n + 1, 0);
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            count[x]++;
        }
        int mex = n + 1;
        for(int i = 0; i <= n; i++){
            if(count[i] == 0){
                mex = i;
                break;
            }
        }
        vector<int> count_idx(n + 1, 0);
        for(int i = 0; i < mex; i++) count_idx[count[i]]++;
        vector<int> result(n + 1);
        result[0] = 1;
        int k = 1;
        for(int i = 1; i <= n; i++){
            k += count_idx[i];
            result[i] = min(k, n + 1 - i);
        }
        for(int x: result) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}