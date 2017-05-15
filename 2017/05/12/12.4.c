#include <stdio.h>

//&a 和&b不同，说明说明a和b不是同一个变量(在内存中a和b是独立的2个内存空间)
//但是a和b是有关联的，实际上b量a赋值得到的
void func1(int b)
{
    //在函数内部，形参b的值等于实参a的值。
    printf("a = %d.\n", b);
    printf("&a = %p.\n", &b);
}

void func2(int a[])
{
    printf("sizeof(a) = %d.\n", sizeof(a)); //输出4
    printf("in func2, a = %p.\n", a);
}

void func3(int *a)
{
    printf("sizeof(a) = %d.\n", sizeof(a));
    printf("in func3, a = %p.\n", a);
}

struct A
{
    char a;   //结构体变量对齐
    int b;
};

void func4(struct A a1)
{
    printf("sizeof(a1) = %d.\n", sizeof(a1));
    printf("&a1 = %p.\n", &al);
    printf("a1.b = %d.\n", a1.b);

}

void func5(struct A *a1)
{
    printf("sizeof(a1) = %d.\n", sizeof(a1));
    printf("sizeof(*a1) = %d.\n", sizeof(*a1));
    printf("&a1 = %p.\n", &a1); //指针的指针，二重指针
    printf("a1 = %p.\n", a1);
    printf("a1->b = %d.\n", a1->b);   //访问结构体时，左边是指针时用-> 左边是变量选择用.来访问
}

int main(void)
{
    int a = 4;
    printf("&a = %p.\n", &a);
    func1(a);   // 传值调用。

    int a[5]
    func2(a);

    struct A a1
    {
        .a = 4,
        .b = 555,
    };
    printf("sizeof(a1) = %d.\n", sizeof(a1));
    printf("&a1 = %p.\n", &al);
    printf("a1.b = %d.\n", a1.b);
    func4(a);

    func5(&a1);


}
