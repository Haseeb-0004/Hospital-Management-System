// Project Name: Hospital Management System
// Coders: Muhammad Haseeb (23P-0004) & Syed Faakhir Abid (23P-0003)
// Purpose of code: This code contains the child class Patient for managing patient's record 

#include <iostream>
#include <string>
using namespace std;

class Patient : public Person{
	protected:
		string contact;
		string concern; // [Emergency Checkup, Cancer Treatment, Small Operation(stiches etc. due to injury), Complex Operation(brain tumor, heart surgery etc)]
		string BillStatus = "Unpaid"; // (Paid or Unpaid)
		
	public:
		Patient():contact("default"),concern("default"),BillStatus("default"){}
        Patient(int ID,string name,int age,string gender,string contact,string concern,string BillStatus):Person(ID,name,age,gender),contact(contact),concern(concern),BillStatus(BillStatus){}
        
		friend void Bill (Patient &x);
		
		void PatInfo(){
			cout << "Patient Info: " << endl;
			cout << "ID         : " << ID << endl;
			cout << "Name       : " << name << endl;
			cout << "Age        : " << age << endl;
			cout << "Gender     : " << gender << endl;
			cout << "Contact.No : " << contact << endl;
			cout << "Concern    : " << concern << endl;
			cout << "Bill Status: " << BillStatus << endl;
			cout << endl;
		}
		
		void UpdatePatInfo(){
			char opt;
			int out;
			while (1){
				out = 0;
				cout << "Update: " << endl;
				cout << "1. Name\n2. Age\n3. Gender\n4. Contact.No\n5. Concern\n6. Exit\nEnter Choice: ";
				cin>>opt;
				cin.ignore();
				switch(opt){
					case '1':
						setName();
						break;
					case '2':
						setAge();
						break;
					case '3':
						setGender();
						break;
					case '4':
						setContact();
						break;
					case '5':
						setConcern();
						break;
					case '6':
						cout << "Exited Successfully\n" << endl;
						out = 1;
						break;
					default:
						cout << "Invalid Input ... Try Again\n" << endl;
				}
				if (out == 1) {break;}
			}
			
		}
		// Getter Methods
		string getBill()const{
			return BillStatus;
		}
		string getContact()const{
			return contact;
		}
		string getConcern()const{
			return concern;
		}
		// Setter Methods
		void setContact(){
			string temp;
			while(1){
				int count = 0;
				cout << "Enter Contact Number (Enter Correctly! Extra digits will be ignored)\n(+92-XXX-XXXXXXX): +92 ";
				cin >> temp;
				for (int i=0;i<10;i++){
					if(temp[i]=='0'||temp[i]=='1'||temp[i]=='2'||temp[i]=='3'||temp[i]=='4'||temp[i]=='5'||temp[i]=='6'||temp[i]=='7'||temp[i]=='8'||temp[i]=='9'){
						count++;
					}
				}
				if (count == 10){
					temp = temp.substr (0,10);
					break;
				}
				cout << "Invalid Input ... Try Again\n" << endl;
			}
			contact = "+92 "+temp;
			cout << endl;
		}
		void setConcern(){
			char opt;
			while(1){
				cout << "Select Concern: " << endl;
				cout << "1. Emergency Checkup\n2. Cancer Treatment\n3. Small Operation\n4. Complex Operation\nEnter Choice: ";
				cin >> opt;
				cin.ignore();
				switch(opt){
					case '1':
						concern = "Emergency Checkup";
						break;
					case '2':
						concern = "Cancer Treatment";
						break;
					case '3':
						concern = "Small Operation";
						break;
					case '4':
						concern = "Complex Operation";
						break;
					default:
						cout << "Invalid Input ... Try Again\n" << endl;
				}
				if (opt=='1'||opt=='2'||opt=='3'||opt=='4'){break;}
			}
			cout << endl;
		}
};
