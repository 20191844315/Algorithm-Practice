#include<bits/stdc++.h>

using namespace std;

/*
            max  z = 3x₁ + 2x₂
            s.t. 
                x₁ +  x₂ ≤ 4
                2x₁ +  x₂ ≤ 5
                x₁, x₂ ≥ 0
1、列出标准型，引入松驰变量，其中松驰变量数量等于(约束数n)，基变量为松弛变量。
    此时默认非基变量为0，基变量为b(偏置)。
2、列出单纯形表
    | 基变量 | x₁ | x₂ | s₁ | s₂ | b |
    |--------|----|----|----|----|---|
    | z      |  3 |  2 |  0 |  0 | 0 |
    | s₁     |  1 |  1 |  1 |  0 | 4 |
    | s₂     |  2 |  1 |  0 |  1 | 5 |
3、找换入和换出变量，
    换入变量选z行中最大的正数，因为这样换入变量增加使z增大最快。
    换出变量选b/a（换成变量列系数）最小的基变量。
4、pivot(e,l)
    1、归一化换出变量(s2)行，把换入变量系数变成1，并将基变量改名
    | s₂     |  1 |  0.5 |  0 |  0.5 | 2.5 |   
    2、把其他基变量行的换入变量(x1)系数变为0
    | 基变量 | x₁    | x₂     | s₁    | s₂     | b    |
    |--------|-------|--------|-------|--------|------|
    | z      |  0    | -0.5   |  0    |  1.5   | 7.5  |
    | s₁     |  0    |  0.5   |  1    | -0.5   | 1.5  |
    | x₁     |  1    |  0.5   |  0    |  0.5   | 2.5  |
    
    重复1,2，直到z的系数全部大于0。
5，根据系数算出最大值z。
    | 基变量 | x₁ | x₂ | s₁ | s₂ | b  |
    |--------|----|----|----|----|----|
    | z      |  0 |  0 |  1 |  1 |  9 |
    | x₂     |  0 |  1 |  2 | -1 |  3 |
    | x₁     |  1 |  0 | -1 |  1 |  1 |

*/
/*
若发现该问题的对偶问题是“最小标准型”，则将数据处理为对偶问题求解： 
c 读入spx.b[]，将 
b 读入spx.c[]，将 
a 转置读入spx.a[][].
*/

struct simple{
    vector<double>b,c;
    vector<vector<double>>a;
    double z;
    int m,n;
    
    void Init(int m_,int n_){
        m=m_;n=n_;
        z=0.0;
        a.assign(m+10,vector<double>(n+10,0.0));//提前留空间，防止访问越界
        b.assign(m+10,0.0);
        c.assign(n+10,0.0);
    }

    void pivot(int e,int l){//e:enter,l:leaving,l行e列
        //归一化离基元素行
        b[l]/=a[l][e];
        for(int j=0;j<n;j++){
            if(j!=e){
                a[l][j]/=a[l][e];
            }
        }
        a[l][e]=1.0/a[l][e];//保存主元倒数，后续处理其他行可以直接用乘法
        //改变其他行
        for(int i=0;i<m;i++){
            if(i==l||fabs(a[i][e]) < 1e-7)continue;
            b[i]-=a[i][e]*b[l];
            for(int j=0;j<n;j++){
                if(j!=e){
                    a[i][j]-=a[i][e]*a[l][j];
                }
            }
            a[i][e]=-a[i][e]*a[l][e];
        }
        //处理z行
        z+=c[e]*b[l];
        for(int j=0;j<n;j++){
            if(j!=e){
                c[j]-=c[e]*a[l][j];
            }
        }
        c[e]*=-a[l][e];

    }
    double solve(){
        while(1){
            int e=-1,l=-1;
            double maxe=1e-7;
            //找z中最大的正数
            for(int j=0;j<n;j++){
                if(c[j]>maxe){
                    maxe=c[j];
                    e=j;
                }
            }

            if(e==-1){
                return z;
            }

            double minb=1e20;
            for(int i=0;i<m;i++){
                if(a[i][e]>1e-7){
                    double temp=b[i]/a[i][e];
                    if(temp<minb){
                        minb=temp;
                        l=i;
                    }
                }
            }
            if(l==-1){//找不到离基变量,则z无限大
                return 1e20;
            }

            pivot(e,l);
        }
    }
};

int main(){
    
        simple s;
        int m=3,n=6;
        // s.Init(3,6);
        s.Init(3,3);
        for(int j=0;j<3;j++){
            double temp;
            cin>>temp;
            s.c[j]=-temp;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<4;j++){
                double temp;
                cin>>temp;
                if(j<3){
                    s.a[i][j]=temp;
                }else s.b[i]=temp;

            }
        }
        // for(int i=0;i<m;i++){
        //     s.a[i][i+3]=1;
        // }
        double ans=s.solve();
        if(ans==1e20){
             printf("No solution\n");
        }else{
            printf("%.2f\n", -ans);
        }
        
        
    
    return 0;
}