#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class Account
{
private:
    string username;
    string password;
    int sodu;
    bool active;
    int numFail;
public:
    Account(string usn, string pw);
    Account();
    ~Account() {

    }
    void creatData(string usn, string pw, int sd);
    bool login();
    string getUsername() const { return username; }
    string getPassword() const { return password; }
    string getSoDu() const { return to_string(sodu);}
    void guiTien();
    void thongTin();
    int chuyenTien();
    bool nhanTien(int tien);
};

#endif // ACCOUNT_H
