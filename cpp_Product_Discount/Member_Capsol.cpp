
#include <iostream>
#include <string>

using namespace std;

class Member {
  static int last_num;
  const int num;
  string name;
    //int count;
    public :
        Member(string name):num(++last_num)   {this->name=name;}

        static  int  GetMemberCount() {
            return  last_num;
        }
        string GerName()const
        {
            return name;
        }
        string ToString() const
        {
            char buf[256]="";
            sprintf_s(buf, sizeof(buf),"번호:%04d 이름:%s", num, name.c_str());
            return buf;
        }

        bool IsEqual(int num) const
        {
            return this->num == num;
        }

        bool IsEqual(string name)const
        {
            return this->name == name;
        }
        
    private:
        void SetMember(string name) {
            this->name = name;
        }
};

int Member::last_num;

int main() {
    Member * marr[3];
    // 회원 개체 생성
    marr[0]=new Member("홍길동");
    marr[1] = new Member("강감찬");
    marr[2] = new Member("이순실");

    // 회원 목록 출력
    cout << "현재 회원 수: " << Member::GetMemberCount() <<  endl;

    for (int i = 0; i < 3; i++)
    {
        cout << marr[i]->ToString() << endl;
    }

    // 회원 이름 검색
    string name;
    cout << "검색할 이름 : ";
    cin >> name;
    bool check =false;
    for (int i = 0; i < 3; i++)
    {
        if (marr[i]->IsEqual(name)) {
            cout << marr[i]->ToString() << endl;
            check=true;
        }
    }
    if (check == false)
    {
        cout << "없습니다." << endl;
    }
    // 회원 번호 검색
    int num;
    cout << "검색할 번호: ";
    cin >> num;
    int i;
    for (i = 0; i <  3; i++)
    {
        if (marr[i]->IsEqual(num))
        {
            cout << marr[i]->ToString() << endl;
            break;
        }
    }
    if (i == 3)
    {
        cout << "없습니다."<< endl;
    }

    // 회원 개체 소멸
    for (i = 0; i < 3; i++)
    {
        delete marr[i];
    }
}