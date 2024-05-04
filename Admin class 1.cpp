class admin :public LMS
{
	private:
		int choice,choice1,a1,x2,choice3,choice4,a4,x3,choice7;
		string data,reg,title;
	public:
	void admin_fun(LMS &lms1)
	{
		x2=lms1.get_student_num();
		x3=lms1.get_teacher_num();
	cout<<"-----------------------------------------"<<endl;	
	cout<<"Press: "<<endl;
	cout<<"1-to Add, remove or update student detail"<<endl;
	cout<<"2-to Check record of all student"<<endl;
	cout<<"3-to Enroll/unenroll student from a course"<<endl;
	cout<<"4-to Add remove or update teacher detail"<<endl;
	cout<<"5-to Check record of all teachers"<<endl;
	cout<<"6-to Check courses alloted to all students"<<endl;
	cout<<"7-to Allocate course to a teacher"<<endl;
	cout<<"8-to Check courses alloted to all teacher"<<endl;
	cout<<"-----------------------------------------"<<endl;
	cin>>choice;
	if(choice==1)
	{   cout<<"----------------------------"<<endl;
	    cout<<"To:"<<endl;
		cout<<"Add detail of student(s) press 1"<<endl;
		cout<<"Remove detail of student press 2"<<endl;
		cout<<"Update detail of student(s) press 3"<<endl;
		cin>>choice1;
		cout<<"----------------------------"<<endl;
		if(choice1==1)
		{
			cout<<"How many students data you want to upload?"<<endl;
			cin>>a1;
			for(int i=0;i<a1;i++)
			{
				cout<<"Enter data for student# "<<i+1<<endl;
				cout<<"Enter Name: "<<endl;
				cin>>data;
				lms1.set_student_data(data,i,0);
				cout<<"Enter Regno: "<<endl;
				cin>>data;
				lms1.set_student_data(data,i,1);
				cout<<"Enter Faculty: "<<endl;
				cin>>data;
				lms1.set_student_data(data,i,2);
				cout<<"Enter contact: "<<endl;
				cin>>data;
				lms1.set_student_data(data,i,3);
				lms1.set_student_data(data,i,-1);
			}
		}
		if(choice1==2)
		{
			cout<<"Enter regno of student to delete his data: "<<endl;
			cin>>reg;
			for(int i=0;i<x2;i++)
			{
				if(lms1.get_student_data(i,1)==reg)
				{
					for(int j=0;j<4;j++)
					{
						lms1.set_student_data1("Data of this student was deleted",i,j);
					}
				}
			}
			cout<<"Data Deleted Sucessfully"<<endl;
		}
		if(choice1==3)
		{
			cout<<"Enter regno to updata data of a student: "<<endl;
			cin>>reg;
			for(int i=0;i<x2;i++)
			{
				if(lms1.get_student_data(i,1)==reg)
				{
					cout<<"Write correct detail"<<endl;
					for(int j=0;j<3;j++)
					{
						cout<<lms1.get_student_data(i,j)<<endl;
						cin>>data;
						lms1.set_student_data1(data,i,j);
					}
				}
			}
		}
		
	}
