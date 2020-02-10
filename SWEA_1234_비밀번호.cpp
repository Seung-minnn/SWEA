#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
 
using namespace std;
 
int main() {
    for (int t = 1; t <= 10; t++){
        int n;
        string s = "";
        //scanf("%d %s", &n, s); ->string은 scanf로 받으면 안 된대;;
        cin >> n >> s;
        while (1) {
            string temp = "";
            bool change = false;
            for (int i = s.size()-1; i >0; i--) {
                //cout << "i: " << i << "\ns: " << s << "\ntemp: " << temp << "\n";
                if (s[i] == s[i - 1]) {
                    //cout << "--------" << s[i] << "&" << s[i - 1] << "--------------\n";
                    s.pop_back();
                    s.pop_back();
                    i--;
                    change = true;
                    //cout << s << "\n";
                    continue;
                }
                temp.push_back(s[i]);
                s.pop_back();
                if (i == 1) {
                    temp.push_back(s[i-1]);
                    s.pop_back();
                }
            }
            while (!s.empty()) {
                temp.push_back(s.back());
                s.pop_back();
            }
            //cout <<"중간결과\ns: " << s << "\ntemp: " << temp << "\n";
            reverse(temp.begin(),temp.end()); //reverse() algorithm 라이브러리로 호출가능
            s = temp;
            //cout << "중간결과\ns: " << s << "\ntemp: " << temp << "\n";
            if (change == false) {
                break;
            }
        }
         
        cout << "#" << t << " " << s << "\n";
    }
 
    //system("pause");
    return 0;
}