#include<iostream>
#include<graphics.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

void setrect(){
	setcolor(10);
    for(int i=0;i<5;i++)
	rectangle(80-i,110-i,560+i,200+i);
    }

int main(){
	char* arr[5]={"Insert","Delete","Find","Modify","Exit"};
    
//    starting graphics window
    int gd,gm,x1,y1,x2,y2;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm," ");
    
//    menubar rectangle
    setrect();
    
//    welcome notes
	outtextxy(200,50,"Welcome to CI Moguls Admin Panel");
    
//    boxes in menubar 
	y1= 110;
	y2=200;
	x1=80;
	x2=80;
    line(x1,y1,x2,y2);
    for(int i=0;i<5;i++)
    {
        x1 = x2 = x1 + 80;
        line(x1,y1,x2,y2);
    }
    
//    setting logo in menubar
	setcolor(12);
    int a=90;
    int b=140;
    
	outtextxy(a,b,"CI Moguls");

//    putting text in menubar
	setcolor(15); 
	a += 90;
    for(int i=0;i<5;i++){
    outtextxy(a,b,arr[i]);
    a+=80;
    }
    
//    putting text below menubar
	outtextxy(80,240,"Press 1: To find top performer");
	outtextxy(80,260,"Press 2: To find worst performer");
    
    
    
    
    
    
    delay(500000);
	
	return 0;
}

