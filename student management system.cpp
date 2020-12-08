    #include<iostream>
    #include<fstream>
    #include<iomanip>
     
    using namespace std;
     
     
     
    class student
    {
    	int idnum;
    	char name[50];
    	int ITSE, DLD, PF, CS, LA;
    	double per;
    	char marks;
    	void calculate();	
    public:
    	void getdata();		
    	void showdata() const;	
    	void show_tabular() const;
    	int getIDNum() const;
    }; 
     
     
    void student::calculate()
    {
    	per=((ITSE+DLD+PF+CS+LA)*100)/500;
    	if(per>=90)
    		marks='A+';
    	else if(per>=80)
    		marks='A';
    	else if(per>=75)
    		marks='A-';
    	else if(per>=70)
    		marks='B+';
    	else if(per>=65)
    		marks='B';
    	else if(per>=60)
    		marks='B-';
    	else if(per>=55)
    		marks='C+';
    	else if(per>=50)
    		marks='C';
    	else
    		marks='F';
    }
     
    void student::getdata()
    {
    	cout<<"\nEnter The ID number of the student ";
    	cin>>idnum;
    	cout<<"\n\nEnter student's Name: ";
    	cin.ignore();
    	cin.getline(name,50);
    	cout<<"\nEnter student's ITSE marks: ";
    	cin>>ITSE;
    	cout<<"\nEnter student's DLD marks: ";
    	cin>>DLD;
    	cout<<"\nEnter student's PF marks: ";
    	cin>>PF;
    	cout<<"\nEnter student's CS marks: ";
    	cin>>CS;
    	cout<<"\nEnter student's LA marks: ";
    	cin>>LA;
    	calculate();
    }
     
    void student::showdata() const
    {
    	cout<<"\nID Number: "<<idnum;
    	cout<<"\nName: "<<name;
    	cout<<"\nITSE: "<<ITSE;
    	cout<<"\nDLD: "<<DLD;
    	cout<<"\nPF: "<<PF;
    	cout<<"\nCS: "<<CS;
    	cout<<"\nComputer Science: "<<LA;
    	cout<<"\nPercentage: "<<per;
    	cout<<"\n Grade: "<<marks;
    }
     
    void student::show_tabular() const
    {
    	cout<<idnum<<setw(6)<<" "<<name<<setw(10)<<ITSE<<setw(4)<<DLD<<setw(4)<<PF<<setw(4)
    		<<CS<<setw(4)<<LA<<setw(8)<<per<<setw(6)<<marks<<endl;
    }
     
    int  student::getIDNum() const
    {
    	return idnum;
    }
 
     
     
     
    void write_student()
    {
    	student st;
    	ofstream outFile;
    	outFile.open("student.dat",ios::binary|ios::app);
    	st.getdata();
    	outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
    	outFile.close();
        	cout<<"\n\nStudent record Has Been Created ";
    	cin.ignore();
    	cin.get();
    }
     
     
     
    void display_all()
    {
    	student st;
    	ifstream inFile;
    	inFile.open("student.dat",ios::binary);
    	if(!inFile)
    	{
    		cout<<"File could not be open !! Press any Key...";
    		cin.ignore();
    		cin.get();
    		return;
    	}
    	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
    	{
    		st.showdata();
    		cout<<"\n\n====================================\n";
    	}
    	inFile.close();
    	cin.ignore();
    	cin.get();
    }
     
     
     
    void display_sp(int n)
    {
    	student st;
    	ifstream inFile;
    	inFile.open("student.dat",ios::binary);
    	if(!inFile)
    	{
    		cout<<"File could not be open !! Press any Key...";
    		cin.ignore();
    		cin.get();
    		return;
    	}
    	bool flag=false;
    	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
    	{
    		if(st.getIDNum()==n)
    		{
    	  		 st.showdata();
    			 flag=true;
    		}
    	}
    	inFile.close();
    	if(flag==false)
    		cout<<"\n\nrecord not exist";
    	cin.ignore();
    	cin.get();
    }
     
     
  
     
     
    void delete_student(int n)
    {
    	student st;
    	ifstream inFile;
    	inFile.open("student.dat",ios::binary);
    	if(!inFile)
    	{
    		cout<<"File could not be open !! Press any Key...";
    		cin.ignore();
    		cin.get();
    		return;
    	}
    	ofstream outFile;
    	outFile.open("Temp.dat",ios::out);
    	inFile.seekg(0,ios::beg);
    	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
    	{
    		if(st.getIDNum()!=n)
    		{
    			outFile.write(reinterpret_cast<char *> (&st), sizeof(student));
    		}
    	}
    	outFile.close();
    	inFile.close();
    	remove("student.dat");
    	rename("Temp.dat","student.dat");
    	cout<<"\n\n\tRecord Deleted ..";
    	cin.ignore();
    	cin.get();
    }
     
     
    void class_result()
    {
    	student st;
    	ifstream inFile;
    	inFile.open("student.dat",ios::binary);
    	if(!inFile)
    	{
    		cout<<"File could not be open !! Press any Key...";
    		cin.ignore();
    		cin.get();
    		return;
    	}
    	cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
    	cout<<"==========================================================\n";
    	cout<<"R.No       Name        P   C   M   E   CS   %age   marks"<<endl;
    	cout<<"==========================================================\n";
    	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(student)))
    	{
    		st.show_tabular();
    	}
    	cin.ignore();
    	cin.get();
    	inFile.close();
    }
     
     
     
     
    int main()
    {
    	char ch;
    	int num;
    	cout.setf(ios::fixed|ios::showpoint);
    	cout<<setprecision(2); 
    	do
    	{
    	system("cls");
    	cout<<"\t-------------------------------------------";
    	cout<<"\n\n\t1.CREATE STUDENT RECORD";
    	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
    	cout<<"\n\n\t3.SEARCH STUDENT RECORD ";
    	cout<<"\n\n\t4.DELETE STUDENT RECORD";
    	cout<<"\n\n\t5. DISPLAY CLASS RESULT";
    	cout<<"\n\n\t6. EXIT";
    	cout<<"\n\n\t---------------------------------------";
    	cout<<"\n\n\tPlease Enter Your Choice (1-6): ";
    	cin>>ch;
    	system("cls");
    	switch(ch)
    	{
    	case '1':	write_student(); break;
    	case '2':	display_all(); break;
    	case '3':	cout<<"\n\n\tPlease Enter Student's ID number: "; cin>>num;
    				display_sp(num); break;
    
    	case '4':	cout<<"\n\n\tPlease Enter Student's ID number: "; cin>>num;
    			delete_student(num);break;
    	case '5' :	class_result(); break;
    	case '6':	exit(0);
    	default:	cout<<"\a"; 
    		
        }
    	}while(ch!='6');
     
    	return 0;
    }
