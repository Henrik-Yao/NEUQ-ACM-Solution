# 最少失约

把每个事件按开始时间从小到大排序

用一个lst记录当前从事事件最晚结束事件

若遇到开始时间大于等于lst的事件，参加
否则，若其结束时间晚与lst，将此事件替换当前最后一次事件


# 跳一跳

f[x]=min{f[x+1~x+a[x]]}+1

用线段树优化一下就过了
