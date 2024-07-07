// Project Name: Hospital Management System
// Coders: Muhammad Haseeb (23P-0004) & Syed Faakhir Abid (23P-0003)
// Purpose of code: This code contains functions for file handling.


// Function to write doctor records to a file
void writeDoctorRecord(const vector<Doctor>& doctors, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& doctor : doctors) {
            file << doctor.getID() << ',' << doctor.getName() << ',' << doctor.getAge() << ',' << doctor.getGender() << ',' << doctor.getSpeciality() << ',' << doctor.getShift() << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file " << filename << " for writing." << endl;
    }
}

// Function to write patient records to a file
void writePatientRecord(const vector<Patient>& patients, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& patient : patients) {
            file << patient.getID() << ',' << patient.getName() << ',' << patient.getAge() << ',' << patient.getGender() << ',' << patient.getConcern() << ',' << patient.getContact() << ',' << patient.getBill() << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file " << filename << " for writing." << endl;
    }
}
// Function to write appointments records to a file
void writeAppointmentRecord(const vector<Appointments>& appointments, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& appointment : appointments) {
            file << appointment.GetID() << ',' << appointment.getDocID() << ',' << appointment.getPatID() << ',' << appointment.getDate() << ',' << appointment.getTime() << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file " << filename << " for writing." << endl;
    }
}

// Function to read doctor records from a file
vector<Doctor> readDoctorRecord(const string& filename) {
    vector<Doctor> doctors;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string token;
            vector<string> tokens;
            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }
            if (tokens.size() == 6) {
                int ID = stoi(tokens[0]);
                string name = tokens[1];
                int age = stoi(tokens[2]);
                string gender = tokens[3];
                string speciality = tokens[4];
                string shift = tokens[5];
                Doctor doctor(ID, name, age, gender, speciality, shift);
                doctors.push_back(doctor);
            }
        }
        file.close();
    } else {
        cout << "Unable to open file " << filename << " for reading." << endl;
    }
    return doctors;
}

// Function to read patients records from a file
vector<Patient> readPatientRecord(const string& filename) {
    vector<Patient> patients;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string token;
            vector<string> tokens;
            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }
            if (tokens.size() == 7) {
                int ID = stoi(tokens[0]);
                string name = tokens[1];
                int age = stoi(tokens[2]);
                string gender = tokens[3];
                string concern = tokens[4];
                string contact = tokens[5];
                string bill = tokens[6];
                Patient patient(ID, name, age, gender, concern, contact, bill);
                patients.push_back(patient);
            }
        }
        file.close();
    } else {
        cout << "Unable to open file " << filename << " for reading." << endl;
    }
    return patients;
}
// Function to read appointment records from a file
vector<Appointments> readAppointmentRecord(const string& filename) {
    vector<Appointments> appointments;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string token;
            vector<string> tokens;
            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }
            if (tokens.size() == 5) {
                int ID = stoi(tokens[0]);
                int docID = stoi(tokens[1]);
                int patID = stoi(tokens[2]);
                string date = tokens[3];
                string time = tokens[4];
                Appointments appointment(ID, docID, patID, date, time);
                appointments.push_back(appointment);
            }
        }
        file.close();
    } else {
        cout << "Unable to open file " << filename << " for reading." << endl;
    }
    return appointments;
}
