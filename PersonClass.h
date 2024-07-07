// Project Name: Hospital Management System
// Coders: Muhammad Haseeb (23P-0004) & Syed Faakhir Abid (23P-0003)
// Purpose of code: This code contains the parent class which inheits 2 child classes for managing the doctor's and patient's records

#include <iostream>
#include <string>
using namespace std;

class Person{
    protected:
        int ID;
        string name;
        int age;
        string gender;   
                
    public: 
        Person():ID(0),name("default"),age(0),gender("default"){}
        Person(int ID,string name,int age,string gender):ID(ID),name(name),age(age),gender(gender){}
        void setID(int x){
            ID = x;
        }
        
        // Setter Methods
        void setID(){
            ID = 0;
        }
        void setName(){
            cout << "Enter Name: ";
            getline(cin,name);
            cout << endl;
        }
        void setAge(){
            string Age;   int count;
            while (1){
                count = 0;
                cout << "Enter Age: ";
                cin >> Age;
                for (int i=0 ; i<Age.length() ; i++){
                    if (Age[i]=='0'||Age[i]=='1'||Age[i]=='2'||Age[i]=='3'||Age[i]=='4'||Age[i]=='5'||Age[i]=='6'||Age[i]=='7'||Age[i]=='8'||Age[i]=='9'){
                        count++;
                    }
                    else{
                        cout << "Invalid Input ... Try Again\n" << endl;
                        break;
                    }
                }
                if (count == Age.length()){
                    age = stoi(Age);
                    break;
                }
            }
            cout << endl;
        }
        void setGender(){
            char opt;
            while(1){
                cout << "Select Gender: " << endl;
                cout << "1. Male\n2. Female\nEnter Choice: ";
                cin >> opt;
                cin.ignore();
                switch(opt){
                    case '1':
                        gender = "Male";
                        break;
                    case '2':
                        gender = "Female";
                        break;
                    default:
                        cout << "Invalid Input ... Try Again\n" << endl;
                }
                if (opt=='1'||opt=='2'){break;}
            }
            cout << endl;
        }
        
        // Getter Methods
        string getName()const{
			return name;
		}
		int getID()const{
			return ID;
		}
		int getAge()const{
			return age;
		}
		string getGender()const{
			return gender;
		}
};
