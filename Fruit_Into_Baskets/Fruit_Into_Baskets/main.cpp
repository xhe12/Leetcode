//
//  main.cpp
//  Fruit_Into_Baskets
//
//  Created by Sharon He on 1/7/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    void subtractOne(unordered_map<int,int>& collection,int i){
        if(collection.find(i)!=collection.end()){
            collection[i]--;
            if(collection[i]<=0){
                collection.erase(i);
            }
        }
    }
public:
    int totalFruit(vector<int>& tree) {
        int total = 0;
        
        unordered_map<int,int> collection;
        
        int rPtr = 0;
        int lPtr = 0;
        int sum;
        
        while(rPtr<tree.size()){
            if(collection.find(tree[rPtr])!=collection.end()){
                collection[tree[rPtr]]+=1;
            }
            else{
                collection[tree[rPtr]] = 1;
                while(collection.size()>=3){
                    subtractOne(collection,tree[lPtr]);
                    lPtr++;
                }
                
            }
            sum = 0;
            for(auto i:collection){
                sum += i.second;
            }
            total = (total>sum)?total:sum;
            rPtr++;
        }
        return total;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> tree = {1,0,1,4,1,4,1,2,3};
    Solution sol;
    int t = sol.totalFruit(tree);
    cout<<t<<endl;
    return 0;
}
