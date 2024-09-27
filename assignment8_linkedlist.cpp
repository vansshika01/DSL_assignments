#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int prn;
    string name;
    Node* next;

    Node(int p, string n) {
        prn = p;
        name = n;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;      
    Node* secretary; 

public:
    LinkedList() {
        head = nullptr;
        secretary = nullptr;
    }

    void addPresident(int prn, string name) {
        Node* newPresident = new Node(prn, name);
        if (head == nullptr) {  
            head = newPresident;
        } else {  
            newPresident->next = head->next;  
            head = newPresident;
        }
        cout << "President added.\n";
    }

    void addSecretary(int prn, string name) {
        if (head == nullptr) {
            cout << "Please add a president first.\n";
            return;
        }

        Node* newSecretary = new Node(prn, name);

        if (secretary != nullptr) {
            newSecretary->next = secretary->next;  
            head->next = newSecretary;  
            secretary = newSecretary;
        } else {
            newSecretary->next = head->next; 
            head->next = newSecretary;
            secretary = newSecretary;
        }
        cout << "Secretary added.\n";
    }

    void addMember(int prn, string name) {
        Node* newMember = new Node(prn, name);

        if (head == nullptr) {
            head = newMember;
            cout << "Member added as the first member.\n";
            return;
        }

        Node* temp;

        if (secretary != nullptr) {
            temp = secretary;
        } else {
            temp = head;
        }

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newMember;
        cout << "Member added.\n";
    }

    void concat(LinkedList& otherList) {
        if (otherList.head == nullptr) {
            cout << "The provided list is empty. No students to concatenate.\n";
            return;
        }

        if (head == nullptr) { 
            head = otherList.head;
            secretary = otherList.secretary;
            cout << "Concatenated the provided list as the new club list.\n";
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = otherList.head;
        cout << "Concatenated the provided list to the club list.\n";
    }

    void deletePresident() {
        if (head == nullptr) {
            cout << "No president to delete.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head == secretary) {
            secretary = nullptr; 
        }

        delete temp;
        cout << "President deleted.\n";
    }

    void deleteSecretary() {
        if (head == nullptr || secretary == nullptr) {
            cout << "No secretary to delete.\n";
            return;
        }

        Node* temp = secretary;
        head->next = secretary->next; 
        secretary = nullptr;
        delete temp;
        cout << "Secretary deleted.\n";
    }

    void deleteMember(int prn) {
        if (head == nullptr) {
            cout << "No members in the club.\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->prn == prn) {
            deletePresident();
            return;
        }

        while (temp != nullptr && temp->prn != prn) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Member with PRN " << prn << " not found.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Member with PRN " << prn << " deleted.\n";
    }

    int countTotalStudents() {
        int count = 0;
        if (head != nullptr) count++; 
        if (secretary != nullptr) count++; 

        Node* temp = head;
        while (temp != nullptr) {
            count++; 
            temp = temp->next;
        }
        return count;
    }

    int countMembers() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void displayMembers() {
        Node* temp = head;

        if (temp == nullptr) {
            cout << "No members in the club.\n";
            return;
        }

        cout << "Members of the club:\n";
        while (temp != nullptr) {
            cout << temp->prn << " - " << temp->name << endl;
            temp = temp->next;
        }
    }

    void displayReverse(Node* node) {
        if (node == nullptr)
            return;

        displayReverse(node->next);
        cout << node->prn << " - " << node->name << endl;
    }

    void displayMembersReverse() {
        if (head == nullptr) {
            cout << "No members in the club.\n";
            return;
        }
        cout << "Members in reverse order:\n";
        displayReverse(head);
    }
};

int main() {
    LinkedList club;
    int choice, prn;
    string name;

    do {
        cout << "\nPinnacle Club Management System\n";
        cout << "1. Add President\n";
        cout << "2. Add Secretary\n";
        cout << "3. Add Member\n";
        cout << "4. Display Members\n";
        cout << "5. Display Members in Reverse Order\n";
        cout << "6. Delete President\n";
        cout << "7. Delete Secretary\n";
        cout << "8. Delete Member\n";
        cout << "9. Count Total Students\n";
        cout << "10. Count Number of Members\n";
        cout << "11. Concatenate Another List of Students\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter PRN and Name of the President: ";
            cin >> prn;
            cin.ignore();
            getline(cin, name);
            club.addPresident(prn, name);
            break;
        case 2:
            cout << "Enter PRN and Name of the Secretary: ";
            cin >> prn;
            cin.ignore();
            getline(cin, name);
            club.addSecretary(prn, name);
            break;
        case 3:
            cout << "Enter PRN and Name of the Member: ";
            cin >> prn;
            cin.ignore();
            getline(cin, name);
            club.addMember(prn, name);
            break;
        case 4:
            club.displayMembers();
            break;
        case 5:
            club.displayMembersReverse();
            break;
        case 6:
            club.deletePresident();
            break;
        case 7:
            club.deleteSecretary();
            break;
        case 8:
            cout << "Enter PRN of the member to delete: ";
            cin >> prn;
            club.deleteMember(prn);
            break;
        case 9:
            cout << "Total number of students: " << club.countTotalStudents() << endl;
            break;
        case 10:
            cout << "Total number of members: " << club.countMembers() << endl;
            break;
        case 11: {
            LinkedList otherClub;
            int n;
            cout << "Enter the number of students to add to the new list: ";
            cin >> n;

            for (int i = 0; i < n; ++i) {
                cout << "Enter PRN and Name of Student " << (i + 1) << ": ";
                cin >> prn;
                cin.ignore();
                getline(cin, name);
                otherClub.addMember(prn, name); // Add members only
            }
            club.concat(otherClub);
            break;
        }
        case 12:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 12);

    return 0;
}
