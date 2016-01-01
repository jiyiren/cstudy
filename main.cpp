#include <stdio.h>
#include "jiyic.h"

int  main()
{
	/*int num=0;
	while(1){
		printf("请输入:");
		scanf("%d",&num);
		printf("%d是否是质数:%d\n",num,isPrime(num));
		printf("%d是否是质数:%d\n",num,isPrime2(num));
	}*/

	/*int a,b;
	while(1){
	
		printf("请输入:");
		scanf("%d%d",&a,&b);
		printf("%d和%d最大公约数为:%d\n",a,b,gcd(a,b));
		printf("%d和%d最大公约数为:%d\n",a,b,gcd2(a,b));
		printf("%d和%d最大公约数为:%d\n",a,b,gcd3(a,b));
	}*/

	/*int a,b;
	while(1){
		printf("请输入:");
		scanf("%d%d",&a,&b);
		printf("%d和%d最小公倍数为:%d\n",a,b,lcm(a,b));
		printf("%d和%d最小公倍数为:%d\n",a,b,lcmBYgcd(a,b));
	}*/

	/*int a[10]={20,15,14,22,90,100,0,-1,-9,2};
	printf("原来的");
	mprint(a,10);
	printf("冒泡排序后");
	sortBubble(a,10);
	mprint(a,10);
	printf("选择排序后");
	sortFastChoose(a,10);
	mprint(a,10);*/

	char *str;
	char mstr[]="Hello";
	str=mstr;
	str[0]='D';
	printf("mstr:%s\n",mstr);
	printf("str:%s\n",str);
	return 0;	
}
