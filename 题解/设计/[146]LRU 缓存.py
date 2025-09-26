# 
#  请你设计并实现一个满足 
#  LRU (最近最少使用) 缓存 约束的数据结构。
#  
# 
#  
#  实现 
#  LRUCache 类：
#  
# 
#  
#  
#  
#  LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存 
#  int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。 
#  void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 
# key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。 
#  
#  
#  
# 
#  函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。 
# 
#  
# 
#  示例： 
# 
#  
# 输入
# ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
# [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
# 输出
# [null, null, null, 1, null, -1, null, -1, 3, 4]
# 
# 解释
# LRUCache lRUCache = new LRUCache(2);
# lRUCache.put(1, 1); // 缓存是 {1=1}
# lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
# lRUCache.get(1);    // 返回 1
# lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
# lRUCache.get(2);    // 返回 -1 (未找到)
# lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
# lRUCache.get(1);    // 返回 -1 (未找到)
# lRUCache.get(3);    // 返回 3
# lRUCache.get(4);    // 返回 4
#  
# 
#  
# 
#  提示： 
# 
#  
#  1 <= capacity <= 3000 
#  0 <= key <= 10000 
#  0 <= value <= 10⁵ 
#  最多调用 2 * 10⁵ 次 get 和 put 
#  
# 
#  Related Topics 设计 哈希表 链表 双向链表 👍 3599 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
#1节点结构
class ListNode:
    def __init__(self,key=0,value=0):
        self.key=key
        self.value=value
        self.prev=None
        self.next=None

class LRUCache:
    #2初始化哈希表，以及头尾两个虚拟节点，及结构关系
    def __init__(self, capacity: int):
        self.capacity=capacity
        self.hashmap={}
        self.head=ListNode()
        self.tail=ListNode()

        self.head.next=self.tail
        self.tail.prev=self.head
    #3定义一个方法处理节点到尾部
    def movetail(self,key):
        #3.1现摘出node，处理node的前后(先前后后)
        node=self.hashmap[key]
        node.prev.next=node.next
        node.next.prev = node.prev
        #3.2处理node本身(先前后后)
        node.prev=self.tail.prev
        node.next=self.tail

        self.tail.prev.next=node
        self.tail.prev=node

    #4记得将node移到最后
    def get(self, key: int) -> int:
        if key in self.hashmap:
            self.movetail(key)
            return self.hashmap[key].value
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.hashmap:
            self.hashmap[key].value=value
            self.movetail(key)

        else:
            if len(self.hashmap)==self.capacity:
                #去掉哈希表中的项
                self.hashmap.pop(self.head.next.key)
                #删除节点
                #self.head.next.next.prev=self.head
                self.head.next=self.head.next.next
                self.head.next.prev=self.head

            new=ListNode(key,value)
            self.hashmap[key]=new
            #先处理自己，在处理两边
            new.prev=self.tail.prev
            new.next = self.tail

            self.tail.prev.next=new
            self.tail.prev=new

        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
# leetcode submit region end(Prohibit modification and deletion)
