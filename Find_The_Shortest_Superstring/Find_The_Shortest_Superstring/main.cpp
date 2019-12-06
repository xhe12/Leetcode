//
//  main.cpp
//  Leetcode #943: Find_The_Shortest_Superstring
//  Time complexity: O(n^2*2^n)
//  Space complexity: O(n*2^n)

//  Created by Sharon He on 12/4/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> cost(1<<n,vector<int>(n,INT_MAX/2));// cost[s][j] is the number of total chars if the string j is added to the state i, ie when the string j is added to the front of the super string of set s. cost is of the size (2^n,n). When s=0, it means the current super string set is an empty set.
        vector<vector<int>> child(1<<n,vector<int>(n,-1));
        vector<vector<int>> twoStringCost(n,vector<int>(n,0));
        string supstring = "";
        
        for(int j = 0; j<n; j++)
        {
            cost[0][j] = A[j].length();
        }
        
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if (i!=j)
                {
                    twoStringCost[i][j] = shortestSuperstringLength(&A[i], &A[j]);
                }
            }
        }
        
        for (int s = 1; s<(1<<n)-1; s++)
        {
            for (int i = 0; i<n; i++)
            {
                if (s&(1<<i))
                {
                    continue;
                }
                for (int j = 0; j<n; j++)
                {
                    if (!(s&(1<<j)))
                    {
                        continue;
                    }
                    int prevState = s&(~(1<<j));
                    if (cost[prevState][j]+twoStringCost[i][j]<cost[s][i])
                    {
                        cost[s][i] = cost[prevState][j]+twoStringCost[i][j];
                        child[s][i] = j;
                    }
                }
            }
        }
        
        // The minimum cost = min_i cost[(1<<n)-1][i]
        int Indx = -1;
        int minCost = INT_MAX/2;
        
        for (int i = 0; i<n; i++)
        {
            if (minCost>cost[((1<<n)-1)&~(1<<i)][i])
            {
                minCost = cost[((1<<n)-1)&~(1<<i)][i];
                Indx = i;
            }
        }
        supstring.append(A[Indx]);
        int remain = ((1<<n)-1) & (~(1<<Indx));
        int prevIndx = -1;
        
        // Tracking the indices through child[][], and updating Indx;
        for (int i = 1; i<n; i++)
        {
            prevIndx = Indx;
            Indx = child[remain][prevIndx];
            remain = remain & (~(1<<Indx));
            string str = shortestExtraString(&A[prevIndx],&A[Indx]);
            supstring.append(str);
        }
        
        return supstring;
    }
private:
    int longestCommonLength(string *front, string *back)
    {
        // Calculate the number of chars added if "concatenate" *front and *back.
        int i = 0; // i is the number of common chars
        
        //longestCommonLengthUtil(front, back,0,0,i);
        int ptr1 = 0;
        int ptr2 = 0;
        while ((ptr1<front->length())&(ptr2<back->length()))
        {
            if((*front)[ptr1]==(*back)[ptr2])
            {
                ptr1 += 1;
                ptr2 += 1;
                i += 1;
            }
            else if (ptr2==0)
            {
                ptr1 += 1;
            }
            else
            {
                ptr2 = 0;
                i = 0;
            }
        }
        return i;
    }
    int shortestSuperstringLength(string *front, string *back)
    {
        int i = longestCommonLength(front, back);
        return front->length()-i;
    }
    string shortestExtraString(string *front, string *back)
    {
        int i;
        i = longestCommonLength(front, back);
        return back->substr(i,back->length()-i);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> A = {"catg","ctaggt","gcta","ttca","atgcatc"};
    //Solution sol;
    //string superstring = sol.shortestSuperstring(A);
    //cout << superstring << endl;
    return 0;
}
