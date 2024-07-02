#include <stdio.h>
long long countNumbers(int p) {
    if (p == 1) return 2;  
    if (p == 2) return 4;  
    if (p == 3) return 7;  
    long long dp[p+1][3][2];  
    for (int i = 0; i <= p; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[1][1][0] = 1;  
    dp[1][1][1] = 1;  
    
    for (int i = 2; i <= p; i++) {
        dp[i][1][0] = dp[i-1][1][1] + dp[i-1][2][1]; 
        dp[i][2][0] = dp[i-1][1][0];  
        dp[i][1][1] = dp[i-1][1][0] + dp[i-1][2][0]; 
        dp[i][2][1] = dp[i-1][1][1];  
    }
    
    return dp[p][1][0] + dp[p][2][0] + dp[p][1][1] + dp[p][2][1];
}

int main() {
    int p;
    printf("Введіть значення p (p ≤ 30): ");
    scanf("%d", &p);
    
    if (p > 30 || p <= 0) {
        printf("Некоректне значення p. Повинно бути в діапазоні 1 ≤ p ≤ 30.\n");
        return 1;
    }
    
    long long result = countNumbers(p);
    printf("Кількість чисел із %d розрядів: %lld\n", p, result);
    
    return 0;
}
