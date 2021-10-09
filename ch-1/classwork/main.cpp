#include <iostream>

using namespace std;


class IntCell1
{
    public:
        explicit IntCell1( int initialValue = 0 )
        {
            storedValue = new int{ initialValue };
        }

        int read( ) const
        {
            return *storedValue;
        }

        void write( int x )
        {
            *storedValue = x;
        }

        IntCell1 & operator= (const IntCell1 & rhs)
        {
            IntCell1 copy = rhs;
            std::swap(*this, copy);
            return *this;
        }

    private:
        int *storedValue;
};


class IntCell2
{
    public:
        explicit IntCell2(int initialValue = 0)
        {
            storedValue = new int{initialValue};
        }

        // destructor
        ~IntCell2()
        {
            delete storedValue;
        }

        // copy assignment
        IntCell2(const IntCell2 & rhs)
        {
            storedValue = new int{*rhs.storedValue};
        }

        // move constructor
        IntCell2(IntCell2 && rhs) : storedValue{ rhs.storedValue }
        {
            rhs.storedValue = nullptr;
        }


    private:
        int *storedValue;
};



int f( )
{
    IntCell1 a{ 2 };
    IntCell1 b = a;
    IntCell1 c;
    c = b;
    a.write( 4 );
    cout << a.read( ) << endl << b.read( ) << endl << c.read( ) << endl;
    return 0;
}

int main()
{
    f();
    return 0;
}
