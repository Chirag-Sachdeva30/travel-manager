#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
using namespace std;

void menu();

class managemenu
{
protected:
    string username;
public:
    managemenu()
    {
        system("color E6");
        cout<<"\n\n\n\n\n\n\t\t\tEnter your name to continue as an admin\n\n\t\t\t\t\t";
        for(int i=5;i>0;i--)
        {
            cin>>username;
            system("CLS");
            if(username=="chirag")
                {
                    menu();
                    return;
                    }
            else
            cout<<"\n\n\n\n\n\n\t\t\tadmin not detected. "<<i-1<<" trials left\n\n\t\t\t\t\t";
        }
        cout<<"the system has been locked for security reasons\n";
        Sleep(2000);
        system("CLS");
    }

};

class customer
{
public:
    string name;
    long long mobile;
    static int id;

    void getdetails()
    {
        ifstream idfile("idno.txt");
       if(idfile)
       idfile>>id;
       idfile.close();
       ofstream file("idno.txt",ios_base::trunc);
        file<<id+1<<endl;
        file.close();
        cout<<"Your customer id has been generated as: "<<id<<endl;
        getchar();
        cout<<"Enter name : ";
        getline(cin,name);

        cout<<"Enter mobile: ";
        cin>>mobile;

        ofstream outfile("customers.txt",ios_base::app);
        outfile<<id<<" "<<name<<" "<<mobile<<endl;
        outfile.close();

        cout<<"\nSAVED\n";
    }
    void showdetails()
    {
        char all[999];
        ifstream infile("customers.txt");
        if(!infile || infile.eof())
        {
            cout<<"customers base is empty\n";
        }
        while(!infile.eof())
        {
            infile.getline(all,999);
            cout<<all<<endl;
        }
        infile.close();
    }

};

     int customer:: id=1;


class cabs
{
    public:
     int cabchoice;
     int kms;
     float currcost;
     static float finalcost;
    int hirecab;

     void cabdetails()
     {
         cout<<"we colaborated with smartest, safest and fastest cab services around the country\n\n";
         cout<<"\n---------------------Chirag Cabs------------------------\n\n";
         cout<<"1.Rent a standard Cab -> 1$ per mile\n";
         cout<<"2.Rent a Luxury Cab->1.5$ per mile\n\n";

         cout<<"chose your cab : 1<->Standard     2<->Luxury\n";
         cin>>cabchoice ;
         if(cabchoice!=1 && cabchoice!=2)
         {
            cout<<"invalid input! redirecting to previous menu\n";
             Sleep(2000);
             system("CLS");
             menu();
             return;
         }


         cout<<"Enter distance of trip in km\n";
         cin>>kms;

         if(cabchoice==1)
         {
             currcost=kms*1;
         }
         else if(cabchoice==2)
         {
             currcost=kms*1.5;
         }

         cout<<"tour cost is calculated to be: "<<currcost<< "$\n";
         cout<<"press 1 to hire this cab or press 2 to select another cab\n";
         cin>>hirecab;

         system("CLS");
         if(hirecab==1)
         {
             cout<<"Please wait while the booking is taking place........\n";
             Sleep(2000);
             finalcost=currcost;
             if(cabchoice==1)
             cout<<"\n successfully hired a standard cab for "<<kms<<" kms\n";
             else
            cout<<"\nsuccessfully hired a luxury cab for "<<kms<<" kms\n";
             cout<<"\ngo to menu to generate reciept or book a hotel\n";
             cout<<".........press any key to continue\n";
             getch();
             system("CLS");
             menu();
             return ;
         }

         else if(hirecab==2)
         {
             cabdetails();
         }
         else
         {
             cout<<"invalid input! redirecting to previous menu\n";
             Sleep(2000);
             system("CLS");
             cabdetails();
         }
     }
};

float cabs::finalcost=0;

class booking
{
    public:
    int choicehotel;
    int days;
    int bookhotel;
    static int cost;

    void hotels()
    {
        string hotelNo[]={"Avendra","Abhinandan","greentop"};
        int priceNo[]={1000,2000,3000};
        for(int i=0;i<3;i++)
            cout<<i+1<<".  hotel "<<hotelNo[i]<<" price: "<<priceNo[i]<<endl<<endl;

        cout<<"currently we collaborated with above hotels!\n";
        cout<<"Enter hotel no. which you want to book\n";
        cin>>choicehotel;
        system("CLS");
        if(choicehotel==1)
        {
            cout<<"welcome to the Hotel Avendra! the tourist's companion\n";
        }
        else if(choicehotel==2)
        {
            cout<<"greeating and welcomes.....as you are at hotel Abhinandan! \n";
        }
        else if(choicehotel==3)
        {
            cout<<"Wecome to greentop!...the pioneer in the art of hotel innovations\n";
        }
        else
        {
            cout<<"Invalid choice!...redirecting to main menu\n";
            Sleep(2000);
            system("CLS");
            menu();
        }
        cout<<"Enter the no of days of stay\n";
        cin>>days;
        cout<<"total cost of stay is calculated to be "<<days*priceNo[choicehotel-1]<<endl;
        cout<<"press 1 to book the deal , press 2 to book any other hotel\n";
        cin>>bookhotel;

         system("CLS");
         if(bookhotel==1)
         {
             cout<<"Please wait while the booking is taking place........\n";
             Sleep(2000);
             cost=days*priceNo[choicehotel-1];

             cout<<"\nwe have successfully booked hotel "<<hotelNo[choicehotel-1]<< " for "<<days<<" days\n";
             cout<<"\ngo to menu to hire a cab/take the reciept\n";
             cout<<"press any key to continue\n";
             getch();
         }

         else if(bookhotel==2)
         {
             hotels();
         }
         else
         {
             cout<<"invalid input! redirecting to previous menu\n";
             Sleep(2000);
             system("CLS");
             hotels();
         }
         cout<<"redirecting to main menu\n";
             Sleep(2000);
             system("CLS");
             menu();
             return;
    }

};

 int booking::cost=0;

class charges : public customer,cabs,booking
{
    public:
    void printbill()
    {
        ofstream outfile("reciept.txt",ios_base::app);
        outfile<<"----------Chirag Travel Agency----------\n"<<endl;
        outfile<<"   ----------------reciept--------------\n"<<endl;
        outfile<<"Customer ID "<<customer::id<<endl;
        outfile<<"Cab cost : "<<cabs::finalcost<<endl;
        outfile<<"Hotel cost: "<<booking::cost<<endl;
        outfile<<"Total:  "<<cabs::finalcost+ booking::cost<<endl;
        outfile<<"_________________________\n "<<endl;
        outfile<<"Thankyou"<<endl<<endl<<endl;
        outfile.close();
        cabs::finalcost=0;
        booking::cost=0;
    }
    void showbills()
    {
        ifstream infile("reciept.txt");
        char a[999];
        if(!infile)
        {
            cout<<"Error\n\n";
        }
        while(!infile.eof())
        {
            infile.getline(a,999);
            cout<<endl<<a;
        }
        infile.close();
    }
};


void menu()
{

    int mainchoice;
    cout<<"\t\t_______________Chirag Travels Welcomes You onboard_________________\n\n\n";
    cout<<"\t\t\t\t customer management-> press 1\n";
    cout<<"\t\t\t\t Cabs management-> press 2\n";
    cout<<"\t\t\t\t hotel management-> press 3\n";
    cout<<"\t\t\t\t Charges and bills-> press 4\n";
    cout<<"\t\t\t\t Exit-> rest of the keys\n\n\n";
    cout<<"note->make sure to register user details for every booking\n\n\n";

    cout<<"Enter your choice: ";
    fflush(stdin);
    cin>>mainchoice;
    system("CLS");
    customer a2;
    cabs a3;
    booking a4;
    charges a5;
    if (mainchoice==1)
    {
        cout<<"--------------customers----------------\n";
        cout<<"1.Enter new customer\n";
        cout<<"2.See old customers\n";

        cout<<"enter choice: ";
        int choice;
        cin>>choice;
        system("CLS");
        if(choice==1)
        {
            a2.getdetails();
        }
        else if(choice==2)
        {
            a2.showdetails();
              cout<<"\n\npress any key to exit\n";
              getchar();
             getch();
        }
        else
        {
            cout<<"Invalid input! redirecting to menu\n";
            Sleep(2000);
            menu();
        }
    }
    else if (mainchoice==2)
        a3.cabdetails();
    else if(mainchoice==3)
        a4.hotels();
    else if(mainchoice==4)
        {
        cout<<"--------------reciepts----------------\n";
        cout<<"1.generate reciept\n";
        cout<<"2.See old reciepts\n";

        cout<<"enter choice: ";
        int choice;
        cin>>choice;
        system("CLS");
        if(choice==1)
        {
             a5.printbill();
              cout<<"please wait while the reciept is being generated..................\n";
              Sleep(2000);
              system("CLS");
              cout<<"Reciept generated successfully in the billbox\n";
              cout<<"press any key to continue\n";
              getch();
        }
        else if(choice==2)
        {
            a5.showbills();
            cout<<"\n\npress any key to exit\n";
            getch();
        }
        else
        {
            cout<<"Invalid input! redirecting to main\n";
            Sleep(2000);
            menu();
        }
    }
   else
   {
           cout<<"Thankyou for using our services!.........visit again!";
           Sleep(2000);
           system("CLS");
           exit(0);
   }
        cout<<"redirecting to the main menu........\n";
        Sleep(2000);
        system("CLS");
        menu();
}



int main()
 {
    managemenu startObject;
    return 0;
}
