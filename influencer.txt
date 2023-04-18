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

int main()
{
    influencers inf;
    clients cli;
    fstream file;
    file.open("influencers.txt", ios::in | ios::out | ios::ate);
    file.clear();
    file.seekp(0, ios::end);
    inf.add_influencer();
    file.write((char *)&inf, sizeof(inf));
    file.close();
    inf.search_influencer();
    inf.show_details();
    return 0;
}