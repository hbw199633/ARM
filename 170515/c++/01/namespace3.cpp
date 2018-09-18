/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：namespace3.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月07日
*   描    述：
================================================================*/
#include <iostream>

using namespace std;
namespace  n1
{
	int show()
	{
		cout <<"n1.... " <<endl;
	}
}

namespace n2
{
	int show()
	{	
		cout << "n2 .... " <<endl;
	}

}


//using namespace n1;
//using namespace n2;

int main(int argc, char *argv[])
{

	n1::show();
	n2::show();

	//show();


    return 0;
}

