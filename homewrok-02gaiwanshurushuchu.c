#include<stdio.h>
#include<stdlib.h>
//FILE *fp;
int maxsum(int *a,int n)
{
    int sum = 0;
    int b = 0;
    int i;
    for (i = 0;i<n;i++)
    {
        /*if (a[i]>2147483647||a[i]<2147483647||b>2147483647||b<2147483647)
        {
            printf("error\n");return -2147483647;
        }
        else*/
        if(b<0)           //...
            b=a[i];
        else
            b+=a[i];
        if(sum<b)
            sum=b;
            //printf("%d %d\n",b,a[i]);
    }
    return sum;
}

int main(int argc,char* argv[])
{

	if(argc==1)
	{
		printf("����maxsun.exe�������ļ���\n");
		return -1;
	}
	else if(argc>2)
	{
		printf("����maxsun.exe�������ļ���,��֧���κθ��Ӳ���\n");
		return -1;
	}
	else
	{
		if(freopen(argv[1],"r",stdin)==NULL)
		{
			printf("�ļ������ڣ��볢�������ļ�������·��\n");
			return -1;
		}
        int m,n;
		if(scanf("%d",&n)!=1)
		{
			printf("�ı���ʽ���������ʾ����������ı�(�д���)\n");
			return -1;
		}
		if(n>100)
		{
			printf("�����������ƣ���������100��\n");
			return -1;
		}
		getchar();getchar();
		if(scanf("%d",&m)!=1)
		{
			printf("�ı���ʽ���������ʾ����������ı����д���\n");
			return -1;
		}
		if(m>100)
		{
			printf("�����������ƣ���������100��\n");
			return -1;
		}
		getchar();getchar();
    //fp = fopen("input,txt","r");//�ļ�����
    int a[100][100];
    int b[100] = {0};
    int i,j,k;
    int x;
    int result,resultmax = 0;
    //scanf("%d",&n);
    //scanf("%d",&m);


    //printf("%d %d",n,m);
    for (i = 0;i<n;i++)
        {
            for (j = 0;j<m;j++)
            {
                if(scanf("%d",&a[i][j])!=1)
				{
					printf("�ı���ʽ���������ʾ����������ı�������������������Ӧ��\n");
					return -1;
				}
				getchar();
            }
        }

    /*for (i = 0;i<n;i++)
       {
         for (j = 0;j<m;j++)
            printf("%d",a[i][j]);
         printf("\n");
       }
    */
    for (i = 1;i<=n;i++)//iΪ��ǰ����ĳ���
        for (j = 0;j<=n-i;j++)//jΪ��ǰ�������һ��
            {
                //printf("%d     %d\n",i,j);

                for(k = 0;k < m;k++)
                {
                    for (x = j;x <= i+j-1;x++)//k,x��ͬ���Ƶ�ǰ�ĺͣ��Ǳ�Ϊ��ǰ���к��У�����x�к͵�k��
                    {
                        b[k] = b[k] + a[x][k];
                        //printf("%d %d\n\n%d %d\n\n\n\n\n\n\n\n\n\n",a[x][k],b[k],x,k);
                    }

                    //printf("%d ",b[k]);

                }

                //printf("\n\n\n%d\n",x);

                result = maxsum(b,m);

                //printf("%d\n\n\n\n\n\n",result);

                if(resultmax < result)
                    resultmax = result;

                //printf("%d     %d\n",i,j);
                for(k = 0;k<m;k++)
                    b[k] = 0;
            }
            printf("%d",resultmax);
        fclose(stdin);}
    return 0;
}
