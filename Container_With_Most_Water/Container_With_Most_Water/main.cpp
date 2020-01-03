//
//  main.cpp
//  Container_With_Most_Water
//
//  Created by Sharon He on 1/3/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        unsigned int max_area = 0;
        unsigned int cur_area = 0;
        unsigned int left_ptr = 0;
        unsigned int right_ptr = (unsigned int)height.size()-1;
        unsigned int cur_height = 0;
        
        while(left_ptr<right_ptr){
            if(height[left_ptr]<height[right_ptr]){
                cur_height = height[left_ptr];
                cur_area = cur_height*(right_ptr-left_ptr);
                left_ptr++;
            }
            else{
                cur_height = height[right_ptr];
                cur_area = cur_height*(right_ptr-left_ptr);
                right_ptr--;
            }
            max_area = (cur_area>max_area)?cur_area:max_area;
        }
        return max_area;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
