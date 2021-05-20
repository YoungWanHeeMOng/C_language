
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
            sprintf_s(buf, sizeof(buf),"��ȣ:%04d �̸�:%s", num, name.c_str());
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
    // ȸ�� ��ü ����
    marr[0]=new Member("ȫ�浿");
    marr[1] = new Member("������");
    marr[2] = new Member("�̼���");

    // ȸ�� ��� ���
    cout << "���� ȸ�� ��: " << Member::GetMemberCount() <<  endl;

    for (int i = 0; i < 3; i++)
    {
        cout << marr[i]->ToString() << endl;
    }

    // ȸ�� �̸� �˻�
    string name;
    cout << "�˻��� �̸� : ";
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
        cout << "�����ϴ�." << endl;
    }
    // ȸ�� ��ȣ �˻�
    int num;
    cout << "�˻��� ��ȣ: ";
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
        cout << "�����ϴ�."<< endl;
    }

    // ȸ�� ��ü �Ҹ�
    for (i = 0; i < 3; i++)
    {
        delete marr[i];
    }
}