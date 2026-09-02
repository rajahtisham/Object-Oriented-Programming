# include <iostream>
# include <string>
using namespace std;

class HospitalStaff{
	protected:
		string staffName;
	public:
		HospitalStaff(string name){
			staffName= name;
		}
		
		virtual void performDuty() = 0;
		
		virtual ~HospitalStaff(){
		}
};


class Doctor : public HospitalStaff{
	public:
	Doctor(string name) : HospitalStaff(name){
	}
	
	void performDuty() override{
	cout << "Doctor " << staffName<< " is diagnosing patients." << endl;
	}
};

class Nurse : public HospitalStaff{
	public:
	Nurse(string name) : HospitalStaff(name){
	}
	
	void performDuty() override{
	cout << "Nurse " << staffName << " is assisting the patients." << endl;}
		
};

class Receptionist : public HospitalStaff{
	public:
	Receptionist(string name) : HospitalStaff(name){
	}
	
	void performDuty() override{
	cout << "Receptionist "<< staffName<< " is managing the appointments." <<endl;}
};

int main(){
	
	HospitalStaff* staff[3];
	staff[0] = new Doctor("Ahmed");
	staff[1] = new Nurse("Fatima");
	staff[2] = new Receptionist("Mr. Bilal");
	
	cout <<"Hospital staff duties: " << endl;
	for (int i =0; i<3; i++){
		staff[i] ->performDuty();
	}
	
	for (int i=0; i<3; i++){
		delete staff[i];
	
	}
	return 0;
}
