#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;
class pms
{
    char namef[15];
    char namel[15];
    char phone[15];
    public:
    void newc();
    void file();
    void output();
    void display();
    void searchn();
    void searchno();
    void edit();
};
void pms::newc()
{
    cout<<"Enter the First name : ";
    cin>>namef;
    cout<<"Enter the Last name : ";
    cin>>namel;
    cout<<"Enter the mobile number : ";
    cin>>phone;
}
void pms::file()
{
    fstream file;
    file.open("record.dat",ios::out|ios::app|ios::binary);
    file.write((char*)this,sizeof(*this));
    file.close();
}
void pms::output()
{
	cout<<setw(15)<<namef<<" ";
	cout<<setw(15)<<setiosflags(ios::left)<<namel;
	cout<<setw(30)<<setiosflags(ios::right)<<phone<<endl;
}
void pms::display()
{
    fstream fin;
    fin.open("record.dat",ios::in|ios::binary);
    cout<<setw(31)<<"Name of person"<<setw(30)<<"Contact"<<endl;
    while(fin.read((char*)this,sizeof(*this)))
    {
    this->output();
	}
    fin.close();
}
void pms::searchn()
{
	fstream fp;
	char phn[15];
	int ps,i,offset;
	ps=-1,i=0;
	bool flag=false;
	cout<<"Enter the number :";
	cin>>phn;
	fp.open("record.dat",ios::in|ios::binary);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)this,sizeof(*this)))
	{
    if(strcmp(this->phone,phn)==0)
    {
    	ps=i;
    	flag=true;
    	break;
	}
	i++;
	}
	if(flag)
	{
		offset=ps*sizeof(*this);
		fp.seekp(offset);
		fp.read((char*)this,sizeof(*this));
		cout<<"Contact found !! \n"<<"The name is "<<this->namef<<" "<<this->namel<<"\n";
	}
	else
	cout<<"No contact found. \n";
	fp.close();
}
void pms::searchno()
{
	fstream fp;
	char n1[15];
	char n2[15];
	int ps,i,offset;
	ps=-1,i=0;
	int flag=0;
	cout<<"Enter the first name :";
	cin>>n1;
	cout<<"Enter the last name :";
	cin>>n2;
	fp.open("record.dat",ios::in|ios::binary);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)this,sizeof(*this)))
	{
    if(strcmp(this->namef,n1)==0&&strcmp(this->namel,n2)==0) 
    {
    	ps=i;
    	flag=1;
    	break;
	}
	i++;
	}
	if(flag)
	{
		offset=ps*sizeof(*this);
		fp.seekp(offset);
		fp.read((char*)this,sizeof(*this));
		cout<<"Contact found !! \n The number is "<<this->phone<<"\n";
	}
	else
	cout<<"No contact found. \n";
	fp.close();	
}
void pms::edit()
{
	fstream fp;
	char phn[15],f1[15],f2[15],p1[15];
	int ps,i,offset,choice;
	ps=-1,i=0;
	bool flag=false;
	cout<<"Enter the number of conatct to edit :";
	cin>>phn;
	fp.open("record.dat",ios::in|ios::out|ios::ate|ios::binary);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)this,sizeof(*this)))
	{
    if(strcmp(this->phone,phn)==0)
    {
    	ps=i;
    	flag=true;
    	break;
	}
	i++;
	}
	cout<<"\n Press 1 to edit contact name \n";
	cout<<"\n Press 2 to edit contact number \n";
	cin>>choice;
	if(flag)
	{
		offset=ps*sizeof(*this);
		fp.seekp(offset);
		if(choice==1)
		{
			cout<<"\n Enter updated name : ";
			cout<<"\n Enter first name : ";
			cin>>f1;
			cout<<"\n Enter last name : ";
			cin>>f2;
			strcpy(this->namef,f1);
			fp.write((char*)this,sizeof(*this))<<flush;
			strcpy(this->namel,f2);
			fp.write((char*)this,sizeof(*this))<<flush;
		}
		if(choice==2)
		{
			cout<<"\n Enter updated number : ";
			cin>>p1;
			strcpy(this->phone,p1);
			fp.write((char*)this,sizeof(*this))<<flush;
			
		}
		cout<<"Contact edited !! \n";
	}
	else
	cout<<"No contact found. \n";
	fp.close();
}
int main()
{
	pms p;
	int c;
	cout<<"\n \n \n";
		cout<<setw(40)<<"Phonebook Management system";
		cout<<endl<<endl<<endl;
	while(1)
	{
		cout<<setw(10)<<"\n Menu \n";
		cout<<"\n \n";
		cout<<"****************************";
		cout<<"\n \n";
		cout<<"1. Save contact \n";
		cout<<"2. Read contact \n";
		cout<<"3. Search contact name \n";
		cout<<"4. Search contact number \n";
		cout<<"5. Edit contact \n";
		cout<<"6. Exit \n";
		cout<<"\n \n";
		cout<<"Enter your choice : ";
		cin>>c;
		switch(c)
		{
			case 1:
				p.newc();
				p.file();
				break;
			case 2:	
				p.display();
				break;
			case 3:
				p.searchn();
				p.file();
				break;
			case 4:
				p.searchno();
				break;
			case 5:
				p.edit();
				break;
			case 6:
			exit(0);
			break;
			default:
			cout<<"Invalid choice."; 	
		}
	}
}

