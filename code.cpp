// Project Name: Hospital Management System
// Coders: Muhammad Haseeb (23P-0004) & Syed Faakhir Abid (23P-0003)
// Purpose of code: This code contains all necessary header files and main function for managing overall menu of the program

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "PersonClass.h"
#include "DoctorClass.h"
#include "PatientClass.h"
#include "AppointmentClass.h"
#include "Billing.h"
#include "FileHandling.h"
using namespace std;

int main()
{
	int doc = 1,pat = 1 ,app = 1 ;
	
	vector<Doctor>Doc;
	vector<Patient> Pat;
	vector<Appointments>App;
	
	Doctor temp1;
	Patient temp2;
	Appointments temp3;
	
	cout << "Loading Files...\n" << endl;
	Doc = readDoctorRecord("doctor_records.txt");
	Pat = readPatientRecord("patient_records.txt");
	App = readAppointmentRecord("appointment_records.txt");
	// Reading the ID's from the file and storing in variables
    ifstream inputFile("ID's.txt");
    if (inputFile.is_open()) {
        inputFile >> doc >> pat >> app;
        inputFile.close();
    } else {
        cout << "Unable to open the file for reading." << endl;
    }
	
	char opt,opt2,opt3;
	string search;
	while(1){
		cout << "Menu:" << endl;
		cout << "1. Doctor Records\n2. Patient Records\n3. Appointments\n4. Exit\n(Enter Correctly! Extra digits will be ignored)\nEnter Choice: ";
		cin >> opt;
		cin.ignore();
		cout << endl;
		switch(opt){
			case '1':
				while(1){
					int out = 0;
					cout << "Doctor Records:" << endl;
					cout << "1. Add New Doctor\n2. Update Doctor's Info\n3. View Doctor's Details\n4. Remove Doctor\n5. Exit\n(Enter Correctly! Extra digits will be ignored)\nEnter Choice: ";
					cin >> opt2;
					cin.ignore();
					cout << endl;
					switch (opt2){
						case '1':
							cout << "Enter following details:\n" << endl;
							
							temp1.setID(doc);
							doc++;
							temp1.setName();
							temp1.setAge();
							temp1.setGender();
							temp1.setSpeciality();
							temp1.setShift();
							
							Doc.push_back(temp1);
							cout << "Doctor Added Successfully!\n" << endl;
							
							break;
							
						case '2':
							if (Doc.empty()==1){cout<<"\nNo Doctor Available.\n\n";break;}
							cout << "ID		Name" << endl;
							for (int i=0; i<Doc.size() ;i++){
								cout << Doc[i].getID() << "		" << Doc[i].getName() << endl;
							}	
							while (1){
								int count = 0;
								cout << "Enter Doctor's ID to Update Info (or type exit to cancel): ";
								cin >> search;
								if (search=="exit"){cout<<endl;break;}
								cout << endl;
								for (int i=0 ; i<search.length() ; i++){
									if (search[i]=='0'||search[i]=='1'||search[i]=='2'||search[i]=='3'||search[i]=='4'||search[i]=='5'||search[i]=='6'||search[i]=='7'||search[i]=='8'||search[i]=='9'){
										count++;
									}
									else{
										cout << "Invalid Input ... Try Again\n" << endl;
										break;
									}
								}
								if (count == search.length()){
									int count2 = 0;
									int x = stoi(search);
									for (int i=0; i<Doc.size() ;i++){
										if (x==Doc[i].getID()){
											Doc[i].UpdateDocInfo();
											cout << "Doctor's Info Updated Successfully!\n" << endl;
											count2 = 1;
											break;
										}
									}
									if (count2 == 1){
										break;
									}
									else{
										cout << "Invalid Input ... Try Again\n" << endl;
									}
								}
							}
							break;
						case '3':
							if (Doc.empty()==1){cout<<"\nNo Doctor Available.\n\n";break;}
							cout << "ID		Name" << endl;
							for (int i=0; i<Doc.size() ;i++){
								cout << Doc[i].getID() << "		" << Doc[i].getName() << endl;
							}	
							while (1){
								int count = 0;
								cout << "Enter Doctor's ID to view Details (or type exit to cancel): ";
								cin >> search;
								if (search=="exit"){cout<<endl;break;}
								cout << endl;
								for (int i=0 ; i<search.length(); i++){
									if (search[i]=='0'||search[i]=='1'||search[i]=='2'||search[i]=='3'||search[i]=='4'||search[i]=='5'||search[i]=='6'||search[i]=='7'||search[i]=='8'||search[i]=='9'){
										count++;
									}
									else{
										cout << "Invalid Input ... Try Again\n" << endl;
										break;
									}
								}
								if (count == search.length()){
									int count2 = 0;
									int x = stoi(search);
									for (int i=0; i<Doc.size() ;i++){
										if (x==Doc[i].getID()){
											Doc[i].DocInfo();
											count2 = 1;
											break;
										}
									}
									if (count2 == 1){
										break;
									}
									else{
										cout << "Invalid Input ... Try Again\n" << endl;
									}
								}
							}
							break;
							
						case '4':
							if (Doc.empty()==1){cout<<"\nNo Doctor Available.\n\n";break;}
							cout << "ID		Name" << endl;
							for (int i=0; i<Doc.size() ;i++){
								cout << Doc[i].getID() << "		" << Doc[i].getName() << endl;
							}
							while (1){
								int count = 0;
								cout << "Enter Doctor's ID to Remove Doctor (or type exit to cancel): ";
								cin >> search;
								if (search=="exit"){cout<<endl;break;}
								cout << endl;
								for (int i=0 ; i<search.length() ; i++){
									if (search[i]=='0'||search[i]=='1'||search[i]=='2'||search[i]=='3'||search[i]=='4'||search[i]=='5'||search[i]=='6'||search[i]=='7'||search[i]=='8'||search[i]=='9'){
										count++;
									}
									else{
										cout << "Invalid Input ... Try Again\n" << endl;
										break;
									}
								}
								if (count == search.length()){
									int count2 = 0;
									int x = stoi(search);
									for (int i=0; i<Doc.size() ;i++){
										if (x==Doc[i].getID()){
											Doc.erase(Doc.begin()+i);
											cout << "Doctor Remved Successfully!\n" << endl;
											count2 = 1;
											break;
										}
									}
									if (count2 == 1){
										break;
									}
									else{
										cout << "Invalid Input ... Try Again\n" << endl;
									}
								}
							}
							break;
						case '5':
							out = 1;
							break;
						default:
							cout << "Invalid Input ... Try Again\n" << endl;
					}
					if (out == 1){break;}
				}				
				break;
			case '2':
				while(1){
					int out = 0;
					cout << "Patient Records:" << endl;
					cout << "1. Add New Patient\n2. Update Patient's Info\n3. View Patient's Details\n4. Billing\n5. Exit\n(Enter Correctly! Extra digits will be ignored)\nEnter Choice: ";
					cin >> opt2;
					cin.ignore();
					cout << endl;
					switch (opt2){
						case '1':
							cout << "Enter following details:\n" << endl;
							
							temp2.setID(pat);
							pat++;
							temp2.setName();
							temp2.setAge();
							temp2.setGender();
							temp2.setContact();
							temp2.setConcern();
							Bill(temp2);
									
							Pat.push_back(temp2);
							cout << "Patient Added Successfully!\n" << endl;
							
							break;
						case '2':
							if (Pat.empty()==1){cout<<"\nNo Patient Available.\n\n";break;}
							cout << "ID		Name" << endl;
							for (int i=0; i<Pat.size() ;i++){
								cout << Pat[i].getID() << "		" << Pat[i].getName() << endl;
							}	
							while (1){
								int count = 0;
								cout << "Enter Patient's ID to Update Info (or type exit to cancel): ";
								cin >> search;
								if (search=="exit"){cout<<endl;break;}
								cout << endl;
								for (int i=0 ; i<search.length() ; i++){
									if (search[i]=='0'||search[i]=='1'||search[i]=='2'||search[i]=='3'||search[i]=='4'||search[i]=='5'||search[i]=='6'||search[i]=='7'||search[i]=='8'||search[i]=='9'){
										count++;
									}
									else{
										cout << "Invalid Input ... Try Again\n" << endl;
										break;
									}
								}
								if (count == search.length()){
									int count2 = 0;
									int x = stoi(search);
									for (int i=0; i<Pat.size() ;i++){
										if (x==Pat[i].getID()){
											Pat[i].UpdatePatInfo();
											cout << "Patient's Info Updated Successfully!\n" << endl;
											count2 = 1;
											break;
										}
									}
									if (count2 == 1){
										break;
									}
									else{
										cout << "Invalid Input ... Try Again\n" << endl;
									}
								}
							}
							break;
						case '3':
							if (Pat.empty()==1){cout<<"\nNo Patient Available.\n\n";break;}
							cout << "ID		Name" << endl;
							for (int i=0; i<Pat.size() ;i++){
								cout << Pat[i].getID() << "		" << Pat[i].getName() << endl;
							}	
							while (1){
								int count = 0;
								cout << "Enter Patient's ID to view Details (or type exit to cancel): ";
								cin >> search;
								if (search=="exit"){cout<<endl;break;}
								cout << endl;
								for (int i=0 ; i<search.length() ; i++){
									if (search[i]=='0'||search[i]=='1'||search[i]=='2'||search[i]=='3'||search[i]=='4'||search[i]=='5'||search[i]=='6'||search[i]=='7'||search[i]=='8'||search[i]=='9'){
										count++;
									}
									else{
										cout << "Invalid Input ... Try Again\n" << endl;
										break;
									}
								}
								if (count == search.length()){
									int count2 = 0;
									int x = stoi(search);
									for (int i=0; i<Pat.size() ;i++){
										if (x==Pat[i].getID()){
											Pat[i].PatInfo();
											count2 = 1;
											break;
										}
									}
									if (count2 == 1){
										break;
									}
									else{
										cout << "Invalid Input ... Try Again\n" << endl;
									}
								}
							}
							break;
						case '4':
							if (Pat.empty()==1){cout<<"\nNo Patient Available.\n\n";break;}
							cout << "ID		Name" << endl;
							for (int i=0; i<Pat.size() ;i++){
								cout << Pat[i].getID() << "		" << Pat[i].getName() << endl;
							}	
							while (1){
								int count = 0;
								cout << "Enter Patient's ID to view Bill Status (or type exit to cancel): ";
								cin >> search;
								if (search=="exit"){cout<<endl;break;}
								cout << endl;
								for (int i=0 ; i<search.length() ; i++){
									if (search[i]=='0'||search[i]=='1'||search[i]=='2'||search[i]=='3'||search[i]=='4'||search[i]=='5'||search[i]=='6'||search[i]=='7'||search[i]=='8'||search[i]=='9'){
										count++;
									}
									else{
										cout << "Invalid Input ... Try Again\n" << endl;
										break;
									}
								}
								if (count == search.length()){
									int count2 = 0;
									int x = stoi(search);
									for (int i=0;i<Pat.size();i++){
										if (x==Pat[i].getID()){
											cout << "Bill Status: " << Pat[i].getBill() << endl << endl;
											if (Pat[i].getBill()=="Unpaid"){
												Bill(Pat[i]);
											}
											count2 = 1;
											break;
										}
									}
									if (count2 == 1){
										break;
									}
									else{
										cout << "Invalid Input ... Try Again\n" << endl;
									}
								}
							}
							break;
													
						case '5':
							out = 1;
							break;
						default:
							cout << "Invalid Input ... Try Again\n" << endl;
					}
					if (out == 1){break;}
				}
				break;
				
			case '3':
				while(1){
					int out=0;
					cout<<"Appointments Section: \n";
					cout<<"1. Schedule Appoinment \n2. Cancel Appointment \n3. Display Appointments\n4. Exit\nEnter choice: ";
					cin>>opt2;
					cin.ignore();
					switch(opt2){
					case '1':
						temp3.ScheduleAppointment(app,Doc,Pat);
						if (temp3.GetID()!=0){
							App.push_back(temp3);
							app++;
						}
						break;
						
					case '2':
						cout << "\nAppointment Cancellation Process: " << endl;	
						for(int i=0; i<App.size() ; i++){
								App[i].DisplayAppointment();
						}
						if (App.empty()==1){cout<<"\nNo Appointments Booked\n\n";break;}
						while(1){
							int count=0;
							string op;
							cout << "\nSelect Appointment ID: ";
							cin >> op;
					//		cin.ignore();
							for (int i=0 ; i<op.length() ; i++){
								if (op[i]=='0'||op[i]=='1'||op[i]=='2'||op[i]=='3'||op[i]=='4'||op[i]=='5'||op[i]=='6'||op[i]=='7'||op[i]=='8'||op[i]=='9'){
									count++;
								}
								else{
									cout << "Invalid Input ... Try Again\n" << endl;
									break;
								}
							}
							if (count == op.length()){
								int c=0;
								int x=stoi(op);
								for(int i=0; i<App.size() ;i++){
									if(x==App[i].GetID()){
										App.erase(App.begin()+i);
										c++;
								}
								if(c==1){break;}
								}
								if(c==0){cout << "Invalid Input ... Try Again\n" << endl;}
								if(c==1){cout<<"\nAppointment Successfully Cancelled!\n\n"; break;}
							}
						}
						break;
			
					case '3':
						if (App.empty()==1){cout<<"\nNo Appointments Booked\n\n";break;}
						for(int i=0; i<App.size() ; i++){
							if(App[i].GetID()!=0){
								App[i].DisplayAppointment();
							}
						}
						while(1){
							int count = 0;
							cout << "\nEnter Appointment ID to view Details (or type exit to cancel): ";
							cin >> search;
							if (search=="exit"){cout<<endl;break;}
							cout << endl;
							for (int i=0 ; i<search.length() ; i++){
								if (search[i]=='0'||search[i]=='1'||search[i]=='2'||search[i]=='3'||search[i]=='4'||search[i]=='5'||search[i]=='6'||search[i]=='7'||search[i]=='8'||search[i]=='9'){
									count++;
								}
								else{
									cout << "Invalid Input ... Try Again\n" << endl;
									break;
								}
							}
							if (count == search.length()){
								int count2 = 0;
								int x = stoi(search);
								for (int i=0; i<App.size() ;i++){
									if (x==App[i].GetID()){
										Doctor a;
										Patient b;
										for (int j=0;j<Doc.size();j++){
											if (App[i].getDocID()==Doc[j].getID()){
												a = Doc[j];
											}
										}
										for (int j=0;j<Pat.size();j++){
											if (App[i].getPatID()==Pat[j].getID()){
												b = Pat[j];
											}
										}
										App[i].DisplayAppointment(a,b);
										count2 = 1;
										break;
									}
								}
								if (count2 == 1){
									break;
								}
								else{
									cout << "Invalid Input ... Try Again\n" << endl;
								}
							}
						}	
						break;
				
					case '4':
						out=1;
						break;
				
					default:
						cout << "Invalid Input ... Try Again\n" << endl;
						break;
					}
					if(out==1){break;}
				}
				break;
				
			case '4':{
				writeDoctorRecord(Doc, "doctor_records.txt");
				writePatientRecord(Pat, "patient_records.txt");
				writeAppointmentRecord(App, "appointment_records.txt");
				// Writing ID's to a file
   				ofstream outputFile("ID's.txt");
    			if (outputFile.is_open()) {
        			outputFile << doc << " " << pat << " " << app;
        			outputFile.close();
    			} else {
        			cout << "Unable to open the file for writing." << endl;
    			}
    			
				cout << "Saving Data..." << endl;
				cout << "Exited Successfully\n" << endl;
				return 0;}
				
			default:
				cout << "Invalid Input ... Try Again\n" << endl;
				break;
		}
	}
}
