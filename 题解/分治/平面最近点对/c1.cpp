#include<iostream>
#include <algorithm>
#include <cmath>
#include <utility>//pair
#include<vector>

using namespace std;

struct point{
    int x,y,sign;
    
    //构造函数
    point (int x,int y,int sign):x(x),y(y),sign(sign){}

};

int distance(const point &a,const point &b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

pair<point,point> updata(const pair<point,point> &cur,const pair<point,point> &ans){
    //计算两个点对的距离
    int cur_dis=distance(cur.first, cur.second);
    int ans_dis=distance(ans.first, ans.second);
    if(cur_dis<ans_dis){
        return cur;
    }else if(cur_dis==ans_dis){
        int cur_a=min(cur.first.sign,cur.second.sign);
        int cur_b=max(cur.first.sign,cur.second.sign);
        int ans_a=min(ans.first.sign,ans.second.sign);
        int ans_b=max(ans.first.sign,ans.second.sign);
        if(cur_a<ans_a||(cur_a==ans_a&&cur_b<ans_b)){
            return cur;
        }
    }
    return ans;
}
bool cmp_x(const point &a,const point &b){//保证cmp为真
    return a.x<b.x;
}
bool cmp_y(const point &a,const point &b){//保证cmp为真
    return a.y<b.y;
}
pair<point,point>find(const vector<point> &ps,int left,int right){//朴素穷举
    pair<point,point>ans(point(0,0,-1),point(1e4,1e4,-1));
    for(int i=left;i<right;i++){
        for(int j=i+1;j<right;j++){
            pair<point,point> cur={ps[i],ps[j]};
            ans = updata(cur, ans);
            
        }
    }
    return ans;
}
pair<point,point>fast_find(const vector<point> &ps,int left,int right){
    //处理边界值，太小用朴素找法
    
    if(right-left<=3){
        return find(ps,left,right);
    }
    int min_dis=1e8+1;
    pair<point,point>ans(point(0,0,-1),point(1e4,1e4,-1));
    int mid=left+(right-left)/2;
    //算左边，不考虑mid，让子问题尽量小
     pair<point,point>left_points=fast_find(ps,left,mid);
    
    //算右边
     pair<point,point>right_points=fast_find(ps,mid,right);
     
    
    ans = updata(left_points, right_points);
    min_dis = distance(ans.first, ans.second);
    //处理中间
    vector<point> strip;
    //收集所有x坐标，距离mid的x坐标小于等于min_dis的点
    for(int i=left;i<right;i++){
       int dx = abs(ps[i].x-ps[mid].x);
       if(dx*dx<=min_dis){
            strip.push_back(ps[i]);
       }
    }
    //接下一个注释
    sort(strip.begin(),strip.end(),cmp_y);

    for(int i=0;i<strip.size();i++){
        for(int j=i+1;j<strip.size();j++){
            int dy=strip[j].y-strip[i].y;
            if(dy*dy>min_dis)break;//可以提前退出
            
            pair<point,point> cur={strip[i],strip[j]};
            ans = updata(cur, ans);
            min_dis = distance(ans.first, ans.second);
           
        }
    }
    

    return ans;
}


int main(){
    int n;
    while (cin>>n){
        vector<point> ps;
        int tx,ty;
        for(int i=0;i<n;i++){
            cin>>tx>>ty;
            ps.push_back(point(tx,ty,i));
        }
        sort(ps.begin(),ps.end(),cmp_x);
        // pair<point,point>res=find(ps,0,n);
        pair<point,point>res=fast_find(ps,0,n);
        if(res.first.sign<res.second.sign){
            cout<<res.first.sign<<" "<<res.second.sign<<endl;
        }else{
            cout<<res.second.sign<<" "<<res.first.sign<<endl;
        }
        
        
        
    }
    return 0;
    
}