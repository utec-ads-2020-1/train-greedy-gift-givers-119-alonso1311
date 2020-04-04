#include<iostream>
#include<map>
#include<stdio.h>

using namespace std;

int main() {
    int number_of_people;        
    scanf("%d", &number_of_people);

    map<string, int> people;

    for(; number_of_people > 0; --number_of_people){
        string name;
        cin >> name;
        people.insert(make_pair(name, 0));
    }

    cin.ignore('\n');

    for(; number_of_people > 0; --number_of_people){
        string name;
        int spend, number;
        cin >> name >> spend >> number;

        string array[number];
        
        for(int i = 0; i < number; ++number){
            string names;
            cin >> names;
            array[i] = names;
        }

        cin.ignore('\n');

        cout << name << '\t' << spend << '\t' << number << '\t';
        for(auto i : array){
            cout << i << endl;
        }
    }
    cin.ignore('\n');

    cout << "Map: \n";
    for(auto it = people.begin(); it != people.end(); ++it){
        cout << it->first << '\t' << it->second << endl;
    }
    

    //printf("The number is %d", number_of_people);

    return 0;
}
