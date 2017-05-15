#include <stdio.h>

#define MYTEST1 1
#define MYTEST2 1

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

#ifdef MYTEST2

int main(void)
{
	int *p = NULL;

	printf("p = %d.\n",p);
	
	*p = 4;

	//野指针：1.第一种是指向不可访问的地址（指向了不可访问的敏感空间，比如说系统内核空间）
			//2.指向一个可用的，而且没什么特别意义的空间（比如我们曾经使用过的
			//但是已经不用栈空间或堆空间）
			//3.指向了也一个可用的空间，而且这个空间其实在程序中正在被使用。那么野指针
			//的引用就会修改这个变量的值，导致程序崩溃
	//指针变量如果是局部变量，则分配在栈上，本身遵从栈的规律，就决定了栈的使用多少会影响这个默认值，因此
	//野指针的值是有一定规律，不是完全随机，但是这个规律对我们来说并没有什么意义，所以，我们应该避免野指针。

	//避免野指针的方法:1.在指针的解引用之前，一定确保指针指向一个绝对可用的空间
		//常规的做法是：
			//第一步：定义指针时，同时初始化为NULL
			//第二步：在指针解引用之前，先判断这个指针是不是NULL
			//第三点：指针使用完之后 ，将其赋值为NULL
			//第四点，在指针使用之前 ，将其赋值绑定给一个可用的地址空间
			
//NULL
#ifdef _cplusplus
#define NULL 0
#else
#define NULL (void *)0
#endif

// NULL的实质就是0，然后我给指针赋值为NULL，其实就是让指针指向0地址处。
//1.第一层原因是0地址作为一个特殊地址，（我们认为指针 指向这里就表示指针没有
//被初始化，就表示 是野指针。）
//2.第二层原因是这个地址0在一般的操作系统中都是不可被访问的，程序员非法访问会触发段错误

//判断是否野指针时，
if(NULL != P);	//好的习惯是把NULL写到左边，防止手误把运算符号写错。
}

#endif

  return 0;


}
