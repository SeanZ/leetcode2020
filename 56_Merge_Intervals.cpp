

/**

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <algorithm>
#include <vector>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }

        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for( int i = 0, j = 1; i < intervals.size();) {
            // i 是 用来被判定的临时的指针，j 是等待和 i对象 对比的指针
            if (intervals[i][1] < intervals[j][0]) {
                res.emplace_back(intervals[i]);
                i = j;
                j++; 
            } else if (intervals[i][1] >=  intervals[j][1]) {
                j++;
            } else {
                intervals[i][1] = intervals[j][1];
                j++;
            }

            if (j > intervals.size() -1) { 
                res.emplace_back(intervals[i]);
                break;
            }
        }

        return res;
    }
};