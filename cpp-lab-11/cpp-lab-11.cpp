#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>
#include <iterator>
#include <deque>
#include <fstream>

using namespace std;

// контейнерные алгоритмы
void container_algorithms(const vector<int>& numbers)
{
    cout << "Sum of elements: " << accumulate(numbers.begin(), numbers.end(), 0) << endl;
    cout << "Minimum element: " << *min_element(numbers.begin(), numbers.end()) << endl;
    cout << "Maximum element: " << *max_element(numbers.begin(), numbers.end()) << endl;
}

// итераторы-адаптеры
void iterators_adapters(vector<int>& numbers)
{
    auto back_add = back_inserter(numbers);
    *back_add = 4;

    list<int> other_numbers = { 6, 7};
    auto front_add = front_inserter(other_numbers);
    *front_add = 5;

    copy(other_numbers.begin(), other_numbers.end(), inserter(numbers, numbers.begin() + 2));

    cout << "Vector after modifications: ";
    for (int num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;

    numbers.erase(numbers.begin() + 3);
    numbers.erase(numbers.begin() + 4);

    cout << "Vector after erasing elements: ";
    for (int num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;
}

//файловый ввод-вывод с итераторами
void file_io_with_iterators()
{
    ofstream file("data.txt");
    if (file.is_open()) {
        ostream_iterator<int> output_iter(file, " ");
        for (int i = 1; i <= 20; ++i) {
            *output_iter++ = i;
        }
        file.close();
    }

    ifstream infile("data.txt");
    if (infile.is_open()) {
        istream_iterator<int> input_iter(infile);
        istream_iterator<int> end_of_stream;
        cout << "Contents of the file: ";
        while (input_iter != end_of_stream) {
            cout << *input_iter++ << " ";
        }
        cout << endl;
        infile.close();
    }
}

//взаимодействие итераторов
void iterators_interaction(const vector<int>& numbers)
{
    deque<int> queue;
    copy(numbers.begin(), numbers.end(), back_inserter(queue));
    cout << "Queue after copying: ";
    for (int num : queue)
    {
        cout << num << " ";
    }
    cout << endl;
}

//обратные итераторы
void reverse_iterators()
{
    list<int> numbers;
    cout << "Enter integers (enter 0 to finish):" << endl;
    int num;
    while (cin >> num && num != 0)
    {
        numbers.push_back(num);
    }
    cout << "Elements in reverse order: ";
    for (auto rit = numbers.rbegin(); rit != numbers.rend(); ++rit)
    {
        cout << *rit << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> numbers;
    cout << "Enter integers (enter 0 to finish):" << endl;
    int num;
    while (cin >> num && num != 0)
    {
        numbers.push_back(num);
    }

    // задание 1
    container_algorithms(numbers);

    // задание 2
    iterators_adapters(numbers);

    // задание 3
    file_io_with_iterators();

    // задание 4 
    iterators_interaction(numbers);

    // задание 5
    reverse_iterators();

    return 0;
}