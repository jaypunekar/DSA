/*

Busy Life
You are actually very busy person. You have a long list of activities. Your aim is to finish much as activities as possible.

In the given figure, if you go to date with crush, you cannot participate in the coding contest and you can’t watch the movie. Also if you play DotA, you can’t study for the exam. If you study for the exam you can’t sleep peacefully. The maximum number of activities that you can do for this schedule is 3.

Either you can

watch movie, play DotA and sleep peacefully (or)

date with crush, play DotA and sleep peacefully


Given the start and finish times of activities, print the maximum number of activities. Input is already store in a vector of pairs. Each pair contains the start and end of the activity.

Sample Input

(7,9) (0,10) (4,5) (8,9) (4,10) (5,7)

Output
3
*/

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int countActivites(vector<pair<int,int> > activities){
    sort(activities.begin(), activities.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int task = 1;
    int prev = activities[0].second;
    for (int i = 1; i < activities.size(); i++) {
        if (prev <= activities[i].first) {
            prev = activities[i].second;
            task++;
        };
    }
    return task;
}

int main() {
    vector<pair<int, int>> v;
    v.push_back(make_pair(7,9));
    v.push_back(make_pair(0, 10));
    v.push_back(make_pair(4, 5));
    v.push_back(make_pair(8, 9));
    v.push_back(make_pair(4, 10));
    v.push_back(make_pair(5, 7));

    cout << countActivites(v) << endl;
    return 0;
}
