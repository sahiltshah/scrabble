//Words source: http://www.mieliestronk.com/corncob_lowercase.txt


#include <iostream>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

int node_count=0;
int leaf_count=0; // number of words added to trie. for verification purposes
int total=58110; // total number of words in the list file
int maxlen=0; // maximum length of word in the trie
int f[26]; // to store the frequency of each letters the scrabble user has
unsigned long long int char_count=0; // total number of characters adding all the words we found
map<char,int> score; // map each character to the score we have
vector<string> recommendation; // recommended words


class Node
{
    public:
    Node* l[27]; // links to other nodes
    string val; // val stores leaf it exists
    Node()
    {
        for(int i=0;i<27;i++)
            l[i]=NULL;
        node_count++;
    }

};
Node *root,*leaf;

void insert_word(Node* root,string s,string master="") // master is the word to be stored at the end
{
    if(s.length())
    {
        if(root->l[s[0]-97]==NULL)
            root->l[s[0]-97]=new Node();
        insert_word(root->l[s[0]-97],s.substr(1),master);
    }
    else
    {
        root->l[26]=leaf;
        leaf_count++;
        root->val=master;
    }
}

bool search_word(Node* root, string s)// searches based on a query word
{
    if(root==NULL)
        return 0;
    else if(root==leaf)
        return 1;
    else
    {
        if(s.length())
            return(search_word(root->l[s[0]-97],s.substr(1)));
        else
            return(search_word(root->l[26],s));
    }
    
}

void search_word(Node* root) //seaches for scrabble
{
    if(root!=NULL&&root!=leaf)
    {
        if(root->val!="")
            recommendation.push_back(root->val);
        for(int i=0;i<26;i++)
        {
            if(f[i])
                {
                    f[i]--;
                    search_word(root->l[i]);
                    f[i]++;
                }
        }
        
    }
}

void trie_creation()
{
    root=new Node();
    leaf=new Node();
    string c;

    ifstream f;
    f.open("words.txt",ios::in);
    if(f.is_open())
        while(getline(f,c))
            {
                insert_word(root,c,c);
                if(c.length()>maxlen)
                    maxlen=c.length();
            }
    else
        cout<<"file opening error"<<endl;
    f.close();
    cout<<"Node count is: "<<node_count<<" leaf count: "<<leaf_count<<" char count: "<<char_count<<endl;
    
}

int score_word(string s) // returns corresponding score of each word
{
    int word_total=0;
    for(int i=0;i<s.length();i++)
    if(score.find(s[i])!=score.end())
        word_total+=score.find(s[i])->second;
    
    return word_total;
}

bool compareRecommendation(string a,string b) // comparator function to use for sorting by score of each word
{
    return score_word(a)>score_word(b);
}

void scrabble_recommender()
{
    for(int i=0;i<26;i++) // initialization of the frequencies
        f[i]=0;
    int noc;
    char c;
    int freq,sc;

    cout<<"enter the number of unique characters: "<<endl;
    cin>>noc;
    cout<<"enter each character one after the one followed by the frequnecy and the score, eg, two 'a's of each score of 1 are :- [a 2 1]"<<endl;
    while(noc--)
    {
        cin>>c>>freq>>sc;
        f[c-97]=freq;
        score.insert(pair<char,int>(c,sc));
    }
    search_word(root);
    sort(recommendation.begin(),recommendation.end(),compareRecommendation);
    cout<<"the words in descending order of scores are: \n"<<endl;
    for(int i=0;i<recommendation.size();i++)
        cout<<score_word(recommendation[i])<<" "<<recommendation[i]<<endl;
}

int main()
{
    trie_creation();
    scrabble_recommender();
    return 0;
}