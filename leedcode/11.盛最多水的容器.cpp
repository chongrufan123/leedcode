/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    // AC
    int min_height(int a, int b){
        if(a < b) return a;
        else return b;
    }
    // int maxArea(vector<int>& height) {
    //     int max = 0;
    //     int mm, limit_height;
    //     for(int i = 0; i < height.size() - 1; ++i){
    //         limit_height = 0;
    //         for(int j = height.size() - 1; j > i; --j){
    //             if(limit_height < height[j]) limit_height = height[j];
    //             else continue;
    //             mm = min_height(height[i], height[j]) * (j - i);
    //             if(max < mm)
    //                 max = mm;
    //             if(limit_height >= height[i]) break;
    //         }
    //     }
    //     return max;
    // }

    // 标答，双指针
    int maxArea(vector<int>& height){
        int max = 0;
        int volume;
        vector<int>::iterator it_l = height.begin(), it_r = height.end() - 1;
        while(it_l != it_r){
            volume = (it_r - it_l) * min_height(*it_l.base(), *it_r.base());
            if(max < volume) max = volume;
            if(*it_l.base() > *it_r.base()) it_r --;
            else it_l ++;
        }
        return max;
    }
};
// @lc code=end

