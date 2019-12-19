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

class Node {
public:
    Node(int _name, int _stops, int _cost): name(_name), cost(_cost), stops(_stops) {}
    int name;
    int cost;
    int stops;
};

class Edge {
public:
    Edge(int _from, int _to, int _cost):from(_from), to(_to), cost(_cost) {}
    int from;
    int to;
    int cost;
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<Edge>> graph(n, vector<Edge>());
        for(auto& f: flights) {
            Edge e(f[0], f[1], f[2]);
            graph[f[0]].push_back(e);
        }
        
        vector<bool> visited(n, false);
        
        auto compare = [](Node lhs, Node rhs) { return lhs.cost > rhs.cost; };
        priority_queue<Node, vector<Node>, decltype(compare)> pq(compare);
        
        Node src_node(src, -1, 0);
        pq.push(src_node);
        
        while(!pq.empty()) {
            Node node = pq.top(); pq.pop();
            if (node.name == dst) {
                return node.cost;
            }
            for(auto e: graph[node.name]) {
                if (!visited[e.to] && node.stops + 1 <= K) {
                    Node nei(e.to, node.stops + 1, node.cost + e.cost);
                    pq.push(nei);
                }
            }
            visited[node.name] = true;
        }
        return -1;
    }
    
    int findCheapestPrice_BellmanFord(int n, vector<vector<int>>& flights, int src, int dst, int K){
        vector<vector<int>> dp(K+1,vector<int>(n,INT_MAX/2));
        for(int i = 0; i<K+1; i++)
        {
            dp[i][src] = 0;
        }
        for(int j = 0; j<flights.size(); j++)
        {
            if(flights[j][0]==src)
            {
                dp[0][flights[j][1]] = flights[j][2];
            }
        }
        for(int i = 1; i<K+1; i++)
        {
            for(int j = 0; j<flights.size(); j++)
            {
                dp[i][flights[j][1]] = min(dp[i][flights[j][1]],dp[i-1][flights[j][0]]+flights[j][2]);
                dp[i][flights[j][1]] = min(dp[i][flights[j][1]],dp[i-1][flights[j][1]]);
            }
        }
        return (dp[K][dst]>=INT_MAX/2)?-1:dp[K][dst];
    }
};

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> flights = {{0,1,5},{1,2,5},{0,3,2},{3,1,2},{1,4,1},{4,2,1}};
    int n = 5;
    int src = 0;
    int dst = 2;
    int K = 2;
    Solution sol;
    cout<<sol.findCheapestPrice_BellmanFord(n, flights, src, dst, K);
     /*
    queue<pair<int,int>> q;
    q.push(make_pair(1,1));
    pair<int,int> topPair = q.front();
    q.pop();
    cout<<topPair.first<<endl;
    cout<<topPair.second<<endl;
    */
    return 0;
}
