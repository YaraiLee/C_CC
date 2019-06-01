#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
    // 使用vector存储数字：3、4、8、4
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(6);
    vec.push_back(8);
    vec.push_back(4);
    
    //循环打印数字
    vector<int>::iterator itor = vec.begin();
    for (; itor != vec.end(); itor++)
    {
        cout << *itor << endl;
    }
    //C++11 auto
    for (auto itor : vec) {
    	cout << itor << endl;
	}
    
    // 使用map来存储字符串键值对
    map<char, string> m;
    pair<char, string> p1('S', "Shang Hai");
    pair<char, string> p2('B', "Bei Jing");
    pair<char, string> p3('G', "Guang Zhou");
   
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    m['H'] = "Hang Zhou";
    // 打印map中数据
    map<char, string>::iterator it = m.begin();
    for (; it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    for (auto itor : m) {
    	cout << "[" << itor.first << "," << itor.second << "]" << endl;
	}
    return 0;
}
