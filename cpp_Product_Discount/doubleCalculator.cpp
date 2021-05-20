/*
    연산자 중복 정의 및 개체 출력자 포함
*/

#include <iostream>
#include <string>

using namespace std;

class FunObject
{
    public:
        int operator() (int a, int b)
        {
            return a+b;
        }
};

class Member
{
    int num;
    string name;
    public :
        Member(int num, string name)
        {
            this->num=num;
            this->name=name;
        }
        int GetNum() const
        {
            return num;
        }

        string GetName() const
        {
            return name;
        }
};

ostream& operator << (ostream& os, const Member* data)
{
    os << "번호: " << data->GetNum() << " 이름: " << data->GetName();
    return os;
}

class IEqual
{
    public :
        virtual bool operator()(Member* data)=0;
};

class MemberCollection
{
    int count;
    Member** base;
    const int capacity;
    public :
        MemberCollection(int capacity) : capacity(capacity)
        {
            base = new Member* [capacity];
            count=0;
        }

        ~MemberCollection()
        {
            delete[] base;
        }
        bool PushBack(Member* data)
        {
            if (IsFull())
            {
                return false;
            }
            base[count]=data;
            count++;
            return true;
        }

        bool IsFull() const
        {
            return count == capacity;
        }

        bool IsAvaillndex(int index)const
        {
            return (index >=0) && (index < capacity);
        }

        int GetCount() const
        {
            return count;
        }

        Member*& operator[](int index)
        {
            if (IsAvaillndex(index) == false)
            {
                throw "사용할 수 없는 인덱스";
            }
            return base[index];
        }

        Member* FindIf(IEqual& ie)
        {
            for (int i = 0; i < count; i++)
            {
                if (ie(base[i]))
                {
                    return base[i];
                }
            }

            return NULL;
        }
       

};

class IEqualNum:public IEqual
{
    int num;
public:
    IEqualNum(int num)
    {
        this->num=num;
    }
    virtual bool operator()(Member* data)
    {
        return num == data->GetNum();
    }
};


int main()
{
    /*FunObject fobj;
    cout << fobj(3,4) << endl;
    cout << fobj.operator()(4,5) << endl;*/

    MemberCollection dc(100);

    dc.PushBack(new Member(3,"홍길동"));
    dc.PushBack(new Member(2, "강감찬"));
    dc.PushBack(new Member(6, "을지문덕"));
    dc.PushBack(new Member(7, "한석봉"));

    int count = dc.GetCount();
    for (int i = 0; i < count; i++)
    {
        cout << dc[i] << endl;
    }

    cout << "검색할 회원 번호: ";
    int num;
    cin >> num;
    IEqualNum en(num);
    Member * member=dc.FindIf(en);
    if (member != NULL)
    {
        cout << member << endl;
    }
    else {
        cout << "찾지 못하였음" << endl;
    }

    for (int i = 0; i < count; i++)
    {
        delete dc[i];
    }
   
    return 0;
 }