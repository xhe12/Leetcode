//
//  main.cpp
//  Leetcode #133: Clone_Graph
//
//  Created by Sharon He on 12/9/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {}
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> nodeCorr;
        unordered_set<Node*> processed;
        
        Node* nodeCopy = new Node(node->val,{});
        nodeCorr[node] = nodeCopy;
        correspondNodes(node,nodeCopy,nodeCorr,processed);
        
        return nodeCopy;
    }
    
    Node* cloneGraph_DFS_iterative(Node* node){
        unordered_map<Node*,Node*> nodeCorr;
        unordered_set<Node*> processed;
        vector<Node*> stack;
        
        Node* nodeCopy = new Node(node->val,{});
        nodeCorr[node] = nodeCopy;
        stack.push_back(node);
        while(!stack.empty())
        {
            Node *cur_node = stack.back();
            stack.pop_back();
            
            if(processed.find(cur_node)!=processed.end())
            {
                continue;
            }
            
            /*
            if(nodeCorr.find(cur_node)==nodeCorr.end())
            {
                Node* cur_node_copy = new Node(cur_node->val,{});
                nodeCorr[cur_node] = cur_node_copy;
            }
             */
            for(Node* x: cur_node->neighbors)
            {
                if(nodeCorr.find(x)==nodeCorr.end())
                {
                    Node* x_copy = new Node(x->val,{});
                    nodeCorr[x] = x_copy;
                }
                nodeCorr[cur_node]->neighbors.push_back(nodeCorr[x]);
                
                if(processed.find(x)==processed.end())
                {
                    stack.push_back(x);
                }
            }
            processed.insert(cur_node);
        }
        
        return nodeCopy;
    }
    
    /*
    Node* cloneGraph_BFS_iterative(Node* node){
        
    }
    */
    
private:
    void correspondNodes(Node* node,Node* nodeCopy,unordered_map<Node*,Node*> &nodeCorr,unordered_set<Node*> &processed)
    {
        if(processed.find(nodeCopy)!=processed.end())
        {
            return;
        }
        for(Node *x: node->neighbors)
        {
            if(nodeCorr.find(x)==nodeCorr.end())
            {
                Node* xCopy = new Node(x->val,{});
                nodeCorr[x] = xCopy;
            }
            nodeCopy->neighbors.push_back(nodeCorr[x]);
            //correspondNodes(x, xCopy, nodeCorr,processed);
        }
        processed.insert(nodeCopy);
        
        for(Node *x: node->neighbors)
        {
            correspondNodes(x, nodeCorr[x], nodeCorr,processed);
        }
    }
};

int main(int argc, const char * argv[]) {
    Node *node1 = new Node(1,{});
    Node *node2 = new Node(2,{node1});
    Node *node3 = new Node(3,{node2});
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node3);
    
    Solution sol;
    Node *node1Copy = sol.cloneGraph_DFS_iterative(node1);
    
}
