#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;
class SinhVien {
    protected:
        char MSV[10]; 
        char HoTen[100];
        char NganhHoc[100];
    public:
        void setSinhVien(char [], char [], char []);
        void setMSV(char[]);
        void setHoTen(char[]);
        void setNganhHoc(char[]);
        string getMSV();
        string getHoTen();
        string getNganhHoc();
};
void SinhVien :: setSinhVien(char msv[], char hoten[], char nganhhoc[]) {
    strcpy(MSV, msv);
    strcpy(HoTen, hoten);
    strcpy(NganhHoc, nganhhoc);
}

void SinhVien :: setMSV(char msv[]) {
    strcpy(MSV, msv);
}

void SinhVien :: setHoTen(char hoten[]) {
    strcpy(HoTen, hoten);
}

void SinhVien :: setNganhHoc(char nganhhoc[]) {
    strcpy(NganhHoc, nganhhoc);
}

string SinhVien :: getMSV() {
    return MSV;
}

string SinhVien :: getHoTen() {
    return HoTen;
}

string SinhVien :: getNganhHoc() {
    return NganhHoc;
}
class Sach {
	protected:
        char MaSach[10];
        char TenSach[100];
        char TheLoai[100];
        char TacGia[100];
        int NamXuatBan;
    public:
        void setSach(char[], char[], char[], char[], int);
        void setMaSach(char[]);
        void setTenSach(char[]);
        void setTheLoai(char[]);
        void setTacGia(char[]);
        void setNamXuatBan(int);
        string getMaSach();
        string getTenSach();
        string getTheLoai();
        string getTacGia();
        int getNamXuatBan();
};
void Sach :: setSach(char Ma[], char Ten[], char Loai[], char TG[], int NXB) {
    strcpy(MaSach, Ma);
    strcpy(TenSach, Ten);
    strcpy(TheLoai, Loai);
    strcpy(TacGia, TG);
    NamXuatBan = NXB;
}

void Sach :: setMaSach(char Ma[]) {
    strcpy(MaSach, Ma);
}

void Sach :: setTenSach(char Ten[]) {
    strcpy(TenSach, Ten);
}

void Sach :: setTheLoai(char Loai[]) {
    strcpy(TheLoai, Loai);
}

void Sach :: setTacGia(char TG[]) {
    strcpy(TacGia, TG);
}

void Sach :: setNamXuatBan(int NXB) {
    this -> NamXuatBan = NXB;
}

string Sach :: getMaSach() {
    return MaSach;
}

string Sach :: getTenSach() {
    return TenSach;
}

string Sach :: getTheLoai() {
    return TheLoai;
}

string Sach :: getTacGia() {
    return TacGia;
}

int Sach :: getNamXuatBan() {
    return NamXuatBan;
}
class MuonTra : public Sach, public SinhVien {
    public:
        void setMuon(char [], char []);
        void setTra(char [], char []);
};
void MuonTra :: setMuon (char msv[], char Ma[]) {
    strcpy(MSV, msv);
    strcpy(MaSach, Ma);
}

void MuonTra :: setTra (char msv[], char Ma[]) {
    strcpy(MSV, msv);
    strcpy(MaSach, Ma);
}
void Menu();
void ThemSach();
void SuaSach();
void XoaSach();
void ThemSinhVien();
void SuaSinhVien();
void XoaSinhVien();
void MuonSach();
void TraSach();
void ToanBoSach();
void ToanBoSinhVien();
void SachMotSinhVienMuon();
void ToanBoSachDuocMuon();
void Thoat();
void Menu() {
    cout << "\t\tCHUONG TRINH QUAN LY THU VIEN ^^!" << endl;
    cout << endl;
    cout << "1.  Nhap them mot cuon sach" << endl;
    cout << "2.  Sua thong tin sach" << endl;
    cout << "3.  Xoa mot cuon sach" << endl;
    cout << "4.  Nhap thong tin sinh vien" << endl;
    cout << "5.  Sua thong tin sinh vien" << endl;
    cout << "6.  Xoa thong tin sinh vien" << endl;
    cout << "7.  Muon sach" << endl;
    cout << "8.  Tra sach" << endl;
    cout << "9.  Liet ke toan bo sach trong thu vien" << endl;
    cout << "10. Liet ke toan bo sinh vien" << endl;
    cout << "11. Liet ke nhung sach duoc muon cua mot sinh vien" << endl;
    cout << "12. Liet ke toan bo sach duoc muon trong thu vien" << endl;
    cout << "13. Thoat khoi he thong" << endl;
    cout << "=> Moi chon chuc nang: ";
}

void ThemSach() {
    cout << "\t\tNhap them mot cuon sach" << endl;
    cout << endl;
    char MS[10], Ten[100], Loai[100], TG[100];
    int NXB;;
    cin.ignore();
    cout << "- Nhap ma sach: ";
    cin.getline(MS, 10);
    cout << "- Nhap ten sach: ";
    cin.getline(Ten, 100);
    cout << "- Nhap the loai: ";
    cin.getline(Loai, 100);
    cout << "- Nhap tac gia: ";
    cin.getline(TG, 100);
    cout << "- Nhap nam xuat ban: ";
    cin >> NXB;
    Sach New;
    New.setSach(MS, Ten, Loai, TG, NXB);
    cout << endl;
    cout << "\t\tThem sach thanh cong ^^" << endl;
    ofstream saveSach("sach.bin", ios :: binary | ios :: app);
    saveSach.write((char*)(&New), sizeof(Sach));
    saveSach.close(); 
}

void SuaSach() {
    cout << "\t\tSua thong tin sach" << endl;
    cout << endl;
    string Find;
    char newMa[10], newTen[100], newLoai[100], newTG[100];
    int newNXB;
    Sach change;
    cin.ignore();
    cout << "Nhap ma sach can sua: ";
    getline(cin, Find);
    ifstream readSach("sach.bin", ios :: binary);
    ofstream changeSach("changesach.bin", ios :: binary);
    if(!readSach) {
        cout << endl;
        cout << "\t\tLoi doc du lieu !" << endl;
    }
    else {
        bool check = false;
        while(!readSach.eof()) {
            readSach.read((char *)(&change), sizeof(Sach));
            if(readSach.good()) {
                if(Find == change.getMaSach()) {
                    strcpy(newMa, Find.c_str());
                    change.setMaSach(newMa);
                    cout << "- Nhap ten sach moi: ";
                    cin.getline(newTen, 100);
                    change.setTenSach(newTen);
                    cout << "- Nhap the loai moi: ";
                    cin.getline(newLoai, 100);
                    change.setTheLoai(newLoai);
                    cout << "- Nhap tac gia moi: ";
                    cin.getline(newTG, 100);
                    change.setTacGia(newTG);
                    cout << "- Nhap nam xuat ban moi: ";
                    cin >> newNXB;
                    change.setNamXuatBan(newNXB);
                    cout << endl;
                    cout << "\t\tSua thong tin sach thanh cong ^^" << endl;
                    check = true;
                }
                changeSach.write((char*)(&change), sizeof(Sach));
            }
        }
        if(check == false) {
            cout << endl;
            cout << "\t\tMa sach vua nhap khong ton tai. Vui long thu lai !" << endl;
        }
    }
    changeSach.close();
    readSach.close();
    ofstream save_readSach("sach.bin", ios :: binary);
    ifstream read_changeSach("changesach.bin", ios :: binary);
    while(!read_changeSach.eof()) {
        read_changeSach.read((char*)(&change), sizeof(Sach));
        if(read_changeSach.good()) {
            save_readSach.write((char*)(&change), sizeof(Sach));
        }
    }
    read_changeSach.close();
    save_readSach.close();
}

void XoaSach() {
    cout << "\t\tXoa mot cuon sach" << endl;
    cout << endl;
    string Find;
    Sach Delete;
    MuonTra Muon;
    cin.ignore();
    cout << "- Nhap ma sach can xoa: ";
    getline(cin, Find);
    ifstream readSach("sach.bin", ios :: binary);
    ifstream readMuon("muontra.bin", ios :: binary);
    ofstream deleteSach("deletesach.bin", ios :: binary);
    if(!readMuon) {
        cout << endl;
        cout << "\t\tLoi doc du lieu !" << endl;
    }
    else {
        bool check_1 = false;
        while(!readMuon.eof()) {
            readMuon.read((char *)(&Muon), sizeof(MuonTra));
            if(Find == Muon.getMaSach()) {
                check_1 = true;
            }
        }
        if(check_1 == false) {
            if(!readSach) {
                cout << endl;
                cout << "\t\tLoi doc du lieu !" << endl;
            }
            else {
                bool check_2 = false;
                while(!readSach.eof()) {
                    readSach.read((char *)(&Delete), sizeof(Sach));
                    if(Find == Delete.getMaSach()) {
                        readSach.read((char *)(&Delete), sizeof(Sach));
                        check_2 = true;
                    }
                    if(readSach.good()) {
                        deleteSach.write((char *)(&Delete), sizeof(Sach));
                    }
                }
                if(check_2 == false) {
                    cout << endl;
                    cout << "\t\tMa sach khong ton tai. Vui long thu lai!" << endl;
                }
                else {
                    cout << endl;
                    cout << "\t\tXoa thanh cong!" << endl;
                }
            }
        }
        else {
            cout << endl;
            cout << "\t\tSach nay dang duoc muon. Khong the xoa, vui long thu lai!" << endl;
            return;
        }
    }
    deleteSach.close();
    readMuon.close();
    readSach.close();
    ofstream save_readSach("sach.bin", ios :: binary);
    ifstream read_deleteSach("deletesach.bin", ios :: binary);
    while(!read_deleteSach.eof()) {
        read_deleteSach.read((char *)(&Delete), sizeof(Sach));
        if(read_deleteSach.good()) {
            save_readSach.write((char *)(&Delete), sizeof(Sach));
        }
    }
    read_deleteSach.close();
    save_readSach.close();
}

void ThemSinhVien() {
    cout << "\t\tNhap thong tin sinh vien" << endl;
    cout << endl;
    char msv[10], hoten[100], nganhhoc[100];
    cin.ignore();
    cout << "- Nhap ma sinh vien: ";
    cin.getline(msv, 10);
    cout << "- Nhap ho va ten: ";
    cin.getline(hoten, 100);
    cout << "- Nhap nganh hoc: ";
    cin.getline(nganhhoc, 100);
    SinhVien New;
    New.setSinhVien(msv, hoten, nganhhoc);
    cout << endl;
    cout << "\t\tThem sinh vien thanh cong ^^" << endl;
    ofstream saveSinhVien("sinhvien.bin", ios :: binary | ios :: app);
    saveSinhVien.write((char*)(&New), sizeof(SinhVien));
    saveSinhVien.close();
}

void SuaSinhVien() {
    cout << "\t\tSua thong tin sinh vien" << endl;
    cout << endl;
    char newMSV[10], newHoTen[100], newNganhHoc[100];
    string Find;
    SinhVien change;
    cin.ignore();
    cout << "Nhap ma sinh vien can sua: ";
    getline(cin, Find);
    ifstream readSinhVien("sinhvien.bin", ios :: binary);
    ofstream changeSinhVien("changesinhvien.bin", ios :: binary);
    if(!readSinhVien) {
        cout << endl;
        cout << "\t\tLoi doc du lieu !" << endl;
    }
    else {
        bool check = false;
        while(!readSinhVien.eof()) {
            readSinhVien.read((char *)(&change), sizeof(SinhVien));
            if(readSinhVien.good()) {
                if(Find == change.getMSV()) {
                    strcpy(newMSV, Find.c_str());
                    change.setMSV(newMSV);
                    cout << "- Nhap ho va ten moi: ";
                    cin.getline(newHoTen, 100);
                    change.setHoTen(newHoTen);
                    cout << "- Nhap nganh hoc moi: ";
                    cin.getline(newNganhHoc, 100);
                    change.setNganhHoc(newNganhHoc);
                    cout << endl;
                    cout << "\t\tSua thong tin sinh vien thanh cong ^^" << endl;
                    check = true;
                }
                changeSinhVien.write((char*)(&change), sizeof(SinhVien));
            }
        }
        if(check == false) {
            cout << endl;
            cout << "\t\tMa sinh vien vua nhap khong ton tai. Vui long thu lai !" << endl;
        }
    }
    changeSinhVien.close();
    readSinhVien.close();
    ofstream save_readSinhVien("sinhvien.bin", ios :: binary);
    ifstream read_changeSinhVien("changesinhvien.bin", ios :: binary);
    while(!read_changeSinhVien.eof()) {
        read_changeSinhVien.read((char*)(&change), sizeof(SinhVien));
        if(read_changeSinhVien.good()) {
            save_readSinhVien.write((char*)(&change), sizeof(SinhVien));
        }
    }
    read_changeSinhVien.close();
    save_readSinhVien.close();
}

void XoaSinhVien() {
    cout << "\t\tXoa thong tin sinh vien" << endl;
    cout << endl;
    string Find;
    SinhVien Delete;
    MuonTra Muon;
    cin.ignore();
    cout << "- Nhap ma sinh vien can xoa: ";
    getline(cin, Find);
    ifstream readSinhVien("sinhvien.bin", ios :: binary);
    ifstream readMuon("muontra.bin", ios :: binary);
    ofstream deleteSinhVien("deletesinhvien.bin", ios :: binary);
    if(!readMuon) {
        cout << endl;
        cout << "\t\tLoi doc du lieu !" << endl;
    }
    else {
        bool check_1 = false;
        while(!readMuon.eof()) {
            readMuon.read((char *)(&Muon), sizeof(MuonTra));
            if(Find == Muon.getMSV()) {
                check_1 = true;
            }
        }
        if(check_1 == false) {
            if(!readSinhVien) {
                cout << endl;
                cout << "\t\tLoi doc du lieu !" << endl;
            }
            else {
                bool check_2 = false;
                while(!readSinhVien.eof()) {
                    readSinhVien.read((char *)(&Delete), sizeof(SinhVien));
                    if(Find == Delete.getMSV()) {
                        readSinhVien.read((char *)(&Delete), sizeof(SinhVien));
                        check_2 = true;
                    }
                    if(readSinhVien.good()) {
                        deleteSinhVien.write((char *)(&Delete), sizeof(SinhVien));
                    }
                }
                if(check_2 == false) {
                    cout << endl;
                    cout << "\t\tMa sinh vien khong ton tai. Vui long thu lai!" << endl;
                }
                else {
                    cout << endl;
                    cout << "\t\tXoa thanh cong!" << endl;
                }
            }
        }
        else {
            cout << endl;
            cout << "\t\tSinh vien nay dang muon sach. Khong the xoa, vui long thu lai!" << endl;
            return;
        }
    }
    deleteSinhVien.close();
    readMuon.close();
    readSinhVien.close();
    ofstream save_readSinhVien("sinhvien.bin", ios :: binary);
    ifstream read_deleteSinhVien("deletesinhvien.bin", ios :: binary);
    while(!read_deleteSinhVien.eof()) {
        read_deleteSinhVien.read((char *)(&Delete), sizeof(SinhVien));
        if(read_deleteSinhVien.good()) {
            save_readSinhVien.write((char *)(&Delete), sizeof(SinhVien));
        }
    }
    read_deleteSinhVien.close();
    save_readSinhVien.close();
}

void MuonSach() {
    cin.ignore();
    cout << "\t\tMuon sach" << endl;
    cout << endl;
    string MSV, MS;
    char msv[10], ms[10];
    cout << "- Nhap ma sinh vien: ";
    getline(cin, MSV);
    strcpy(msv, MSV.c_str());
    cout << "- Nhap ma sach: ";
    getline(cin, MS);
    strcpy(ms, MS.c_str());
    MuonTra Muon;
    Sach sach;
    SinhVien sinhvien;
    Muon.setMuon(msv, ms);
    bool check_1 = false, check_2 = false;
    ifstream readSinhVien("sinhvien.bin", ios :: binary);
    if(!readSinhVien) {
        cout << endl;
        cout << "\t\tLoi doc du lieu" << endl;
    }
    else {
        while(!readSinhVien.eof()) {
            readSinhVien.read((char *)(&sinhvien), sizeof(SinhVien));
            if(readSinhVien.good()) {
                if(MSV == sinhvien.getMSV()){
                    check_1 = true;
                }
            }
        }
    }
    readSinhVien.close();
    ifstream readSach("sach.bin", ios :: binary);
    if(!readSach) {
        cout << endl;
        cout << "\t\tLoi doc du lieu" << endl;
    }
    else {
        while(!readSach.eof()) {
            readSach.read((char *)(&sach), sizeof(Sach));
            if(readSach.good()) {
                if(MS == sach.getMaSach()) {
                    check_2 = true;
                }
            }
        }
    }
    readSach.close();
    if(check_1 == true && check_2 == true) {
        ofstream saveMuon("muontra.bin", ios :: binary | ios :: app);
        saveMuon.write((char*)(&Muon), sizeof(MuonTra));
        saveMuon.close();
        cout << endl;
        cout << "\t\tMuon sach thanh cong!" << endl;
    }
    else if(check_1 == true && check_2 != true) {
        cout << endl;
        cout << "\t\tMa sach khong ton tai. Vui long thu lai!" << endl;
    }
    else if(check_1 != true && check_2 == true) {
        cout << endl;
        cout << "\t\tMa sinh vien khong ton tai. Vui long thu lai!" << endl;
    }
    else {
        cout << endl;
        cout << "\t\tMa sach va ma sinh vien khong ton tai. Vui long thu lai!" << endl;
    }
}

void TraSach() {
    cin.ignore();
    cout << "\t\tTra sach" << endl;
    cout << endl;
    string msv, ms;
    MuonTra Tra;
    cout << "- Nhap ma sinh vien: ";
    getline(cin, msv);
    cout << "- Nhap ma sach: ";
    getline(cin, ms);
    ifstream readMuon("muontra.bin", ios :: binary);
    ofstream deleteMuon("deletemuon.bin", ios :: binary);
    if(!readMuon) {
        cout << endl;
        cout << "\t\tLoi doc du lieu !" << endl;
    }
    else {
        bool check = false;
        while(!readMuon.eof()) {
            readMuon.read((char *)(&Tra), sizeof(MuonTra));
            if(msv == Tra.getMSV() && ms == Tra.getMaSach()) {
                readMuon.read((char *)(&Tra), sizeof(MuonTra));
                cout << endl;
                cout << "\t\tTra sach thanh cong!" << endl;
                check = true;
            }
            if(readMuon.good()) {
                deleteMuon.write((char *)(&Tra), sizeof(MuonTra));
            }
        }
        if (check == false) {
            cout << endl;
            cout << "\t\tMa sinh vien hoac ma sach khong dung :( Vui long thu lai!" << endl;
        }
    }
    deleteMuon.close();
    readMuon.close();
    ofstream save_readMuon("muontra.bin", ios :: binary);
    ifstream read_deleteMuon("deletemuon.bin", ios :: binary);
    while(!read_deleteMuon.eof()) {
        read_deleteMuon.read((char *)(&Tra), sizeof(MuonTra));
        if(read_deleteMuon.good()) {
            save_readMuon.write((char *)(&Tra), sizeof(MuonTra));
        }
    }
    read_deleteMuon.close();
    save_readMuon.close();
}

void ToanBoSach() {
    cout << "\t\tLiet ke toan bo sach trong thu vien" << endl;
    cout << endl;
    cout << "STT\tMa sach\t\tTen sach\t\tThe loai\t\tTac gia\t\t\tNam xuat ban\n";
    cout << endl;
    int stt = 0;
    Sach old;
    ifstream printSach("sach.bin", ios :: binary);
    if(!printSach) {
        cout << endl;
        cout << "\t\tLoi doc du lieu !" << endl;
    }
    else {
        while(!printSach.eof()) {
            printSach.read((char *)(&old), sizeof(Sach));
            if(printSach.good()) {
                cout << stt + 1 << "\t";
                cout << old.getMaSach() << "\t\t";
                cout << old.getTenSach() << "\t\t";
                cout << old.getTheLoai() << "\t\t";
                cout << old.getTacGia() << "\t\t";
                cout << old.getNamXuatBan() << endl;
            }
            stt++;
        }
    }
    printSach.close();
}

void ToanBoSinhVien() {
    cout << "\t\tLiet ke toan bo sinh vien" << endl;
    cout << endl;
    cout << "STT\tMSV\t\tHo va ten\t\tNganh hoc\n";
    cout << endl;
    int stt = 0;
    SinhVien old;
    ifstream printSinhVien("sinhvien.bin", ios :: binary);
    if(!printSinhVien) {
        cout << endl;
        cout << "\t\tLoi doc du lieu !" << endl;
    }
    else {
        while(!printSinhVien.eof()) {
            printSinhVien.read((char *)(&old), sizeof(SinhVien));
            if(printSinhVien.good()) {
                cout << stt + 1 << "\t";
                cout << old.getMSV() << "\t\t";
                cout << old.getHoTen() << "\t\t";
                cout << old.getNganhHoc() << endl;
            }
            stt++;
        }
    }
    printSinhVien.close();
}

void SachMotSinhVienMuon() {
    cin.ignore();
    cout << "\t\tLiet ke nhung sach duoc muon cua mot sinh vien" << endl;
    cout << endl;
    string Find;
    int stt = 0;
    cout << "Nhap ma sinh vien: ";
    getline(cin, Find);
    cout << endl;
    cout << "STT\tMa sach\t\tTen sach\t\tThe loai\t\tTac gia\t\t\tNam xuat ban" << endl;
    cout << endl;
    ifstream readMuon("muontra.bin", ios :: binary);
    MuonTra printMuon;
    Sach Muon;
    if(!readMuon) {
        cout << endl;
        cout << "\t\tLoi doc du lieu !" << endl;
    }
    else {
        bool check = false;
        while(!readMuon.eof()) {
            readMuon.read((char *)(&printMuon), sizeof(MuonTra));
            if(readMuon.good()) {
                if(Find == printMuon.getMSV()) {
                    cout << stt + 1 << "\t";
                    cout << printMuon.getMaSach() << "\t\t";
                    ifstream readSach("sach.bin", ios :: binary);
                    if(!readSach) {
                        cout << endl;
                        cout << "\t\tLoi doc du lieu !" << endl;
                    }
                    else {
                        while(!readSach.eof()) {
                            readSach.read((char *)(&Muon), sizeof(Sach));
                            if(readSach.good()) {
                                if(printMuon.getMaSach() == Muon.getMaSach()) {
                                    cout << Muon.getTenSach() << "\t\t";
                                    cout << Muon.getTheLoai() << "\t\t";
                                    cout << Muon.getTacGia() << "\t\t";
                                    cout << Muon.getNamXuatBan() << endl;
                                }
                            }
                        }
                    }
                    readSach.close();
                    stt++;
                    check = true;
                }
            }
        }
        if (check == false) {
            cout << endl;
            cout << "\t\tMa sinh vien khong ton tai :( Vui long thu lai!" << endl;
        }
    }
    readMuon.close();
}

void ToanBoSachDuocMuon() {
    cout << "\t\tLiet ke toan bo sach duoc muon trong thu vien" << endl;
    cout << endl;
    cout << "STT\tMSV\t\tHo va ten\t\tMa sach\t\tTen sach\t\tThe loai\t\tTac gia\t\t\tNam xuat ban" << endl;
    cout << endl;
    int stt = 0;
    ifstream readMuon("muontra.bin", ios :: binary);
    SinhVien printSinhVien;
    MuonTra printMuon;
    Sach printSach;
    if(!readMuon) {
        cout << endl;
        cout << "\t\tLoi doc du lieu !" << endl;
    }
    else {
        while(!readMuon.eof()) {
            readMuon.read((char *)(&printMuon), sizeof(MuonTra));
            if(readMuon.good()) {
                cout << stt + 1 << "\t";
                cout << printMuon.getMSV() << "\t\t";
                ifstream readSinhVien("sinhvien.bin", ios :: binary);
                if(!readSinhVien) {
                    cout << endl;
                    cout << "\t\tLoi doc du lieu !" << endl;
                }
                else {
                    while(!readSinhVien.eof()) {
                        readSinhVien.read((char *)(&printSinhVien), sizeof(SinhVien));
                        if(readSinhVien.good()) {
                            if(printMuon.getMSV() == printSinhVien.getMSV()) {
                                cout << printSinhVien.getHoTen() << "\t\t";
                            }
                        }
                    }
                }
                readSinhVien.close();
                ifstream readSach("sach.bin", ios :: binary);
                if(!readSach) {
                    cout << endl;
                    cout << "\t\tLoi doc du lieu !" << endl;
                }
                else {
                    while(!readSach.eof()) {
                        readSach.read((char *)(&printSach), sizeof(Sach));
                        if(readSach.good()) {
                            if(printMuon.getMaSach() == printSach.getMaSach()) {
                                cout << printSach.getMaSach() << "\t\t";
                                cout << printSach.getTenSach() << "\t\t";
                                cout << printSach.getTheLoai() << "\t\t";
                                cout << printSach.getTacGia() << "\t\t";
                                cout << printSach.getNamXuatBan() << endl;
                            }
                        }
                    }
                }
                readSach.close();
                stt++;
            }
        }
    }
    readMuon.close();
}

void Thoat() {
    cout << endl;
    cout << "\t\t\t\tChuc moi nguoi ngay moi tot lanh!" << endl;
    cout<<"\t\t**---------------------  \\(^.^)/  ---------------------**";
    cout << endl;
}


int main() {
    int chon;
    do {
        Menu();
        cin >> chon;
        cout << "============================================================================================" << endl;
        switch(chon) {
            case 1:
                ThemSach();
                break;
            case 2:
                SuaSach();
                break;
            case 3:
                XoaSach();
                break;
            case 4:
                ThemSinhVien();
                break;
            case 5:
                SuaSinhVien();
                break;
            case 6:
                XoaSinhVien();
                break;
            case 7:
                MuonSach();
                break;
            case 8:
                TraSach();
                break;
            case 9:
                ToanBoSach();
                break;
            case 10:
                ToanBoSinhVien();
                break;
            case 11:
                SachMotSinhVienMuon();
                break;
            case 12:
                ToanBoSachDuocMuon();
                break;
            case 13:
                Thoat();
                break;
        }
        if(chon != 13) {
            cout << endl;
            cout << "============================================================================================"<<endl;
            cout << "=> Nhan Enter de tro ve !";
            cin.ignore();
            cin.get();
            system("cls");
        }
    }
    while(chon != 13);
	return 0;
}
