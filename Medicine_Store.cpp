#include <iostream>

#define max 1000

using namespace std;

int flag ; 

class store 
{
    public:
        string name;
        string code;
        int exp;
        int Price;
};
 
int num;
void showMenu();
store med[max];

void display()
{
    if (num==0)
    {
        cout<<"\n---NO MEDICINES PRESENT---"<<endl ;
    }
    else
    {
        cout<<"\n Following Entries are present:"<<endl ;
        for (int k = 0; k < num; k++)
        {
            cout<<"\n Name: "<<med[k].name<<endl ;
            cout<<" Medicine Code: "<<med[k].code<<endl ;
            cout<<" Quantity: "<<med[k].exp<<endl ;
            cout<<" Price: "<<med[k].Price<<endl ;
        }
    }
}

void medID()
{
    cout << " Medicine Code: ";
    cin >> med[num].code;
    
    for (int i = 0; i < num; i++)
    {
        if (med[num].code==med[i].code)
        {
            cout<<" This Medicine Code already exists\n\nPress 1 to re-enter a new one."<<endl ;
            cout<<" Type 0 to go back to menu "<<endl ;
            int q ;
            cin>>q ;
            switch (q)
            {
            case 0:
                flag = 1 ;
                break ;
            
            default:
                medID() ;
                break;
            }
        }   
    }            
}

void insert()
{
    if (num < max) 
    {
        int n;
        cout << "\n Enter the number of enteries required: ";
        cin >> n;
        int f=0 ;
        
        if(num+n<=max)
        {
            for (int i=0;i < n; i++)
            {
                cout << "\n Enter the information of the Medicine\n";

                medID() ;

                if(flag == 1)
                {
                    flag = 0 ;
                    break ;             
                }

                cout << " Name: ";
                cin >> med[num].name;
    
                cout << " Quantity: ";
                cin >> med[num].exp;
    
                cout << " Price: ";
                cin >> med[num].Price;

                num++ ;
            }
        }
        else
        {
            cout << "\n We have only "<<max-num<<" entries left"<<endl ;
            insert() ;
        }
        
    }

    else 
    {
        cout << "\n---No More Entries Possible---\n";     
    }
    display() ;
    
}

void deleteIndex(int i)
{
    for (int j = i; j < num - 1; j++) 
    {
        med[j].name = med[j + 1].name;
        med[j].code = med[j + 1].code;
        med[j].exp = med[j + 1].exp;
        med[j].Price = med[j + 1].Price;
    }
    return;
}

void deleteRecord()
{
    if(num!=0)
    {
        cout << " Enter the Medicine Code to Delete Record: ";
    
        string code;
        cin >> code;

        for (int i = 0; i < num; i++) 
        {
            if (med[i].code == code) 
            {
                deleteIndex(i);
                num--;
                break;
            }
        }
    }
    display() ;
     
}
 
void searchRecord()
{
    int f=0 ;
    if (num==0)
    {
        cout<<"\n---NO MEDICINES PRESENT---"<<endl ;
    }
    
    else
    {
        cout << " Enter the Medicine Code to Search Record: " ;

        string code;
        cin >> code;
        for (int i = 0; i < num; i++) 
        {
            if (med[i].code == code) 
            {
                cout << "\n Name: "<< med[i].name <<endl;
                cout << " Medicine Code: "<<med[i].code <<endl;
                cout << " Quantity: "<< med[i].exp <<endl;
                cout << " Price: "<< med[i].Price <<endl;
                f=1 ;
                break;
            }

        }
        if (f==0)
        {
            cout<<"\n---NO SUCH ENTRY---"<<endl ;
        }
    }
}

void modify()
{
    if(num!=0)
    {
        cout << " Enter the Medicine Code to Modify: " ;
    
        string code;
        cin >> code;

        int f = 0 ;

        for (int i = 0; i < num; i++) 
        {
            if (med[i].code == code) 
            {
                cout << "\n Current Name: "<< med[i].name <<endl ;
                cout<< " Enter new name: " ;
                cin>> med[i].name ;
    
                cout << "\n Medicine Code: "<<med[i].code <<endl ;
    
                cout << "\n Current Quantity: "<< med[i].exp <<endl;
                cout<< " Enter Updated Quantity: " ;
                cin>> med[i].exp ;
    
                cout << "\n Price: "<< med[i].Price <<endl;

                f=1 ;
                break;
            }

        }
        if(f==0)
        {
            cout<<"\n---NO SUCH ENTRY---\n" ;
        }
    }
    display();
}

void showMenu()
{
    cout << "\n ------------------------\n"
         << "   MEDICAL STORE"
         << "\n ------------------------\n\n";
 
    cout << " Available Options:\n\n";
    cout << " Display - - - - - - (1)\n";
    cout << " Insert New Entries--(2)\n";
    cout << " Delete Entry - - - -(3)\n";
    cout << " Search a Record - - (4)\n";
    cout << " Modify a Record - - (5)\n";
    cout << " Exit - - - - - - - -(6)\n\n\n";
    cout << " Enter you choice here: "  ;
 
    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        display() ;
        break;
    
    case 2:
        insert() ;
        break;
    
    case 3:
        deleteRecord() ;
        break;

    case 4:
        searchRecord() ;
        break;
    
    case 5:
        modify() ;
        break ;
    
    case 6 :
        exit(1) ;
        break ;

    default:
        cout<<"\n Expected options are 1/2/3/4/5/6"<<endl ;
        break ;
    }
}

int main()
{
    while (1)
    {
        showMenu() ;    
    }
 
    return 0;
}