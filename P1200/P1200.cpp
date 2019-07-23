#include <iostream>
#include <string>
using namespace std;

int main() {
    string comet_name;
    string group_name;

    cin >> comet_name >> group_name;
    int sum_comet = 1;
    int sum_group = 1;
    for (int i = 0; i < static_cast<int>(comet_name.length()); i++)
        sum_comet *= comet_name[i] - 'A' + 1;

    for (int i = 0; i < static_cast<int>(group_name.length()); i++)
        sum_group *= group_name[i] - 'A' + 1;

    if (sum_comet % 47 == sum_group % 47)
        cout << "GO" << endl;
    else
        cout << "STAY" << endl;
}
