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
