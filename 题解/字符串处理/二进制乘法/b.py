import sys
def normalize(x):#x为逆序存储，处理x后面多余的0，和统一为x进位
    #处理后面多余的0
    while x and x[-1]==0:#先判断x不为空
        x.pop()
    #统一进位
    cur=0
    for i in range(len(x)):
        x[i]+=cur
        cur=x[i]>>1
        #取二进制最后一位
        x[i]=x[i]&1
    #补齐后面的进位
    while cur :
        x.append(cur&1)
        cur>>=1

    return x

def add(n1,n2,sign=1):
    n3 = n1[:]#索引赋值必须声明
    #不能保证n1和n2一样长
    max_len = max(len(n1), len(n2))
    n3 = [0] * max_len
    for i in range(len(n1)):
        n3[i] += n1[i]
    for i in range(len(n2)):
        n3[i] += n2[i] * sign

    return  n3

def mul(n1,n2):
    n3 = [0]*(len(n1)+len(n2)+1)
    for i in range(len(n1)):
        for j in range(len(n2)):
            n3[i+j]+=n1[i]*n2[j]

    return n3

def mul_2(n1,k):
    return [0]*k+n1;

def fast_mul(n1,n2):
    # 接近递归终点，小规模数据不分治，朴素乘
    if len(n1)<=32:
        return mul(n1,n2)

    #计算AD+BC = (A+B)*(C+D)-AC-BD，避免减法出现负数
    mid=len(n1)>>1
    a,b=n1[mid:],n1[:mid]
    c,d=n2[mid:],n2[:mid]

    ac=fast_mul(a,c)
    bd=fast_mul(b,d)
    # 计算AD+BC = (A+B)*(C+D)-AC-BD，避免减法出现负数
    ad_bc=add(add(fast_mul(add(a,b),add(c,d)),ac,-1),bd,-1)
    n3=add(add(mul_2(ac,mid*2),mul_2(ad_bc,mid)),bd)
    return n3


def main1():
    data=sys.stdin.read().split()
    n=len(data)
    for i in range(0,n,2):
        if i+1 < n:
            s1=data[i]
            s2=data[i+1]
            #转为逆序数组
            n1 = [1 if c=='1' else 0 for c in s1[::-1]]
            n2 = [1 if c == '1' else 0 for c in s2[::-1]]
            #保证长度相等
            if (len(n1)<len(n2)):
                n1=n1+[0]*(len(n2)-len(n1))
            else:
                n2=n2+[0]*(len(n1)-len(n2))

            res=normalize(fast_mul(n1,n2))
            res_str=''.join(str(c)for c in res[::-1])
            print(res_str)


def main():
    # 使用sys.stdin.read()一次性读取所有输入
    data = sys.stdin.read().split()

    # 每两个数字为一组
    for i in range(0, len(data), 2):
        if i + 1 < len(data):
            s1 = data[i]
            s2 = data[i + 1]

            # 转为逆序数组
            n1 = [1 if c == '1' else 0 for c in s1[::-1]]
            n2 = [1 if c == '1' else 0 for c in s2[::-1]]

            # 保证长度相等
            max_len = max(len(n1), len(n2))
            if len(n1) < max_len:
                n1 += [0] * (max_len - len(n1))
            if len(n2) < max_len:
                n2 += [0] * (max_len - len(n2))

            res = normalize(fast_mul(n1, n2))
            res_str = ''.join(str(bit) for bit in res[::-1]) if res else "0"
            print(res_str)
if __name__ =="__main__":
    main()