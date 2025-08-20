/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        //vector<int> a(26, 0);
        vector<vector<int>> m;
        vector<vector<string>> ans;
        for(string s:strs){
            vector<int> cur(26, 0);
            for(char c:s){
                cur[c-'a']++;
            }
            int tag=0;
            for(int i=0;i<m.size();i++){
                if(cur==m[i]){
                    tag=1;
                    ans[i].push_back(s);
                    break;
                }
            }
            if(tag==0){
                m.push_back(cur);
                ans.push_back({s});
            }
        }
        return ans;


    }

    //排序后哈希
     vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;
        for(string &s:strs){
            string key=s;
            sort(key.begin(),key.end());
            map[key].emplace_back(s);

        }
        for(auto temp:map){
            ans.push_back(temp.second);
        }
        return ans;
    }

};
// @lc code=end

