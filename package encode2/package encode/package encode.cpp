// package encode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// Ver_2
//author：Evand
//data：2022-3-13

#include <iostream>
#include <bitset>
using namespace std;
using std::cout;
using std::endl;
using std::string;



int main()
{
	int siyao[5] = {0};
	int gongyao[5] = {0};
	int mingwen[100] = {}, mingwenn[100] = {};//第一个是加密前的，第二个是解密的
	int miwen=0;
	int miwenn, mingwen10;
	int m = 200, n = 3,nn,i = 0,N;
	cout << "输入私钥：";
	while (i<5) {
		cin >> siyao[i];
	/*	cout << siyao[i] << " ";*/
		i++;
	}
	/*for (int i = 0; i < 5; ++i)
	{
		cin >> siyao[i];
	}*/
	cout << "输入m(注意要比私钥所有数字之和还大)：";
	cin >> m;
	cout << "输入n：（注意要与m互质）";
	cin >> n;
	cout << "计算公钥为：" << endl;
	for (int i = 0; i < 5; ++i)
	{
		gongyao[i] = (siyao[i] * n) % m;
		cout << gongyao[i]<<",";
	}
	cout << endl;
	cout << "输入明文：";
	cin >> mingwen10;
	i = 0;
	while (mingwen10 != 0) {
		mingwen[i] = (mingwen10 % 2 == 0 ? 0 : 1);
		mingwen10 /= 2;
		i++;
	}
	N = i-1;
	for (i = N ; i >= 0; i--)
	{
		if (mingwen[N-i] == 1)
			miwen = miwen + gongyao[i];
	}
	cout << "密文为：" << miwen << endl;
	cout << "***下面解密***"<< endl;
	cout << "输入n的模n'为：";
	cin >> nn;
	miwenn = (miwen * nn) % m;
	cout << "计算明文为：" << endl;
	for (int i = N; i >= 0; i--)
	{
		if (miwenn >= siyao[i])
		{
			miwenn = miwenn - siyao[i];
			mingwenn[i] = 1;
		}
	}
	for (int i = 0; i < N+1; i++)
	{
		cout << mingwenn[i] << ",";
	}
	cout << endl;
	cout << "即十进制的：" << endl;
	int mingwenndex=0;
	for (int i = N; i >= 0; i--)
	{
		mingwenndex += mingwenn[i] * pow(2, N - i);
	}
	cout << mingwenndex << endl;
	std::cout << "计算结束\n";

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
