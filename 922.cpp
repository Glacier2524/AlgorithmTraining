//双指针

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        auto even = nums.begin();//奇
        auto odd = nums.begin() + 1;//偶

        auto temp = nums.end() - 1;//只看最后一个元素
        while (even < nums.end() && odd < nums.end()) {
            
            //保证奇数指针上面是奇数，偶也是
            if (*temp % 2 == 0) {
                std::swap(*temp, *even);
                temp = nums.end() - 1;
                even = even + 2;
            }
            else {
                std::swao(*temp, *odd);
                temp = nums.end() - 1;
                odd = odd + 2;
            }
        }

    }
    return nums;
};