//
//  main.cpp
//  DiceRollSimulation
//
//  Created by Sharon He on 11/14/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int dieSimulator(int n, vector<int>& rollMax)
    {
        vector<vector<int>> dp(n,vector<int>(6,0));
        vector<int> sum(n,0);
        long maxium = 1e9 + 7;
        
        for (int j=0; j<6; ++j)
        {
            dp[0][j] = 1;
        }
        sum[0] = 6;
        for (int i=1; i<6; ++i)
        {
            sum[i] = 0;
        }
        
        for (int i=1; i<n; ++i)
        {
            for (int j=0; j<6; ++j)
            {
                if (i+1<=rollMax[j])
                {
                    dp[i][j] = sum[i-1];
                }
                else
                {
                    for (int k=i-rollMax[j];k<=i-1;++k)
                    {
                        dp[i][j] += sum[k] - dp[k][j];
                    }
                }
                sum[i] = (sum[i] + dp[i][j]) % maxium;
            }
        }
        
        return sum[n-1];
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    int n = 20;
    vector<int> rollMax = {8,6,7,9,2,9};
    int validCases = sol.dieSimulator(n, rollMax);
    std::cout << "The total number of valid cases is: "<<validCases<<".\n";
    return 0;
}
