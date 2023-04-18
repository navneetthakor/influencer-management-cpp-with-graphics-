#include<iostream>
#include<graphics.h>
#include<fstream>
#include<stdlib.h>
using namespace std;

char* arr[5]={"Insert","Delete","Find","Modify","Exit"};

// sample functions
void insert(){
	cout<<"Insert"<<endl;
}

void delete1(){
	cout<<"Delete"<<endl;
}
    
void setrect(){
	setcolor(10);
    for(int i=0;i<5;i++)
	rectangle(80-i,110-i,560+i,200+i);
    }
    
void normalvideo(int i)
{
    outtextxy((i*80)+170,140,arr[i]);
    setbkcolor(15);
    setcolor(0);

}

void reversevideo(int i)
{
    outtextxy((80*i)+170,140,arr[i]);
    setbkcolor(0);
    setcolor(15);
}

int main(){
    
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
	a += 80;
    for(int i=0;i<5;i++){
    outtextxy(a,b,arr[i]);
    a+=80;
    }
    
//    putting text below menubar
	outtextxy(80,240,"Press 1: To find top performer");
	outtextxy(80,260,"Press 2: To find worst performer");
    
     int i=0;
     while(true){
     int ch=getch();
     if(ch==0)
    {
       	ch=getch();
        switch(ch)
        {
       case 75:
           normalvideo(i);
           if(i==0)
            i=5;
        i--;
        reversevideo(i);
        break;

         case 77:
            normalvideo(i);
            if(i==4)
            i=-1;
            i++;
            reversevideo(i);
        break;
        
        }
        
    }
    else if(ch==13){
    	if(i==0){
    		insert();
		}
		else if(i==1){
			closegraph();
    		delete1();
		}
		else if(i==4)
		{
			closegraph();
		}
		else{
			
		}	
	}
 }
    
    
    
    
    delay(500000);
	
	return 0;
}

