#include "Account.h"

Account::Account(string usn, string pw){
    username = usn;
    password = pw;
    sodu = 0;
    fstream file;
    file.open("Account.txt", ios::app);
    if(file.is_open()){
        file<<username<<"."<<password<<"."<< sodu<<".";
        file.close();
    }
}

Account::Account(){

}

void Account::creatData(string usn, string pw, int sd){
    username = usn;
    password = pw;
    sodu = sd;
}

bool Account::login(){
    string pw;
    cout << "Password: \n";
    cin >> pw;
    if(pw == password){
        cout<<"Success";
        return true;
    }
    else{
        cout<<"Password error\n";
        return false;
    }
}

void Account::guiTien(){
    int tong=0;
    for(int i=0; i<4; i++){
        int mg, sl;
        cout<<"\nMenh gia: ";
        cin>>mg;
        cout<<"\nSo luong: ";
        cin>>sl;
        sodu += mg*sl;
        tong += mg*sl;
    }
    cout<<endl<<tong<<endl;
}

void Account::thongTin(){
    system("cls");
    cout<<"Ten tai khoan: "<<username<<endl;
    cout<<"So du: "<<sodu<< "000 vnd"<<endl;

}

int Account::chuyenTien(){
    cout<<"\nNhap so tien:";
    int tien;
    cin>>tien;
    if(tien <= sodu){
        sodu-=tien;
        cout<<"\nChuyen thanh cong";
        return tien;
    }
    cout<<"\nSo du khong du";
    return 0;
}

bool Account::nhanTien(int tien){
    if(tien > 0){
        sodu+= tien;
        return true;
    }
    else return false;
}
