#include <bits/stdc++.h>
#include <cstring>
#include <fstream>
using namespace std;

class influencers
{
    char id[5];
    char name[20];
    char email[20];
    float due;

public:
    float gains;
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
        gains = 0;
    }

    void add_influencer(influencers &inf)
    {
        add();
        fstream file;
        file.open("influencers.txt", ios::in | ios::out | ios::ate);
        file.clear();
        file.seekp(0,ios::end);
        file.write((char *)&inf, sizeof(inf));
        file.close();
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

    void max(){
        influencers inf;
        fstream file;
        int i=0;
        vector<float> arr;
        file.open("influencers.txt",ios::in|ios::out|ios::ate);
        file.seekg(0);
        while(file.read((char *)&inf,sizeof(inf))){
            arr.push_back(inf.gains);
        }
        float big=arr[0];            
        float small=arr[0];            
        for(int j=0;j<i;j++){
            for(int k=j+1;k<i;k++){
                if(big<arr[k]){
                    big=arr[k];
                }
                if(small>arr[k]){
                    small=arr[k];
                }
            }
        }
        cout<<big<<" "<<small;
        file.seekg(0);
        while(file.read((char *)&inf,sizeof(inf))){
            if(big == inf.gains){
                inf.show_details();
            }
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
        // takking details of client 
        cout << "Enter client name : ";
        cin >> client_name;
        cout << "Enter package : ";
        cin >> package;

        char *sid;
        bool exists=false;
        int flag= 1;
        cout << "Enter influencer id to add client : ";
        cin >> sid;

        influencers temp_inf;
        fstream file;
        file.open("influencers.txt", ios::in | ios::ate);
        file.seekg(0, ios::beg);
        while (file.read((char *)&temp_inf, sizeof(temp_inf)))
        {
            if (strcmp(sid, temp_inf.ret_inf_id()) == 0 && flag)
            {
                exists = true;
                temp_inf.gains += package;
                flag = 0;
            }
        }
        if (exists)
        {
            // adding client in file 
            ofstream clf("client.txt");
            clf.write((char*)&(*this),sizeof(*this));
            clf.close();
            cout << "Added client " << client_name << " to Influencer : " << temp_inf.ret_inf_name() << endl;

            // modifying influencer
           flag =  file.tellg();
           flag -= sizeof(temp_inf);
           file.seekp(flag,ios::beg);
           file.write((char*)&(temp_inf),sizeof(temp_inf));
        file.close();
        }
        else
        {
            cout << "Wrong influencer credentials.\n";
            cout<<endl<<"client not added "<<endl;
        }
    }
};

int main()
{
    influencers inf;
    clients cli;
    inf.add_influencer(inf);
    inf.show_details();
    return 0;
}