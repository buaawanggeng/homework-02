#include<stdio.h>
int FindMax(int a[],int column)
{
	int max=-1<<31,i;
	max=a[0];
	for(i=1;i<column;i++){
		a[i]+=a[i-1]>0?a[i-1]:0;
		max=max>a[i]?max:a[i];}
	return max;
}
int main(int argc,char* argv[])
{
	if(argc==1){
		printf("请在maxsun.exe后输入文件名\n");return -1;}
	else if(argc>2){
		printf("请在maxsun.exe后输入文件名，此为1.0版本，不支持任何附加参数\n");return -1;}
	else{
		if(freopen(argv[1],"r",stdin)==NULL){
			printf("文件不存在，请尝试输入文件的完整路径\n");return -1;}
		int row,column,i=0,a[1000],maxsum;
		if(scanf("%d",&row)!=1){
			printf("文本格式错误，请参照示例输入测试文本(行错误)\n");return -1;}
		getchar();getchar();
		if(scanf("%d",&column)!=1){
			printf("文本格式错误，请参照示例输入测试文本（列错误）\n");return -1;}
		getchar();
		while(i<column){
			getchar();
			if(scanf("%d",&a[i++])!=1){
				printf("文本格式错误，请参照示例输入测试文本（数据与行列数不对应）\n");return -1;}
			if(i>=1000){
				printf("数组越界，最多只能处理1000个数\n");return -1;}}
		maxsum=FindMax(a,column);
		printf("%d\n",maxsum);
		fclose(stdin);}
	return 0;
}
