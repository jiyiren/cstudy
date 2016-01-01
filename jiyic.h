/*
@time:2015-12-31
@author:JIYI
@usage:#include "jiyic.h"
*/

#include<stdio.h>
#include<math.h>

/*
0和1既不是质数也不是合数
@aim:求是否为质数函数
@param int num 传入的数值,数值可以为负数、0、1等
@return int 返回为0说明不是质数，返回值为1说明是质数
所以此函数如果传入的值是0,1或者4,8等都给予不是质数的判断
*/
int isPrime(int num){
	if(num<=0||num==1){
		return 0;
	}

	int j=2;
	while(num%j!=0){//j从2开始，num>=2,所以如果最后的结束是num==j结束的，那说明num就是质数
					//如果结束在j=num之前，则说明num就不是质数了！
		j++;
	}
	if(num==j){
		return 1;
	}else{
		return 0;
	}
}
/*
求质数方法二
*/
int isPrime2(int num){
	if(num<=0||num==1){
		return 0;
	}
	//写法第一种
	//int i=0,count=0;
	//for(i=2;i<(int)sqrt((double)num);i++){
	//	if(num%i==0){          //只要这判断为真了,count就变为1,跳出循环,最后根据这个判断是否为真判断是否有因数
	//		count=1;
	//		break;
	//	}
	//}
	//if(count==1){
	//	return 0;
	//}else{
	//	return 1;
	//}

	//写法第二种
	int j=0,k;
	k=(int)sqrt((double)num);
	for(j=2;j<=k;j++){
		if(num%j==0){ //如果k可以被除尽，则j++就不会被执行，所以如果不是质数，j的最大值为k,而除不尽了最后的值应该是j=k+1;
					  //所以最后判断j>k为质数，否则不是
			break;
		}
	}
	if(j>k){
		return 1;
	}else{
		return 0;
	}
}


/*
求最大公约数
辗转相除法
有两整数a和b：
① a%b得余数c
② 若c=0，则b即为两数的最大公约数
③ 若c≠0，则a=b，b=c，再回去执行①

例如求27和15的最大公约数过程为：
27÷15 余12
15÷12余3
12÷3余0因此，3即为最大公约数
*/
int gcd(int x,int y){
	if(x<=0||y<=0){
		return -1;
	}
	int temp;
	if(x<y){ //最大值给x,最小值给y
		temp=x;
		x=y;
		y=temp;
	} 

	int c;
	while(y!=0){ 
		c=x%y; //c当0时终止
		x=y;  //当执行到最后c等于0时，最小公倍数为c=x%y里的y，但是x=y这句执行后y的值给了x，所以最后返回的是x。
		y=c;  //如果返回了y，则都是0，因为y=c此句执行了
	}
	return x;
}


/*
⑵ 相减法
有两整数a和b：
① 若a>b，则a=a-b
② 若a<b，则b=b-a
③ 若a=b，则a（或b）即为两数的最大公约数
④ 若a≠b，则再回去执行①

例如求27和15的最大公约数过程为：
27－15＝12( 15>12 ) 15－12＝3( 12>3 )
12－3＝9( 9>3 ) 9－3＝6( 6>3 )
6－3＝3( 3==3 )
因此，3即为最大公约数
*/
int gcd2(int x,int y){
	if(x<=0||y<=0){
		return -1;
	}
	if(x==y){ //这里的等于一定要拿出来比一下的，不然一直是循环不结束的。但是此处的等于也可以拿到下面的循环里加个条件语句
		return x;
	}
	while(x!=y){
		if(x>y){
			x=x-y;
		}else{
			y=y-x;
		}
	}
	return x;
}

/*
(3)穷举法
1.找出x,y中的较小值，temp
2.temp能否被x,y整除
3.若能，则temp即为最大公约数
4.若不能，则temp--,执行2步
*/
int gcd3(int x,int y){
	if(x<=0||y<=0){
		return -1;
	}
	int min=y;
	if(x<y){
		min=x;
	} //temp获得的是最小值

	while(min>=1){
		if(x%min==0&&y%min==0){
			break;
		}
		min--;
	}
	return min;

}

/*
求最小公倍数
最小公倍数=两数的乘积÷两数的最大公约数
穷举法求最小公倍数
*/
int lcm(int x,int y){
	if(x<=0||y<=0){
		return -1;
	}
	int temp,i=1;//从1开始
	if(x<y){
		temp=x;
		x=y;
		y=temp;
	}	//x为较大值，y为较小值
	
	while(i<=y){
		if((i*x)%y==0){ //只要i从1开始到较小值y之间变化，并每次都用i*x判断这是否能除尽y，如果能则i*x为最小公倍数
			break;
		}
		i++;
	}
	return i*x;
}

//求最小公倍数利用最大公约数
int lcmBYgcd(int x,int y){
	if(x<=0||y<=0){
		return -1;
	}
	return x*y/gcd(x,y);
}

//数组排序
//数组输出
void mprint(int arr[],int len){
	int i=0;
	printf("数组为:");
	for(i=0;i<len;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
//冒泡排序法时间复杂度T(n)=n(n-1)/2所以T(n)=O(n^2)
/*
算法思想简单描述：
在要排序的一组数中，对当前还未排好序的范围内的全部数，自上而下对相邻的两个数依次进行比较和调整，
让较大的数往下沉，较小的往上冒。即：每当两相邻的数比较后发现它们的排序与排序要求相反时，就将它们互换。
冒泡算法是稳定的
*/
//从小到大
void sortBubble(int arr[],int len){
	int i,j,temp;
	for(i=0;i<len;i++){ //这里的写len可以，len-1也可以
		for(j=0;j<len-1-i;j++){//这里一定要len-1的，因为下面有arr[j+1]所以要允许j+1的下标可访问
			if(arr[j]>arr[j+1]){ //这里改为<就是从大到小
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

//选择排序时间复杂度T(n)=O(n^2)
/*
在要排序的一组数中，选出最小的一个数与第一个位置的数交换；然后在剩下的数当中再找最小的与第二个位置的数交换，
如此循环到倒数第二个数和最后一个数比较为止。
选择排序是不稳定的。算法复杂度O(n2)--[n的平方]
*/
void sortFastChoose(int arr[],int len){
	int i=0,j=0,k,temp;
	for(i=0;i<len-1;i++){
		k=i;
		for(j=i+1;j<len;j++){
			if(arr[k]>arr[j]){ //这里该为<就是从大到小
				k=j;
			}
		}
		if(k!=i){
			temp=arr[k];
			arr[k]=arr[i];
			arr[i]=temp;
		}
	}
}