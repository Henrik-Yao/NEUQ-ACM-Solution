# solution week6
## 7-1 字符串模式匹配（KMP）
kmp复杂度是O(n+m)而不是O(n*m),因为他失败之后是寻找fail而不是从头开始找。
hash也可以做到。忘记kmp怎么写可以直接写hash，可以用unsignedint。
## 7-2 妈妈再也不用担心我被拖库啦！
就模拟就行了，用map存一下user和密码。
## 7-3 子字符串个数匹配
用hash找一下就行了，kmp也可以。