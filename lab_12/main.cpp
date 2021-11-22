#include <iostream>
#include <vector>
#include <numeric>
#include <tuple>

using namespace std;

void task_1();

void task_3();

int main() {
//    task_1();
    task_3();
}

void task_3() {
    std::vector<string> vec = {"aaaaaa, bbb, cccc, ddddddddd, eeeeeeee"};
    auto func = [](std::vector<string> vec) -> std::tuple<size_t, size_t, string> {
        auto min_length = std::min_element(vec.begin(), vec.end(), [](string_view str1, string_view str2) {
            return str1.length() < str2.length();
        })->length();

        auto average_length = std::accumulate(vec.begin(), vec.end(), 0, [](int acc_len, string &ele) {
            return acc_len + ele.length();
        });
        cout << average_length / vec.size() << endl;

        return make_tuple(min_length, 2, "123");
    };
    std::tuple<size_t, size_t, string> res = func(vec);
}

void task_1() {
    std::vector<int> vec = {-33, -4, 5, 77, 22, 44566, 768, 12, 87, 4};
    size_t idx = 0;
    std::for_each(vec.begin(), vec.end(), [&idx, size = vec.size()](int elem) {
        cout << elem;
        if (++idx != size)
            cout << " | ";
    });
    cout << endl;

    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    float mean = (float) sum / (float) vec.size();
    cout << "Mean: " << mean << endl;

    size_t evenCount = std::count_if(vec.begin(), vec.end(), [](int elem) { return elem % 2 == 0; });
    cout << "Even count: " << evenCount << endl;

    cout << "Without negative: " << endl;
    std::erase_if(vec, [](int elem) { return elem < 0; });
    std::for_each(vec.begin(), vec.end(), [](int elem) { cout << elem << " "; });

    cout << endl << "Even elements first:" << endl;
    std::partition(vec.begin(), vec.end(), [](int el) { return !(el & 1); });
    std::for_each(vec.begin(), vec.end(), [](int elem) { cout << elem << " "; });

    cout << endl << "Negate elements:" << endl;
    std::transform(vec.begin(), vec.end(), vec.begin(), [](int elem) { return -elem; });
    std::for_each(vec.begin(), vec.end(), [](int elem) { cout << elem << " "; });

    int num = -20;
    size_t lessThanCount = std::count_if(vec.begin(), vec.end(), [num](int elem) { return elem < num; });
    cout << endl << "Less than " << num << " count: " << lessThanCount << endl;
}