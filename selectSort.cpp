//这是一个简单的选择排序算法
//可以自动生成随机数组以共测试

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void selectSort(int arr[], int n);
void randomArr(int* a, int n, int l, int r);

int main()
{
  	clock_t startTime, endTime;
	
	int n = rand()%(30 - 20 + 1) + 20;  //生成[20,30]内的一个随机数
	int* Array = new int[n];  //生成数组大小为n的动态数组
	
	randomArr(Array, n, 0, 100);
	
	//计算排序算法的运行时间
	startTime = clock();
	selectSort(Array, n);
	endTime = clock();
	
	cout << "Runtime of main cycle is: " << double(startTime - endTime) << endl;
	//cout << "Run time of main cycle is: " << double(startTime - endTime)/CLOCK_PER_SEC <<endl;
	
	for (int i = 0; i < n; i++)
	{
		cout << Array[i] << " ";
	}
	
	return 0;
}

void selectSort(int arr[],int n) //选择排序算法实现
{
	int min;
	int temp;
	for (int i = 0; i < n; i++)
	{
		min = i;
	
		for (int j = i; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		
    		if (min != i)
		{
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

void randomArr(int* a, int n, int l, int r) //生成随机数组
{
	srand(time(0)); //设置随机数种子(time(0) 意思是从1970年1月1日开始到现在经过的秒数)
	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%(r - l + 1) + l;
	}
}
