
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
            cout << name << "판매 가격: " << GetPrice() << endl;
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
            cout << "상품 가격: " << Product::GetPrice() << "   할인율: "<< discount <<   endl;
            Product::Print();
        }

   private :
       void SetDiscount(int discount)
       {
           this->discount=discount;
        }

};



int main() {

    Product *p1=new Product("치약", 3000);
    Product* p2 = new DiscountProduct("칫솔", 3000,15);
    p1->Print();
    p2->Print();

    delete p1;
    delete p2;



    return 0;
}