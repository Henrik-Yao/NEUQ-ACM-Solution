# solution
## 7-1 ��̬�������
��״����С����������
## 7-2 С������
����ģ��
��¼β��������
ͷĬ��Ϊ0
## 7-3 ����Լɪ������
����ģ��
## 7-4 ��������ۺ�ʵ�� 1.4
������Ŀģ��
## 7-5 ����ƥ��
��stack��������ʽһ����)))(((((������Ҳ����û�С�
top=0��ƥ�䣬���ǿ�м��ַ�ƥ��)))((((�������׿�����ô�ӡ�
## 7-6 �ַ����Գ�
��stack����������ʱ��Ҫ���е��м��ַ�����������Ȼ����for���á�
## 7-7 ħ�����Խ���
�Ķ������
## 7-8 �������
������ƥ��һ��
## 7-9 �����Ŷ�����֮�����ڡ���������
ģ�������ڰ�ҵ�������һ��ռ��ʱ�䣬�������ռ��ʱ���������˼��ɣ���������ģ�⡣
## 7-10 �г���������
�㲻��Ϊɶ�����ǹ̶���???
�����зֳ����ٵļ���ʹ��ÿ�鶼�ǵ����ġ�
[cf847B](https://codeforces.com/problemset/problem/847/B)
�����Ŀ�Ѿ������������������
```cpp
iterate through array from the left to the right;
Ivan only looks at unused numbers on current iteration;
if current number is the first unused number on this iteration or this number is greater than previous unused number on current iteration, then Ivan marks the number as used and writes it down.
```
����cf��������2e5�ġ�
��Ŀ�����Ƿֳ��ļ����ĩβ��ɵ������ǲ����ġ� 
ÿ�ζ��ּ���ֵ�����̫С���¿�һ��vector���ȥ��
�õ�������Ͼ���a[i]->n-a[i]+1.