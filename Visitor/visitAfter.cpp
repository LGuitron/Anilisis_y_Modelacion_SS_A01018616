#include<iostream>

using namespace std;

class Integer;
class Double;

class Visitor
{
public:

		template<class T>
		static T* getInstance()
    {
        static T instance;
        return &instance;
    }



    virtual void visit(Integer*) = 0;
    virtual void visit(Double*) = 0;
};




class Number
{
protected:
    string quienSoy;
public:
    string getQuienSoy(){return quienSoy;}
    virtual void accept(Visitor*) = 0;
};

class Integer : public Number
{
public:
    Integer()
    {
        quienSoy = "Integer";
    }
    static int countInts;
    void accept(Visitor*);
};
int Integer::countInts = 0;
class Double : public Number
{
public:
    Double()
    {
        quienSoy = "Double";
    }
    static int countDouble;
    void accept(Visitor*);
};
int Double::countDouble = 0;


class PresentVisitor : public Visitor
{

private:
	PresentVisitor(){}

public:
    void visit(Integer* i)
    {
        cout << i->getQuienSoy();
    }
    void visit(Double* d)
    {
        cout << d->getQuienSoy();
    }
		friend class Visitor;
};

class CountVisitor : public Visitor
{
private:
	CountVisitor(){}
public:
    void visit(Integer* i)
    {
        cout << Integer::countInts;
    }
    void visit(Double* i)
    {
        cout << Double::countDouble;
    }
		friend class Visitor;
};

class AddVisitor : public Visitor
{
private:
	AddVisitor(){}
public:
    void visit(Integer*)
    {
        Integer::countInts++;
    }
    void visit(Double*)
    {
        Double::countDouble++;
    }
		friend class Visitor;
};

void Double::accept(Visitor* v)
{
    v->visit(this);
}

void Integer::accept(Visitor* v)
{
    v->visit(this);
}

int main()
{
		Visitor* c = Visitor::getInstance<CountVisitor>();
    Visitor* a = Visitor::getInstance<AddVisitor>();
    Visitor* p = Visitor::getInstance<PresentVisitor>();
<<<<<<< HEAD
=======

>>>>>>> db9018e7f2d366f4453235187b2776495ba9e581
    Number* n[] ={new Integer, new Double};

    for(int i=0; i< 5; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            n[j]->accept(a);
        }
    }

    n[0]->accept(p);
    n[0]->accept(c);
    cout << endl;
    n[1]->accept(p);
    n[1]->accept(c);
<<<<<<< HEAD
    cout<<endl;
}
=======
		cout << endl;

		delete p;
		delete c;
		delete a;
		delete n[1];
		delete n[0];
}
>>>>>>> db9018e7f2d366f4453235187b2776495ba9e581
