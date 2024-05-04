class student :public teacher,public LMS,public admin
{
	private:
		int x2,choice,choice2;
		string name,regno,course;
	public:
	void student_fun(LMS &lms1)
	{
	x2=lms1.get_student_num();
	cout<<"Enter your name: "<<endl;
	cin>>name;
	cout<<"Enter your regno: "<<endl;
	cin>>regno;
	for(int i=0;i<x2;i++)
	{
		if(name==lms1.get_student_data(i,0)&&regno==lms1.get_student_data(i,1))
		{   cout<<"-------------------------------"<<endl;
			cout<<"Press: "<<endl;
			cout<<"1 to Check personal details"<<endl;
			cout<<"2 to Enroll in available courses"<<endl;
			cout<<"3 to View obtained marks"<<endl;
			cout<<"4 to View list of teachers"<<endl;
			cin>>choice;
			cout<<"--------------------------------"<<endl;
			system("CLS");
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
		cout<<"####Warning!Enter correct name and regno####"<<endl;
	}
	}
};
	
int main(){
	LMS lms1;
	char choice;
do
{
	int user;
	admin admin1;
	teacher teacher1;
	student student1;
	cout<<"Who are you?"<<endl; 
	cout<<"1 for admin"<<endl; 
	cout<<"2 for teacher"<<endl; 
	cout<<"3 for student"<<endl;
	cout<<"---Enter one---"<<endl;  
	cin>>user;
	system("CLS");
	if(user==1)
	{
		teacher1.admin_fun(lms1);
	}
	if(user==2)
	{
		student1.teacher_fun(lms1);
	}
	if(user==3)
	{
		student1.student_fun(lms1);
	}
	cout<<"Do you want to continue(y/n)?"<<endl;
	cin>>choice;
}while(choice!='n'&&choice!='N');

	return 0;
}
