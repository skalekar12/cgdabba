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
int main()
{
	int gd=DETECT,gm;
	int k;
	float steps,x2,y2,dx,dy,x1,y1,xi,yi;
	int round(float );
	initgraph(&gd,&gm,(char*)"");
	printf("Enter the first and last coordinates\n");	
	scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
	printf("\n\n\nTHE ENDPOINTS ARE \nx1=%f\ty1=%f\nx2=%f\ty2=%f\n",x1,y1,x2,y2);
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
	getch();
	closegraph();
	return 0;
}

