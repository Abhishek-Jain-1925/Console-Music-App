#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;

struct node 
{
    struct node* prev;
    string SongName;
    string Artist;
    struct node* next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE head)
{
    string SongName;
    string artist;
    
     cout<<"\n Enter Name of Song (Press $ to Complete): ";
     getline(cin,SongName,'$');
     cout<<"\n Enter Name of Singer (Press $ to Complete): ";
     getline(cin,artist,'$');
    
    
    PNODE temp = *head;
    PNODE newn = NULL;
    newn =(PNODE) malloc(sizeof(NODE));
    newn->prev = NULL;
    newn->SongName = SongName;
    newn->Artist = artist;
    newn->next = NULL;
    
    if(*head == NULL)
    {
        *head = newn;
        newn->next = newn;
        newn->prev = newn;
        cout<<"\n\n * First Song is Inserted as : "<<newn->SongName<<endl;
    }
    else
    {
        //cout<<"Inside else blk";
        while(temp->next != *head)
        {
            temp=temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
        newn->next = *head;
        *head = newn;
        cout<<"\n\n * First Song is Inserted as : "<<newn->SongName<<endl;
        //cout<<"Song Inserted At First";
    }
}

void InsertLast(PPNODE head)
{
    string songName;
    string artist;

    cout<<"\n Enter Name of Song (Press $ to Complete): ";
     getline(cin,songName,'$');
     cout<<"\n Enter Name of Singer (Press $ to Complete): ";
     getline(cin,artist,'$');

    PNODE temp = *head;
    PNODE first = *head;
    PNODE newn = NULL;
    newn = (PNODE) malloc(sizeof(NODE));
    newn->prev=NULL;
    newn->SongName = songName;
    newn->Artist = artist;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = newn;
        newn->prev = newn;
        newn->next = newn;
    }
    else
    {
        while(temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
        newn->next = first;
        first->prev = newn;
        cout<<"\n\n * Song Inserted with Name : "<<newn->SongName<<endl;
    }
}

void InsertAtPos(PPNODE head)
{
    int pos=0,cnt=1;
    string songName;
    string artist;

    cout<<"\n Enter Name of Song (Press $ to Complete): ";
     getline(cin,songName,'$');
     cout<<"\n Enter Name of Singer (Press $ to Complete): ";
     getline(cin,artist,'$');

    PNODE newn = NULL;
    PNODE temp=*head, prev=NULL;
    newn = (PNODE) malloc(sizeof(NODE));
    newn->prev = NULL;
    newn->SongName = songName;
    newn->Artist = artist;
    newn->next = NULL;

    if(*head == NULL)
    {
        *head = newn;
        newn->next = newn;
        newn->prev = newn;
    }
    else
    {
        cout<<"\nEnter Position at Which You Want To Add New Song : ";
        cin>>pos;
        if(pos==1)
        {

        }
        else
        {
            while(cnt != pos)
            {
                prev = temp;
                temp=temp->next;
                cnt++;
            }
            prev->next = newn;
            newn->prev = prev;
            newn->next = temp;
            temp->prev = newn;
            cout<<"\n\n * Song Inserted with Name : "<<newn->SongName<<endl;
        }
    }
}

void DeleteAtPos(PPNODE head)
{
    int pos=0,cnt=1;
    PNODE prev = NULL;
    PNODE temp = *head;
    PNODE ptr = NULL;
    if(*head == NULL)
    {
        cout<<"\nPlaylist is Empty...Nothing To Delete..!!";
    }
    else
    {
        cout<<"It Seems You are not Happy with Song List---What Happened..??"<<endl;
        cout<<"\n Enter Song Position to Delete : "<<endl;
        cin>>pos;
        while(cnt != pos)
        {
            prev = temp;
            temp = temp->next;
            cnt++;
        }
        prev->next = temp->next;
        temp->next->prev = prev;
        free(temp);
        cout<<"\n Song Removed From Playlist..!!"<<endl;
    }
}

void Display(PNODE head)
{
    PNODE temp = head;
    if(head == NULL)
    {
        cout<<"\n** Ooopss...Nothing in Playlist...!! **"<<endl<<endl;
    }
    else
    {
        cout<<endl;
        cout<<"\n** Displaying Playlist ** \n";
        while(temp->next != head)
        {
            cout<<"------------------------------"<<endl;
            cout<<"Song : "<<temp->SongName<<endl;
            cout<<"Artist : "<<temp->Artist<<endl;
            temp = temp->next;
        }
        cout<<"------------------------------"<<endl;
        cout<<"Song : "<<temp->SongName<<endl;
        cout<<"Artist : "<<temp->Artist<<endl;
        cout<<"------------------------------"<<endl;
    }
}

void letsRock(PNODE head)
{
    PNODE temp=head;
    int no=0,cnt=1,ch=0;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"----- SHA Music World WelComes You In UNISPAB Era..!!-----"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"\nEnter Song Number To Play : ";
    cin>>no;
    while(cnt!=no)
    {
        temp=temp->next;
        cnt++;
    }
     cout<<"Now Playing..."<<temp->SongName<<endl;
    do{
    cout<<"----------------"<<endl;
    cout<<"1.Prev <<"<<endl;
    cout<<"2. | Pause |"<<endl;
    cout<<"3.Next >>"<<endl;
    cout<<"4.Exit from Song Playing Menu"<<endl;
    cout<<"----------------"<<endl;
    cout<<"Enter Your Choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
            temp=temp->prev;
            cout<<"\n Now Playing...."<<temp->SongName<<endl;
            break;
        case 2:
            cout<<"PAUSED - "<<temp->SongName<<endl;
            break;
        case 3:
            temp=temp->next;
            cout<<"\n Now Playing..."<<temp->SongName<<endl;
            break;
        case 4:
            break;
        default:
            cout<<"\n * Invalid Case...Plz Try Again...!!"<<endl;
    }
    }while(ch!=4);
}

int main()
{
    int ch =0;
    PNODE First=NULL;

    while(ch != 7){
    cout<<"------------------------------"<<endl;
    cout<<"- Welcome In SHA Music World -"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"1.Display Playlist"<<endl;
    cout<<"2.Insert Song at First in Your Playlist"<<endl;
    cout<<"3.Insert Song at Last in Your Playlist"<<endl;
    cout<<"4.Insert Song at Specified Position"<<endl;
    cout<<"5.Remove Song from Playlist"<<endl;
    cout<<"6.let's Rock...Listen To Playlist"<<endl;
    cout<<"7.Quit Music App"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"Enter Your Choice : "<<endl;
    cin>>ch;

    switch(ch)
    {
        case 1:
                Display(First);
                break;
        case 2:
                InsertFirst(&First);
                break;
        case 3:
                InsertLast(&First);
                break;
        case 4:
                InsertAtPos(&First);
                break;
        case 5:
                DeleteAtPos(&First);
                break;
        case 6:
                letsRock(First);
                break;
        case 7:
                return 0;
                break;
        default:
                cout<<"* Plz...Enter Valid Choice..!! *"<<endl;
                break;
    }
    }
}