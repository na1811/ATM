#include"Account.h"

vector<Account> listTk;
int bank[501];
int ktk=2;
int dmk=2;

void data(){
    ifstream file("Account.txt");
    string usn, id, pw, sodu, nsai;
    while(getline(file, usn, '.')){
        getline(file, id,'.');
        getline(file, pw, '.');
        getline(file, sodu, '.');
        getline(file, nsai, '.');
        Account p;
        p.taotk(usn, id, pw, stoi(sodu), stoi(nsai));
        listTk.push_back(p);
    }
    ifstream f("Bank.txt");
    if(f.is_open()){
        while(!f.eof()){
            int mg, sl;
            f>> mg >> sl;
            bank[mg] = sl;
        }
        f.close();
    }
}

void saveDL(){
    ofstream file("Account.txt");
    for(Account x : listTk){
        file << x.getUsername() <<"."<<x.getID()<<"."<<x.getPassword()<<"."<< x.getSoDu() << "." << x.getNsai() << ".";
    }
    file.close();
    ofstream f("Bank.txt");
    f << "500 " << bank[500] <<endl;
    f << "200 " << bank[200] << endl;
    f << "100 " << bank[100] << endl;
    f << "50 " << bank[50] << endl;
    f.close();
}

int waitKeyPress(){
    int x = -1;
    while(x == -1){
        cin >> x;
    }
    return x;
}

int main()
{
    data();
    START:
    while (true) {
        system("cls");
        int choose = 0;
        cout<<endl;
        cout <<"------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout <<"                                           Chao mung ban den voi Super ATM!" <<endl;
        cout <<"------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
        cout << "\n        1.Dang nhap\n\n        2.Tao tai khoan\n\n";
        cin >> choose;
        if (choose == 1) {
            system("cls");
            string id;
            cout << "\n       Nhap ID: ";
            cin >> id;
            bool ok = false;
            for (int i = 0; i < listTk.size(); i++) {
                if(listTk.at(i).getID() == id){
                    if (listTk.at(i).login()) {
                        saveDL();
                        //Login success
                        //tai khoan hien tai
                        Account* tkht = &listTk.at(i);
                        MENU:
                        system("cls");
                        cout <<endl<<"   "<< tkht->thoidiem()<<endl<<endl;
                        cout <<"------------------------------------------------------------------------------------------------------------------------"<<endl;
                        cout <<"                                           Chuc mung " << tkht->getUsername() <<" dang nhap thanh cong!" <<endl;
                        cout <<"------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
                        cout <<"   Lua chon:\n";
                        cout <<"\n      1. Gui tien\n      2. Chuyen tien\n      3. Rut tien\n      4. Kiem tra tai khoan\n      5. Lich su giao dich\n      6. Khoa tai khoan\n      7. Doi mat khau\n      8. Dang xuat\n\n";
                        int chon;
                        cin>>chon;
                        switch(chon){
                            case 1:
                                system("cls");
                                tkht->guiTien( bank);
                                break;
                            case 2:
                                {
                                system("cls");
                                string idK;
                                cout << "\n     ID tai khoan can chuyen: ";
                                cin>>idK;
                                int dem=0;
                                for(int j = 0; j < listTk.size(); j++){
                                    if( idK == listTk.at(j).getID()){
                                        cout<<"\n     Ban co chac muon chuyen tien den ten tai khoan: "<< listTk.at(j).getUsername()<<" khong?\n";
                                        cout<<"\n1.Co\n2.Khong va quay lai.\n\n";
                                        int x;
                                        cin>>x;
                                        if( x==2) goto MENU;
                                        if(x==1) {
                                        system("cls");
                                        listTk.at(j).nhanTien(tkht->chuyenTien());
                                        dem++;
                                        }
                                    }
                                }
                                if ( dem ==0){
                                    cout<<"\n     ID khong hop le. Vui long thu lai!\n";
                                }
                                break;
                                }
                            case 3:
                                system("cls");
                                tkht->rutTien(bank);
                                break;
                            case 4:
                                system("cls");
                                tkht->thongTin();
                                break;
                            case 5:
                                system("cls");
                                tkht->inLichSu();
                                break;
                            case 6:
                                system("cls");
                                tkht->khoaTK(ktk);
                                if( ktk==1) goto MENU;
                                if( ktk==3) {
                                    cout<<"     Mat khau khong dung.\n\n";
                                    ktk=2;
                                }
                                break;
                            case 7:
                                system("cls");
                                tkht->doiMK( dmk);
                                if( dmk ==0){
                                    cout<<"\n\n    Nhap sai mat khau moi.\n";
                                }
                                if( dmk==1){
                                    cout<<"    Sai mat khau.\n";
                                }
                                break;
                            case 8:
                                system("cls");
                                goto START;
                                break;
                            default:
                                break;
                        }
                        saveDL();
                        if(ktk ==2){
                            cout<<"\nVui long lua chon:\n0.Quay lai\n1.Dang xuat\n\n";
                            int back = waitKeyPress();
                            if(back == 0) goto MENU;
                            else if(back == 1) {
                                goto START;
                                delete tkht;
                            }
                        }
                    }
                    else {
                        saveDL();
                        cout<<"\n\n1.Thoat\n\n";
                        int back = waitKeyPress();

                        if(back == 1) {
                            goto START;

                        }
                    }

                ok = true;
                }
            }
            if(!ok){
                cout<<"\n       ID khong ton tai!\n";
                int a;
                cout<<"\n       1.Thoat\n\n";
                cin>>a;
            }
        }
        else if (choose == 2) {
            TTK:
            system( "cls");
            string usn, id, pw;
            cout << "\n        Ten tai khoan: ";
            cin.ignore();
            getline(cin, usn);
            cout << "\n\n        ID: ";
            cin>> id;
            for (int i = 0; i < listTk.size(); i++) {
                if(listTk.at(i).getID() == id){
                    cout<<"\n        ID da ton tai. Vui long tao ID khac!";
                    cout<<"\n\n        0.Quay lai\n        1.Thoat\n\n";
                    int back = waitKeyPress();
                    if(back == 0) goto TTK;
                    else if(back == 1) {
                        goto START;
                    }
                }
            }
            cout << "\n\n        Mat khau: ";
            cin >> pw;
            Account p(id, usn, pw);
            listTk.push_back(p);
            saveDL();
            cout<<"\n\n        Tao tai khoan thanh cong!\n";
            cout<<"\n\n        0.Quay lai\n        1.Thoat\n\n";
            int back = waitKeyPress();
            if(back == 0) goto TTK;
            else if(back == 1) {
                goto START;
            }
        }
        saveDL();
    }
}



