﻿/* ------------------------------------------------------------------|
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效的 IP 地址。

 

示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：

输入：s = "0000"
输出：["0.0.0.0"]
示例 3：

输入：s = "1111"
输出：["1.1.1.1"]
示例 4：

输入：s = "010010"
输出：["0.10.0.10","0.100.1.0"]
示例 5：

输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

提示：

0 <= s.length <= 3000
s 仅由数字组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/restore-ip-addresses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了69.49%的用户
*	内存消耗：6.8 MB, 在所有 C++ 提交中击败了55.80%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidSegment(const string& segment) {
    if (segment.size() > 1 && segment[0] == '0') {
        return false;
    }
    return (stoi(segment) >= 0 && stoi(segment) <= 255);
}
vector<string> restoreIpAddresses(string s) {
    if (s.size() < 4 || s.size() > 12) {
        return {};
    }
    vector<string> res;
    for (int i = 0; i < s.size() - 3; i++) {
        for (int j = i + 1; j < s.size() - 2; j++) {
            for (int k = j + 1; k < s.size() - 1; k++) {
                bool flag = isValidSegment(s.substr(0, i + 1))
                    && isValidSegment(s.substr(i + 1, j - i))
                    && isValidSegment(s.substr(j + 1, k - j))
                    && isValidSegment(s.substr(k + 1, s.size() - k - 1));
                if (flag) {
                    res.push_back(s.substr(0, i + 1) + '.' + s.substr(i + 1, j - i) + '.' + s.substr(j + 1, k - j) + '.' + s.substr(k + 1, s.size() - k - 1));
                }
            }
        }
    }
    return res;
}

