# C++ Cheat Sheet

This guide is a collection of C++ code snippets that cover the basics of the language for coding interviews. It's organized sequentially to help JavaScript/Python developers learn C++ syntax and features.

---

## Setup & Basics

```cpp
// Common includes you'll need
#include <iostream>     // cin, cout
#include <vector>       // dynamic arrays
#include <string>       // strings
#include <unordered_map> // hash maps
#include <unordered_set> // hash sets
#include <map>          // ordered map
#include <set>          // ordered set
#include <queue>        // queue, priority_queue
#include <stack>        // stack
#include <algorithm>    // sort, reverse, etc.
#include <cmath>        // math functions
#include <climits>      // INT_MAX, INT_MIN

using namespace std;  // So you can write 'cout' instead of 'std::cout'

// Every C++ program needs a main function
int main() {
    // Your code here
    return 0;
}
```

---

## Variables & Types

```cpp
// C++ is statically typed (must declare type)
int n = 0;
double d = 3.14;
string s = "abc";
bool flag = true;

// Multiple declarations
int a = 0, b = 1, c = 2;  // same type only

// Type inference with auto (C++11)
auto x = 5;        // x is int
auto y = 3.14;     // y is double
auto z = "hello";  // z is const char*
auto str = string("hello");  // str is string

// Constants
const int MAX = 100;
// MAX = 200;  // Error! Can't modify const

// Increment/Decrement
n = n + 1;  // good
n += 1;     // good
n++;        // good (C++ has this!)
n--;        // decrement

// NULL equivalent for pointers
int* ptr = nullptr;
```

---

## Console Output

```cpp
// Use cout (like console.log)
cout << "Hello World" << endl;

// Print multiple values
int n = 5;
string name = "Alice";
cout << "n = " << n << endl;
cout << "Name: " << name << endl;

// Chain outputs
cout << "n = " << n << ", name = " << name << endl;

// Input with cin
int age;
cout << "Enter age: ";
cin >> age;
```

---

## If-statements

```cpp
// Parentheses and curly braces required
int n = 1;
if (n > 2) {
    n -= 1;
} else if (n == 2) {
    n *= 2;
} else {
    n += 2;
}

// Logical operators
// && = and
// || = or
// ! = not
int m = 2;
if ((n > 2 && n != m) || n == m) {
    n += 1;
}

// Ternary operator
int max = (n > m) ? n : m;
```

---

## Loops

```cpp
// While loop
int n = 0;
while (n < 5) {
    cout << n << endl;
    n++;
}

// For loop (i from 0 to 4)
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}

// For loop (i from 2 to 5)
for (int i = 2; i <= 5; i++) {
    cout << i << endl;
}

// For loop (i from 5 down to 2)
for (int i = 5; i >= 2; i--) {
    cout << i << endl;
}

// Range-based for loop (C++11) - like for...of in JS
vector<int> nums = {1, 2, 3};
for (int n : nums) {
    cout << n << endl;
}

// With reference (to modify elements)
for (int& n : nums) {
    n *= 2;
}

// Break and continue work the same
for (int i = 0; i < 10; i++) {
    if (i == 5) break;
    if (i % 2 == 0) continue;
    cout << i << endl;
}
```

---

## Functions

```cpp
// Basic function
int add(int a, int b) {
    return a + b;
}

// Void function (returns nothing)
void printMessage(string msg) {
    cout << msg << endl;
}

// Pass by value (default - makes a copy)
void increment(int x) {
    x++;  // only modifies the copy
}

int n = 5;
increment(n);
cout << n << endl;  // Still 5

// Pass by reference (modifies original)
void incrementRef(int& x) {
    x++;  // modifies original
}

int m = 5;
incrementRef(m);
cout << m << endl;  // Now 6

// Pass by const reference (efficient, can't modify)
void printVector(const vector<int>& vec) {
    for (int n : vec) {
        cout << n << " ";
    }
    // vec.push_back(1);  // Error! Can't modify
}

// Lambda functions (C++11)
auto multiply = [](int a, int b) {
    return a * b;
};
cout << multiply(3, 4) << endl;  // 12

// Lambda with capture
int factor = 10;
auto scale = [factor](int x) {
    return x * factor;
};
cout << scale(5) << endl;  // 50
```

---

## Pointers & References

```cpp
// Reference: alias to existing variable
int x = 5;
int& ref = x;  // ref is another name for x
ref = 10;
cout << x << endl;  // 10

// Pointer: stores memory address
int* ptr = &x;  // ptr holds address of x
cout << *ptr << endl;  // dereference to get value: 10

*ptr = 20;  // modify value through pointer
cout << x << endl;  // 20

// Null pointer
int* nullPtr = nullptr;

// Dynamic memory allocation (rarely needed for interviews)
int* arr = new int[5];  // allocate array of 5 ints
delete[] arr;  // must free memory

// For interviews: use references for function parameters
// and avoid manual memory management (use vectors instead)
```

---

## Math

```cpp
// Integer division truncates
cout << 5 / 2 << endl;        // 2

// Use double for decimal division
cout << 5.0 / 2 << endl;      // 2.5
cout << (double)5 / 2 << endl;  // 2.5 (cast to double)

// Modulo
cout << 10 % 3 << endl;       // 1
cout << -10 % 3 << endl;      // -1 (typically, implementation defined)

// Math functions (need #include <cmath>)
cout << floor(3.7) << endl;   // 3
cout << ceil(3.2) << endl;    // 4
cout << sqrt(16) << endl;     // 4
cout << pow(2, 3) << endl;    // 8
cout << abs(-5) << endl;      // 5

// Max and Min
cout << max(3, 5) << endl;    // 5
cout << min(3, 5) << endl;    // 3

// Max/Min for 3+ values
cout << max({1, 5, 3, 9, 2}) << endl;  // 9

// Constants
cout << INT_MAX << endl;      // 2147483647
cout << INT_MIN << endl;      // -2147483648

// Rounding
cout << round(3.7) << endl;   // 4
cout << round(3.2) << endl;   // 3
```

---

## Arrays (Vectors)

```cpp
// Vector = dynamic array (like JS arrays)
vector<int> arr = {1, 2, 3};
cout << arr[0] << endl;  // 1

// Push and pop (like stack)
arr.push_back(4);   // add to end
arr.push_back(5);
arr.pop_back();     // remove from end

// Size
cout << arr.size() << endl;

// Access elements
arr[0] = 10;        // modify
cout << arr.back() << endl;   // last element
cout << arr.front() << endl;  // first element

// Insert at position
arr.insert(arr.begin() + 1, 99);  // insert 99 at index 1

// Erase element
arr.erase(arr.begin() + 1);  // remove element at index 1

// Initialize with size and default value
vector<int> vec(5, 0);  // {0, 0, 0, 0, 0}
vector<int> vec2(5);    // {0, 0, 0, 0, 0} (default is 0 for int)

// Check if empty
if (arr.empty()) {
    cout << "Empty!" << endl;
}

// Clear all elements
arr.clear();

// Loop through with index
for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << endl;
}

// Loop through with value
for (int n : arr) {
    cout << n << endl;
}

// Loop and modify
for (int& n : arr) {
    n *= 2;
}

// Reverse
reverse(arr.begin(), arr.end());

// Sort
vector<int> nums = {5, 2, 8, 1, 9};
sort(nums.begin(), nums.end());  // ascending

// Sort descending
sort(nums.begin(), nums.end(), greater<int>());

// Custom sort with lambda
vector<string> words = {"alice", "bob", "alexander", "jo"};
sort(words.begin(), words.end(), [](const string& a, const string& b) {
    return a.length() < b.length();  // sort by length
});

// 2D vector (matrix)
vector<vector<int>> matrix(3, vector<int>(4, 0));  // 3x4 matrix of zeros
matrix[0][0] = 1;
matrix[2][3] = 5;

// Static arrays (fixed size, less common for interviews)
int staticArr[5] = {1, 2, 3, 4, 5};
```

---

## Strings

```cpp
// Strings are mutable in C++ (unlike JS)
string s = "abc";
s[0] = 'A';
cout << s << endl;  // "Abc"

// Concatenation
s += "def";
cout << s << endl;  // "Abcdef"

string s2 = s + " xyz";

// Length
cout << s.length() << endl;
cout << s.size() << endl;  // same as length()

// Substring
string sub = s.substr(0, 3);  // from index 0, length 3
string sub2 = s.substr(2);    // from index 2 to end

// Find
int pos = s.find("bc");
if (pos != string::npos) {  // npos means not found
    cout << "Found at: " << pos << endl;
}

// Character at index
cout << s[0] << endl;
cout << s.at(0) << endl;  // with bounds checking

// Convert to/from numbers
int num = stoi("123");           // string to int
double d = stod("3.14");         // string to double
string str = to_string(123);     // int to string

// ASCII value
cout << (int)'a' << endl;  // 97
cout << (char)97 << endl;  // 'a'

// Loop through string
for (char c : s) {
    cout << c << endl;
}

// Modify while looping
for (char& c : s) {
    c = toupper(c);
}

// Compare strings
string a = "abc";
string b = "abc";
if (a == b) {
    cout << "Equal" << endl;
}

// Lexicographic comparison
if (a < b) {
    cout << "a comes before b" << endl;
}
```

---

## Stack

```cpp
// Stack - LIFO (Last In First Out)
stack<int> stk;

// Push
stk.push(1);
stk.push(2);
stk.push(3);

// Top (peek at top element)
cout << stk.top() << endl;  // 3

// Pop (removes top element, doesn't return it)
stk.pop();
cout << stk.top() << endl;  // 2

// Size
cout << stk.size() << endl;

// Check if empty
if (stk.empty()) {
    cout << "Stack is empty" << endl;
}

// Note: Can't iterate through a stack directly
// Need to pop elements to access them
```

---

## Queues

```cpp
// Queue - FIFO (First In First Out)
queue<int> q;

// Push (enqueue)
q.push(1);
q.push(2);
q.push(3);

// Front and back
cout << q.front() << endl;  // 1
cout << q.back() << endl;   // 3

// Pop (dequeue - removes front)
q.pop();
cout << q.front() << endl;  // 2

// Size and empty
cout << q.size() << endl;
if (q.empty()) {
    cout << "Queue is empty" << endl;
}

// Deque - double-ended queue
deque<int> dq;

// Can push/pop from both ends
dq.push_back(1);
dq.push_back(2);
dq.push_front(0);   // {0, 1, 2}

dq.pop_back();      // {0, 1}
dq.pop_front();     // {1}

// Access elements
cout << dq[0] << endl;
cout << dq.front() << endl;
cout << dq.back() << endl;
```

---

## HashSets

```cpp
// Unordered set (hash set) - O(1) average operations
unordered_set<int> s;

// Insert
s.insert(1);
s.insert(2);
s.insert(3);
s.insert(2);  // duplicates ignored

// Size
cout << s.size() << endl;  // 3

// Check if element exists
if (s.count(2)) {  // or s.find(2) != s.end()
    cout << "2 exists" << endl;
}

// Erase
s.erase(2);
if (s.count(2) == 0) {
    cout << "2 removed" << endl;
}

// Loop through (unordered)
for (int x : s) {
    cout << x << endl;
}

// Clear
s.clear();

// Ordered set (balanced BST) - O(log n) operations
set<int> orderedSet;
orderedSet.insert(5);
orderedSet.insert(1);
orderedSet.insert(3);

// Elements are sorted
for (int x : orderedSet) {
    cout << x << endl;  // 1, 3, 5
}
```

---

## HashMaps

```cpp
// Unordered map (hash map) - O(1) average operations
unordered_map<string, int> map;

// Insert / Update
map["alice"] = 90;
map["bob"] = 85;
map["alice"] = 95;  // updates value

// Access
cout << map["alice"] << endl;  // 95

// Check if key exists
if (map.count("alice")) {  // or map.find("alice") != map.end()
    cout << "alice exists" << endl;
}

// Erase
map.erase("bob");

// Size
cout << map.size() << endl;

// Loop through
for (auto& pair : map) {
    cout << pair.first << ": " << pair.second << endl;
}

// Or with structured binding (C++17)
for (auto& [key, value] : map) {
    cout << key << ": " << value << endl;
}

// Get keys only
for (auto& pair : map) {
    cout << pair.first << endl;
}

// Get values only
for (auto& pair : map) {
    cout << pair.second << endl;
}

// Ordered map (balanced BST) - O(log n) operations, keys sorted
map<string, int> orderedMap;
orderedMap["charlie"] = 70;
orderedMap["alice"] = 90;
orderedMap["bob"] = 85;

// Keys are sorted
for (auto& [key, value] : orderedMap) {
    cout << key << ": " << value << endl;
    // Output: alice: 90, bob: 85, charlie: 70
}
```

---

## Pairs

```cpp
// Pair - holds two values
pair<int, string> p = {1, "apple"};
cout << p.first << endl;   // 1
cout << p.second << endl;  // "apple"

// Make pair
pair<int, int> p2 = make_pair(3, 4);

// Pairs can be compared (lexicographically)
pair<int, int> a = {1, 2};
pair<int, int> b = {1, 3};
if (a < b) {
    cout << "a is less than b" << endl;
}

// Common use: storing coordinates
pair<int, int> coord = {5, 10};
int x = coord.first;
int y = coord.second;

// Vector of pairs
vector<pair<int, string>> vec = {
    {1, "one"},
    {2, "two"},
    {3, "three"}
};

for (auto& p : vec) {
    cout << p.first << ": " << p.second << endl;
}

// Pairs with maps
unordered_map<string, int> map = {{"a", 1}, {"b", 2}};
for (pair<string, int> p : map) {
    cout << p.first << " = " << p.second << endl;
}
```

---

## Tuples

```cpp
// Tuple - holds multiple values (can be different types)
tuple<int, string, double> t = {1, "hello", 3.14};

// Access elements
cout << get<0>(t) << endl;  // 1
cout << get<1>(t) << endl;  // "hello"
cout << get<2>(t) << endl;  // 3.14

// Make tuple
auto t2 = make_tuple(5, "world", 2.5);

// Structured binding (C++17)
auto [num, str, dbl] = t;
cout << num << " " << str << " " << dbl << endl;

// Tuple size
cout << tuple_size<decltype(t)>::value << endl;  // 3

// Note: Pairs are more common in interviews
// Use tuples when you need 3+ values
```

---

## Heaps (Priority Queue)

```cpp
// Priority queue - max heap by default
priority_queue<int> maxHeap;

// Insert
maxHeap.push(3);
maxHeap.push(1);
maxHeap.push(4);
maxHeap.push(2);

// Top (max element)
cout << maxHeap.top() << endl;  // 4

// Pop (removes max)
maxHeap.pop();
cout << maxHeap.top() << endl;  // 3

// Size
cout << maxHeap.size() << endl;

// Min heap (need to specify)
priority_queue<int, vector<int>, greater<int>> minHeap;

minHeap.push(3);
minHeap.push(1);
minHeap.push(4);
minHeap.push(2);

cout << minHeap.top() << endl;  // 1

// Build heap from vector
vector<int> nums = {3, 1, 4, 1, 5};
priority_queue<int> pq(nums.begin(), nums.end());

while (!pq.empty()) {
    cout << pq.top() << " ";
    pq.pop();
}
// Output: 5 4 3 1 1

// Custom comparator (e.g., for pairs)
auto cmp = [](pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;  // min heap by second value
};
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pqCustom(cmp);
```

---

## Classes

```cpp
// Basic class
class MyClass {
public:  // accessible from outside
    // Member variables
    int size;
    vector<int> nums;
    
    // Constructor
    MyClass(vector<int> n) {
        nums = n;
        size = n.size();
    }
    
    // Member functions
    int getSize() {
        return size;
    }
    
    int getDoubleSize() {
        return 2 * getSize();  // call other member function
    }
    
    void printNums() {
        for (int n : nums) {
            cout << n << " ";
        }
        cout << endl;
    }

private:  // only accessible within class
    int secretValue = 42;
    
    int getSecret() {
        return secretValue;
    }
};

// Create object
MyClass obj({1, 2, 3});
cout << obj.getSize() << endl;        // 3
cout << obj.getDoubleSize() << endl;  // 6
obj.printNums();                      // 1 2 3

// Access public members
cout << obj.size << endl;  // 3
obj.size = 10;

// Can't access private members
// cout << obj.secretValue << endl;  // Error!

// Default constructor
class Point {
public:
    int x, y;
    
    Point() {
        x = 0;
        y = 0;
    }
    
    Point(int xVal, int yVal) {
        x = xVal;
        y = yVal;
    }
};

Point p1;           // calls default constructor
Point p2(5, 10);    // calls parameterized constructor
```

---

## Additional Tips

```cpp
// Auto keyword for type inference
auto x = 5;                    // int
auto vec = vector<int>{1, 2};  // vector<int>
auto map = unordered_map<string, int>{};

// Range-based loops work with most containers
for (auto& element : container) {
    // use element
}

// Common algorithms (need #include <algorithm>)
vector<int> v = {5, 2, 8, 1, 9};

sort(v.begin(), v.end());              // sort ascending
reverse(v.begin(), v.end());           // reverse
auto it = find(v.begin(), v.end(), 8); // find element
int sum = accumulate(v.begin(), v.end(), 0);  // sum all elements

// Binary search (vector must be sorted)
if (binary_search(v.begin(), v.end(), 5)) {
    cout << "Found 5" << endl;
}

// Min/max element
auto minIt = min_element(v.begin(), v.end());
auto maxIt = max_element(v.begin(), v.end());
cout << *minIt << " " << *maxIt << endl;
```