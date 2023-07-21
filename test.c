#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//动态内存分配函数有4个  malloc  free  calloc  realloc


//struct S
//{
//	char name[20];
//	int age;
//};
//
//int main()
//{
//	struct S arr[50];
//
//	return 0;		
//}

//C语言是可以创建变长数组的 -- C99中增加了









//1.malloc  free

//int main()
//{
//	//向内存申请10个整型的空间
//	int* p = (int*)malloc(40);//如果开辟失败返回NULL
//	if (p == NULL)
//	{
//		//打印错误原因的一个方式
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//正常使用空间
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//当动态申请的空间不再使用的时候
//	//就应该还给操作系统
//	free(p);
//	p = NULL;
//	return 0;
//}










//2.calloc -- 会初始化为0 



//int main()
//{
//	//malloc(10*sizeof(int));
//	int* p = (int*)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n",strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ",*(p+i)); 
//		}
//	}
//	//释放空间
//	//free函数是用来释放动态开辟的空间的
//	free(p);
//	p = NULL;
//	return 0;
//}







//realloc
//调整动态开辟内存空间的大小

//int main()
//{
//	int* p = (int*)malloc(20);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 5; i++)
//		{
//			*(p + i) = i;
//		}
//	}
//	//就是在使用malloc开辟的20个字节空间
//	//假设这里,20个字节不能满足我们的使用
//	//希望我们能有40个字节的空间
//	//这里就可以使用realloc来调整动态开辟的的内存
//	//
//	//realloc使用的注意事项：
//	//1.如果p指向的空间之后有足够的内存空间可以追加,则直接追加,后返回p
//	//2.如果p指向的空间之后没有足够的内存空间可以追加,则realloc函数会重新找一个新的内存区域开辟一块满足需求的空间
//	//  并且把原来内存中的数据拷贝回来,释放旧的内存空间,最后返回新开辟内存空间的地址
//	//3.得用一个新的变量来接收realloc函数的返回值
//	int* ptr = realloc(p, 40);
//	if (ptr != NULL)
//	{
//		p = ptr;
//		int i = 0;
//		for (i = 5; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//
//	//释放内存
//	free(p);
//	p = NULL;
//	return 0;
//}










//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}
//1.运行代码程序会出现崩溃的现象
//2.程序存在内存泄露的现象
//str以值传递的形式给p  p是GetMenory函数的形参,只能函数内部有效,等GetMemory函数返回之后,动态开辟内存尚未释放,并且无法找到
//所以会造成内存泄露

//改正1
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//改正2
//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}









//char* GetMemory(void) //返回栈空间的地址 
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0; 
//}


//int* test()
//{
//	//int a = 10;//栈区
//	static int a = 10;//静态区
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	*p = 20;
//	return 0;
//}





//void Test(void)
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);//free释放str指向的空间后,并不会把str置为NULL
//	str = NULL;
//	if (str != NULL)
//	{
//		strcpy(str,"world");//非法访问内存
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}






