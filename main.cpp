#include<iostream>
#include<unordered_map>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main() {
    unordered_map<string, int> people;
    int number_of_people;        
    cin >> number_of_people; cin.ignore();

    string line, name;
    getline(cin, line, '\n');

    stringstream s(line);
    while(getline(s, name, ' '))
        people.insert(make_pair(name, 0));
    
    for(int i = 0; i < number_of_people; ++i){
        vector<string> to_lines;
        string word;
        getline(cin, line, '\n');
        stringstream ss(line);
        while(getline(ss, word, ' '))
            to_lines.push_back(word);

        int expense_per_person = stoi(to_lines[1])/stoi(to_lines[2]);
        
        auto search_1 = people.find(*begin(to_lines));
        if(search_1 != end(people))
            search_1->second -= (expense_per_person*stoi(to_lines[2]));
       
        for(auto it = next(begin(to_lines), 3); it != end(to_lines); it++) {
            auto search_2 = people.find(*it);
            if(search_2 != end(people))
                search_2->second += expense_per_person;
        }
    }

    for(auto it = people.begin(); it != people.end(); ++it)
        cout << it->first << ' ' << it->second << endl;
    
    
    return 0;
}
