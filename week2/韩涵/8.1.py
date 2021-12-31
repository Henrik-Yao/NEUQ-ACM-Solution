def hanoi(a, b, c, d):  # a，b，c分别为一，二，三根柱子
    if d > 1:  # 当 d = 1时就只有一个圆盘，不需要在进行递归
        hanoi(a, c, b, d - 1)  # 将n-1个圆盘从a移动到b
    print(a + "->" + c)
    if d > 1:  # 同理
        hanoi(b, a, c, d - 1)  # 将n-1个圆盘从b移动到c


def week2_1():
    n = int(input(""))
    name = [input(""), input(""), input("")]
    hanoi(name[0], name[1], name[2], n)


if __name__ == '__main__':
    week2_1()
