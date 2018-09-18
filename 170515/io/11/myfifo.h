/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：myfifo.h
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月25日
*   描    述：
================================================================*/

#ifndef _MYFIFO_H_
#define _MYFIFO_H_

extern int  fifo_read(const char * fifoname,  //有名管道文件路径+名称
					  void * buff,   //管道数据的存储地址
					  int buffsize); //管道数据的存储大小
/*
  功能：该函数可以从指定的管道中读取数据到本地内存；
  参数：
  返回值：成功  0  失败  系统错误码
  		  -1  参数错误

  注意事项： 必须事先创建一个有名管道文件。
*/

extern  int  fifo_write(const char * fifoname,  ///有名管道
						void * buff,            ///数据内存
						int    buffsize);       ///数据大小
/*
  功能： 该函数可以向指定的管道中写入数据；
  参数：
  返回值：成功 0  失败  系统错误码
  注意事项： 必须事先创建一个有名管道文件。 
*/



#endif 
