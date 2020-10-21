// https://github.com/dwyl/english-words/blob/master/words_alpha.txt

#include <iostream>
#include <set>
using namespace std;

int total=370103;
int maxlen=0;
set<string> s;


int main()
{
    
    string c;
    for(int i=0;i<total;i++)
    {
        cin>>c;
        s.insert(c);
        if(c.length()>maxlen)
            maxlen=c.length();
    }
    cout<<"set creation complete with size: "<<s.size()<<" with max length of a word: "<<maxlen<<endl;
    return 0;
}
