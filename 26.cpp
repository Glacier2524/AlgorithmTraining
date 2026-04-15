class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //快慢指针处理
        auto slow = nums.begin();
        auto fast = nums.begin();

        while (fast != nums.end()) {
            if (*fast == *slow)
            {
                fast++;  //快指针先移动，直到找到不同数
            }
            else
            {
                slow++;  //slow用于改变原数组，直接将不同数尾插
                *slow = *fast;
            }
        }
        return slow - nums.begin() + 1;
    }
};