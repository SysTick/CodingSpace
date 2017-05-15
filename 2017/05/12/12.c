#include <stdio.h>

int main(void)
{

    const int a = 5
    a = 6;  //编译报错

    //用const修饰的变量并不是一定不能被改变，基于gcc编译器的原理，
    //const只是用来声明该变量不应该被修改，（我们也不应该试图去修改用const修饰的变量）而并不是说不能被修改。
    int *p;
    p = (int *)&a;
    *p = 6;
    printf("a = %d\n", a );   //a = 6;

    int a = 29;
    //第一种
    const int *p1;   //
    int const *p2;
    int * const p3;
    const int * const p4;

    *p1 = 3;  //
    *p2 = 3;   //编译报错，给只读赋值 p为const
    p1 = &a;
    p2 = &a;  //编译通过
    *p3 = 5;  //编译通过。
    p3 = &a   //编译报错

    *p4 = 3;  //编译报错
    p4 = &a;  //编译报错


}
