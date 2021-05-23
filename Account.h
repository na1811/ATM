#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<ctime>

using namespace std;


class Account
{
private:
    string username;
    string password;
    string id;
    int sodu;
    int nsai;
public:
    Account(string _id, string usn, string pw);
    Account();
    ~Account() {

    }
    void taotk(string usn, string _id, string pw, int sd, int ns);
    bool login();
    string getUsername() const { return username; }
    string getID () const {return id; }
    string getPassword() const { return password; }
    string getSoDu() const { return to_string(sodu);}
    string getNsai() const { return to_string(nsai); }
    void guiTien( int bank[]);
    void thongTin();
    int chuyenTien();
    bool nhanTien(int tien);
    void rutTien(int bank[]);
    void inLichSu();
    void vietLichSu(string s);
    string thoidiem();
    void khoaTK( int &ktk);
    void doiMK( int &dmk );
};

#endif // ACCOUNT_H
