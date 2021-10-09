#include <iostream>
#include <vector>
#include <string>

using namespace std;


template <typename Object>
class Collection
{
    public:

        Collection(unsigned int len = 0) : length{len}
        {
            elements.resize(len);
        }

        Collection(vector<Object> v): elements{v}
        {
            length = v.size();
        }

        Collection(vector<Object>&& v): length{v.size()}, elements{std::move(v)}
        {
            length = v.size();
        }

        void makeEmpty()
        {
            if (length != 0)
            {
                length = 0;
                elements.clear();
            };
        }

        const unsigned int* len()
        {
            return &length;
        }

        const vector<Object>* get_elements()
        {
            return &elements;
        }

        void insert(Object new_item, unsigned int idx=0)
        {
            typename vector<Object>::iterator it;
            it = elements.begin() + idx;
            elements.insert(it, new_item);
            length = elements.size();
        }

        void remove(Object item_to_remove)
        {
            int existing_index = find_index_of(item_to_remove);
            while (existing_index != -1)
            {
                length -= 1;
                elements.erase(elements.begin() + existing_index);
                existing_index = find_index_of(item_to_remove);
            }
        }

        const bool isEmpty()
        {
            if (length != 0)
            {
                return false;
            } else {
                return true;
            };
        }

        const bool contains(Object element)
        {
            const int existing_index = find_index_of(element);
            if (existing_index != -1)
            {
                return true;
            } else {
                return false;
            }
        }


    private:

        vector<Object> elements;
        unsigned int length = 0;

        int find_index_of(Object element)
        {
            for (int i = 0; i<length; i++)
            {
                if (elements[i] == element)
                {
                    return i;
                }
            }
            return -1;
        }

};

int main()
{
    Collection<int> c1 {5};
    vector<string> a {"kek", "mem"};
    Collection<string> c2 {a};


    c1.makeEmpty();
    const vector<int>* el = c1.get_elements();
    for (auto i: *el)
    {
        std::cout << i << '\n';
    }
    cout << c1.isEmpty()<<endl;



    const unsigned int* p1 = c2.len();
    const vector<string>* elem1 = c2.get_elements();

    c2.insert("vev", 2);
    c2.insert("nen", 3);
    c2.remove("nen");
    cout << c2.contains("vev") << endl;

    for (auto i: *elem1)
    {
        std::cout << i << '\n';
    }

    return 0;
}