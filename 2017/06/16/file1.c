/*
 * 写两个函数，分别求出两个函数的最大公约数和最小公倍数，用主函数调用这两个函数，并输出结果，两个整数由键盘输入。
 */

#include <stdio.h>

//求u v的最大公约数
int hcf(int u, int v)
{
    int t, r;
    if(v > u) {
        t = u;
        u = v;
        v = t;
    }
    while (v != 0) {
        r = u % v;
        u = v;
        v = r;
    }
    return u;
}

//h为u v的最大公约数，求u v的最小公倍数
int lcd(int u,int v, int h)
{
    return(u * v / h);
}

//测试最大公约数和最小公倍数的算法
void main()
{
    int u, v, h, l;
    printf("请输入两个整数，并用逗号隔开：\n");
    scanf("%d, %d", &u, &v);
    h = hcf(u, v);
    printf("H.C.F = %d.\n", h);
    l = lcd(u, v, h);
    printf("L.C.D = %d.\n", l);
}
