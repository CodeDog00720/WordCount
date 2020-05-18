#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
int CountWord(FILE* fp);
int CountChar(FILE* fp);
int StringCmp(char* str);
int main(int argc, char* argv[]) {
	FILE* fp1,*fp2;
	char ch;
	int flag = 0, cmp;
	fp1 = fopen(argv[2], "r");
	if (fp1 == NULL)
	{
		printf("Failure to open the file!\n");
	}
	while ((ch = fgetc(fp1)) != EOF)
	{
		putchar(ch);
	}
	printf("\n");
	fclose(fp1);
	fp2 = fopen(argv[2], "r");//命令行第二个参数表示文本文件名
	cmp = StringCmp(argv[1]);//表计数字符或单词操作
	switch (cmp)
	{
	case 1:
		printf("The number of char :%d\n", CountChar(fp2));
		break;
	case 2:
		printf("The number of word:%d\n", CountWord(fp2));
		break;
	default:
		printf("Wrong Input!\n");
		break;
	}
	if (!fclose(fp2))
		printf("Success to close file!\n");
	return 0;
}
int CountWord(FILE* fp)
{
	int flag = 0;
	char ch;
	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch == ' ' || ch == ',')
			++flag;
	}
	return(++flag);
}
int CountChar(FILE* fp)
{
	char ch;
	int flag = 0;
	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch == ' ' || ch == ',')
		{
			flag = 0;
			break;
		}
		else
			++flag;
	}
	return flag;
}
int StringCmp(char* str)
{
	char str1[] = "-c";
	char str2[] = "-w";
	if (strcmp(str1, str) == 0)
		return 1;
	else
	{
		if (strcmp(str, str2) == 0)
			return 2;
		else
			return 0;
	}
}