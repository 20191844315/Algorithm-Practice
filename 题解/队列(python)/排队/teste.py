from asyncio import Queue
from os.path import split

n=int(input().strip())
a=list(map(int,input().split()))
queue = []

for i in range(n):
    if i==0:
        queue.append(i)
    else :
        last =queue[-1];

        if a[i]>a[last]:
            queue.append(i);
            if len(queue)>5:
                queue.pop(0);
res=[int(x+1) for x in queue]
print(*res)


        # if len(queue)==5
        #     if a[i]> a[last]:
        #         queue.append(i);
        #         queue.pop(0);
        # else:
        #     if a[i] > a[last]:
        #         queue.append(i);
        #         queue.pop(0);



