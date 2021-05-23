#include "Account.h"

Account::Account(string _id, string usn, string pw){
    id= _id;
    username = usn;
    password = pw;
    sodu = 0;
    nsai =0;
    fstream file;
    file.open("Account.txt", ios::app);
    if(file.is_open()){
        file<<username<<"."<<id<<"."<<password<<"."<< sodu<<"."<<nsai<<".";
        file.close();
    }
}

Account::Account(){

}

void Account::creatData(string usn, string _id, string pw, int sd, int ns){
    username = usn;
    id=_id;
    password = pw;
    sodu = sd;
    nsai = ns;
}

bool Account::login(){
    if(nsai <= 5){
        string pw;
        cout << "\n       Mat khau: ";
        cin >> pw;
        if(pw == password){
            vietLichSu("Dang nhap thanh cong!");
            nsai = 0;
            return true;
        }
        else{
            cout<<"\n       Sai mat khau.\n";
            vietLichSu("Dang nhap that bai.");
            nsai += 1;
            return false;
        }
    }
    else {
        cout<<"\n       Tai khoan da bi khoa!";
        vietLichSu("Tai khoan da bi khoa!");
        return false;
    }
}

void Account::guiTien( int bank[]){
    int tong=0, sl500, sl200, sl100, sl50;
    cout<<"\n        Menh gia 500k -> So luong: ";
    cin>> sl500;
    tong += sl500 *500;
    sodu += sl500 *500;
    bank[500]+= sl500;
    cout<<"\n\n        Menh gia 200k -> So luong: ";
    cin>> sl200;
    tong += sl200 *200;
    sodu += sl200 *200;
    bank[200]+= sl200;
    cout<<"\n\n        Menh gia 100k -> So luong: ";
    cin>> sl100;
    tong += sl100 *100;
    sodu += sl100 *100;
    bank[100]+= sl100;
    cout<<"\n\n        Menh gia 50k -> So luong: ";
    cin>> sl50;
    tong += sl50 *50;
    sodu += sl50 *50;
    bank[50]+= sl50;
    cout<<"\n    Gui thanh cong " <<tong<<"k vnd." <<endl;
    vietLichSu("Gui tien thanh cong: +" + to_string(tong)+ "k vnd.");
}

void Account::thongTin(){
    system("cls");
    cout<<"\n     Ten tai khoan: "<<username<<endl;
    cout<<"     ID: "<<id<<endl;
    cout<<"     So du: "<<sodu<< "k vnd."<<endl;
}

int Account::chuyenTien(){
    cout<<"\n     Nhap so tien: ";
    int tien;
    cin>>tien;
    if(tien <= sodu){
        sodu-=tien;
        cout<<"\n     Chuyen thanh cong "<<tien<<"k vnd!\n";
        vietLichSu("Chuyen tien thanh cong: -" + to_string(tien)+"k vnd.");
        return tien;
    }
    cout<<"\nSo du khong du.\n\n";
    return 0;
}

bool Account::nhanTien(int tien){
    if(tien > 0){
        sodu+= tien;
        vietLichSu("Nhan tien: +" + to_string(tien)+ "k vnd.");
        return true;
    }
    else return false;
}
void Account::rutTien(int bank[]){
    cout<<"\n      Nhap so tien can rut: ";
    int sotien, stc;
    cin>> sotien;
    stc = sotien;
    if(sotien <= sodu){
        int a[4];
        a[0] = bank[500];
        a[1] = bank[200];
        a[2] = bank[100];
        a[3] = bank[50];

        for(int i=0; i<4; i++){
            int giatri = 50;
            if(i == 0) giatri = 500;
            else if(i == 1) giatri = 200;
            else if (i == 2) giatri = 100;
            else giatri=50;
            while(sotien >= giatri && a[i] > 0){
                sotien -= giatri;
                a[i] --;
            }
        }

        if(sotien == 0) {
            sodu -= stc;

            cout<<"\n      Menh gia           So luong";
            cout<<"\n        500k                "<<bank[500]-a[0];
            cout<<"\n        200k                "<<bank[200]-a[1];
            cout<<"\n        100k                "<<bank[100]-a[2];
            cout<<"\n         50k                "<<bank[50]-a[3]<<endl;
            cout<<"\n      Rut thanh cong: "<<stc<<"k vnd.\n";
            bank[500] = a[0];
            bank[200] = a[1];
            bank[100] = a[2];
            bank[50] = a[3];

            vietLichSu("Rut tien thanh cong: -" + to_string(stc)+"k vnd.");
        }
        else cout<<"\n      Loi ngan hang.\n";

    }
    else cout<<"\n      So du khong du.\n";
}

void Account::inLichSu(){
    ifstream file(username + ".txt");
    string s;
    while(getline(file, s)){
        cout<<s<<endl;
    }
    file.close();
}
void Account::vietLichSu(string s){
    fstream file;
    file.open(username + ".txt", ios::app);
    file <<"\n    "<<thoidiem() <<"\n    "<< s<<endl <<endl<< "------------------------------------------"<<endl;
    file.close();
}

string Account::thoidiem()
{
    time_t rawtime;
    time(&rawtime);
    string tc = ctime(&rawtime);
    tc.erase(tc.length() - 1, 1);
    return tc;
}

void Account::khoaTK(int & ktk)
{
    string pw;
    cout<<"\n     Nhap mat khau: ";
    cin>> pw;
    if( pw== password){
        cout<<"     Ban co chac chan muon khoa tai khoan khong?\n"
            <<"     1.Co        2.Khong va quay lai\n\n";
        int x;
        cin>>x;
        if( x==1){
                nsai=10;
                ktk=0;
                cout<<"      Khoa tai khoan thanh cong!\n";
        }
        else if( x==2){
                ktk=1;
        }
        else{
                cout<<"Khong hop le.\n";
        }
    }
    else{
        ktk=3;
    }
}

void Account::doiMK( int &dmk)
{
    string pwc, pwm1, pwm2;
    cout<<"\n    Nhap mat khau hien tai: ";
    cin>> pwc;
    if( pwc== password){
        cout<<"\n    Nhap mat khau moi: ";
        cin>> pwm1;
        cout<<"\n    Nhap lai mat khau moi: ";
        cin>> pwm2;
        if( pwm1==pwm2){
            dmk=2;
            password=pwm1;
            cout<<"\n\n    Doi mat khau thanh cong!\n";
        }
        else {
            dmk=0;
        }
    }
    else{
        dmk=1;
    }
}
