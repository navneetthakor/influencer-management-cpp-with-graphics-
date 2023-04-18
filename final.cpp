#include<iostream>
#include<graphics.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
char* arr[5]={"Insert","Delete","Find","Modify","Exit"};

// classes to be used 
class influencers
{
    char id[5];
    char name[20];
    char email[20];
    float due;
    float gains;

public:
    char *ret_inf_id()
    {
        return id;
    }

    float ret_inf_gains()
    {
        return gains;
    }

    char *ret_inf_name()
    {
        return name;
    }

    void add_influencer()
    {
        cout << "Enter influencer id : ";
        cin >> id;
        cout << "Enter influencer name : ";
        cin >> name;
        cout << "Enter influencer email : ";
        cin >> email;
        cout << "Enter due amount : ";
        cin >> due;
        gains = 0;
    }

    void show_details()
    {
        influencers inf;
        int flag=0;
        char sid[5];
        cout<<"Enter id to search : ";
        cin>>sid;
        fstream file;
        file.open("influencers.txt", ios::in | ios::out | ios::ate);
        file.seekg(0);
        while (file.read((char *)&inf, sizeof(inf)))
        {
            if (strcmp(sid, inf.id) == 0)
            {
                cout << endl;
                cout << "id :" << inf.id << endl;
                cout << "name :" << inf.name << endl;
                cout << "email :" << inf.email << endl;
                cout << "due :" << inf.due << endl;
                cout << "gains :" << inf.gains << endl;
                flag=1;
            }
        }
        if(flag==0){
            cout<<"No such influencer found.\n";
        }
        file.close();
    }

    void search_influencer()
    {
        influencers inf;
        char sid[5];
        fstream file;
        file.open("influencers.txt", ios::in);
        int chances = 3,flag=0;
        cout << "Enter id of influencer to search : ";
            cin >> sid;
            file.seekg(0);
            while (file.read((char *)&inf, sizeof(inf)))
            {
                if (strcmp(sid, inf.id) == 0)
                {
                    cout << "Yes.. The influencer exists.\n";
                    chances = 0;
                    flag=1;
                }
            }
            if(flag!=1){
                cout<<"Influencer not found.\n";
            }
    file.close();
    }
};

class clients
{
    char client_name[20];
    float package;

public:
    void add_client()
    {
        char *sid;
        bool exists;
        cout << "Enter influencer id to add client : ";
        cin >> sid;

        influencers temp_inf;
        fstream file;
        file.open("influencers.txt", ios::in);
        file.seekg(0, ios::beg);
        while (file.read((char *)&temp_inf, sizeof(temp_inf)))
        {
            if (strcmp(sid, temp_inf.ret_inf_id()) == 0)
            {
                exists = true;
            }
        }
        if (exists)
        {
            cout << "Enter client name : ";
            cin >> client_name;
            cout << "Enter package : ";
            cin >> package;
            cout << "Added client " << client_name << " to Influencer : " << temp_inf.ret_inf_name() << endl;
        }
        else
        {
            cout << "Wrong influencer credentials.\n";
            exists = false;
        }
        file.close();
    }
};




    // to create rectangle of menubar 
void setrect(){
	setcolor(10);
    for(int i=0;i<5;i++)
	rectangle(80-i,110-i,560+i,200+i);
    }




// to create whole graph 
void creategp(){
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


}





// sample functions
void insert(){
	cout<<"Insert"<<endl;
}

void delete1(){
	cout<<"Delete"<<endl;
}



// function to change the color 
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



// main funciton 
int main(){
	creategp();
	
    influencers i1;

    
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
    		closegraph();
    		i1.add_influencer();
    		delay(2000);
    		creategp();
		}
		else if(i==1){
			closegraph();
    		delete1();
    		delay(2000);
    		creategp();
		}
		else if(i==2)
		{
			closegraph();
			i1.search_influencer();
			delay(2000);
			creategp();
		}
		else if(i==3)
		{
			closegraph();
			i1.show_details();
			delay(2000);
			creategp();
		}
		else if(i==4)
		{
			closegraph();
			return 0;
		}	
	}
 }
    
    
    
    
    delay(5000000);
	
	return 0;
}

