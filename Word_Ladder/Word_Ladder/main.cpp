//
//  main.cpp
//  Leetcode #127: Word_Ladder
//
//  Created by Sharon He on 1/6/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution{
    bool neighboring(string curWord,string wordToPick){
        int count = 0;
        for(int i = 0; i<curWord.length();i++){
            if(curWord[i]!=wordToPick[i]){
                count++;
            }
            if(count>=2){return false;}
        }
        return true;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        unordered_map<string,vector<string>> graph;
        if(wordList.size()==1 && neighboring(wordList[0], beginWord)){
            graph[beginWord].push_back(wordList[0]);
            graph[wordList[0]].push_back(beginWord);
        }
        for(int i = 0; i<wordList.size()-1; i++){
            if(neighboring(wordList[i], beginWord)){
                graph[beginWord].push_back(wordList[i]);
            }
            for(int j = i+1; j<wordList.size(); j++){
                if(neighboring(wordList[i], wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        
        if(graph.find(endWord)==graph.end()){
            return 0;
        }
        unordered_map<string,int> visited;//if the word is unvisited, then value = 0; otherwise, value = distance to beginWord.
        
        for(int i = 0; i<wordList.size(); i++){
            visited[wordList[i]]=-1; //if the word is unvisited, then value = 0; otherwise, value = distance to beginWord.
            visited[beginWord] = 1;
        }
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            string curWord =q.front();
            q.pop();
            if(curWord==endWord){
                return visited[curWord];
            }
            else{
                for(string s:graph[curWord]){
                    if(visited[s]==-1){
                        q.push(s);
                        visited[s] = visited[curWord]+1;
                    }
                }
            }
        }
        return 0;
    }
};
int main(int argc, const char * argv[]) {
    //vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    vector<string> wordList = {"cog"};
    string beginWord = "hog";
    string endWord = "cog";
    Solution sol;
    int l = sol.ladderLength(beginWord, endWord, wordList);
    return 0;
}
