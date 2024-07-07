// Project Name: Hospital Management System
// Coders: Muhammad Haseeb (23P-0004) & Syed Faakhir Abid (23P-0003)
// Purpose of code: This code contains friend function of class patient for managing bills of patients

#include <iostream>
#include <string>
using namespace std;

void Bill (Patient &x){
	int bill;   string pay;   char opt;
	
	if (x.concern == "Emergency Checkup"){bill = 300;}
	else if (x.concern == "Cancer Treatment"){bill = 800000;}
	else if (x.concern == "Small Operation"){bill = 100000;}
	else{bill = 500000;}  // complex operation
	
	cout << "Your Total Bill is: " << bill << endl;
	while (1){
		cout << "Do you want to pay now? (y/n): ";	
		cin >> opt;
		cin.ignore();
		cout << endl;
		switch (opt){
			case 'y':
			case 'Y':
				while(1){
					int count = 0;
					cout << "Your Total Bill is : " << bill << endl;
					cout << "Enter Amount to pay: " ;
					cin >> pay;
					for (int i=0 ; i<pay.length() ; i++){
						if (pay[i]=='0'||pay[i]=='1'||pay[i]=='2'||pay[i]=='3'||pay[i]=='4'||pay[i]=='5'||pay[i]=='6'||pay[i]=='7'||pay[i]=='8'||pay[i]=='9'){
							count++;
						}
						else{
							cout << "Invalid Input ... Try Again\n" << endl;
							break;
						}
					}
					if (count == pay.length()){
						int paid = stoi(pay);
						if (paid >= bill){
							if (paid == bill){
								cout << "Bill Paid Successfully\n" << endl;
								break;
							}
							else {
								cout << "Bill Paid Successfully\n" << endl;
								cout << "Ammount Returned:" << paid - bill << "\n" << endl;
								break;
							}
							
						}
						else{
							cout << "Invalid Amount ... Try Again\n" << endl;
						}
					}	
				}
				x.BillStatus = "Paid";
				break;
			case 'n':
			case 'N':
				if (x.BillStatus != "Paid"){x.BillStatus = "Unpaid";}
				break;
			default:
				cout << "Invalid Input ... Try Again\n" << endl;
		}
		if (opt=='y'||opt=='Y'||opt=='n'||opt=='N') {break;}
	}
}
