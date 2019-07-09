#include <iostream>
using namespace std;

int main() {
    string line;
    int s[26] = {0};

    for (int i = 0; i < 4; i++) {
        getline(cin, line);
        for (int j = 0; j < line.size(); j++)
            if (line[j] >= 'A' && line[j] <= 'Z')
                s[line[j]-'A']++;
    }
    int height = 0;
    for (int i = 0; i < 26; i++) {
        if (s[i] > height)
            height = s[i];
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < 26; j++) {
            if (s[j] < height - i)
                cout << " ";
            else
                cout << "*";
            
            if (j != 26)
                cout << " ";
        }
        cout << endl;
    }
    cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << endl;

    return 0;
}