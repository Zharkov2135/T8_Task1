#include <iostream>
using namespace std;

int sumDivisors(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0)
            sum += i;
    }
    return sum;
}

int main() {
    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;

    if (a > b) swap(a, b);

    cout << "Amicable numbers:\n";
    for (int i = a; i <= b; i++) {
        int s = sumDivisors(i);
        if (s > i && s <= b && sumDivisors(s) == i) {
            cout << i << " and " << s << endl;
        }
    }
    return 0;
}
