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
