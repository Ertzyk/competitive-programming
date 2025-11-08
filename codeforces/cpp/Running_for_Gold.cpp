#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, cur_winner = 0;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(5));
        bool flag = false;
        for(int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
        for(int i = 1; i < n; i++){
            int wins = 0;
            wins += ((a[cur_winner][0] < a[i][0]) ? 1 : 0);
            wins += ((a[cur_winner][1] < a[i][1]) ? 1 : 0);
            wins += ((a[cur_winner][2] < a[i][2]) ? 1 : 0);
            wins += ((a[cur_winner][3] < a[i][3]) ? 1 : 0);
            wins += ((a[cur_winner][4] < a[i][4]) ? 1 : 0);
            if(wins < 3) cur_winner = i;
        }
        for(int i = 0; i < n; i++){
            if(i == cur_winner) continue;
            int wins = 0;
            wins += ((a[cur_winner][0] < a[i][0]) ? 1 : 0);
            wins += ((a[cur_winner][1] < a[i][1]) ? 1 : 0);
            wins += ((a[cur_winner][2] < a[i][2]) ? 1 : 0);
            wins += ((a[cur_winner][3] < a[i][3]) ? 1 : 0);
            wins += ((a[cur_winner][4] < a[i][4]) ? 1 : 0);
            if(wins < 3){
                flag = true;
                cout << "-1\n";
                break;
            }
        }
        if(!flag) cout << cur_winner + 1 << '\n';
    }
    return 0;
}