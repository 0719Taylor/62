#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//��̬�ڴ���亯����4��  malloc  free  calloc  realloc


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

//C�����ǿ��Դ����䳤����� -- C99��������









//1.malloc  free

//int main()
//{
//	//���ڴ�����10�����͵Ŀռ�
//	int* p = (int*)malloc(40);//�������ʧ�ܷ���NULL
//	if (p == NULL)
//	{
//		//��ӡ����ԭ���һ����ʽ
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//����ʹ�ÿռ�
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
//	//����̬����Ŀռ䲻��ʹ�õ�ʱ��
//	//��Ӧ�û�������ϵͳ
//	free(p);
//	p = NULL;
//	return 0;
//}










//2.calloc -- ���ʼ��Ϊ0 



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
//	//�ͷſռ�
//	//free�����������ͷŶ�̬���ٵĿռ��
//	free(p);
//	p = NULL;
//	return 0;
//}







//realloc
//������̬�����ڴ�ռ�Ĵ�С

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
//	//������ʹ��malloc���ٵ�20���ֽڿռ�
//	//��������,20���ֽڲ����������ǵ�ʹ��
//	//ϣ����������40���ֽڵĿռ�
//	//����Ϳ���ʹ��realloc��������̬���ٵĵ��ڴ�
//	//
//	//reallocʹ�õ�ע�����
//	//1.���pָ��Ŀռ�֮�����㹻���ڴ�ռ����׷��,��ֱ��׷��,�󷵻�p
//	//2.���pָ��Ŀռ�֮��û���㹻���ڴ�ռ����׷��,��realloc������������һ���µ��ڴ����򿪱�һ����������Ŀռ�
//	//  ���Ұ�ԭ���ڴ��е����ݿ�������,�ͷžɵ��ڴ�ռ�,��󷵻��¿����ڴ�ռ�ĵ�ַ
//	//3.����һ���µı���������realloc�����ķ���ֵ
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
//	//�ͷ��ڴ�
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
//1.���д���������ֱ���������
//2.��������ڴ�й¶������
//str��ֵ���ݵ���ʽ��p  p��GetMenory�������β�,ֻ�ܺ����ڲ���Ч,��GetMemory��������֮��,��̬�����ڴ���δ�ͷ�,�����޷��ҵ�
//���Ի�����ڴ�й¶

//����1
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

//����2
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









//char* GetMemory(void) //����ջ�ռ�ĵ�ַ 
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
//	//int a = 10;//ջ��
//	static int a = 10;//��̬��
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
//	free(str);//free�ͷ�strָ��Ŀռ��,�������str��ΪNULL
//	str = NULL;
//	if (str != NULL)
//	{
//		strcpy(str,"world");//�Ƿ������ڴ�
//		printf(str);
//	}
//}
//int main()
//{
//	Test();
//	return 0;
//}






