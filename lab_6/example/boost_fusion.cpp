#include <iostream>
#include <boost/fusion/container.hpp>
#include <boost/fusion/sequence.hpp>

using namespace std;

class Print {
public:
    template<typename T>
    void operator()(T t) {
        cout << t << endl;
    }
};

int main() {
    boost::fusion::vector<int, string, bool, double> vec{10, "C++", true, 3.14};
    cout << "Trzeci element w vec:" << boost::fusion::at<boost::mpl::int_<2>>(vec) << endl;
    auto vec2 = push_back(vec, 'M');
    cout << "Liczba elementow w wvec: " << size(vec) << endl;
    cout << "Liczba elementow w vec2: " << size(vec2) << endl;
    cout << "Pierwszy element w vec2: " << front(vec2) << endl;
    cout << "Ostatni element w vec2: " << back(vec2) << endl;
    cout << "Cala zawartosc vec2: " << endl;
    boost::fusion::for_each(vec2, Print());

    auto itvStart = begin(vec);
    auto itvStop = end(vec);
    cout << "Pierwszy element: " << *itvStart << endl;
    cout << "Drugi element: " << *next(itvStart) << endl;
    cout << "Trzeci element: " << *advance<boost::mpl::int_<2>>(itvStart) << endl;
}