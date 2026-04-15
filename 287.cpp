
//类似环形链表
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        //左程云的解法，很奇妙
        //慢一次一，快一次二，按数移动至对应下标
        int slow = nums[0];
        int fast = nums[nums[0]];

        while (fast != slow) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        //最后将快指针归0，和满指针同速，找到环的初始点
        while (slow != fast) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};