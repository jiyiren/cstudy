#include <stdio.h>
#include "jiyic.h"

int  main()
{
	/*int num=0;
	while(1){
		printf("������:");
		scanf("%d",&num);
		printf("%d�Ƿ�������:%d\n",num,isPrime(num));
		printf("%d�Ƿ�������:%d\n",num,isPrime2(num));
	}*/

	/*int a,b;
	while(1){
	
		printf("������:");
		scanf("%d%d",&a,&b);
		printf("%d��%d���Լ��Ϊ:%d\n",a,b,gcd(a,b));
		printf("%d��%d���Լ��Ϊ:%d\n",a,b,gcd2(a,b));
		printf("%d��%d���Լ��Ϊ:%d\n",a,b,gcd3(a,b));
	}*/

	/*int a,b;
	while(1){
		printf("������:");
		scanf("%d%d",&a,&b);
		printf("%d��%d��С������Ϊ:%d\n",a,b,lcm(a,b));
		printf("%d��%d��С������Ϊ:%d\n",a,b,lcmBYgcd(a,b));
	}*/

	/*int a[10]={20,15,14,22,90,100,0,-1,-9,2};
	printf("ԭ����");
	mprint(a,10);
	printf("ð�������");
	sortBubble(a,10);
	mprint(a,10);
	printf("ѡ�������");
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
