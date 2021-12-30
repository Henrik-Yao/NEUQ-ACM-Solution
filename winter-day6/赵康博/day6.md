### 7 - 1

---

直接插入排序

---

### 7 - 2

---

用结构体存储，用sort排序。

```
bool cmp(node a,node b)
{
    if(a.cj < b.cj)return false;
    else if(a.cj > b.cj)return true;
    else {
        if(a.s.compare(b.s) > 0)return false;
        else return true;
    }
}
```

### 7 - 3

---

用数组储存次数，以年限为下标，最后不为0的输出。

---

### 7 - 4

---

最少的交换次序等于，所有逆序对的和，用归并排序，归并排序的过程就是在比较的过程，在比较的时候记录逆序。最后相加即可

---

### 7 - 5

---

堆排序过程。

---

### 7 - 6

---

快速排序，每次排完输出，比较过程中，把kay <= s[last]换成kay < s[last]就通过了。

```
while(first<last)
    {
        while(first < last &&key < s[last])
        {
            last--;
        }
        while(first < last &&s[first] <= key)
        {
            first++;
        }
        if(last > first)
        {
            int t  = s[last];
            s[last] = s[first];
            s[first] = t;
        }
    }
```