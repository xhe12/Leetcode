//
//  main.cpp
//  Find_The_Cheapest_Flight
//
//  Created by Sharon He on 12/16/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K){
       if(src == dst)
        {
            return 0;
        }
        vector<vector<vector<int>>> graph(n);
        vector<int> stops(n,-1);
        vector<int> distTo(n,INT_MAX/2);
        auto compare = [](vector<int>edge1,vector<int>edge2){
            return  edge1[1]>edge2[1];};
        priority_queue<vector<int>,vector<vector<int>>,decltype(compare)> pq(compare);
        
        for(int i = 0; i < flights.size(); i++)
        {
            vector<int> v = {flights[i][1],flights[i][2]};
            graph[flights[i][0]].push_back(v);
        }
        distTo[src] = 0;
        pq.push(vector<int>{src,0});
        while(!pq.empty())
        {
            vector<int> edge = pq.top();
            pq.pop();
            int v = edge[0];
            for(vector<int> e: graph[v])
            {
                //relax e
                if(distTo[e[0]]>distTo[v]+e[1])
                {
                    distTo[e[0]]=distTo[v]+e[1];
                    stops[e[0]] = stops[v] + 1;
                    pq.push(vector<int>{e[0],distTo[e[0]]});
                }
            }
        }
        if(distTo[dst]>=INT_MAX/2)
        {
            return -1;
        }
        return distTo[dst];
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> flights = {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
    int n = 4;
    int src = 0;
    int dst = 3;
    int K = 1;
    Solution sol;
    cout<<sol.findCheapestPrice(n, flights, src, dst, K);
    return 0;
}
