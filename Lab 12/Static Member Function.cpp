# include <iostream>
# include <string>
using namespace std;
 class Employee{
 	private:
 		int employeeID;
 		string employeeName;
 		static string companyName;
 	public:
 		Employee(int id, string name){
 			employeeID = id;
 			employeeName = name;
 			
		 }
		 
		static void displayCompanyInfo(){
		 	cout <<"Company name:" << companyName << endl;
		 }
		 
		void displayEmployeeInfo(){
		 	cout << "Employee Name: " << employeeName << endl;
		 	cout << "Employee ID: " << employeeID << endl;
		 	cout << "Company Name: "  << companyName << endl;
		 }
		 
		static void setCompanyName(string name){
		 	companyName= name;
		 }
 };
 
        string Employee :: companyName = "ABC Tech Solutions" ;
        
int main(){
	Employee :: displayCompanyInfo();
	cout << endl;
	
	Employee e1(101, "Ali Khan");
	Employee e2(102, "Sara Ahmad");
	Employee e3(103, "Zona Adan");
	
	cout << "Before changing company name:  " << endl;
	cout << endl;
	
	e1.displayEmployeeInfo();
	cout << endl;
	e2.displayEmployeeInfo();
	cout << endl;
	e3.displayEmployeeInfo();
	cout << endl;
	cout <<endl;
	cout << "...Changing company name for all employees... " << endl;
	Employee:: setCompanyName("XYZ Global Ltd");
	cout << endl;
	cout << endl;
	cout << "After changing company name: " << endl;
	cout << endl;
	e1.displayEmployeeInfo();
	cout << endl;
	e2.displayEmployeeInfo();
	cout << endl;
	e3.displayEmployeeInfo();
	
	return 0;
	
	
	
}
