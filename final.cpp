#include<iostream>
#include<graphics.h>
#include<fstream>
#include<stdlib.h>
#include<vector>
using namespace std;
char* arr[5]={"Insert","Delete","Find","Modify","Exit"};

// classes to be used 
class influencers
{
    char id[5];
    char name[20];
    char email[20];
    float due;

public:
    float gains;
    char* ret_inf_id()
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

   void add()
    {
        cout << "Enter influencer id : ";
        cin >> id;
        cout << "Enter influencer name : ";
        cin >> name;
        cout << "Enter influencer email : ";
        cin >> email;
        cout << "Enter due amount : ";
        cin >> due;
        cout<<endl;
        gains = 0;
    }

    void add_influencer()
    {
        add();
        fstream file;
        file.open("influencers.txt", ios::in | ios::out | ios::ate);
        file.clear();
        file.seekp(0,ios::end);
        file.write((char *)&(*this), sizeof(*this));
        file.close();
    }

    void modify(){
        influencers inf;
        char sid[5] ,a[5],b[20],c[20];
        float d,e;
        int x;
        // int infsize = sizeof(inf);
        cout<<"Enter influencer id to modify : ";
        cin>>sid;
        fstream file;
        file.open("influencers.txt", ios::in|ios::out|ios::ate);
        file.seekg(0);
            while (file.read((char *)&inf, sizeof(inf)))
            {
                if (strcmp(sid, inf.id) == 0)
                {
                    cout<<"Enter id : ";
                    cin>>a;
                    cout<<"Enter name : ";
                    cin>>b;
                    cout<<"Enter email : ";
                    cin>>c;
                    cout<<"Enter due : ";
                    cin>>d;
                    cout<<"Enter gains : ";
                    cin>>e;
                    strcpy(inf.id,a);
                    strcpy(inf.name,b);
                    strcpy(inf.email,c);
                    inf.due=d;
                    inf.gains=e;

                    file.seekp(file.tellg() - sizeof(inf));
                    file.write((char*)&inf, sizeof(inf));
                }
            }
        file.close();
    }

    void show_details()
    {
       
                cout << endl;
                cout << "id :" << id << endl;
                cout << "name :" << name << endl;
                cout << "email :" << email << endl;
                cout << "due :" << due << endl;
                cout << "gains :" << gains << endl;
                
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
                    
//                    showing data
					cout << endl;
                cout << "id :" << inf.id << endl;
                cout << "name :" << inf.name << endl;
                cout << "email :" << inf.email << endl;
                cout << "due :" << inf.due << endl;
                cout << "gains :" << inf.gains << endl;
                }
            }
            if(flag!=1){
                cout<<"Influencer not found.\n";
            }
    file.close();
     
    }

     void delete1(){
        influencers inf;
        char sid[5] ,a[5],b[20],c[20];
        float d,e;
        int x;
        cout<<"Enter influencer id to deleted : ";
        cin>>sid;
        fstream file;
        file.open("influencers.txt", ios::in|ios::out|ios::ate);
        file.seekg(0);
            while (file.read((char *)&inf, sizeof(inf)))
            {
                if (strcmp(sid, inf.id) == 0)
                {
                    strcpy(inf.id,"");
                    strcpy(inf.name,"");
                    strcpy(inf.email,"");
                    inf.due=0;
                    inf.gains=0;

                    file.seekp(file.tellg() - sizeof(inf));
                    file.write((char*)&inf, sizeof(inf));
                }
            }
            cout<<"deleted successfully"<<endl;
        file.close();
    }
    
//    print all influencers
	void displayinf()
	{
		influencers inf;
	    fstream file;
        file.open("influencers.txt", ios::in|ios::out|ios::ate);
        file.seekg(0);	
        while (file.read((char *)&inf, sizeof(inf)))
            {
                inf.show_details();
            }
        file.close();
	}
	
//	find max 
	void max(){
        influencers inf;
        fstream file;
        int i=0;
        vector<float> arr;
        file.open("influencers.txt",ios::in|ios::out|ios::ate);
        file.seekg(0);
        while(file){
        	file.read((char *)&inf,sizeof(inf));
            arr.push_back(inf.gains);
        }
         file.close();
        
        float big=arr[0];                        
        for(int j=0;j<arr.size();j++){
            for(int k=j+1;k<arr.size();k++){
                if(big<arr[k]){
                    big=arr[k];
                }
            }
        }
        
        ifstream file1("influencers.txt");
        cout<<big<<" ";
        file.seekg(0);
        while(file1){
        	file1.read((char *)&inf,sizeof(inf));
            if(big == inf.gains){
            	inf.show_details();
			}
        }
       
    }
    
    //	find min 
	void min(){
        influencers inf;
        fstream file;
        int i=0;
        vector<float> arr;
        file.open("influencers.txt",ios::in|ios::out|ios::ate);
        file.seekg(0);
        while(file){
        	file.read((char *)&inf,sizeof(inf));
            arr.push_back(inf.gains);
        }
         file.close();
        
        float big=arr[0];                        
        for(int j=0;j<arr.size();j++){
            for(int k=j+1;k<arr.size();k++){
                if(big>arr[k]){
                    big=arr[k];
                }
            }
        }
        
        ifstream file1("influencers.txt");
        cout<<big<<" ";
        file.seekg(0);
        while(file1){
        	file1.read((char *)&inf,sizeof(inf));
            if(big == inf.gains){
            	inf.show_details();
			}
        }
       
    }
};

class clients
{
    char client_name[20];
    float package;

public:
   void add_client()
    {
        // takking details of client 
        cout << "Enter client name : ";
        cin >> client_name;
        cout << "Enter package : ";
        cin >> package;

        char sid[5];
        bool exists=false;
        int flag= 1;
        cout << "Enter influencer id to add client : ";
        cin >> sid;

        influencers temp_inf;
        fstream file;
        file.open("influencers.txt", ios::in | ios::out | ios::ate);
        file.seekg(0, ios::beg);
        while (file)
        {
            file.read((char *)&temp_inf, sizeof(temp_inf));
            if (strcmp(sid, temp_inf.ret_inf_id()) == 0 && flag)
            {
                exists = true;
                temp_inf.gains += package;
                flag = 0;

                file.seekp(file.tellg() - sizeof(temp_inf));
                file.write((char*)&temp_inf, sizeof(temp_inf));
                temp_inf.show_details();
            }
        }
        if (exists)
        {
            // adding client in file 
            ofstream clf("clients.txt");
            clf.write((char*)&(*this),sizeof(*this));
            clf.close();
            cout << "Added client " << client_name << " to Influencer : " << temp_inf.ret_inf_name() << endl;
        }
        else
        {
            cout << "Wrong influencer credentials.\n";
            cout<<endl<<"client not added "<<endl;
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
	outtextxy(80,280,"Press 3: To show all the Influencers.");
	outtextxy(80,300,"Press 4: To Add Client");

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
    clients c1;

    
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
    		delay(3000);
    		creategp();
		}
		else if(i==1){
			closegraph();
    		i1.delete1();
    		delay(3000);
    		creategp();
		}
		else if(i==2)
		{
			closegraph();
			i1.search_influencer();
			delay(5000);
			creategp();
		}
		else if(i==3)
		{
			closegraph();
			i1.modify();
			delay(3000);
			creategp();
		}
		else if(i==4)
		{
			closegraph();
			return 0;
		}	
	}
	else if(ch==49)
		{
			closegraph();
			i1.min();
			delay(5000);
			creategp();
		}
		else if(ch==50)
		{
			closegraph();
		    i1.max();
		    delay(5000);
		    creategp();
		}
		else if(ch==51)
		{
			closegraph();
		    i1.displayinf();
		    delay(5000);
		    creategp();
		}
		else if(ch==52)
		{
			closegraph();
		    c1.add_client();
		    delay(5000);
		    creategp();
		}
 }
    
    
    
    
    delay(5000000);
	
	return 0;
}

