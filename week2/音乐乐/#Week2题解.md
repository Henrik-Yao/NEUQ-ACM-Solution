#Week2题解

---

##2-1汉诺塔

考虑n个盘，为将其从1柱挪到3柱，需要先将n-1个盘从1柱挪到2柱，将底盘从1柱挪到3柱，再将n-1个盘从2柱挪到3柱，递归即可。

---

##2-2分而治之

开辟结构体记录每条道路两端连接的城市，对被攻占的城市进行标记，检索是否有任意一条道路两边的城市均未被标记，若存在，则此方案不成功。

---

##2-3归并排序

分治思想，将原数组依次二分直到每个最小组中只有一个元素，再将各组两两合并。

