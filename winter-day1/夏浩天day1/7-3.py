list=[]
s=n=input()
n,m,k=s.split()
n=int(n)
m=int(m)-1
k=int(k)-1
# 这行往上的代码等价于c++的 int n,m,k;cin>>n>>m>>k;
# ~~看着都觉得麻烦，而且用时也长~~
i=1
xb=0
while i<=n:
    list.append(i)
    i+=1

while len(list)!=0: # 列表不为空
    xb=xb-m
    while xb<0:
        xb+=len(list)
    print(list.pop(xb),end=' ')
    if len(list)==0:
        break
    xb=xb+k-1
    while xb>=len(list):
        xb-=len(list)
    print(list.pop(xb),end=' ')
print('')