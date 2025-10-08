#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> b2h(const string &b){//引用的目的：避免拷贝大对象;const 的目的：保证安全
    vector<int> hex;
    int len = b.length();
    for(int i=len-1;i>=0;i-=4){
        //w为权重
        int val=0,j=0,w=1;

        while(i-j>=0&&j<4){
            val+=(b[i-j]=='1')*w;
            j++;
            w*=2;
        }
        hex.push_back(val);
    }
    return hex;
}
vector <int> mul(const vector <int>&h1,const vector <int>&h2){
    vector <int> res(h1.size()+h2.size()+1,0);
    for(int i=0;i<h1.size();i++){
        for(int j=0;j<h2.size();j++){
            res[i+j]+=h1[i]*h2[j];
        }
    }
    return res;
}
vector <int> normalize( vector <int>&h){
    
    for (int i = 0; i < h.size() - 1; i++) {
        h[i + 1] += h[i] / 16;
        h[i] %= 16;
    }
    while (h.back() >= 16) {
        int carry = h.back() / 16;
        h.back() %= 16;
        h.push_back(carry);
    }
    while(!h.empty()&&h.back()==0){
        h.pop_back();
    }
    return h;
}
void h2b_output(const vector<int> &h) {
    
    
    // 因为h是低位在前，需要从高位开始输出（即从后往前）
    // 先处理最高位（最后一个元素）
    int highest = h.back();
     switch (highest) {
        case 1: cout << "1"; break;
        case 2: cout << "10"; break;
        case 3: cout << "11"; break;
        case 4: cout << "100"; break;
        case 5: cout << "101"; break;
        case 6: cout << "110"; break;
        case 7: cout << "111"; break;
        case 8: cout << "1000"; break;
        case 9: cout << "1001"; break;
        case 10: cout << "1010"; break;
        case 11: cout << "1011"; break;
        case 12: cout << "1100"; break;
        case 13: cout << "1101"; break;
        case 14: cout << "1110"; break;
        case 15: cout << "1111"; break;
        default: cout << "0"; break; 
    } 
   
    
    // 处理剩余的高位（从倒数第二个到第一个）
    for (int i = h.size() - 2; i >= 0; i--) {
        int val = h[i];
        switch (val) {
        case 1: cout << "0001"; break;
        case 2: cout << "0010"; break;
        case 3: cout << "0011"; break;
        case 4: cout << "0100"; break;
        case 5: cout << "0101"; break;
        case 6: cout << "0110"; break;
        case 7: cout << "0111"; break;
        case 8: cout << "1000"; break;
        case 9: cout << "1001"; break;
        case 10: cout << "1010"; break;
        case 11: cout << "1011"; break;
        case 12: cout << "1100"; break;
        case 13: cout << "1101"; break;
        case 14: cout << "1110"; break;
        case 15: cout << "1111"; break;
        default: cout << "0000"; break; 
    }
    }
}

int main() {
    string b1, b2;
    while(cin>>b1>>b2){
        vector <int> h1=b2h(b1);
        vector <int> h2=b2h(b2);
        vector <int> res=mul(h1,h2);
        res=normalize(res);
        h2b_output(res);  
        cout<<endl;
       
    }
     return 0;
    
    
    
}