//
//  main.cpp
//  Top_K_Frequent_Element
//
//  Created by Sharon He on 12/21/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> frequency;
        auto compare = [](pair<int,int>pair1,pair<int,int>pair2){
            return pair1.second<pair2.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(compare)> pq(compare);
        vector<int> mostFrequent;
        for(int i = 0; i<nums.size(); i++)
        {
            if(frequency.find(nums[i])!=frequency.end())
            {
                frequency[nums[i]] += 1;
            }
            else
            {
                frequency[nums[i]] = 1;
            }
        }
        for(auto itr = frequency.begin(); itr!=frequency.end(); ++itr)
        {
            pq.push(make_pair(itr->first,itr->second));
        }
        for(int i = 1; i<=k; i++)
        {
            int j = pq.top().first;
            pq.pop();
            mostFrequent.push_back(j);
        }
        return mostFrequent;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
