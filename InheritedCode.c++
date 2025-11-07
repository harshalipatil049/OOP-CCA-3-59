#include <iostream>
#include <string>
using namespace std;

class TooShort : public exception {
    int len;
public:
    TooShort(int n) : len(n) {}
    int length() const { return len; }
};

void check_username(const string& username) {
    if (username.length() < 4) {
        throw TooShort(username.length());
    }
    for (char c : username) {
        if (!isalpha(c)) {
            throw runtime_error("Invalid");
        }
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string username;
        getline(cin, username);
        try {
            check_username(username);
            cout << "Valid" << endl;
        } catch (TooShort &e) {
            cout << "Too short: " << e.length() << endl;
        } catch (...) {
            cout << "Invalid" << endl;
        }
    }
    return 0;
}
