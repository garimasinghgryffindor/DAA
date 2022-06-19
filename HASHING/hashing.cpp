//HASHING  &&  COLLSION HANDLING USING CHAINING

#include <iostream>
#include <vector>
#define MAX 10
using namespace std;

typedef struct node{
    string name;
    int age;
    struct node * next;
}person;

void initialize_person(vector<person*>&people)
{
    for(int i=0 ; i<MAX ; i++)
    {
        people[i]=NULL;
    }
}

int hash_value(string x)
{
    int len = x.length();
    return len%MAX;
}

bool insert(vector<person*>&people , person * pr)
{
    if(pr==NULL)
        return false;

    int index = hash_value(pr->name);
    person * temp = people[index];
    pr->next = temp;
    people[index] = pr;

    return true;
}

person* lookup(vector<person*> people, string name)
{
    int index = hash_value(name) , f=0;

    person* temp = people[index];
    if(temp==NULL)
        return NULL;
    
    while(1)
    {
        if(temp==NULL)
            return NULL;
        if(name!=temp->name)
            temp = temp->next;
        if(name==temp->name)
            return temp;
    }


    return NULL;
}

person* delete1(vector<person*> &people, string name)
{
    person * temp2 = lookup(people,name);
    if(temp2==NULL)
    {
        cout<<"The record does not exist\n";
        return NULL;
    }

    int index = hash_value(name);
    person * ptr = people[index];

    if(ptr==NULL)
        return NULL;
    
    if(ptr->name==name)
    {
        people[index] = ptr->next;
        delete ptr;  
        cout<<"The record has been deleted!\n" <<ptr->next<<endl; 
        return ptr;
    }

    while(1)
    {
        if(ptr==NULL)
            return NULL;
        if(ptr->next==NULL)
            return NULL;
        if(ptr->next->name!=name)
        {
            ptr=ptr->next;
        }
        else
            break;
    }

    if(ptr->next->name==name)
    {
        person * temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
        temp=NULL;
        cout<<"The record has been deleted!\n";
    }
    return NULL;
}

void print_table(vector <person*>people)
{
    for(int i=0 ; i<MAX ; i++)
    {
        person * temp = people[i];

        while(temp!=NULL)
        {
            cout<<"Name:  "<<temp->name<<"    ,    Age:  "<<temp->age<<"    ,    index:  "<<i<<endl;
            temp=temp->next;
        }
    }
}

int main()
{
    int n , y;
    string x;
    cout<<"Enter the number of person:  ";
    cin>>n;

    vector < person *> people(MAX);

    initialize_person(people);

    for(int i=0 ; i<n ; i++)
    {
        cout<<"Enter the name of person:  ";
        cin>>x;
        cout<<"Enter the age of the person:  ";
        cin>>y;
        person *pr;
        pr = new person();
        pr->name=x;
        pr->age=y;
        pr->next=NULL;

        insert(people,pr);
    }

    print_table(people);

    cout<<"Enter the name which you are looking for:  ";
    cin>>x;

    person * ptr = lookup(people,x);
    if(ptr==NULL)  
    {
        cout<<"The record does not exist!"<<endl;
    }
    else
    {
        cout<<"Name:  "<<ptr->name<<"    ,    Age:  "<<ptr->age<<endl;
    }

    cout<<"Enter the name the record of which you want to delete:  ";
    cin>>x;

    ptr = delete1(people,x);

    cout<<endl;
    print_table(people);

    return 0;
}