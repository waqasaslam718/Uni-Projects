#include <iostream>

using namespace std;

int main() {
    
    string name = "Your Name";
    string studentID = "Your Student ID";

    
    cout << "Name: " << name << endl;
    cout << "Student ID: " << studentID << endl;

    int choice;
    do {
     
        cout << "\nMenu:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "How many numbers do you want to add? ";
                cin >> n;
                double sum = 0;
                for (int i = 0; i < n; ++i) {
                    double num;
                    cout << "Enter number " << i + 1 << ": ";
                    cin >> num;
                    sum += num;
                }
                cout << "Result: " << sum << endl;
                break;
            }
            case 2: {
                int n;
                cout << "How many numbers do you want to subtract? ";
                cin >> n;
                double result;
                cout << "Enter number 1: ";
                cin >> result;
                for (int i = 1; i < n; ++i) {
                    double num;
                    cout << "Enter number " << i + 1 << ": ";
                    cin >> num;
                    result -= num;
                }
                cout << "Result: " << result << endl;
                break;
            }
            case 3: {
                int n;
                cout << "How many numbers do you want to multiply? ";
                cin >> n;
                double product = 1;
                for (int i = 0; i < n; ++i) {
                    double num;
                    cout << "Enter number " << i + 1 << ": ";
                    cin >> num;
                    product *= num;
                }
                cout << "Result: " << product << endl;
                break;
            }
            case 4: {
                int n;
                cout << "How many numbers do you want to divide? ";
                cin >> n;
                double result;
                cout << "Enter numerator: ";
                cin >> result;
                for (int i = 1; i < n; ++i) {
                    double num;
                    cout << "Enter denominator " << i + 1 << ": ";
                    cin >> num;
                    if (num == 0) {
                        cout << "Error: Division by zero is not allowed." << endl;
                        result = 0;
                        break;
                    }
                    result /= num;
                }
                cout << "Result: " << result << endl;
                break;
            }
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
