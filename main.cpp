#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

// Hardcoded Password (Security Risk)
char const * ADMIN_DB_PASS = "hussain_admin_2026";

void buffer_vulnerability() {
    char buffer[16];
    cout << "Enter student ID for deletion: ";
    // VULNERABILITY: Use of gets() [Stack Overflow]
    gets(buffer); 
    cout << "Deleting student record " << buffer << "..." << endl;
}

void format_string_vulnerability(char* input) {
    // VULNERABILITY: Format String Vulnerability
    printf(input); 
    printf("\n");
}

void command_injection() {
    char filename[64];
    cout << "Enter filename to check logs: ";
    cin >> filename;
    
    char cmd[128];
    // VULNERABILITY: Command Injection
    sprintf(cmd, "ls -l %s", filename);
    system(cmd);
}

int main(int argc, char** argv) {
    cout << "=== Hussain's C++ Student Portal ===" << endl;
    
    if (argc > 1) {
        format_string_vulnerability(argv[1]);
    }

    int choice;
    while(true) {
        cout << "\n1. Delete Student (Buffer Check)\n2. View Logs (Command Injection)\n3. Exit\nChoice: ";
        cin >> choice;
        getchar(); // consume newline
        
        if (choice == 1) buffer_vulnerability();
        else if (choice == 2) command_injection();
        else if (choice == 3) break;
        else cout << "Invalid choice" << endl;
    }

    return 0;
}
