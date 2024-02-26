#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void printState(pii state) {
    cout << "(" << state.first << ", " << state.second << ")";
}

void printPath(map<pii, pii> mp, pii u) {
    if (u.first == 0 && u.second == 0) {
        printState(u);
        return;
    }
    printPath(mp, mp[u]);
    cout << " -> ";
    printState(u);
}

void printEntireStateSpaceTree(int jug1_capacity, int jug2_capacity, int target_capacity) {
    queue<pii> q;
    set<pii> visited;
    map<pii, pii> mp;
    bool found_solution = false; // Flag to track if a solution has been found

    q.push({0, 0});
    visited.insert({0, 0});

    while (!q.empty()) {
        pii current_state = q.front();
        q.pop();

        // Print the current state
        printState(current_state);
        cout << endl;

        // Check if the current state is a solution
        if (current_state.first == target_capacity || current_state.second == target_capacity) {
            // Print the path to the solution state if not already found
            if (!found_solution) {
                cout << "First correct path found: ";
                printPath(mp, current_state);
                cout << endl;
                found_solution = true; // Set flag to true indicating solution found
            }
        }

        // Perform all possible operations
        // Fill jug1
        pii next_state = {jug1_capacity, current_state.second};
        if (visited.find(next_state) == visited.end()) {
            q.push(next_state);
            visited.insert(next_state);
            mp[next_state] = current_state;
        }

        // Fill jug2
        next_state = {current_state.first, jug2_capacity};
        if (visited.find(next_state) == visited.end()) {
            q.push(next_state);
            visited.insert(next_state);
            mp[next_state] = current_state;
        }

        // Empty jug1
        next_state = {0, current_state.second};
        if (visited.find(next_state) == visited.end()) {
            q.push(next_state);
            visited.insert(next_state);
            mp[next_state] = current_state;
        }

        // Empty jug2
        next_state = {current_state.first, 0};
        if (visited.find(next_state) == visited.end()) {
            q.push(next_state);
            visited.insert(next_state);
            mp[next_state] = current_state;
        }

        // Pour from jug1 to jug2 until full or empty
        int pour = min(current_state.first, jug2_capacity - current_state.second);
        next_state = {current_state.first - pour, current_state.second + pour};
        if (visited.find(next_state) == visited.end()) {
            q.push(next_state);
            visited.insert(next_state);
            mp[next_state] = current_state;
        }

        // Pour from jug2 to jug1 until full or empty
        pour = min(current_state.second, jug1_capacity - current_state.first);
        next_state = {current_state.first + pour, current_state.second - pour};
        if (visited.find(next_state) == visited.end()) {
            q.push(next_state);
            visited.insert(next_state);
            mp[next_state] = current_state;
        }
    }
}

int main() {
    int jug1_capacity = 4, jug2_capacity = 3, target_capacity = 2;
    cout << "Entire state space tree in BFS order:\n";
    printEntireStateSpaceTree(jug1_capacity, jug2_capacity, target_capacity);
    return 0;
}
