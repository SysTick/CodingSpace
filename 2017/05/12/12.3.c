include <stdio.h>

#define dpchar char *
typedef  char * tpchar  //用来重命名类型，或者用来制造用户重定义类型

void func(int a[])
{
    printf("数组大小 = %d.\n", sizeof(a));
}

void func1(int *a)
{
    printf("数组大小 = %d.\n", sizeof(a));
}

void func2(int *a, int num)
{
    //在子函数内，a是传进来的数组的指针(首地址)
    //num是数组的大小。
}

int main(void)
{
    char str[] = "hello";
    printf("sizeof(str) = %d.\n", sizeof(str));   //sizeof(str)既不是左值，也不是右值，输出数组大小 6 内存空间大小 包括"\0"
    printf("sizeof(str[0]) = %d.\n", sizeof(str[0]));   //输出1 str[0] 是char型，占一个字节
    printf("strlen(str) = %d.\n", strlen(str));   //输出5 字符串长度，不包括"\0".

    char str[] = "hello";
    char *p = str;
    printf("sizeof(p) = %d.\n", sizeof(p));   //p是指针变量，相当于sizeof(char *),即输出4
    printf("sizeof(*p) = %d.\n", sizeof(*p));  //相当于sizeof(char)  即输出1
    printf("strlen(p) = %d.\n", strlen(p));    //相当于strlen(str) 即输出5

    int n = 10;
    printf("sizeof(n) = %d.\n", sizeof(n));   //输出4
    printf("sizeof(int) = %d.\n", sizeof(int));   //输出4

    int b[100] = 10;
    printf("sizeof(b) = %d.\n", sizeof(b)); //输出400 (100 * sizeof(int))

    int a[20];
    func(a);

    func2(a,sizeof(a));   //数组经过函数调用是，只传进去数组的地址，没有传数组的大小

    dpchar p1, p2;    //等价于char *p1, char p2;
    tpchar p3, p4;    //等价于char *p3, char *p4;
    printf("sizeof(p1) = %d.\n", sizeof(p1)); //输出4   sizeof(char *)
    printf("sizeof(p1) = %d.\n", sizeof(p2)); //输出1   sizeof(char)
    printf("sizeof(p1) = %d.\n", sizeof(p3)); //输出4   sizeof(char *)
    printf("sizeof(p1) = %d.\n", sizeof(p4)); //输出4   sizeof(char *)

    int a[100];
    int b = sizeof(a) / sizeof(a[0]);
    printf("b = %d.\n", b);   //输出数组元素个数

    return 0;
}
