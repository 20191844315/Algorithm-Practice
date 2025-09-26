def main():
    n= int(input().strip());
    nums=list(map(int,input().split()))
    ops=input().split();
    #优先处理乘法
    n_nums=[];
    n_nums.append(nums[0])
    n_ops=[];
    for i in range(len(ops)):
        if ops[i]=='*':
            last=n_nums.pop();
            n_nums.append(last*nums[i+1]);

        else:
            n_nums.append(nums[i+1]);
            n_ops.append(ops[i]);
    #在处理加减法
    res=n_nums[0];
    for i in range(len(n_ops)):
        if n_ops[i]=='+':
            res+=n_nums[i+1];
        else:
            res-=n_nums[i+1];

    print(res);

if __name__ == "__main__":
    main()
