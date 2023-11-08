#include<stdio.h>
#include<graphics.h>
int x1,y1,x2,y2,xmin=100,ymin=100,xmax=900,ymax=600;
float u1,u2;
void lineclip(){
	float p[4],q[4],r[4],dx,dy,X1,Y1,X2,Y2;
	int i;
	u1=0,u2=1;
	dx = x2-x1;
	dy = y2-y1;
	p[0] = -dx;
	p[1] = dx;
	p[2] = -dy;
	p[3] = dy;
	q[0] = x1-xmin;
	q[1] = xmax-x1;
	q[2] = y1-ymin;
	q[3] = ymax-y1;
	for(i=0;i<4;i++){
		if((p[i]=0 && q[i]<0)){
			printf("Line Eliminated\n");
			break;
		}
		else if(p[i]<0){
			r[i] = q[i]/p[i];
			if(r[i]>u1){
				u1 = r[i];
			}
		}
		else if(p[i]>0){
			r[i] = q[i]/p[i];
			if(r[i]<u2){
				u2 = r[i];
			}
		}
		if(u1<u2){
			X1 = x1+(dx*u1);
			Y1 = y1+(dy*u1);
			X2 = x1+(dx*u2);
			Y2 = y1+(dy*u2);
			printf("%f %f %d %d",X1,Y1,X2,Y2);
			setcolor(RED);
		line((int)X1,(int)Y1,(int)X2,(int)Y2);
		}
//		else if(u1>u2){
//			printf("Line Eliminated\n");
//			break;
//		}
		
	}
}
int main(){
	int gd=DETECT,gm,ch;
	initwindow(1000,800,"2dTransformation",50,50,false,true);
	rectangle(xmin,ymin,xmax,ymax);
	do{
		printf("1)Enter Line\t2)End\nEnter choice\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:printf("Enter line coordinates\n");
					scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
					setcolor(WHITE);
					line(x1,y1,x2,y2);
					lineclip();
					break;
			case 2:break;
			default:printf("Invalid Choice\n");
					break;
		}
	}while(ch!=2);
	getch();
	closegraph();
	return 0;
}
