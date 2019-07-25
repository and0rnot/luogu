#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    int no;
    int chinese_score;
    int math_score;
    int english_score;
    int total_score;
} Student;

bool comp(Student a, Student b) {
    if (a.total_score > b.total_score)
        return true;
    if (a.total_score < b.total_score)
        return false;

    if (a.chinese_score > b.chinese_score)
        return true;
    if (a.chinese_score < b.chinese_score)
        return false;

    if (a.no < b.no)
        return true;

    return false;
}

int main() {
    Student ss[301];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        Student stu;
        cin >> stu.chinese_score >> stu.math_score >> stu.english_score;
        stu.total_score = stu.chinese_score + stu.math_score + stu.english_score;
        stu.no = i;
        ss[i] = stu;
    }

    sort(ss+1, ss+n+1, comp);

    for (int i = 1; i <= 5; i++) {
        cout << ss[i].no << " " << ss[i].total_score << endl;
    }
    return 0;
}