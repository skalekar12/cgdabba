//BEZIER CURVE
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
void bezier(){
	double t,xt,yt;
	int x[4],y[4],i;
	for(i = 0;i<4;i++){
		printf("Enter x%d and y%d \n",i,i);
		scanf("%d%d",&x[i],&y[i]);
	}
	for(t=0;t<1.0;t+=0.0005){
		xt = pow((1-t),3)*x[0] + 3*pow((1-t),2)*t*x[1] + 3*pow(t,2)*(1-t)*x[2] + pow(t,3)*x[3];
		yt = pow((1-t),3)*y[0] + 3*pow((1-t),2)*t*y[1] + 3*pow(t,2)*(1-t)*y[2] + pow(t,3)*y[3];
		putpixel(xt,yt,RED);
	}
	for(i=0;i<4;i++){
		putpixel(x[i],y[i],YELLOW);
	}
}
int main(){
	int gd=DETECT,gm,ch;
	initwindow(1000,800,"2dTransformation",50,50,false,true);
	do{
//		System("cls");
		cleardevice();
		bezier();
		printf("1)Draw Again?\t2)No\n");
		scanf("%d",&ch);
	}while(ch!=2);
	
	getch();
	closegraph();
	return 0;
}
