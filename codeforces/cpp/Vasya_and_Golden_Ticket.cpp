#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, cnt0 = 0;
    string num;
    cin >> n >> num;
    bool flag2 = false;
    for(int i = n - 1; i >= 0; i--){
        if(num[i] == '0') cnt0++;
        else break;
    }
    if(cnt0 == n){
        cout << "YES\n";
        return 0;
    }
    for(int i = 1; i < n - cnt0; i++){
        int core_sum = 0, cur_sum = 0;
        for(int j = 0; j < i; j++) core_sum += num[j] - '0';
        bool flag = true;
        for(int j = i; j < n; j++){
            cur_sum += num[j] - '0';
            if(cur_sum == core_sum) cur_sum = 0;
            else if(cur_sum > core_sum){
                flag = false;
                break;
            }
        }
        if(cur_sum > 0) flag = false;
        if(flag){
            cout << "YES\n";
            flag2 = true;
            break;
        }
    }
    if(!flag2) cout << "NO\n";
    return 0;
}