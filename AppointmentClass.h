// Project Name: Hospital Management System
// Coders: Muhammad Haseeb (23P-0004) & Syed Faakhir Abid (23P-0003)
// Purpose of code: This code contains the child class inherited by both Doctor and Patient classes for managing appointmets

#include <iostream>
#include <string>
using namespace std;

class Appointments : public Doctor, public Patient{
	private:
	 	int appID,patientId,doctorId;
		string date;
		string time;
		
	public:
		Appointments():appID(0){}
		Appointments(int appID,int docID,int patID,string date,string time):appID(appID),doctorId(docID),patientId(patID),date(date),time(time){}
		
	void ScheduleAppointment(int id , vector<Doctor>d , vector<Patient>p){
		string op;
	
		if(d.empty()==1){cout<<"No Doctor Available\n"<<endl; return;}
		if(p.empty()==1){cout<<"No Patient Available\n"<<endl; return;}
	
		cout << "\nSchedule Appointment: " << endl;
	
		cout << "List of Doctors:" << endl;
		cout << "ID		Name" << endl;
		for (int i=0; i<d.size() ;i++){
			cout << d[i].getID() << "		" << d[i].getName() << endl;
		}
		cout << "\n Select Doctor from the list above" << endl;
		while(1){
			int count=0;
			int out=0;
			
			cout << "Enter Doctor's ID (or type exit to cancel): ";
			cin >> op;
			if (op=="exit"){cout<<endl;return;}
			cout << endl;
	
			for (int i=0 ; i<op.length() ; i++){
				if (op[i]=='0'||op[i]=='1'||op[i]=='2'||op[i]=='3'||op[i]=='4'||op[i]=='5'||op[i]=='6'||op[i]=='7'||op[i]=='8'||op[i]=='9'){
					count++;
				}
				else{
					cout << "Invalid Input ... Try Again\n" << endl;
					break;
				}	
			}
			if(op.length()==count){
				int x=stoi(op);
				for (int i=0; i<d.size() ;i++){
					if (x==d[i].getID()){
						doctorId = x;
						out = 1;
						time = d[i].getShift();
						break;
					}
				}
				if(out == 1){
					break;
				}
				else{
					cout << "Invalid Input ... Try Again\n" << endl;	
				}
			}
		}

		cout << "List of Patients:" << endl;
		cout << "ID		Name" << endl;
		for (int i=0; i<p.size() ;i++){
			cout << p[i].getID() << "		" << p[i].getName() << endl;
		}
		cout << "\n Select Patient from the list above" << endl;
		while(1){
			int count=0;
			int out=0;
		
			cout << "Enter Patient's ID (or type exit to cancel): ";
			cin >> op;
			if (op=="exit"){cout<<endl;return;}
			cout << endl;
				
			for (int i=0 ; i<op.length() ; i++){
				if (op[i]=='0'||op[i]=='1'||op[i]=='2'||op[i]=='3'||op[i]=='4'||op[i]=='5'||op[i]=='6'||op[i]=='7'||op[i]=='8'||op[i]=='9'){
					count++;
				}
				else{
					cout << "Invalid Input ... Try Again\n" << endl;
					break;
				}	
			}
		
			if(op.length()==count){
				int x=stoi(op);
				for (int i=0; i<p.size() ;i++){
					if (x==p[i].getID()){//p[i].getID()!=0 && 
						patientId = x;
						out = 1;
						break;
					}
				}
				if(out == 1){
					break;
				}
				else{
					cout << "Invalid Input ... Try Again\n" << endl;	
				}
			}
		}
	
		
		string day, month, year;
		int count;
		cout << "Enter Date: (Format, DD/MM/YYYY)" << endl;
		while(1){
			cout << "Day (DD): ";
			cin >> day;
			if (day=="01"||day=="02"||day=="03"||day=="04"||day=="05"||day=="06"||day=="07"||day=="08"||day=="09"||day=="10"||day=="11"||
				day=="12"||day=="13"||day=="14"||day=="15"||day=="16"||day=="17"||day=="18"||day=="19"||day=="20"||day=="21"||day=="22"||
				day=="23"||day=="24"||day=="25"||day=="26"||day=="27"||day=="28"||day=="29"||day=="30"||day=="31"){break;}
				
			if(day=="1"||day=="2"||day=="3"||day=="4"||day=="5"||day=="6"||day=="7"||day=="8"||day=="9")
				{cout << "Invalid format ... Try Again\n" << endl;continue;}
			cout << "Invalid day ... Try Again\n" << endl;
		}
		while(1){
			cout << "Month (MM): ";
			cin >> month;
			if (month=="01"||month=="02"||month=="03"||month=="04"||month=="05"||month=="06"||month=="07"||month=="08"||month=="09"||month=="10"||month=="11"||month=="12"){break;}
			if(month=="1"||month=="2"||month=="3"||month=="4"||month=="5"||month=="6"||month=="7"||month=="8"||month=="9"){cout << "Invalid format ... Try Again\n" << endl;continue;}
			cout << "Invalid month ... Try Again\n" << endl;
		}
		while(1){
			count = 0;
			cout << "Year (YYYY): ";
			cin >> year;
			for (int i=0;i<year.length();i++){
				if (year[i]=='0'||year[i]=='1'||year[i]=='2'||year[i]=='3'||year[i]=='4'||year[i]=='5'||year[i]=='6'||year[i]=='7'||year[i]=='8'||year[i]=='9'){
					count++;
					continue;
				}
				cout << "Invalid Input ... Try Again\n" << endl;
				count = 0;
				break;
			}
			if (count == 4){
				break;
			}
			if (count != 0){
				cout << "Invalid Format ... Try Again\n" << endl;
			}
		}
		date = day + "/" + month + "/" + year;
				
		cout << "Time: " << time << endl << endl;
		
		cout << "Appointment Scheduled Successfully!" << endl;
		appID = id;
	}
	void DisplayAppointment(){
		cout<<endl;
		cout<<"Appointment ID: "<<appID<<endl;
		cout<<"Patient ID    : "<<patientId<<endl;
		cout<<"Doctor ID     : "<<doctorId<<endl;
	}
	void DisplayAppointment(Doctor d,Patient p){
		cout<<endl;
		cout<<"Appointment ID: "<<appID<<endl;
		cout<<"Patient ID    : "<<patientId<<endl;
		cout<<"Patient Name  : "<<p.getName()<<endl;
		cout<<"Doctor ID     : "<<doctorId<<endl;
		cout<<"Doctor Name   : "<<d.getName()<<endl;
		cout<<"Date          : "<<date<<endl;
		cout<<"Time          : "<<time<<endl<<endl;
	}
	
	int GetID()const{
		return appID;
	}
	int getDocID()const{
		return doctorId;
	}
	int getPatID()const{
		return patientId;
	}
	string getDate()const{
		return date;
	}
	string getTime()const{
		return time;
	}
};
