//Koch
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
void koch(int X1,int Y1,int X2,int Y2,int it){
	float r = 60*(3.14/180);
	int X3 = ((2*X1)+X2)/3;
	int Y3 = ((2*Y1)+Y2)/3;
	int X4 = ((2*X2)+X1)/3;
	int Y4 = ((2*Y2)+Y1)/3;
	int X = X3 + (X4-X3)*cos(r) - (Y4-Y3)*sin(r);
	int Y = Y3 + (X4-X3)*sin(r) + (Y4-Y3)*cos(r);
	if(it > 0){
		koch(X1,Y1,X3,Y3,(it-1));
		koch(X3,Y3,X,Y,(it-1));
		koch(X,Y,X4,Y4,(it-1));
		koch(X4,Y4,X2,Y2,(it-1));
	}
	else{
		line(X1,Y1,X3,Y3);
		line(X3,Y3,X,Y);
		line(X,Y,X4,Y4);
		line(X4,Y4,X2,Y2);
	}
}
int main(){
	int gd=DETECT,gm,ch,X1,Y1,X2,Y2,it;
	initwindow(1000,800,"KOCH",50,50,false,true);
	do{
		cleardevice();
		printf("Enter line coordinates\n");
		scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
		printf("Enter the no of iterations\n");
		scanf("%d",&it);
		koch(X1,Y1,X2,Y2,it);
		printf("1)Draw again?\t2)Stop\n");
		scanf("%d",&ch);
	}while(ch!=2);
	getch();
	closegraph();
	return 0;
}
