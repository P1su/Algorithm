#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int dp[101][101] = {0,};
    int answer = 0;
    
    // 첫 경로는 1로 초기화
    dp[1][2] = 1;
    dp[2][1] = 1;

    // 웅덩이는 -1로 초기화
    for (int i = 0; i < puddles.size(); ++i) {
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }
    
    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= m ; j++){
            // 웅덩이거나 첫 경로일 경우 건너뜀
            if(dp[i][j] == -1 || (i == 1 && j == 2) || (i == 2 && j == 1))continue;
            
            // 이전 경로의 수를 더한 값과 이전 경로값을 비교
            // 웅덩이가 있는 경우를 고려
            dp[i][j] = max(dp[i-1][j] + dp[i][j-1], max(dp[i-1][j], dp[i][j-1])) % 1000000007;
        }
    }
   
    return dp[n][m];
}