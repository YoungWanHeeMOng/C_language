
#include <string>
#include <iostream>

using namespace std;

class Product
{
    string name;
    int price;

    public :
        Product(string _name, int _price) {
            SetName(_name);
            SetPrice(_price);
        }
        virtual int GetPrice() const
        {
            return price;
        }
        virtual string GetName() const
        {
            return name;
        }

        virtual  void Print() const
        {
            cout << name << "�Ǹ� ����: " << GetPrice() << endl;
        }
    private:
        void SetName(string _name)
        {
            this->name=_name;
        }
        void SetPrice(int _price)
        {
            this->price=_price;
        }

};

class DiscountProduct : public Product
{
    int discount;
    public:
        DiscountProduct(string name, int price, int discount) :Product(name, price)
        {
            SetDiscount(discount);
        }
        int GetDiscount() const
        {
            return discount;
        }
        virtual int GetPrice() const
        {
            int origin_price=Product::GetPrice();
            int dc=origin_price*discount/100;
            return origin_price-dc;
        }
        virtual void Print() const
        {
            cout << "��ǰ ����: " << Product::GetPrice() << "   ������: "<< discount <<   endl;
            Product::Print();
        }

   private :
       void SetDiscount(int discount)
       {
           this->discount=discount;
        }

};



int main() {

    Product *p1=new Product("ġ��", 3000);
    Product* p2 = new DiscountProduct("ĩ��", 3000,15);
    p1->Print();
    p2->Print();

    delete p1;
    delete p2;



    return 0;
}