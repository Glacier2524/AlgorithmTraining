//第一种是我自己想到的暴力解法，但是很慢

class Solution {
public:
    int strStr(string haystack, string needle) {

        //注意预处理
        if (needle.empty())
            return 0;

        auto small = needle.begin();
        auto slow = haystack.begin();
        auto fast = slow;

        while (slow != haystack.end()) {
            if (*fast == *small && fast != haystack.end() && small != needle.end()) {
                fast++;
                small++;
                continue;
            }
            if (small == needle.end()) {
                return  slow - haystack.begin();

            }
            else {
                slow++;
                fast = slow;
                small = needle.begin(); //第一次写的时候没有重置，下次注意
            }

        }
        return -1;

    }
};


//第二种KMP算法要快的多，并且主指针永远不回溯
class Solution {
public:
    int strStr(string haystack, string needle) {
        // 特殊情况：空字符串直接返回0
        if (needle.empty()) return 0;

        int n = haystack.size();
        int m = needle.size();

        // ========== 第一步：构建 next 数组（前缀表）==========
        // next[i] 表示：needle[0...i] 这一段字符串中，最长相同前后缀的长度
        // 什么是前后缀？前缀是去掉最后一个字符，后缀是去掉第一个字符
        // 例如："ababa" 的前缀是 "abab"，后缀是 "baba"，最长相同的是 "aba" 长度为3

        vector<int> next(m, 0);  // next[0] 永远是0，因为单个字符没有前后缀

        // i：正在计算 next[i] 的位置（后缀的末尾）
        // j：前缀的末尾位置，也表示当前匹配到的相同前后缀的长度
        for (int i = 1, j = 0; i < m; i++) {
            // 当 j > 0 且当前字符不匹配时，j 需要回退
            // 回退到 next[j-1] 的位置，这是 KMP 的核心思想
            // 相当于说："既然长的不匹配，我试试短一点的能不能匹配上"
            while (j > 0 && needle[i] != needle[j]) {
                j = next[j - 1];  // 根据已知信息回跳，避免从头开始
            }

            // 如果当前字符匹配上了，相同前后缀长度+1
            if (needle[i] == needle[j]) {
                j++;
            }

            // 记录 i 位置的最长相同前后缀长度
            next[i] = j;
        }

        // ========== 第二步：利用 next 数组进行字符串匹配 ==========
        // i：主串 haystack 的指针，永远不后退！
        // j：模式串 needle 的指针，匹配失败时根据 next 数组回跳

        for (int i = 0, j = 0; i < n; i++) {
            // 当 j > 0 且当前字符不匹配时
            // 主串指针 i 不动，模式串指针 j 根据 next 数组回跳
            // 这避免了暴力法中 i 的回溯，大大提高了效率
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];  // j 回跳到之前记录的位置
            }

            // 如果当前字符匹配，j 前进
            if (haystack[i] == needle[j]) {
                j++;
            }

            // 如果 j 走到了模式串的末尾，说明完全匹配成功
            if (j == m) {
                // 返回匹配的起始位置
                // i 是当前匹配到的位置，j 是模式串长度
                // 起始位置 = i - j + 1
                return i - m + 1;
            }
        }

        // 没有找到匹配的子串
        return -1;
    }
};