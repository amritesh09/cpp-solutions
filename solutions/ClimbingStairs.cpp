// Problem 15: Climbing Stairs
// You are climbing a staircase. Each time you can either climb 1 or 2 steps. Find the number of distinct ways to reach the top.

#include <iostream>
using namespace std;

int climbStairs(int n) {
    if (n == 1) return 1;
    int first = 1, second = 2;
    for (int i = 3; i <= n; ++i) {
        int third = first + second;
        first = second;
        second = third;
    }
    return second;
}

int main() {
    int n = 5;
    cout << "Number of ways to climb stairs: " << climbStairs(n) << endl;
    return 0;
}