import sys
def int2fib(s):
    n = len(s)
    INT_MAX=2**31 -1
    def check_0(x_str):
        if x_str[0] == '0':
            return len(x_str) == 1
        return True
    #枚举第一个数
    for i in range(1,n):
        snum1=s[:i]
        if not check_0(snum1):
            continue
        num1=int(snum1)
        if num1>INT_MAX:
            continue
        #枚举第一个数
        for j in range(i+1,n):
            snum2=s[i:j]
            if not check_0(snum2):
                continue
            num2=int(snum2)
            if num2>INT_MAX:
                continue

            seq=[num1,num2]
            pos=j
            sign=True
            while pos<n:
                nxt=seq[-1]+seq[-2]
                if nxt>INT_MAX:
                    sign=False
                    break
                snxt=str(nxt)
                if s.startswith(snxt,pos):
                    seq.append(nxt)
                    pos+=len(snxt)
                else:
                    sign=False
                    break
            
            if sign and len(seq)>2 and pos==n:
                return seq
    return None

    
def main():
    for line in sys.stdin:
        s = line.strip()
        res = int2fib(s)
        if res is None:
            print("None")
        else:
            print(" ".join(map(str,res)))

if __name__ == "__main__":
    main()
