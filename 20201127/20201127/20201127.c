#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main() {
	//File是一个已经定义好的结构体
	//这里的f是一个结构体指针
	//'w'只写,如果没有,就新建一个
	FILE* f = fopen("d:/test.txt", "w");    
	if (f == NULL) {    //检索
		//errno =error number错误代码 strerror函数将其转换成字符型

		// printf("文件打开失败! errno = %d, %s\n", errno, strerror(errno));
		
		perror("文件打开失败!");//这里的perror与上面的意思一样,只是更简化了
		system("pause");
		return 1;
	}
	printf("文件打开成功!\n");





	// fread 函数负责将磁盘上的数据存于内存中
	 char buf[1024] = { 0 };
	// 其中第二个参数和第三个参数相乘, 就得到了要读取的整体的字节数. 
	// 返回值表示实际读取到的元素个数. 
	// 如果实际读到的元素个数小于预期的要读的元素个数, 就可以认为
	// 文件读完了
	int n = fread(buf, 1, 1024, f);    
	printf("%s\n", buf);

	// fwrite 负责把内存的数据, 写到磁盘中
	// 如果 fwrite 写成功了, 那么就会返回实际写入的元素个数. 
	// 如果失败了就会返回 < 0 的结果. 
	char buf[1024] = "hahaha";
	int n = fwrite(buf, 1, strlen(buf), f);
	if (n < strlen(buf)) {
		perror("fwrite");
	}

	// 使用 fprintf 进行格式化写入
	int num = 10;
	fprintf(f, "num = %d", num);

	// 这个操作就和 printf 是等价的. 
	// 使用 fscanf(stdin, ""); 就和 scanf 是等价的.
	fprintf(stdout, "num = %d", num);

	// sprintf / sscanf 这是一个非常重要的函数
	// sprintf 把格式化的结果写到字符串中
	// sscanf 是从格式化字符串中解析结果. 

	char buf[1024] = { 0 };
	sprintf(buf, "num = %d", num);
	printf("%s\n", buf);

	// sprintf 和 sscanf 的一个典型用法: 
	// 把整数转成字符串, 把字符串转成整数. 

	int num = 10;
	// buf 中的内容是一个 "10"
	char buf[1024] = { 0 };
	// 这个操作不是 "输出", 而是把 int 这个数据, 给放到 char buf[] 数组里了
	sprintf(buf, "%d", num);

	printf("%c\n", buf[0]);
	printf("%c\n", buf[1]);
	printf("%c\n", buf[2]);

	printf("%s\n", buf);

	// 在 C 语言中, 还有一组函数也能实现字符串和整数的转换
	// atoi 把字符串, 转成整数
	// itoa 把整数, 转成字符串


	fclose(f);		//关闭文件

	// \ 也表示 转义字符 
	 char name[] = "D:\\program2\\qq\\Bin";
	char name[] = "D:/program2/qq/Bin";
	printf("%s\n", name);
	system("pause");
	return 0;
}