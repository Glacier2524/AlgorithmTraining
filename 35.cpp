//本题是二分查找模板

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)  //！！！
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target) {
                left = mid + 1;  //重点
            }
            else if (nums[mid] > target) {
                right = mid - 1; //！！！
            }
            else
                return mid;
        }

        return left;
    }
};