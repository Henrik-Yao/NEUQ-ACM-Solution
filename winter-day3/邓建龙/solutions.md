# day3

## 7-1 图的创建

> **图**
>
> 用 vector<pair<int, int>> gh[N] 存边，has[N] 存第i个点是否有边即可
>
> 如果 第 i 个点有边，对记录的他的边进行排序

```c++
for (int i = 0; i < e; i++) {
    cin >> a >> b >> c;
    has[a] = true;
    gh[a].push_back({b, c});
}
for (int i = 0; i < n; i++) {
    if (has[i]) quick_sort(0, gh[i].size() - 1, i);
}
```

## 7-2 图的删边操作

> **图**
>
> 类似 7 - 1，重点在**删边**
>
> 如果 i 点只有一条边，只需要将 has[i] 更新为 false 即可
>
> 否则，将 i 点要删除的边的另一点改为 - 1 ，输出时忽略这个点即可

```c++
for (int i = 0; i < k; i++) {
    cin >> a >> b;
    if (gh[a].size() == 1) has[a] = false;
    else {
        for (int j = 0; j < gh[a].size(); j++) {
            if (gh[a][j].first == b) {
                gh[a][j].first = -1;
            }
        }
    }
}
for (int i = 0; i < n; i++) {
    if (has[i]) {
        printf("%d:", i);
        for (int j = 0; j < gh[i].size(); j++) {
            if (gh[i][j].first != -1) {
                printf("(%d,%d,%d)", i, gh[i][j].first, gh[i][j].second);
            }
        }
        printf("\n");
    }
}
```

## 7-3 递增子序列

> **深度优先遍历**
>
> 看成一个树，递归遍历每一种可行的路径 `path`，注意每层中不能出现重复

```c++
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> res; // 储存结果
vector<int> nums; // 读入数组
vector<int> path; // 子集
void backTracking(vector<int>& nums, int startIdx) {
	if (path.size() > 1) res.push_back(path); // 当子集长度大于等于2时存入结果向量中，子集数量自然加一
	unordered_set<int> uset; // 用来去重（只在 startIdx 向后所有的元素这一层，不影响上下层）
	for (int i = startIdx; i < nums.size(); i++) {
		// 如果 子集不空且当前索引位置值大于之前存入子集最后一个值 或者当前索引位置值在 uset 中出现过说明同层重复
        // uset.find(x) 查询 uset 中的 x 如果查不到返回 uset.end() 查到返回迭代器
		if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end()) continue;
		uset.insert(nums[i]);
		path.push_back(nums[i]);
		backTracking(nums, i + 1);
		path.pop_back(); // 状态复原
	}
}
vector<vector<int>> findSubSequences(vector<int>& nums) {
	res.clear(); path.clear();
	backTracking(nums, 0);
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		nums.push_back(num);
	}
	vector<vector<int>> ans = findSubSequences(nums);
	cout << ans.size() << endl;
	return 0;
}
```

## 7-4 岛屿数量

> **广度优先遍历**
>
> 遍历所有的岛屿，需要注意的是减少遍历的次数

```c++
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        // 如果遍历过，vis 值为 true ，减少遍历次数
        if (vis[i][j]) continue;
        if (vex[i][j] == 1) bfs(i, j), ans++;
    }
}
```

## 7-5 繁忙的都市

>  **克鲁斯卡尔算法(Kruskal算法) -- 最小生成树**
>
>  主要针对**边**
>
>  1. 对所有边按照权值的大小进行排序
>  2. 遍历所有边，如果边两个顶点标记不同，则把与其中一个顶点标记相同的所有顶点更改为另一个顶点的标记（**并查集--合并**）
>  3. 结束条件（已遍历边数量为 `顶点数量 - 1`）

```c++
// 并查集查询
int find(int x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x])); // 返回父节点值  并且父节点会更新成最顶层
}
// 并查集合并
void merge(int i, int j) {
    int x = find(i), y = find(j);
    // dep 表示以一个点为顶点的树的深度，下面的方式可以尽量减小树的总深度，减少耗时
    if (dep[x] <= dep[y]) fa[x] = y;
    else fa[y] = x;
    if (dep[x] == dep[y] && x != y) dep[y]++;
}

// 主要代码
for (int i = 0; i < m; i++) {
    if (find(road[i].u) == find(road[i].v)) continue;
    merge(road[i].u, road[i].v), edgeN++, maxC = max(maxC, road[i].c);
}
```

## 7-6 最小支撑树

> **克鲁斯卡尔算法(Kruskal算法) -- 最小生成树**
>
> 同 7 - 5算法
>
> 主要的是**判断是否存在最小支撑树**，我的方式是判断一共有多少的跟节点，如果只有一个说明存在最小生成树，否则不存在（这种方式的前提是使用的并查集必须将每个节点的标记更改为它的最高层根节点即下面代码中的 `findRoot` 函数）

```c++
// 每个节点的标记都是树的总根节点，而不仅仅是节点的父节点
int findRoot(int a) {
    return sign[a] == a ? a : (sign[a] = findRoot(sign[a]));
}

// 主要代码
int rootN = 1;
int root = findRoot(1);
for (int i = 1; i <= n; i++)if (findRoot(i) != root) rootN++;
if (rootN > 1) cout << "There is no minimum spanning tree." << endl;
else {
    cout << total << endl;
}
```

## 7-7 特殊最小成本修路

> **克鲁斯卡尔算法(Kruskal算法) -- 最小生成树**
>
> 同 7 - 5 算法
>
> 增加了**节点的边数量限制**，合并之前判断计数即可

```c++
for (int i = 0; i < e; i++) {
    if (find(road[i].u) == find(road[i].v)) continue;
    if ((road[i].u == v || road[i].v == v) && vN < 2) merge(road[i].u, road[i].v), edgeN++, total += road[i].c, vN++;
    if (road[i].u != v && road[i].v != v) merge(road[i].u, road[i].v), edgeN++, total += road[i].c;
    if (edgeN == n - 1) break;
}
firstL == 1 ? (edgeN == n - 1 && vN <= 2) ? printf("%d", total), firstL = 0 : printf("-1"), firstL = 0 : (edgeN == n - 1 && vN <= 2) ? printf("\n%d", total) : printf("\n-1");
```

