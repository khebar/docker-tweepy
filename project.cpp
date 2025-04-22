#include <iostream>
#include <string>
using namespace std;
class student
{
private:
    string username;
    string password;
    string name;
    string lastname;
    string studentID;
    float GPAofTerm;
    float GPAofAllTerms;
    int creditofTerm;
    bool mashroot;
    bool alef;
public:
    
    student() 
        : username(""), password(""), name(""), lastname(""), studentID(""), GPAofTerm(0.0), GPAofAllTerms(0.0), creditofTerm(0) {
        
    }

    
    student(string u, string p, string n, string l, string id, float gpt, float gpaat, int cot, int coaat) 
        : username(u), password(p), name(n), lastname(l), studentID(id), GPAofTerm(gpt), GPAofAllTerms(gpaat), creditofTerm(cot) {
        
    }

    
    string getUsername() const { return username; }
    void setUsername(const string& u) { username = u; } 
    void setPassword(const string& p) { 
        if (!p.empty()) { 
            password = p; 
        } else {
            cout << "Password cannot be empty." << endl;
        }
    }

    string getPassword() const { return password; }
    
    void setName(const string& n) { 
        if (!n.empty()) { 
            name = n; 
        } else {
            cout << "Name cannot be empty." << endl;
        }
    }
    void setLastname(const string& l) { 
        if (!l.empty()) { 
            lastname = l; 
        } else {
            cout << "Lastname cannot be empty." << endl;
        }
    }
    string getName() const { return name; }
    string getLastname() const { return lastname; }
    
    void setStudentID(string id) { 
        studentID = id;
    }
    string getStudentID() const { return studentID; }
    void setGPAofTerm(float gpt) { 
        if (gpt >= 0.0 && gpt <= 20.0) { 
            GPAofTerm = gpt; 
        } else {
            cout << "GPA of term must be between 0.0 and 20.0 ." << endl;
        }
    }
    bool setMashroot(bool m) { 
        mashroot = m; 
        return mashroot; 
    }
    bool getMashroot() const { return mashroot; }
    bool setAlef(bool a) { 
        alef = a; 
        return alef; 
    }
    bool getAlef() const { return alef; }
    float getGPAofTerm() const { return GPAofTerm; }
    void setGPAofAllTerms(float gpaat) { 
        if (gpaat >= 0.0 && gpaat <= 20.0) { 
            GPAofAllTerms = gpaat; 
        } else {
            cout << "GPA of all terms must be between 0.0 and 20.0 ." << endl;
        }
    }
    float getGPAofAllTerms() const { return GPAofAllTerms; }
    void setCreditofTerm(int cot) { 
        if (cot >= 0) { 
            creditofTerm = cot; 
        } else {
            cout << "Credit of term cannot be negative." << endl;
        }
    }
    int getCreditofTerm() const { return creditofTerm; }

};
class course
{
private:
    string branchNumber;
    string courseCode;
    string nameOfProfessor;
    string courseName;
    int examHour;
    string examDate;
    int creditHours;
    int maxStudents;
    int enrolledStudents;
    student* enrolledList; 
    int waitingCount;     
    int maxWaitingSize = 200;   
    student* enrollqueue; 
public:
    
    
    
    int enrollStudent(student& s) {
        if (enrolledStudents < maxStudents && s.getCreditofTerm() >= creditHours) {
            enrolledList[enrolledStudents++] = s; 
            s.setCreditofTerm(s.getCreditofTerm() - creditHours);
            return 0;
        }
        else if (s.getCreditofTerm() < creditHours) {
            return 1;
        } else
        {
            return 2;
        }
        
        
    }
    
    
    course() 
        : branchNumber(""), courseCode(""), nameOfProfessor(""), courseName(""),waitingCount(0), examHour(0), examDate(""), creditHours(0), maxStudents(0), enrolledStudents(0), enrolledList(nullptr), enrollqueue(nullptr) {
        
    }
    
    course(string bn, string cc, string nop, string cn, int ch, int ms, string ed = "", int eh = 0) 
        : branchNumber(bn), courseCode(cc), nameOfProfessor(nop), courseName(cn), waitingCount(0), maxStudents(ms), examHour(eh), examDate(ed), creditHours(ch), enrolledStudents(0), enrolledList(nullptr), enrollqueue(nullptr) {
        if (ms > 0) {
            enrolledList = new student[maxStudents]; 
} else {
            enrolledList = nullptr; 
        }
    }
    
    ~course() {
        delete[] enrolledList;
        delete[] enrollqueue;
    }
    
    string getBranchNumber() const { return branchNumber; }
    void setBranchNumber(const string& bn) { branchNumber = bn; }
    string getCourseCode() const { return courseCode; }
    void setCourseCode(const string& cc) { 
        if (!cc.empty()) { 
            courseCode = cc; 
        } else {
            cout << "Course code cannot be empty." << endl;
        }
    }

    string getNameOfProfessor() const { return nameOfProfessor; }
    void setNameOfProfessor(const string& nop) { 
        if (!nop.empty()) { 
            nameOfProfessor = nop; 
        } else {
            cout << "Name of professor cannot be empty." << endl;
        }
    }
    student* getEnrollQueue() const { return enrollqueue; }
    int getWaitingCount() const { return waitingCount; }
    int getMaxWaitingSize() const { return maxWaitingSize; }
    void incrementWaitingCount() { waitingCount++; }
    void decrementWaitingCount() { if (waitingCount > 0) waitingCount--; }
    void setMaxWaitingSize(int size) { 
        if (size > 0) maxWaitingSize = size; 
        else cout << "Maximum waiting list size must be positive." << endl;
    }
    
    int getExamHour() const { return examHour; }
    void setExamHour(int hour) { 
        if (hour >= 0 && hour < 24) { 
            examHour = hour; 
        } else {
            cout << "Exam hour must be between 0 and 23." << endl;
        }
    }
    string getExamDate() const { return examDate; }
    void setExamDate(const string& date) { 
        if (!date.empty()) { 
            examDate = date; 
        } else {
            cout << "Exam date cannot be empty." << endl;
        }
    }
    
    void setMaxStudents(int ms) { 
        if (ms > 0) { 
            if (enrolledList != nullptr) {
                delete[] enrolledList; 
            }
            maxStudents = ms;
            enrolledList = new student[maxStudents]; 
            enrolledStudents = 0; 
        } else {
            cout << "Maximum number of students must be greater than zero." << endl;
        }
    }
    
    void setEnrollQueue(int size) {
        if (size > 0) {
            enrollqueue = new student[size]; 
        } else {
            enrollqueue = nullptr; 
        }
    }
    
    student* getEnrolledList() const {
        return enrolledList; 
    }
    int getEnrolledStudents() const { return enrolledStudents; }
    
    int getNumberOfEnrolledStudents() const {
        return enrolledStudents; 
    }
    
    void setEnrolledStudents(int count) {
        if (count >= 0 && count <= maxStudents) {
            enrolledStudents = count;
        }
    }
    
    int getMaxEnrolledStudents() const {
        return maxStudents; 
    }
    
    string getCourseName() const { return courseName; }
    
    void setCourseName(const string& cn) { 
        if (!cn.empty()) { 
            courseName = cn; 
        } else {
            cout << "Course name cannot be empty." << endl;
        }
    }
    int getCreditHours() const { return creditHours; }
    void setCreditHours(int ch) { 
        if (ch > 0) { 
            creditHours = ch; 
        } else {
            cout << "Credit hours must be greater than zero." << endl;
        }
    }
    int getMaxStudents() const { return maxStudents; }
    
    
    
    
};
class professor
{
private:
    string username;
    string password;
    string name;
    string lastname;
    string professorID;
    int TeachingLoad; 
    course* Courses; 
public:
    
    professor() 
        : username(""), password(""), name(""), lastname(""), professorID(""), TeachingLoad(0), Courses(nullptr) {
        
    }
    
    ~professor() {
        delete[] Courses;
    }
    
    string getUsername() const { return username; }
    void setUsername(const string& u) { username = u; }
    string getPassword() const { return password; }
    void setPassword(const string& p) { password = p; }
    string getName() const { return name; }
    void setName(const string& n) { name = n; }
    string getLastname() const { return lastname; }
    void setLastname(const string& l) { lastname = l; }
    string getProfessorID() const { return professorID; }
    void setProfessorID(string id) { professorID = id; }
    int getTeachingLoad() const { return TeachingLoad; }
    void setTeachingLoad(int tl) { 
        if (tl >= 0) { 
            TeachingLoad = tl; 
        } else {
            cout << "Teaching load cannot be negative." << endl;
        }
    }
    
    string* getNameOfCourses() const {
        if (Courses != nullptr) {
            string* courseNames = new string[TeachingLoad];
            for (int i = 0; i < TeachingLoad; i++) {
                courseNames[i] = Courses[i].getCourseName();
            }
            return courseNames; 
        }
        return nullptr; 
    }
    void setNameOfCourses(int tl, string* noc) {
        if (tl > 0) { 
            delete[] Courses; 
            TeachingLoad = tl;
            Courses = new course[tl]; 
            for (int i = 0; i < tl; i++) {
                Courses[i].setCourseName(noc[i]); 
            }
        } else {
            cout << "Teaching load must be greater than zero." << endl;
        }
    }
    
    
    
    
    
};


bool loginStudent(student& s, const string& username, const string& password) {
    return (s.getUsername() == username && s.getPassword() == password);
}
bool loginProfessor(professor& p, const string& username, const string& password) {
    return (p.getUsername() == username && p.getPassword() == password);
}
bool searchStudent(student* students, int numberOfStudents, const string& username) {
    for (int i = 0; i < numberOfStudents; i++) {
        if (students[i].getUsername() == username) {
            return true; 
        }
    }
    return false; 
}
bool searchProfessor(professor* professors, int numberOfProfessors, const string& username) {
    for (int i = 0; i < numberOfProfessors; i++) {
        if (professors[i].getUsername() == username) {
            return true; 
        }
    }
    return false; 
}
void showInfoStudent(const student& s) {
    cout << "Student Information:" << endl;
    cout << "Name: " << s.getName() << " " << s.getLastname() << endl;
    cout << "Username: " << s.getUsername() << endl;
    cout << "Student ID: " << s.getStudentID() << endl;
    cout << "GPA of Term: " << s.getGPAofTerm() << endl;
    cout << "GPA of All Terms: " << s.getGPAofAllTerms() << endl;
    cout << "Credits of Term: " << s.getCreditofTerm() << endl;
}
void showInfoProfessor(const professor& p) {
    cout << "Professor Information:" << endl;
    cout << "Name: " << p.getName() << " " << p.getLastname() << endl;
    cout << "Username: " << p.getUsername() << endl;
    cout << "Professor ID: " << p.getProfessorID() << endl;
    cout << "Teaching Load: " << p.getTeachingLoad() << endl;
    string* courses = p.getNameOfCourses();
    if (courses != nullptr) {
        cout << "Courses Taught: ";
        for (int i = 0; i < p.getTeachingLoad(); i++) {
            cout << courses[i] << (i < p.getTeachingLoad() - 1 ? ", " : "");
        }
        cout << endl;
    }
}
int searchCurrentProffessorIndex(professor* professors, int numberOfProfessors, const string& username) {
    for (int i = 0; i < numberOfProfessors; i++) {
        if (professors[i].getUsername() == username) {
            return i; 
        }
    }
    return -1; 
}
int searchCurrentStudentIndex(student* students, int numberOfStudents, const string& username) {
    for (int i = 0; i < numberOfStudents; i++) {
        if (students[i].getUsername() == username) {
            return i; 
        }
    }
    return -1; 
}
bool hasConflict(const course& c1, const course& c2) {
    
    return (c1.getExamHour() == c2.getExamHour() && c1.getExamDate() == c2.getExamDate());
}

bool canEnrollInCourse(const student& s, course* courses, int numberOfCourses, const course& newCourse) {
    // Check for conflicts only with courses the student is already enrolled in
    for (int i = 0; i < numberOfCourses; i++) {
        // Only check courses where this student is enrolled
        student* enrolledList = courses[i].getEnrolledList();
        int enrolledCount = courses[i].getNumberOfEnrolledStudents();
        bool studentEnrolled = false;
        
        // Check if student is enrolled in this course
        for (int j = 0; j < enrolledCount; j++) {
            if (enrolledList[j].getUsername() == s.getUsername()) {
                studentEnrolled = true;
                break;
            }
        }
        
        // Only check for conflict if student is enrolled in this course
        if (studentEnrolled && hasConflict(courses[i], newCourse)) {
            cout << "Conflict with course: " << courses[i].getCourseName() << endl;
            return false;
        }
    }
    return true;
}

bool addToEnrollQueue(course& c, const student& s) {
    
    if (c.getEnrollQueue() == nullptr) {
        
        c.setEnrollQueue(10);
    }
    
    
    student* waitingQueue = c.getEnrollQueue();
    if (waitingQueue == nullptr) return false;
    
    int waitingCount = c.getWaitingCount();
    
    
    if (waitingCount < c.getMaxWaitingSize()) {
        waitingQueue[waitingCount] = s;
        c.incrementWaitingCount();
        cout << "Added to waiting list. Position: " << waitingCount + 1 << endl;
        return true;
    }
    
    cout << "Waiting list is also full!" << endl;
    return false;
}


bool processWaitlist(course& c) {
    if (c.getNumberOfEnrolledStudents() < c.getMaxEnrolledStudents() && c.getWaitingCount() > 0) {
        
        student* waitingQueue = c.getEnrollQueue();
        if (waitingQueue == nullptr) return false;
        
        int enrolled = c.enrollStudent(waitingQueue[0]);
        if (enrolled == 0) {
            cout << "Student " << waitingQueue[0].getName() << " " 
                 << waitingQueue[0].getLastname() << " automatically enrolled from waitlist." << endl;
            
            for (int i = 0; i < c.getWaitingCount() - 1; i++) {
                waitingQueue[i] = waitingQueue[i + 1];
            }
            c.decrementWaitingCount();
            return true;
        }
    }
    return false;
}

int main(){
    cout << "Welcome to the University Management System!" << endl;
    int numberOfStudents = 1;
    int numberOfProfessors = 1;
    int numberOfCourses = 1;
    int indexOfStudents = 0;
    int indexOfProfessors = 0;
    int indexOfCurrentProfessor;
    int indexOfCurrentStudent;
    int indexOfCourses = 0;
    student* students = new student[numberOfStudents];
    professor* professors = new professor[numberOfProfessors]; 
    course* courses = new course[numberOfCourses];
    
    char userType;
    while(true){
    cout << "Are you a student (s) or a professor (p)? ";
    cin >> userType;
    cout <<"Please enter your username: ";
    string username;
    cin >> username;
    cout <<"Please enter your password: ";
    string password;
    cin >> password;
    if (username.empty() || password.empty()) {
        cout << "Username and password cannot be empty." << endl;
        delete[] students;
        delete[] professors;
        delete[] courses;
        return 1; 
    }
    if (userType == 's' || userType == 'S') {
        
        if(!searchStudent(students, numberOfStudents, username)) {
            if (indexOfStudents >= numberOfStudents) {
                int newSize = numberOfStudents * 2;
                student* newStudents = new student[newSize];
                for (int i = 0; i < numberOfStudents; i++) {
                    newStudents[i] = students[i];
                }
                delete[] students;
                students = newStudents;
                numberOfStudents = newSize;
            }
            
            students[indexOfStudents].setUsername(username);
            students[indexOfStudents].setPassword(password);
            cout << " Enter your name: ";
            string name;
            cin >> name;
            cout << " Enter your last name: ";
            string lastname;
            cin >> lastname;
            students[indexOfStudents].setName(name);
            students[indexOfStudents].setLastname(lastname);
            cout << " Enter your student ID: ";
            string studentID;
            cin >> studentID;
            students[indexOfStudents].setStudentID(studentID);
            cout << " Enter your GPA of the term: ";
            float gpaOfTerm;
            cin >> gpaOfTerm;
            students[indexOfStudents].setGPAofTerm(gpaOfTerm);
            cout << " Enter your GPA of all terms: ";
            float gpaOfAllTerms;
            cin >> gpaOfAllTerms;
            students[indexOfStudents].setGPAofAllTerms(gpaOfAllTerms);
            indexOfStudents++; 
            indexOfCurrentStudent = indexOfStudents - 1;
            if (students[indexOfCurrentStudent].getGPAofTerm() > 12 && students[indexOfCurrentStudent].getGPAofTerm() < 17)
            {
                students[indexOfCurrentStudent].setCreditofTerm(20);
                students[indexOfCurrentStudent].setMashroot(false);
                students[indexOfCurrentStudent].setAlef(false);
            }
            else if (students[indexOfCurrentStudent].getGPAofTerm() < 12)
            {
                students[indexOfCurrentStudent].setCreditofTerm(14);
                students[indexOfCurrentStudent].setMashroot(true);
                students[indexOfCurrentStudent].setAlef(false);
            }
            else if(students[indexOfCurrentStudent].getGPAofTerm() > 17)
            {
                students[indexOfCurrentStudent].setCreditofTerm(24);
                students[indexOfCurrentStudent].setMashroot(false);
                students[indexOfCurrentStudent].setAlef(true);
            }
            
        }
        else{
            indexOfCurrentStudent = searchCurrentStudentIndex(students, numberOfStudents, username);
            showInfoStudent(students[indexOfCurrentStudent]); 
            cout << "Welcome back, " << students[indexOfCurrentStudent].getName() << "!" << endl;
        }
        while (true)
        {
            if (students[indexOfCurrentStudent].getGPAofTerm() > 12 && students[indexOfCurrentStudent].getGPAofTerm() < 17)
            {
                cout << "Pay Attention!" << endl;
                cout << "*------------------------------------------------------------------------*"<< endl;
                cout << "You can have credits up to 20 next term and you can't have fewer than 12." << endl;

            }
            else if (students[indexOfCurrentStudent].getGPAofTerm() < 12)
            {
                cout << "Pay Attention!" << endl;
                cout << "*---------------------------------------*"<< endl;
                cout << "You can have credits up to 14 next term." << endl;
            }
            else if(students[indexOfCurrentStudent].getGPAofTerm() > 17)
            {
                cout << "Pay Attention!" << endl;
                cout << "*------------------------------------------------------------------------*"<< endl;
                cout << "You can have credits up to 24 next term and you can't have fewer than 12." << endl;
            }
            
            
            cout << "What do you want to do?" << endl;
            cout << "1. Enroll in a course" << endl;
            cout << "2. Drop a course" << endl; 
            cout << "3. Show enrolled courses" << endl;
            cout << "4. Change username" << endl;
            cout << "5. Change password" << endl;
            cout << "6. Show your information" << endl;
            cout << "7. Show all courses" << endl; 
            cout << "8. Show courses of each Professor" << endl; 
            cout << "9. Exit" << endl; 
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice < 1 || choice > 9) {
                cout << "Invalid choice. Please try again." << endl;
                continue; 
            }
            if (choice == 1) {
                
                if (indexOfCourses <= 0) {
                    cout << "No courses available to enroll in." << endl;
                    continue; 
                }
                cout << "Available courses:" << endl;
                for (int i = 0; i < indexOfCourses; i++) {
                    cout << i + 1 << ". " 
                         << courses[i].getCourseName() 
                         << " (Code: " 
                         << courses[i].getCourseCode() 
                         << ", Max Students: " 
                         << courses[i].getMaxStudents() 
                         << ", Professor: "
                         << courses[i].getNameOfProfessor()
                         << ")" 
                         << endl;
                }
                cout << "Enter the course number to enroll: ";
                int courseNumber;
                cin >> courseNumber;
                if (courseNumber < 1 || courseNumber > indexOfCourses) {
                    cout << "Invalid course number." << endl;
                    continue; 
                }
                
                
                if (!canEnrollInCourse(students[indexOfCurrentStudent], courses, indexOfCourses, courses[courseNumber - 1])) {
                    cout << "Cannot enroll due to exam time conflicts with your existing courses." << endl;
                    continue; 
                }

                
                int enrolled = courses[courseNumber - 1].enrollStudent(students[indexOfCurrentStudent]);
                int isValid = students[indexOfCurrentStudent].getCreditofTerm() - courses[courseNumber - 1].getCreditHours();
                if (enrolled == 0) {
                    cout << "Successfully enrolled in the course!" << endl;
                    
                
                }
                else if ( enrolled == 1){
                    cout << "Not enough credits available to enroll in this course." << endl;
                } else {
                    cout << "Course is full. Adding to waiting list..." << endl;
                    bool addedToQueue = addToEnrollQueue(courses[courseNumber - 1], students[indexOfCurrentStudent]);
                    if (addedToQueue) {
                        cout << "Added to waiting list." << endl;
                    } else {
                        cout << "Waiting list is full." << endl;
                    }
                }
                
                
            } else if (choice == 2) {
                cout << "Enter the course code to drop: ";
                string dropCode;
                cin >> dropCode;
                bool found = false;
                for (int i = 0; i < indexOfCourses; i++) {
                    if (courses[i].getCourseCode() == dropCode) {
                        student* enrolledList = courses[i].getEnrolledList();
                        int enrolledCount = courses[i].getNumberOfEnrolledStudents();
                        for (int j = 0; j < enrolledCount; j++) {
                            if (enrolledList[j].getUsername() == students[indexOfCurrentStudent].getUsername()) {
                                int courseCredits = courses[i].getCreditHours();
                                students[indexOfCurrentStudent].setCreditofTerm(
                                    students[indexOfCurrentStudent].getCreditofTerm() + courseCredits
                                );
                                
                                for (int k = j; k < enrolledCount - 1; k++) {
                                    enrolledList[k] = enrolledList[k + 1];
                                }
                                courses[i].setEnrolledStudents(enrolledCount - 1);
                                cout << "Successfully dropped the course." << endl;
                                found = true;
                                
                                processWaitlist(courses[i]);
                                break;
                            }
                        }
                        if (!found) {
                            cout << "You are not enrolled in this course." << endl;
                        }
                        break;
                    }
                }
                if (!found) {
                    cout << "Course not found." << endl;
                }
                
            } else if (choice == 3) {
                cout << "Enrolled courses:" << endl;
                bool hasEnrolledCourses = false;
                for (int i = 0; i < indexOfCourses; i++) {
                    student* enrolledList = courses[i].getEnrolledList();
                    int enrolledCount = courses[i].getNumberOfEnrolledStudents();
                    for (int j = 0; j < enrolledCount; j++) {
                        if (enrolledList[j].getUsername() == students[indexOfCurrentStudent].getUsername()) {
                            cout << courses[i].getCourseName() 
                                 << " (Code: " 
                                 << courses[i].getCourseCode() 
                                 << ")" 
                                 << endl;
                            hasEnrolledCourses = true;
                            break;
                        }
                    }
                }
                if (!hasEnrolledCourses) {
                    cout << "You are not enrolled in any courses." << endl;
                }
            } 
            else if (choice == 4) {
                cout << "Enter new username: ";
                string newUsername;
                cin >> newUsername;
                if (newUsername.empty()) {
                    cout << "Username cannot be empty." << endl;
                    continue; 
                }
                students[indexOfCurrentStudent].setUsername(newUsername);
                cout << "Username changed successfully." << endl;
            } 
            else if (choice == 5) {
                cout << "Enter new password: ";
                string newPassword;
                cin >> newPassword;
                if (newPassword.empty()) {
                    cout << "Password cannot be empty." << endl;
                    continue; 
                }
                students[indexOfCurrentStudent].setPassword(newPassword);
                cout << "Password changed successfully." << endl;
            } 
            else if (choice == 6) {
                showInfoStudent(students[indexOfCurrentStudent]);
            } 
            else if (choice == 7) {
                
                cout << "All available courses:" << endl;
                for (int i = 0; i < indexOfCourses; i++) {
                    cout << i + 1 << ". " 
                         << courses[i].getCourseName() 
                         << " (Code: " 
                         << courses[i].getCourseCode() 
                         << ", Max Students: " 
                         << courses[i].getMaxStudents()
                         << ", Professor: "
                         << courses[i].getNameOfProfessor()
                         << ")" 
                         << endl;
                }
            } 
            else if (choice == 8) {

                cout << "Courses of each professor:" << endl;
                for (int i = 0; i < indexOfProfessors; i++) {
                    cout << "Professor: " << professors[i].getName() << endl;
                    string* courseNames = professors[i].getNameOfCourses();
                    if (courseNames != nullptr) {
                        cout << "Courses: ";
                        for (int j = 0; j < professors[i].getTeachingLoad(); j++) {
                            cout << courseNames[j] << (j < professors[i].getTeachingLoad() - 1 ? ", " : "");
                        }
                        cout << endl;
                    }
                }
            }
            else if (choice == 9) {
                break; 
            } 
            else {
                cout << "Invalid choice. Please try again." << endl;
            }
            
        }
    }
        
        
    
    else if (userType == 'p' || userType == 'P') {
        
        indexOfCurrentProfessor = searchCurrentProffessorIndex(professors, numberOfProfessors, username);
        if(!searchProfessor(professors, numberOfProfessors, username)) {
            if (indexOfProfessors >= numberOfProfessors) {
                int newSize = numberOfProfessors * 2;
                professor* newProfessors = new professor[newSize];
                for (int i = 0; i < numberOfProfessors; i++) {
                    newProfessors[i] = professors[i];
                }
                delete[] professors;
                professors = newProfessors;
                numberOfProfessors = newSize;
            }
            
            professors[indexOfProfessors].setUsername(username);
            professors[indexOfProfessors].setPassword(password);
            cout << " Enter your name: ";
            string name;
            cin >> name;
            cout << " Enter your last name: ";
            string lastname;
            cin >> lastname;
            professors[indexOfProfessors].setName(name);
            professors[indexOfProfessors].setLastname(lastname);
            cout << " Enter your professor ID: ";
            string professorID;
            cin >> professorID;
            professors[indexOfProfessors].setProfessorID(professorID);
            indexOfProfessors++; 
            indexOfCurrentProfessor = indexOfProfessors - 1;
        }
        else {
            if(indexOfCurrentProfessor >= 0) {
                showInfoProfessor(professors[indexOfCurrentProfessor]); 
                cout << "Welcome back, " << professors[indexOfCurrentProfessor].getName() << "!" << endl;
            } else {
                cout << "Error: Professor account found but unable to retrieve index." << endl;
                continue;
            }
        }
        int choice;
        while (true){
            cout << "What do you want to do?" << endl;
            cout << "1. Add a new course" << endl;
            cout << "2. Remove a course" << endl;
            cout << "3. Change username" << endl;
            cout << "4. Change password" << endl;
            cout << "5. Show enrolled students in a course" << endl;
            cout << "6. Exit" << endl;
            cin >> choice;
        if (choice < 1 || choice > 6) {
            cout << "Invalid choice. Please try again." << endl;
            continue; 
        }
        if( choice == 1) {
            if (indexOfCourses >= numberOfCourses) {
                int newSize = numberOfCourses * 2;
                course* newCourses = new course[newSize];
                for (int i = 0; i < numberOfCourses; i++) {
                    newCourses[i] = courses[i];
                }
                delete[] courses;
                courses = newCourses;
                numberOfCourses = newSize;
            }
            
            cout << "Enter course code: ";
            string courseCode;
            cin >> courseCode;
            cout << "Enter course name: ";
            string courseName;
            cin >> courseName;
            cout << "Enter branch number: ";
            string branchNumber;
            cin >> branchNumber;
            cout << "Enter exam hour (0-23): ";
            int examHour;
            cin >> examHour;
            cout << "Enter exam date (YYYY-MM-DD): ";
            string examDate;
            cin >> examDate;
            cout << "Enter credit hours: ";
            int creditHours;
            cin >> creditHours;
            cout << "Enter maximum students: ";
            int maxStudents;
            cin >> maxStudents;
            courses[indexOfCourses] = course(branchNumber, courseCode, professors[indexOfCurrentProfessor].getName(), courseName, creditHours, maxStudents, examDate, examHour);
            indexOfCourses++;
        } else if (choice == 2) {
            
        cout << "Enter the course code to remove: ";
        string removeCode;
        cin >> removeCode;
        bool found = false;
        for (int i = 0; i < indexOfCourses; i++) {
            if (courses[i].getCourseCode() == removeCode) {
                for (int j = i; j < indexOfCourses - 1; j++) {
                    courses[j] = courses[j + 1];
                }
                indexOfCourses--;
                cout << "Course removed successfully." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Course not found." << endl;
        }
        } else if (choice == 3) {
            
            cout << "Enter new username: ";
            string newUsername;
            cin >> newUsername;
            if(!newUsername.empty()) {
                professors[indexOfCurrentProfessor].setUsername(newUsername);
                cout << "Username changed successfully." << endl;
            } else {
                cout << "Username cannot be empty." << endl;
            }
        } else if (choice == 4) {
            
            cout << "Enter new password: ";
            string newPassword;
            cin >> newPassword;
            professors[indexOfCurrentProfessor].setPassword(newPassword);
        } else if (choice == 5) {
            

            cout << "Enter the course code to view enrolled students: ";
            string courseCode;
            cin >> courseCode;
            bool found = false;
            for (int i = 0; i < indexOfCourses; i++) {
                if (courses[i].getCourseCode() == courseCode) {
                    found = true;
                    student* enrolledList = courses[i].getEnrolledList();
                    int enrolledCount = courses[i].getNumberOfEnrolledStudents();
                    cout << "Enrolled students in " << courses[i].getCourseName() << ":" << endl;
                    for (int j = 0; j < enrolledCount; j++) {
                        cout << enrolledList[j].getName() << " " 
                             << enrolledList[j].getLastname() 
                             << " (ID: " 
                             << enrolledList[j].getStudentID() 
                             << ")" 
                             << endl;
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Course not found." << endl;
            }
        } else if (choice == 6) {
            break; 
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
            continue; 
        }
        
    } 
    } else {
        cout << "Invalid user type. Please enter 's' for student or 'p' for professor." << endl;
        continue; 
    }
}
    
    delete[] students;
    delete[] professors;
    delete[] courses;
    cout << "Thank you for using the University Management System!" << endl;
    return 0;
    }
