diary.txt为存储数据的文件，diary.h中定义了数据结构，和Read, Write等函数，diary.cpp中是这些函数的实现
pdshow.cpp, pdadd.cpp, pdlist.cpp, pdremove.cpp中是题目要求的四个函数的实现
在文件夹中提供了这四个函数的.exe文件，windows系统可以直接运行
同时提供了makefile文件，windows系统可以通过mingw32-make编译，linux和mac系统可以通过make编译，得到4个可执行文件

日期输入格式: 8位，前四位表示年份，后面两位表示月份，最后两位表示日期，如：20220417
日记记录格式：每一页日记第一行为日期，从第二行开始为正文内容，以一个只有'.'的行表示该页日记结束，每一页之间没有空行

在sample.bat中提供了样例，可以直接双击运行