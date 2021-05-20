/*
    �ļ� Ʈ���� �̿��� ���� ����
*/

#include <iostream>
#include <string>

using namespace std;

class Calculator
{
    string expr;
    int tcnt=0;
    public:
        Calculator(string expr)
        {
            this->expr=expr;
            tcnt=0;
        }

        void Run()
        {
            cout << expr << " ����մϴ�." << endl;
            if (Lexical())
            {
                if (Syntax())
                {
                    Parsing();
                    PostOrderView();
                    cout << expr << " = " << Calculate() << endl;
                }
                else 
                {
                    cout << "���Ŀ� ����� ǥ���� ������ ���� �ʽ��ϴ�." << endl;
                }
            } 
            else 
            {
            cout << "����� �� ���� ��ȣ�� �ֽ��ϴ�" << endl;
            }
            cout << endl;
        }

    private:
        bool Lexical()
        {
            int i=0;
            while (expr[i])
            {
                if (IsOperator(expr[i]))
                {
                    i=MakeOperator(i);
                }
                else {
                    if (IsDigit(expr[i]))
                    {
                        i=MakeOperand(i);
                    }
                    else {
                        return false;
                    }
                }
            }
            return true;
        }

        bool IsOperator(char ch)
        {

        return   (ch=='+') || (ch=='-') || (ch=='*') || (ch=='/');

        }
        bool IsDigit(char ch)
        {
            return (ch >= '0') && (ch <= '9');
        }

        struct Token
        {
            int priority;
            virtual void View()=0;
            bool MoreThanPriority(Token* token)
            {
                return priority >= token->priority;
            }
        };

        struct Operator :public Token
        {
            char ch;
            Operator(char ch)
            {
                this->ch=ch;
                if ((ch == '+') || (ch == '-'))
                {
                    priority=1;
                }
                else {
                    priority=2;
                }

            }
            void View()
            {
                cout << ch << " ";
            }
        };

        Token* tokens[100];

        int MakeOperator(int index)
        {
            tokens[tcnt]=new Operator(expr[index]);
            tcnt++;

            return index+1;
        }

        struct Operand :public Token
        {
            int value;
            Operand(int value)
            {
                this->value=value;
                priority=3;
            }
            void View()
            {
                cout << value << " ";
            }
        };

        int MakeOperand(int index)
        {
            int value=0;
            while (IsDigit(expr[index]))
            {
                value=value*10 + expr[index]-'0';
                index++;
            }
            tokens[tcnt] = new Operand(value);
            tcnt++;
            return index;
        }
        bool Syntax()
        {
            if (tcnt % 2 == 0)
            {
                return false;
            }
            if (tokens[0]->priority != 3)
            {
                return false;
            }
            for (int i = 1; i < tcnt; i += 2)
            {
                if (tokens[i]->priority == 3)
                {
                    return false;
                } 
                if (tokens[i + 1]->priority != 3)
                {
                    return false;
                }
            }
            return true;
        }
        struct ParserTree
        {
            struct Node
            {
                Token * token;
                Node* lc;
                Node* rc;
                Node(Token* token)
                {
                    this->token=token;
                    lc=rc=0;
                }
            };
            Node* root;
            ParserTree(Token* token)
            {
                root=new Node(token);

            }
            void Add(Token* token)
            {
                Node * now= new Node(token);
                Token* st=root->token;
                if (st->MoreThanPriority(token))
                {
                    now->lc=root;
                    root=now;
                }
                else 
                {
                    if (token->priority != 3)
                    {
                        /*Node* pa=root;
                        while (pa->rc)
                        {
                            pa=pa->rc;
                        }
                        pa->rc=now;*/
                        now->lc=root->lc;
                        root->rc=now;
                    }
                    else
                    {
                        Node* pa = root;
                        while (pa->rc)
                        {
                            pa = pa->rc;
                        }
                        pa->rc = now;
                    }
                }
            }
            void View()
            {
                PostOrder(root);
                cout << endl;
            }
            void PostOrder(Node* sr)
            {
                if (sr)
                {
                    PostOrder(sr->lc);
                    PostOrder(sr->rc);
                    sr->token->View();
                }
            }
            int Calculate()
            {
                return PostOrderCalculate(root);
            }

            int PostOrderCalculate(Node* sr)
            {
                if (sr->lc)
                {
                    int lvalue=PostOrderCalculate(sr->lc);
                    int rvalue=PostOrderCalculate(sr->rc);
                    Operator* op=dynamic_cast<Operator*> (sr->token);
                    switch (op->ch)
                    {
                        case '+': return lvalue+rvalue; 
                        case '-' : return lvalue-rvalue;
                        case '*': return lvalue * rvalue;
                        case '/': 
                            if (rvalue)
                            {
                                return lvalue/rvalue;
                                }
                            cout << "divide zero error" << endl;
                            return 0;
                        default:
                            throw "�������� ���� �������Դϴ�.";
                            break;
                    }
                }
                Operand* oprd = dynamic_cast<Operand*>(sr->token);
                return oprd->value;
            }

        };

        ParserTree* ps;

        void Parsing()
        {
            ps=new ParserTree(tokens[0]);
            for (int i =1; i < tcnt; i++)
            {
                ps->Add(tokens[i]);
            }
        }
        void PostOrderView()
        {
            ps->View();
        }
        int Calculate()
        {
            return ps->Calculate();
        }
};


int main()
{

    string tx_exprs[6]=
    {
        "2+3=5*5+6/2",
        "23*5/2+4*6",
        "2+4*5#6",
        "2+3*5+",
        "3+36+*7",
        "45+3*5-25/2*7"
    };

    for (int i = 0; i < 6; i++)
    {
        Calculator * cal = new Calculator(tx_exprs[i]);
        cal->Run();
        delete cal;
    }



    return 0;
}