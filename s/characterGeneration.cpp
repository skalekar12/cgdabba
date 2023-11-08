#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdio.h>
int round(float a)
{
int b;
float c;
b=(int)a;
c=a-b;
if(c<0.5)
{
return floor(a);
}
else
{
return ceil(a);
}
}
void DDA(float x1,float y1,float x2,float y2){
	int k;
	float steps,dx,dy,xi,yi;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
	{
		steps=dx;
	}
	else
	{
		steps=dy;
	}
	xi=dx/steps;
	yi=dy/steps;
	putpixel(round(x1),round(y1),WHITE);
	for(k=0;k<=steps;k++)
	{
		x1+=xi;
		y1+=yi;
		putpixel(round(x1),round(y1),WHITE);
	}
}
void bitmap()
	{
		int i,j;
		int a[13][9]={{0,0,0,1,1,1,0,0,0},
					  {0,0,1,0,0,0,1,0,0},
					  {0,1,0,0,0,0,0,1,0},
					  {0,1,0,0,0,0,0,1,0},
					  {0,1,0,0,0,0,0,1,0},
					  {0,1,0,0,0,0,0,1,0},
					  {0,1,0,0,0,0,0,1,0},
					  {0,1,1,1,1,1,1,1,0},
					  {0,1,0,0,0,0,0,1,0},
					  {0,1,0,0,0,0,0,1,0},
					  {0,1,0,0,0,0,0,1,0},
					  {0,1,0,0,0,0,0,1,0},
					  {1,1,1,0,0,0,1,1,1}};
		for(i=0;i<13;i++){
			for(j=0;j<9;j++){
				putpixel(200+j,200+i,15*a[i][j]);
			}
		}		
				  
	}
void stroke(){
	DDA(200.00,100.00,100.00,300.00);
	DDA(200.00,100.00,300.00,300.00);
	DDA(150.00,200.00,250.00,200.00);
}
int main()
{
	int gd=DETECT,gm;
	int ch;
	initgraph(&gd,&gm,(char*)"");
	printf("1)Stroke Method\n2)Bitmap Method");
	printf("Enter the choice\n");
	scanf("%d",&ch);
	switch(ch){
		case 1: stroke();
			break;
		case 2:	bitmap();
			break;
	}
	getch();
	closegraph();
	return 0;
}
