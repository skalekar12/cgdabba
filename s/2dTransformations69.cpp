#include<stdio.h>
#include<graphics.h>
#include<math.h>
int x1 = 200;
int y01 = 200;
int x2 = 300;
int y2 = 300;
int x3 = 400;
int y3 = 100; 
void triangle(int x1,int y01,int x2,int y2,int x3,int y3){
	cleardevice();
	line(x1,y01,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y01);
}
void translation(){
	int tx,ty;
	printf("Enter the x translation:\n");
	scanf("%d",&tx);
	printf("Enter the y translation:\n");
	scanf("%d",&ty);
	triangle((x1+tx),(y01+ty),(x2+tx),(y2+ty),(x3+tx),(y3+ty));
}
void rotation(double ang){
	double r = ang*(3.14/180);
	triangle(((x1*cos(r))-(y01*sin(r))),((x1*sin(r))+(y01*cos(r))),((x2*cos(r))-(y2*sin(r))),((x2*sin(r))+(y2*cos(r))),((x3*cos(r))-(y3*sin(r))),((x3*sin(r))+(y3*cos(r))));
}
void scaling(){
	float sx,sy;
	printf("Enter the x scaling factor:\n");
	scanf("%f",&sx);
	printf("Enter the y scaling factor:\n");
	scanf("%f",&sy);
	triangle((int)(x1*sx),(int)(y01*sy),(int)(x2*sx),(int)(y2*sy),(int)(x3*sx),(int)(y3*sy));
}
void shearing(){
	float shx,shy;
	int ch;
	printf("1)X-shear\n2)Y-shear\n");
	scanf("%d",&ch);
	if(ch==1){
		printf("Enter the x shearing factor:\n");
		scanf("%f",&shx);
		triangle((int)(x1+(shx*y01)),(y01),(int)(x2+(shx*y2)),(y2),(int)(x3+(shx*y3)),(y3));
	}
	else{
		printf("Enter the y shearing factor:\n");
		scanf("%f",&shy);
		triangle((x1),(int)(y01+(shy*x1)),(x2),(int)(y2+(shy*x2)),(x3),(int)(y3+(shy*x3)));	
	}
}
void reflection(){
	int ch;
	printf("1)X reflection\n2)Y reflection\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:triangle((x1),(500-y01),(x2),(500-y2),(x3),(500-y3));
				break;
		case 2:triangle((500-x1),(y01),(500-x2),(y2),(500-x3),(y3));
				break;
	}
}
int main(){
	int gd=DETECT,gm,ch;
	double ang;
	initwindow(1000,800,"2dTransformation",50,50,false,true);
//	initgraph(&gd, &gd, (char*)"");
	do{
		printf("2D TRANSFORMATIONS\n");
		printf("1)Translation\t2)Rotation\t3)Scaling\n4)Shearing\t5)Reflection\t6)End\n");
		printf("Enter Your Choice\n");\
		scanf("%d",&ch);
		cleardevice();
		triangle(x1,y01,x2,y2,x3,y3);
		switch(ch){
			case 1:translation();
			       break;
			case 2:printf("Enter the angle of rotation\n");
				   scanf("%lf",&ang);
				   rotation(ang);
				   break;
			case 3:scaling();
				   break;
			case 4:shearing();
				   break;
			case 5:reflection();
					break;
			case 6:break;
			default:printf("Invalid choice\n");
			        break;
		}
	}while(ch!=6);
	getch();
	closegraph();
	return 0;
}
