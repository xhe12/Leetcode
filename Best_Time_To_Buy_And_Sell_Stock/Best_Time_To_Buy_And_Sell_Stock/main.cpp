//
//  main.cpp
//  Best_Time_To_Buy_And_Sell_Stock
//
//  Created by Xuan He on 12/14/19.
//  Copyright © 2019 Xuan He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curMin = prices[0];
        int profit = 0;
        for(int i = 1; i<prices.size(); i++)
        {
            if(prices[i]>curMin)
            {
                profit = max(profit,prices[i]-curMin);
            }
            else
            {
                curMin = prices[i];
            }
        }
        return profit;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
