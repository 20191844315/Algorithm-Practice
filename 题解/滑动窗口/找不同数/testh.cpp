#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
int main(){
    int n,q,temp;
    while(cin>>n>>q){
        vector<int>nums;
        vector<int>ws;
        for(int i=0;i<n;i++){
            cin>>temp;
            nums.push_back(temp);
        }
        for(int i=0;i<q;i++){
            cin>>temp;
            ws.push_back(temp);
        }

        int max=*max_element(nums.begin(),nums.end());
        for(int i=0;i<q;i++){
            int w=ws[i];
            int j,distinct=0;
            long long res=0;
            vector<int>freq(max+1,0);
            //处理第一个窗口
            for(j=0;j<w;j++){
                if( freq[nums[j]]==0){
                    distinct++;
            }
            freq[nums[j]]++;
            }
            res+=distinct;
            //滑动窗口开始
            for(j;j<n;j++){
                //处理左边消失的数
                int left=nums[j-w];
                freq[left]--;
                if(freq[left]==0){
                    distinct--;
                }
                //处理右边出现的数
                int right=nums[j];
                if( freq[nums[j]]==0){
                    distinct++;
                }
                freq[nums[j]]++;

                res+=distinct;
            }
            cout<<res<<endl;
    }
    }

}