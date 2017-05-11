#include <stdio.h>

#define MYTEST1 1

int main(void)
{
#ifdef MYTEST1
//下面的这几种定义方式从本质上来说完全一样。*号和前面的int结合成新的数据类型int * 型。
	int c = 23;

	int *p1;	//虽然理论上来讲，int *是一个整体，表示一个int *型的数据类型，但是我们习惯上使用这种方法来定义一个指针变量，这种定义方式是有原因的
	int* p2;
	int*p3;	

	p1 = &c;
	p2 = &c;
	p3 = &c;	//上面的几条语句都是先定义一个指针变量，然后再赋值初始化。
				//我们也可以在定义指针变量的时候就可以直接进行赋值初始化
	
	int *p4 = &c;	//在定义指针变量的同时对其进行赋值初始化。
					//可以拆分为两条语句：int *p4; p4 = &c;



	int *p5, a;		//这条语句有两层意思，
					//1.定义int 型指针变量p5(int *p5). 2.定义int型变量a(int a).

	int* p6, b;		//这样写也没错，但是，从字面的表示来看，
					//很容易让人误解成：1.int* p6. 2.int* b;所以并不推荐这么写。

	//输出指针变量的地址，我们知道取变量的地址可以使用&，那么取指针的地址我们
	//也可以使用&，即：&p1, &p2, &p3, &p4
	printf("the addr of p1 is :0x%x.\n", &p1);			
	printf("the addr of p2 is :0x%x.\n", &p2);	
	printf("the addr of p3 is :0x%x.\n", &p3);	
	printf("the addr of p4 is :0x%x.\n", &p4);	

	//输出变量c的地址
	printf("the addr of c is :0x%x.\n", &c);			
	
	//下面的这四种输出的结果是一样的，都是变量c的地址。
	printf("the value of p1 = %p.\n", p1);			
	printf("the value of p2 = %p.\n", p2);	
	printf("the value of p3 = %p.\n", p3);	
	printf("the value of p4 = %p.\n", p4);
	
	printf("p = 0x%x.\n", p1);	//输出的值和printf("p = %p.\n", p1)一样


	//下面的这四个输出结果也是一样的，都变量c的值。
	printf("the value of c is : %p.\n ", *p1);
	printf("the value of c is : %p.\n ", *p2);
	printf("the value of c is : %p.\n ", *p3);
	printf("the value of c is : %p.\n ", *p4);	

	/*
	 *	总结：
	 *	1.从本质上来说，指针变量和一般的变量没有区别。
	 *	2.指针变量里保存的实际上是该指针指向的变量的地址。
	 *	3.指针变量用来实现也间接访问。
	 *
	 */
#endif

  return 0;


}
