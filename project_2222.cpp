class teacher
{
	private:
		int choice, x2,x3;
		string name,d,regno;
	public:
	void teacher_fun(lms &lms1)
	{
	x2=lms1.get_teacher_num();
	x3=lms1.get_student_num();
	cout<<"Enter your name: "<<endl;
	cin>>name;
	for(int q=0;q<x2;q++)
	{
		if(lms1.get_teacher_data(q,0)==name)
		{
			cout<<"Press: "<<endl;
			cout<<"1 to check personal detail"<<endl;
			cout<<"2 to check allocated courses"<<endl;
			cout<<"3 to view enrolled students in each course"<<endl;
			cout<<"4 assign marks to students"<<endl;
			cin>>choice;
			if(choice==1)
			{
				for(int i=0;i<3;i++)
				{
					cout<<lms1.get_teacher_data(q,i)<<endl;
				}
			}
			if(choice==2)
			{
				for(int i=0;i<3;i++)
				{
					cout<<lms1.get_teacher_course(q,i)<<endl;
				}
			}
			if(choice==3)
			{
				for(int i=0;i<3;i++)
				{
					d=lms1.get_teacher_course(q,i);
					for(int j=0;j<5;j++)
					{
						for(int k=0;k<5;k++)
						{
							if(d==lms1.get_student_course(j,k))
							{
								cout<<lms1.get_student_data(j,0)<<"---"<<lms1.get_student_data(j,1)<<"---"<<lms1.get_student_course(j,k)<<endl;
							}
						}
					}
				}
			}
			if(choice==4)
			{
				cout<<"Enter regno of student to save his marks: "<<endl;
				cin>>regno;
				for(int i=0;i<x3;i++)
				{
					if(lms1.get_student_data(i,1)==regno)
					{
						string marks;
						cout<<"Enter marks: "<<endl;
						cin>>marks;
						lms1.set_student_data1(marks,i,4);
					}
				}
			}
		}
		choice=-1;
	}
	if(choice!=-1)
		{
			cout<<"Incorect name!";
		}
	}
};
class student
{
	private:
		int x2,choice,choice2;
		string name,regno,course;
	public:
	void student_fun(lms &lms1)
	{
	x2=lms1.get_student_num();
	cout<<"Enter your name: "<<endl;
	cin>>name;
	cout<<"Enter your regno: "<<endl;
	cin>>regno;
	for(int i=0;i<x2;i++)
	{
		if(name==lms1.get_student_data(i,0)&&regno==lms1.get_student_data(i,1))
		{
			cout<<"Press: "<<endl;
			cout<<"1 to Check personal details"<<endl;
			cout<<"2 to Enroll in available courses"<<endl;
			cout<<"3 to View obtained marks"<<endl;
			cout<<"4 to View list of teachers"<<endl;
			cin>>choice;
			if(choice==1)
			{
				for(int j=0;j<x2;j++)
				{
					cout<<lms1.get_student_data(i,j)<<endl;
				}
			}
			if(choice==2)
			{
				cout<<"Press: "<<endl;
				cout<<"1 to enroll in courses"<<endl;
				cout<<"2 to replace a course"<<endl;
				cin>>choice2;
				if(choice2==1)
				{
					for(int j=0;j<5;j++)
					{
						cout<<"Enter course# "<<j+1<<endl;
						cin>>course;
						lms1.set_student_course(course,i,j);
					}
				}
				if(choice2==2)
				{
					cout<<"Your current corses are: "<<endl;
					for(int j=0;j<5;j++)
					{
						cout<<lms1.get_student_course(i,j)<<endl;
					}
					cout<<"Enter course you want to replace: "<<endl;
					cin>>course;
					for(int j=0;j<5;j++)
					{
						if(course==lms1.get_student_course(i,j))
						{
							cout<<"Enter new course title: "<<endl;
							cin>>course;
							lms1.set_student_course(course,i,j);
						}
					}
				}
			}
			if(choice==3)
			{
				cout<<"Obtained Marks by "<<lms1.get_student_data(i,0)<<" are: "<<lms1.get_student_data(i,4)<<endl;
			}
			if(choice==4)
			{
				for(int j=0;j<5;j++)
				{
					for(int k=0;k<3;k++)
					{
						for(int l=0;l<3;l++)
						{
							if(lms1.get_student_course(i,j)==lms1.get_teacher_course(k,l))
							{
								cout<<lms1.get_student_course(i,j)<<"---"<<lms1.get_teacher_data(k,0)<<endl;
							}
						}
					}
				}
			}
			x2=-1;
		}
	}
	if(x2!=-1)
	{
		cout<<"Enter correct name and regno"<<endl;
	}
	}
};

