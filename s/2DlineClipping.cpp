#include<stdio.h>
#include<conio.h>
#include<graphics.h>

float p[4],q[4];
float u1[5],u2[5],r[4];
float max(float u[]);
float min(float u[]);
int main()
{
	int gd=DETECT,gm,i;
	int x1,y1,x2,y2,xmin,ymin,xmax,ymax,x0,y0,x3,y3;
	float u11=0,u22=1;
	//xmin=200 ymin=200 xmax=180 ymax=180//
	initwindow(1000,800,"2dTransformation",50,50,false,true);
	printf("enter (x1,y1),(x2,y2): ");
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	printf("enter xmin,ymin,xmax,ymax: ");
	scanf("%d %d %d %d",&xmin,&ymin,&xmax,&ymax);
	line(x1,y1,x2,y2);
	rectangle(xmin,ymin,xmax,ymax);
	p[0]=x1-x2;p[1]=x2-x1;p[2]=y1-y2;p[3]=y2-y1;
	q[0]=x1-xmin;q[1]=xmax-x1;q[2]=y1-ymin;q[3]=ymax-y1;
	for(i=0;i<5;i++)
	{	u1[i]=0;u2[i]=1;  }
	for(i=0;i<4;i++)
	{       r[i]=q[i]/p[i];

		if(p[i]==0 && q[i]<0)
		{	printf("line is outsdie the window");
			break;
		}
		if(p[i]<0)
		{       u1[i+1]=r[i];
			u11=max(u1);
		}
		else if(p[i]>0)
		{
			u2[i+1]=r[i];
			u22=min(u2);
		}
	}
	if(u11==0 && u22==1)
	{
		printf("line is completely inside");
		setcolor(YELLOW);
		line(x1,y1,x2,y2);
	}
	else if(u11>u22)
	{
		printf("line is outside the window");
	}
	else
	{
		x0=x1+u11*p[1];y0=y1+u11*p[3];
		x3=x1+u22*p[1];y3=y1+u22*p[3];
		setcolor(GREEN);
		line(x0,y0,x3,y3);
	}
	getch();
	closegraph();

}
float max(float u[])
{
	float max=u[0];
	int i;
	for(i=1;i<5;i++)
	{
		if(max<u[i])
		{	max=u[i];	}
	}
	return max;
}
float min(float u[])
{
	float min=u[0];
	int i;
	for(i=1;i<5;i++)
	{
		if(min>u[i]){	min=u[i];	}
	}
	return min;
}

