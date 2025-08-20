/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        //教科书般的堆，
        /*
        lambda[捕获列表](参数列表) -> 返回类型 { 函数体 }
        */
        //捕获队列记得用[&],用[=]会爆内存
        //priority_queue 默认是 最大堆（less<T>），即 > 会让较小的元素排在前面，形成 最小堆。
        auto cmp =[&nums1,&nums2](const pair<int ,int >&a,const pair<int, int> & b){
            return nums1[a.first]+nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        vector<vector<int>> res;
        int m=nums1.size();
        int n=nums2.size();
        /*priority_queue<Type, Container, Compare> pq;
        其中三个模板参数的含义如下：
            Type: 队列中存储的元素类型（必需）
            Container: 底层容器类型（可选，默认为 vector<Type>）
            Compare: 比较函数/函数对象类型（可选，默认为 less<Type>）
        
        */
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        
        /*
        如果您已经有一个对象实例并且想要将其添加到容器中，使用 push_back 是合适的。
        如果您想要构造一个新对象并直接放到容器中，使用 emplace_back 可以避免额外的拷贝或移动操作，从而更为高效。
        */
        for(int i=0;i<min(m,k);i++){
            pq.emplace(i,0);
        }

        while(k-->0&&!pq.empty()){
            auto [x,y]=pq.top();
            pq.pop();
            
            res.push_back({nums1[x],nums2[y]});
            if(y+1<n){
                pq.emplace(x,y+1);
            }
        }
        
        return res;
        
    }
};
// @lc code=end

