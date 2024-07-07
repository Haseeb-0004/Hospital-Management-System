// Project Name: Hospital Management System
// Coders: Muhammad Haseeb (23P-0004) & Syed Faakhir Abid (23P-0003)
// Purpose of code: This code contains the child class Doctor for managing doctor's record 

#include <iostream>
#include <string>
using namespace std;

class Doctor : public Person{
    protected:
        string speciality;
        string shift;
        
    public:
    //  friend class Appointments;
        Doctor():speciality("default"),shift("default"){}
        Doctor(int ID,string name,int age,string gender,string speciality,string shift):Person(ID,name,age,gender),speciality(speciality),shift(shift){}
        void DocInfo(){
            cout << "Doctor Details: " << endl;
            cout << "ID        : " << ID << endl;
            cout << "Name      : " << name << endl;
            cout << "Age       : " << age << endl;
            cout << "Gender    : " << gender << endl;
            cout << "Speciality: " << speciality << endl;
            cout << "Shift     : " << shift << endl;
            cout << endl;
        }
        void UpdateDocInfo(){
            char opt;
            int out;
            while (1){
                out = 0;
                cout << "Update: " << endl;
                cout << "1. Name\n2. Age\n3. Gender\n4. Speciality\n5. Shift\n6. Exit\nEnter Choise: ";
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
                        setSpeciality();
                        break;
                    case '5':
                        setShift();
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
        // Setter Methods
        void setSpeciality(){
            char opt;
            while(1){
                cout << "Select Speciality: " << endl;
                cout << "1. Cardiology\n2. Dermatology\n3. Emergency Medicine\n4. Family Medicine\n5. Forensic Pathology\nEnter Choice: ";
                cin >> opt;
                cin.ignore();
                switch(opt){
                    case '1':
                        speciality = "Cardiology";
                        break;
                    case '2':
                        speciality = "Dermatology";
                        break;
                    case '3':
                        speciality = "Emergency Medicine";
                        break;
                    case '4':
                        speciality = "Family Medicine";
                        break;
                    case '5':
                        speciality = "Forensic Pathology";
                        break;
                    default:
                        cout << "Invalid Input ... Try Again\n" << endl;
                }
                if (opt=='1'||opt=='2'||opt=='3'||opt=='4'||opt=='5'){break;}
            }
            cout << endl;
        }
        void setShift(){
            char opt;
            while(1){
                cout << "Select Shift: " << endl;
                cout << "1. Morning\n2. Evening\n3. Night\nEnter Choice: ";
                cin >> opt;
                cin.ignore();
                switch(opt){
                    case '1':
                        shift = "Morning";
                        break;
                    case '2':
                        shift = "Evening";
                        break;
                    case '3':
                        shift = "Night";
                        break;
                    default:
                        cout << "Invalid Input ... Try Again\n" << endl;
                }
                if (opt=='1'||opt=='2'||opt=='3'){break;}
            }
            cout << endl;
        }
        // Getter Methods
        string getShift()const{
			return shift;
		}
		string getSpeciality()const{
			return speciality;
		}
};
