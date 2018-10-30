import java.util.*;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        BigInteger dp[][] = new BigInteger[1005][105];
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        for (int i = 0; i <= n; i++)
            dp[i][0] = dp[i][1] = BigInteger.valueOf(1);
        for (int j = 0; j <= k; j++)
            dp[0][j] = dp[1][j] = BigInteger.valueOf(1);
        for (int i = 2; i <= n; i++)
            for (int j = 2; j <= k; j++)
                if (i - j >= 0)
                    dp[i][j] = dp[i][j - 1].add(dp[i - j][j]);
                else
                    dp[i][j] = dp[i][j - 1];
        System.out.println(dp[n][k]);
    }
}
