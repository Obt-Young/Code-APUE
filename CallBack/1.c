#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef void (*p_func)(int);

struct stu_func{
	p_func ptr;	//指向void (int)类型函数的指针
	int para;	//对应入参
};

struct stu_func a[10]; //100个结构体，存储和管理

void func(int n)
{
	printf("我是被调函数-%d\n",n);
	return;
}

void caller(void (*ptr)(int),int n,int opt)
{
	static int i=0;		//静态局部变量，用作计数
	printf("我是回调函数-%d\n",i);

	if(opt){//如果opt!=0,那么立刻执行传入的函数指针指向的函数
		ptr(n);
	}
	else{   //如果opt==0，那么把传入的函数指针存起来，同时把传入的参数也一并存起来，当存满99个，一次性执行，执行完了以后清空结构体，
		//同时移动指针下标i至结构数组最前端
		a[i].ptr=ptr;
		a[i++].para=n;
		while(i==9)
		{
			int j;
			for(j=0;j!=i;j++)
				{
					a[j].ptr(a[j].para);  //执行第j个函数
				}
			memset(a,0x00,sizeof(struct stu_func)*10);
			i=0;
		}
	}
}


int main(int arg, char ** argv)
{
	int j=0;
	while(j++!=9)
	{
		caller(func,j,1);
		sleep(1);	//速度放缓
	}
	printf("-----------------------------------\n");
	while(j--)
	{
		caller(func,j,0);
		sleep(1);
	}
}

//说明：执行程序后，输出如下：
//我是回调函数-0
//我是被调函数-1
//我是回调函数-0
//我是被调函数-2
//我是回调函数-0
//我是被调函数-3
//我是回调函数-0
//我是被调函数-4
//我是回调函数-0
//我是被调函数-5
//我是回调函数-0
//我是被调函数-6
//我是回调函数-0
//我是被调函数-7
//我是回调函数-0
//我是被调函数-8
//我是回调函数-0
//我是被调函数-9
//-----------------------------------
//我是回调函数-0
//我是回调函数-1
//我是回调函数-2
//我是回调函数-3
//我是回调函数-4
//我是回调函数-5
//我是回调函数-6
//我是回调函数-7
//我是回调函数-8
//我是被调函数-9
//我是被调函数-8
//我是被调函数-7
//我是被调函数-6
//我是被调函数-5
//我是被调函数-4
//我是被调函数-3
//我是被调函数-2
//我是被调函数-1
//我是回调函数-0
//
//可见，对于上半部分，回调和被调是交替出现的，对于下半部分，回调和被调都是集中出现的。

