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
		printf("����maxsun.exe�������ļ���\n");return -1;}
	else if(argc>2){
		printf("����maxsun.exe�������ļ�������Ϊ1.0�汾����֧���κθ��Ӳ���\n");return -1;}
	else{
		if(freopen(argv[1],"r",stdin)==NULL){
			printf("�ļ������ڣ��볢�������ļ�������·��\n");return -1;}
		int row,column,i=0,a[1000],maxsum;
		if(scanf("%d",&row)!=1){
			printf("�ı���ʽ���������ʾ����������ı�(�д���)\n");return -1;}
		getchar();getchar();
		if(scanf("%d",&column)!=1){
			printf("�ı���ʽ���������ʾ����������ı����д���\n");return -1;}
		getchar();
		while(i<column){
			getchar();
			if(scanf("%d",&a[i++])!=1){
				printf("�ı���ʽ���������ʾ����������ı�������������������Ӧ��\n");return -1;}
			if(i>=1000){
				printf("����Խ�磬���ֻ�ܴ���1000����\n");return -1;}}
		maxsum=FindMax(a,column);
		printf("%d\n",maxsum);
		fclose(stdin);}
	return 0;
}
