class teacher :public LMS,public admin
{
	private:
		int choice, x2,x3;
		string name,d,regno;
	public:
	void teacher_fun(LMS &lms1)
	{
	x2=lms1.get_teacher_num();
	x3=lms1.get_student_num();
	cout<<"Enter your name: "<<endl;
	cin>>name;
	for(int q=0;q<x2;q++)
	{
		if(lms1.get_teacher_data(q,0)==name)
		{   cout<<"-----------------------------------------"<<endl;
			cout<<"Press: "<<endl;
			cout<<"1 to check personal detail"<<endl;
			cout<<"2 to check allocated courses"<<endl;
			cout<<"3 to view enrolled students in each course"<<endl;
			cout<<"4 assign marks to students"<<endl;
			cin>>choice;
			cout<<"------------------------------------------"<<endl;
			system("CLS");
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
