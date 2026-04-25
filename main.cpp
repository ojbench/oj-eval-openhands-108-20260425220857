
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    // dp[j] represents the maximum value that can be achieved with capacity j
    vector<int> dp(m + 1, 0);
    
    for (int i = 0; i < n; i++) {
        int p, w, v;
        cin >> p >> w >> v;
        
        // Optimization: use binary representation to reduce multiple items to log(p) items
        // This is the "binary optimization" for bounded knapsack
        int num = p;
        for (int k = 1; k <= num; k *= 2) {
            int weight = k * w;
            int value = k * v;
            // 0-1 knapsack update in reverse order
            for (int j = m; j >= weight; j--) {
                dp[j] = max(dp[j], dp[j - weight] + value);
            }
            num -= k;
        }
        
        // Handle the remaining items
        if (num > 0) {
            int weight = num * w;
            int value = num * v;
            for (int j = m; j >= weight; j--) {
                dp[j] = max(dp[j], dp[j - weight] + value);
            }
        }
    }
    
    cout << dp[m] << endl;
    return 0;
}
