#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <iomanip>
using namespace std;

double distance(int x1, int y1, int x2, int y2){
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<double> dp(n);
    vector<pair<int, pair<pair<int, int>, double>>> order(n);
    for(int i = 0; i < n; i++){
        int x, y, t;
        double p;
        cin >> x >> y >> t >> p;
        order[i] = {t, {{x, y}, p}};
    }
    sort(order.begin(), order.end());
    double result = 0;
    for(int i = 0; i < n; i++){
        dp[i] = order[i].second.second;
        for(int j = 0; j < i; j++){
            if(distance(order[i].second.first.first, order[i].second.first.second, order[j].second.first.first, order[j].second.first.second) 
            <= order[i].first - order[j].first + 0.00001) dp[i] = max(dp[i], dp[j] + order[i].second.second);
        }
        result = max(result, dp[i]);
    }
    cout << fixed << setprecision(8) << result;
    return 0;
}