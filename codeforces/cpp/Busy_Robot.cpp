#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, position = 0;
        cin >> n;
        vector<pair<int, int>> commands(n);
        for(auto &pr: commands) cin >> pr.first >> pr.second;
        vector<int> where(n + 1);
        int going = commands[0].second, result = 0;
        for(int i = 1; i < n; i++){
            if(going > position) position = min(going, position + commands[i].first - commands[i - 1].first);
            else if(going < position) position = max(going, position - commands[i].first + commands[i - 1].first);
            if(position == going) going = commands[i].second;
            where[i] = position;
        }
        where[n] = going;
        for(int i = 0; i < n; i++){
            if(where[i] < where[i + 1]){
                if(where[i] <= commands[i].second && commands[i].second <= where[i + 1]) result++;
            } else {
                if(where[i] >= commands[i].second && commands[i].second >= where[i + 1]) result++;
            }
        }
        cout << result << '\n';
    }
    return 0;
}