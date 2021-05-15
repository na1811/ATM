#include"Account.h"

vector<Account> list_account;

void initData(){
    ifstream file("Account.txt");
    string usn, pw, sodu;
    while(getline(file, usn, '.')){
        getline(file, pw, '.');
        getline(file, sodu, '.');
        Account p;
        p.creatData(usn, pw, stoi(sodu));
        list_account.push_back(p);
    }
}

void saveData(){
    ofstream file("Account.txt");
    for(Account x : list_account){
        file << x.getUsername() <<"."<<x.getPassword()<<"."<< x.getSoDu() << ".";
    }
    file.close();
}

void waitKeyPress(){
    int x = 1;
    while(x){
        cin >> x;
    }
}
int main()
{
    initData();
    while (true) {
        int choose = 0;
        cout << "1.Dang nhap\n2.Tao tk\n";
        cin >> choose;
        if (choose == 1) {
            string usn;
            cout << "Username: \n";
            cin >> usn;
            bool ok = false;
            for (int i = 0; i < list_account.size(); i++) {
                if(list_account.at(i).getUsername() == usn){
                    if (list_account.at(i).login()) {
                        //Login success
                        //tai khoan hien tai
                        Account* tkht = &list_account.at(i);
                        LOOP:
                        system("cls");
                        cout<<"\n1.Gui tien\n2.Chuyen tien\n3.Rut tien\n4.Thong tin\n5.Lich su\n";
                        int chon;
                        cin>>chon;
                        switch(chon){
                            case 1:
                                tkht->guiTien();
                                break;
                            case 2:
                                {
                                string tkk;
                                cout << "So tai khoan: ";
                                cin>>tkk;
                                for(int j = 0; j < list_account.size(); j++){
                                    if(tkk == list_account.at(j).getUsername()){
                                        list_account.at(j).nhanTien(tkht->chuyenTien());
                                    }
                                }
                                break;
                                }
                            case 3:
                            case 4:
                                tkht->thongTin();
                                waitKeyPress();
                                goto LOOP;
                                break;
                            case 5:
                            default:
                                break;
                        }
                    }

                ok = true;
                }
            }
            if(!ok) cout<<"Account does not exist\n";
        }
        else if (choose == 2) {
            string usn, pw;
            cout << "Username: \n";
            cin >> usn;
            cout << "Password: \n";
            cin >> pw;
            Account p(usn, pw);
            list_account.push_back(p);
        }

        saveData();

        waitKeyPress();

        system("cls");
    }
}


/* 1
100 2
200 0
500 3


1200
1200 - 500 = 700
700 - 500 = 200
200 - 100 = 100

sotiencr
while(sotiencr > 500 && bank[500] > 0){
    sitien -= 500;
    sl500 +=1;
    bank[500]--;
}
while(//)

if(sotien == 0) cout<<sl 500, 200,
*/

