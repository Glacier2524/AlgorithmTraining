class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto slow = nums.begin();
        auto fast = nums.begin();

        while (fast != nums.end()) {
            if (*fast == val)
            {
                fast++;
            }
            else
            {
                *slow = *fast;
                fast++;
                slow++;
            }
        }
        return slow - nums.begin() ;
    }
};