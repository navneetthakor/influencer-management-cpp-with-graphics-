#include<graphics.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
/*
keys-
UP=start
DOWN=options
ESC=exit
*/
// Arrow
class admin
{
    char id[6];
    char name[30];

public:
    admin()
    {
        cout << "THE ID ::";
        cin >> id;
        cout << "THE NAME ::";
        cin >> name;
    }
};

class employee
{
protected:
    char id[9];
    char name[30];
    char department[20];

public:
    void update_info_emp()
    {
        cout << "THE ID :: ";
        cin >> id;
        cout << "THE NAME :: ";
        cin >> name;
        cout << "THE DEPARTMENT :: ";
        cin >> department;
    }

    char *return_name()
    {
        return name;
    }
    char *return_id()
    {
        return id;
    }
};

class complain : public employee
{
    char com_id[7];
    char date[11];
    char categoty[20];
    char desciption[100];
    // int update;

public:
    // complain(int i) : employee()
    // {
    //     cout << "ertyui " << endl;
    // }
    // complain() : employee()
    // {
    //     cout << "THE DATE :: ";
    //     cin >> date;
    //     cout << "THE CATEGORY :: ";
    //     cin >> categoty;
    //     cout << "THE DESCRIPTION :: ";
    //     // getline(cin,desciption);
    //     cin >> desciption;
    //     cout << "THE UPDATE :: " ;
    //     cin >> update;
    // }
    void display()
    {
        cout << "THE USER ID :: " << id << "\nTHE NAME :: " << name << "\nTHE DEPARTMENT :: " << department << "\nTHE COMAPAINT ID" << com_id << "\nTHE DATE :: " << date << "\nTHE CATEGORY :: " << categoty << "\nTHE DESCRIPTION :: " << desciption << endl
             << endl;
    }
    // int return_update()
    // {
    //     return update;
    // }
    void return_day(char temp[])
    {
        temp[0] = date[0];
        temp[1] = date[1];
    }
    void return_month(char temp[])
    {
        temp[0] = date[3];
        temp[1] = date[4];
    }
    void return_year(char temp[])
    {
        temp[0] = date[6];
        temp[1] = date[7];
        temp[2] = date[8];
        temp[3] = date[9];
    }
    char *return_cat()
    {
        return categoty;
    }
    char *return_depart()
    {
        return department;
    }
    char *return_complaier_id()
    {
        return com_id;
    }
    // int return_sat()
    // {
    //     return update;
    // }
    void update_info()
    {
        cout << "THE USER ID :: ";
        cin >> id;
        cout << "THE NAME :: ";
        cin >> name;
        cout << "THE DEPARTMENT :: ";
        cin >> department;
        cout << "THE COMAPLAINT ID :: ";
        cin >> com_id;
        cout << "THE DATE :: ";
        cin >> date;
        cout << "THE CATEGORY :: ";
        cin >> categoty;
        cout << "THE DESCRIPTION :: ";
        cin >> desciption;
        // cout << "THE UPDATE :: ";
        // cin >> update;
    }

    void deleteit(char co_id[])
    {

        int pos, flag = 0;

        ifstream ifs;
        ifs.open("employee.txt", ios::in | ios::binary);

        ofstream ofs;
        ofs.open("temp.txt", ios::out | ios::binary);

        while (!ifs.eof())
        {

            ifs.read((char *)this, sizeof(complain));

            // if(ifs)checks the buffer record in the file
            if (ifs)
            {

                // comparing the roll no with
                // roll no of record to be deleted
                if (strcmp(com_id , co_id)==0)
                {
                    flag = 1;
                    cout << "The deleted record is \n";

                    // display the record
                    display();
                }
                else
                {
                    // copy the record of "he" file to "temp" file
                    ofs.write((char *)this, sizeof(complain));
                }
            }
        }

        ofs.close();
        ifs.close();
        ofstream ofs1;
        ofs1.open("employee.txt", ios::out | ios::binary);

        ifstream ifs1;
        ifs1.open("temp.txt", ios::in | ios::binary);
        // delete the old file

        while(ifs1)
        {
            if(!ifs1.eof())
            {
                ifs1.read((char *)this , sizeof(complain));
                if(strcmp(com_id,co_id)!=0)
                ofs1.write((char *)this , sizeof(complain));
            }
        }
        // remove("employee.txt");

        // // rename new file to the older file
        // rename("temp.txt", "employee.txt");

        if (flag == 1)
            cout << "\nrecord successfully deleted \n";
        else
            cout << "\nrecord not found \n";
    }
};

void add_user_complain()
{
	cout<<"add complain at user side"<<endl;
	char passcode[12];
	int count = 3;
        while (count)
        {
            cout << "ENTER THE PASSCODE :: ";
            cin >> passcode;

            if (strcmp(passcode, "itsemployee") == 0)
            {
                count=0;
                cout << "You are classified" << endl;
                complain object;
                char again1 = 'y';
                while (toupper(again1) == 'Y')
                {
                    // system("cls");
                        ofstream wrie_to_emp("employee.txt", ios::app | ios::binary);
                        object.update_info();
                        wrie_to_emp.write((char *)&object, sizeof(object));
                        wrie_to_emp.close();
                        
                    cout << "Y FOR CONTUINE\nN FOR END THE SESSION";
                    cin >> again1;
                }
            }
            else
            {
                cout << "WRONG PASSCODE \n ERROR !!!";
                count--;
                if (count <= 0)
                {
                    exit(0);
                }
                else
                {
                    cout << "TRY AGAIN\n";
                    cout << "CHANCE LEFT " << count << endl;
                }
            }
        }
}
void check_user_complain()
{
	cout << "the checing of the complain at user side" << endl;
	char passcode[12];
     int count = 3;
        while (count)
        {
            complain object;
            cout << "ENTER THE PASSCODE :: ";
            cin >> passcode;
            if (strcmp(passcode, "itsemployee") == 0)                         			// admin passwoerd = " itsadmin"
            {
                count=0;
                cout << "You are classified" << endl;
                char again = 'y';
                int counter_object = -1;
                while (toupper(again) == 'Y')
                {
                    counter_object = -1;
                
                        cout << "***************************************************************************************************************************" << endl;
                         char comapiner_id[20];
                        cout << "ID OF COMPLAINER::";
                        cin >> comapiner_id;
                        ifstream read_from_emp("success.txt", ios::binary);
                        read_from_emp.seekg(0);
               
                        while (read_from_emp)
                        {
                            if (!read_from_emp.eof())
                            {
                                read_from_emp.read((char *)&object, sizeof(object));
                           
                                if (strcmp(object.return_id(), comapiner_id) == 0)
                                {
                                	object.display();
                                    cout << "THE COMPLAINT IS SUCCESSFULLY TAKEN CARE BY THE ORGANZATION" << endl;
                                    cout << "THANK YOU FOR YOUR PATIENCE WITH US" << endl;
                                    // cout << "THE SATATUS :: " << object.return_update() << endl;
                                }
                            }
                        }
                        read_from_emp.close();
               }
               cout << "END OF THE OPERATION" << endl;
            }
            else
            {
                cout << "WRONG PASSCODE \n ERROR !!!";
                count--;
                if (count <= 0)
                {
                    exit(0);
                }
                else
                {
                    cout << "TRY AGAIN\n";
                    cout << "CHANCE LEFT " << count << endl;
                }
            }
        }
}
void check_complain_admin()
{
	cout << "the checing of the complain at admin side" << endl;
	char passcode[12];
     int count = 3;
        while (count)
        {
            complain object;
            cout << "ENTER THE PASSCODE :: ";
            cin >> passcode;
            if (strcmp(passcode, "itsadmin") == 0)                         			// admin passwoerd = " itsadmin"
            {
                count=0;
                cout << "You are classified" << endl;
                char again = 'y';
                int counter_object = -1;
                while (toupper(again) == 'Y')
                {
                    counter_object = -1;
                
                        cout << "***************************************************************************************************************************" << endl;
                        ifstream read_from_emp("employee.txt", ios::binary);
                        read_from_emp.seekg(0, ios::beg);
      
                        while (read_from_emp)
                        {
                            if (!read_from_emp.eof())
                            {
                                read_from_emp.read((char *)&object, sizeof(object));
                                object.display();
                                counter_object++;
                            }
                        }
                       cout << endl;
                                if(counter_object==-1)
                            {
                            	cout << "THE RECORD IS NOT FOUND" << endl;
							}
							else
							{
									cout << "THE RECORD IS NOT FOUND" << endl;
								   cout << "THE NUMBER OF COMPLAINS :: " << counter_object << endl;
							}

                        read_from_emp.close();
                        cout << "Y FOR CONTUINE\nN FOR END THE SESSION";
                         cin >> again;
               }
               cout << "END OF THE OPERATION" << endl;
            }
            else
            {
                cout << "WRONG PASSCODE \n ERROR !!!";
                count--;
                if (count <= 0)
                {
                    exit(0);
                }
                else
                {
                    cout << "TRY AGAIN\n";
                    cout << "CHANCE LEFT " << count << endl;
                }
            }
        }
}
void filter_admin_complain()
{
	cout << "filter the complain at the admin side" << endl;
	cout << "the checing of the complain at admin side" << endl;
	char passcode[12];
     int count = 3;
        while (count)
        {
            complain object;
            cout << "ENTER THE PASSCODE :: ";
            cin >> passcode;
            if (strcmp(passcode, "itsadmin") == 0)                         			// admin passwoerd = " itsadmin"
            {
                count=0;
                cout << "You are classified" << endl;
                char again = 'y';
                int counter_object = -1;
                while (toupper(again) == 'Y')
                {
                    counter_object = -1;
                     
                       cout << endl
                             << "THE STATICAL DATA ACCORDING TO USER" << endl;
                        cout << "1.BY NAME\n2.BY DAY\n3.BY MONTH\n4.BY YEAR\n5.BY CATEGORY\n6.BY DEPARTMENT\n";
                        int choose_inner_inner;
                        cout << "OPRATION TO BE PERFORMED" << endl;
                        cin >> choose_inner_inner;
                        ifstream read_from_emp("employee.txt", ios::binary);
                        switch (choose_inner_inner)
                        {
                        case 1:
                        {
                            read_from_emp.seekg(0);
                            char name_search[20];
                            cout << "ENTER THE NAME OF COMPLAINER :: ";
                            cin >> name_search;
            
                            while (read_from_emp)
                            {
                                if (!read_from_emp.eof())
                                {
                                    read_from_emp.read((char *)&object, sizeof(object));
                                    if (strcmp(object.return_name(), name_search) == 0)
                                    {
                                        cout << "FOUND THE COMPLAINT" << endl;
                                        counter_object++;
                                        object.display();
                                    }
                                }
                            }
                            cout << endl;
                                if(counter_object==-1)
                            {
                            	cout << "THE RECORD IS NOT FOUND" << endl;
							}
							else
							{
									cout << "THE RECORD IS NOT FOUND" << endl;
								   cout << "THE NUMBER OF COMPLAINS :: " << counter_object << endl;
							}
                            read_from_emp.close();
                            break;
                        }
                        case 2:
                        {
                            // ifstream read_from_emp("employee.txt", ios::binary);
                            read_from_emp.seekg(0);
                            char day_search[3];
                            cout << "ENTER THE DAY OF THE COMPLAIN FILE :: ";
                            cin >> day_search;
                            char temp_day[2]{0};
          
                            while (read_from_emp)
                            {
                                if (!read_from_emp.eof())
                                {
                                    read_from_emp.read((char *)&object, sizeof(object));
                                    object.return_day(temp_day);
                                    if (strncmp(temp_day, day_search, 2) == 0)
                                    {
                                        cout << "FOUND THE COMPLAINT" << endl;
                                        counter_object++;
                                        object.display();
                                    }
                                }
                            }
                            cout << endl;
                            if(counter_object==-1)
                            {
                            	cout << "THE RECORD IS NOT FOUND" << endl;
							}
							else
							{
									cout << "THE RECORD IS NOT FOUND" << endl;
								   cout << "THE NUMBER OF COMPLAINS :: " << counter_object << endl;
							}
                               
                            read_from_emp.close();
                            break;
                        }
                        case 3:
                        {
                            read_from_emp.seekg(0);
                            char month_search[3];
                            cout << "ENTER THE MONTH OF THE COMPLAIN FILE :: ";
                            cin >> month_search;
                            char temp_month[2]{0};
             
                            while (read_from_emp)
                            {
                                if (!read_from_emp.eof())
                                {
                                    read_from_emp.read((char *)&object, sizeof(object));
                                    object.return_month(temp_month);
                                    if (strncmp(temp_month, month_search, 2) == 0)
                                    {
                                        cout << "FOUND THE COMPLAINT" << endl;
                                        counter_object++;
                                        object.display();
                                    }
                                }
                            }
                            cout << endl;
                                 if(counter_object==-1)
                            {
                            	cout << "THE RECORD IS NOT FOUND" << endl;
							}
							else
							{
									cout << "THE RECORD IS NOT FOUND" << endl;
								   cout << "THE NUMBER OF COMPLAINS :: " << counter_object << endl;
							}
                            read_from_emp.close();
                            break;
                        }
                        case 4:
                        {
                            read_from_emp.seekg(0);
                            char year_search[5];
                            cout << "ENTER THE YEAR OF THE COMPLAIN FILE :: ";
                            cin >> year_search;
                            char temp_year[4]{0};
     
                            while (read_from_emp)
                            {
                                if (!read_from_emp.eof())
                                {
                                    read_from_emp.read((char *)&object, sizeof(object));
                                    object.return_year(temp_year);
                                    if (strncmp(temp_year, year_search, 4) == 0)
                                    {
                                        cout << "FOUND THE COMPLAINT" << endl;
                                        counter_object++;
                                        object.display();
                                    }
                                }
                            }
                            cout << endl;
                                  if(counter_object==-1)
                            {
                            	cout << "THE RECORD IS NOT FOUND" << endl;
							}
							else
							{
									cout << "THE RECORD IS NOT FOUND" << endl;
								   cout << "THE NUMBER OF COMPLAINS :: " << counter_object << endl;
							}
                            read_from_emp.close();
                            break;
                        }
                        case 5:
                        {
                            read_from_emp.seekg(0);
                            char cat_search[20];
                            cout << "ENTER THE CATEGORY OF THE COMPLAIN FILE :: ";
                            cin >> cat_search;
                            char temp_cat[20]{0};
        
                            while (read_from_emp)
                            {
                                if (!read_from_emp.eof())
                                {
                                    read_from_emp.read((char *)&object, sizeof(object));
                                    strcpy(temp_cat, object.return_cat());
                                    if (strcmp(temp_cat, cat_search) == 0)
                                    {
                                        cout << "FOUND THE COMPLAINT" << endl;
                                        counter_object++;
                                        object.display();
                                    }
                                }
                            }
                            cout << endl;
                                 if(counter_object==-1)
                            {
                            	cout << "THE RECORD IS NOT FOUND" << endl;
							}
							else
							{
									cout << "THE RECORD IS NOT FOUND" << endl;
								   cout << "THE NUMBER OF COMPLAINS :: " << counter_object << endl;
							}
                            read_from_emp.close();
                            break;
                        }
                        case 6:
                        {
                            read_from_emp.seekg(0);
                            char depart_search[20];
                            cout << "ENTER THE DEPARTMENT OF THE COMPLAIN FILE :: ";
                            cin >> depart_search;
                            char temp_depart[20]{0};
                 
                            while (read_from_emp)
                            {
                                if (!read_from_emp.eof())
                                {
                                    read_from_emp.read((char *)&object, sizeof(object));
                                    strcpy(temp_depart, object.return_depart());
                                    if (strcmp(temp_depart, depart_search) == 0)
                                    {
                                        cout << "FOUND THE COMPLAINT" << endl;
                                        counter_object++;
                                        object.display();
                                    }
                                }
                            }
                            cout << endl;
                                 if(counter_object==-1)
                            {
                            	cout << "THE RECORD IS NOT FOUND" << endl;
							}
							else
							{
									cout << "THE RECORD IS NOT FOUND" << endl;
								   cout << "THE NUMBER OF COMPLAINS :: " << counter_object << endl;
							}
                            read_from_emp.close();
                            break;
                        }
                        }
                        cout << endl;
                        cout << "Y.CONTUINUE \n N.END OF SESSION" << endl;
                        cin >> again;
               }
               cout << endl;
               cout << "END OF THE OPERATION" << endl;
            }
            else
            {
                cout << "WRONG PASSCODE \n ERROR !!!";
                count--;
                if (count <= 0)
                {
                    exit(0);
                }
                else
                {
                    cout << "TRY AGAIN\n";
                    cout << "CHANCE LEFT " << count << endl;
                }
            }
        }
}
void update_status_complain()
{
	cout << "update the status of the compain at the admin side" << endl;
	complain object;
		cout << "the checing of the complain at admin side" << endl;
	char passcode[12];
     int count = 3;
        while (count)
        {
            complain object;
            cout << "ENTER THE PASSCODE :: ";
            cin >> passcode;
            if (strcmp(passcode, "itsadmin") == 0)                         			// admin passwoerd = " itsadmin"
            {
                count=0;
                cout << "You are classified" << endl;
                char again = 'y';
                int counter_object = -1;
                while (toupper(again) == 'Y')
                {
                    counter_object = -1;
                
                        cout << "***************************************************************************************************************************" << endl;
                       char co_id[7];
                        char compa_id[9];
                        cout << "USER ID :: ";
                        cin >> compa_id;
                        cout << "COMPLAIN ID :: ";
                        cin >> co_id;
                        ifstream read_from_emp("employee.txt", ios::binary);
                        ofstream write_to_success("success.txt", ios::binary | ios::app);
                        read_from_emp.seekg(0);
               
                        while (read_from_emp)
                        {
                            if (!read_from_emp.eof())
                            {
                                read_from_emp.read((char *)&object, sizeof(object));
                                if (strcmp(object.return_id(), compa_id) == 0)
                                {
                                    if (strcmp(object.return_complaier_id(), co_id) == 0)
                                    {
                                        cout << "THE COMPLAINT IS SUCCESFULLY STORE" << endl;
                                        write_to_success.write((char *)&object, sizeof(object));
                                        object.deleteit(co_id);
                                        counter_object++;
                                        
                                        break;
                                    }
                                }
                            }
                        }
                        cout << endl;
                         if(counter_object==-1)
                            {
                            	cout << "THE RECORD IS FOUND" << endl;
                                cout << "THE NUMBER OF COMPLAINS :: " << counter_object << endl;
							}
							else
							{
									cout << "THE RECORD IS  FOUND" << endl;
				
							}
                        read_from_emp.close();
                        write_to_success.close();
                        cout << "Y FOR CONTUINE\nN FOR END THE SESSION";
                         cin >> again;
               }
               cout << "END OF THE OPERATION" << endl;
            }
            else
            {
                cout << "WRONG PASSCODE \n ERROR !!!";
                count--;
                if (count <= 0)
                {
                    exit(0);
                }
                else
                {
                    cout << "TRY AGAIN\n";
                    cout << "CHANCE LEFT " << count << endl;
                }
            }
        }
	                    
}
void check_update_complain()
{
	cout << "the updated complain is checked" << endl;
	cout << "update the status of the compain at the admin side" << endl;
	complain object;
		cout << "the checing of the complain at admin side" << endl;
	char passcode[12];
     int count = 3;
        while (count)
        {
            complain object;
            cout << "ENTER THE PASSCODE :: ";
            cin >> passcode;
            if (strcmp(passcode, "itsadmin") == 0)                         			// admin passwoerd = " itsadmin"
            {
                count=0;
                cout << "You are classified" << endl;
                char again = 'y';
                int counter_object = -1;
                while (toupper(again) == 'Y')
                {
                   ifstream read_from_emp("success.txt", ios::binary);
                        read_from_emp.seekg(0);
            
                        while (read_from_emp)
                        {
                            if (!read_from_emp.eof())
                            {
                                read_from_emp.read((char *)&object, sizeof(object));
                                counter_object++;
                                object.display();
                            }
                        }

                        cout << endl;
                         if(counter_object==-1)
                            {
                            	cout << "THE RECORD IS FOUND" << endl;
                                cout << "THE NUMBER OF COMPLAINS :: " << counter_object << endl;
							}
							else
							{
									cout << "THE RECORD IS  FOUND" << endl;
				
							}
                        read_from_emp.close();
                         cout << "Y FOR CONTUINE\nN FOR END THE SESSION";
                         cin >> again;

               }
               cout << "END OF THE OPERATION" << endl;
            }
            else
            {
                cout << "WRONG PASSCODE \n ERROR !!!";
                count--;
                if (count <= 0)
                {
                    exit(0);
                }
                else
                {
                    cout << "TRY AGAIN\n";
                    cout << "CHANCE LEFT " << count << endl;
                }
            }
        }
	                    
}
void arrow(int color,int pos)
{
	setcolor(color);
	int points[8]={170,190+pos*50,220-10,210+pos*50,170,230+pos*50,170,190+pos*50};
	drawpoly(4,points);
	setfillstyle(SOLID_FILL,color);
	fillpoly(4,points);

}

// menu bar
void menu(int box_color,int text_color)
{

    setcolor(box_color);
    for(int i=0;i<10;i++)
	rectangle(110-i,150-i,580+i,430+i);

    setcolor(text_color);
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,4);
	outtextxy(240,200,"USER");
	outtextxy(240,250,"Admin");
	outtextxy(240,300,"EXIT");
}
void menu2(int box_color,int text_color)
{

     setcolor(box_color);
    for(int i=0;i<10;i++)
	rectangle(110-i,150-i,880+i,430+i);

    setcolor(text_color);
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,4);
	outtextxy(240,200,"ADD COMPLAIN");
	outtextxy(240,250,"STATUS OF COMPLAIN");
	outtextxy(240,300,"EXIT");
}
void menu3(int box_color,int text_color)
{

     setcolor(box_color);
    for(int i=0;i<10;i++)
	rectangle(110-i,150-i,950+i,500+i);

    setcolor(text_color);
	settextstyle(EUROPEAN_FONT,HORIZ_DIR,4);
	outtextxy(240,200,"1.SEE THE COMPLAIN");
	outtextxy(240,250,"2.FILTER THE COMPLAIN");
	outtextxy(240,300,"3.UPDATE THE COMPLAIN");
	outtextxy(240,350,"4.SEE THE UPDATED COMPLAIN");
	outtextxy(240,400,"ESC.EXIT");
}


int mainmenu()
{
	initwindow(700,600,"Game Menu",150,50);
	int arrow_color=14;
   	int box_color=11;
   	int text_color=14;
   	int pos=0;
   	int page=0;
   	arrow(arrow_color, pos);
   	do{
   		setactivepage(page);
   		setvisualpage(1-page);
		cleardevice();
		if (GetAsyncKeyState(VK_DOWN))
        {
        	pos = (pos + 1) % 3;
        }
        else if (GetAsyncKeyState(VK_UP))
        {
            pos = (pos + 2) % 3;
        }
		arrow(arrow_color, pos);
		menu(box_color,text_color);
		delay(250);
		page=1-page;
   		
	}while(!GetAsyncKeyState(VK_SPACE));
	closegraph();
	return pos;
}
int mainmenu2()
{
	initwindow(700,600,"Game Menu",150,50);
	int arrow_color=14;
   	int box_color=11;
   	int text_color=14;
   	int pos=0;
   	int page=0;
   	arrow(arrow_color, pos);
   	do{
   		setactivepage(page);
   		setvisualpage(1-page);
		cleardevice();
		if (GetAsyncKeyState(VK_DOWN))
        {
        	pos = (pos + 1) % 3;
        }
        else if (GetAsyncKeyState(VK_UP))
        {
            pos = (pos + 2) % 3;
        }
		arrow(arrow_color, pos);
		menu2(box_color,text_color);
		delay(250);
		page=1-page;
   		
	}while(!GetAsyncKeyState(VK_SPACE));
	closegraph();
	return pos;
}
int mainmenu3()
{
	initwindow(700,600,"Game Menu",150,50);
	int arrow_color=14;
   	int box_color=11;
   	int text_color=14;
   	int pos=0;
   	int page=0;
   	arrow(arrow_color, pos);
   	do{
   		setactivepage(page);
   		setvisualpage(1-page);
		cleardevice();
		if (GetAsyncKeyState(VK_DOWN))
        {
        	pos = (pos + 1) % 5;
        }
        else if (GetAsyncKeyState(VK_UP))
        {
            pos = (pos + 4) % 5;
        }
		arrow(arrow_color, pos);
		menu3(box_color,text_color);
		delay(250);
		page=1-page;
   		
	}while(!GetAsyncKeyState(VK_SPACE));
	closegraph();
	return pos;
}

int main()
{
	int ch,chb,chc;
 do{
       ch=mainmenu();
   
		switch(ch)
		{
			case 0:
       	     do{
		            chb=mainmenu2();
		            switch(chb)
	 				{
						case 0:
            			add_user_complain();
        	    		break;
        				
						case 1:		
	            		check_user_complain();
    	        		break;
        				
						default:
            			break;
	            	}
                 }while(chb!=2);
             break;
			   
        	case 1:
	           do{
					chc=mainmenu3();
		           	switch(chc)
					{
						case 0:
               			check_complain_admin();//	
        	    		break;
        	
						case 1:
	            		filter_admin_complain();
						break;
						
        				case 2:
	            		update_status_complain();
    	        		break;
    	     
			 			case 3:
	            		check_update_complain();                 
    	        		break;
    	        		
        				default:
            			break;
					}
				}while(chc!=4);
    	    break;
        	
			default:
            	break;
		}
  }while(ch!=2);

	return 0;
}


