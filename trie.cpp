#include <iostream>
using namespace std;
class Node
{
    public:
    Node* l[27];
    Node()
    {
        for(int i=0;i<27;i++)
            l[i]=NULL;
    }

};
Node *root,*leaf;

void insert_word(Node* root,string s)
{
    if(s.length())
    {
        if(root->l[s[0]-97]==NULL)
            root->l[s[0]-97]=new Node();
        insert_word(root->l[s[0]-97],s.substr(1));
    }
    else
    {
        root->l[26]=leaf;
    }
}

bool search_word(Node* root, string s)
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

int main()
{
    //return 0;
    root=new Node();
    leaf=new Node();
    insert_word(root,"sahil");
    insert_word(root,"sahilshah");
    cout<<search_word(root,"sah")<<endl;
    cout<<search_word(root,"sahil")<<endl;
    cout<<search_word(root,"sahilx")<<endl;
    cout<<search_word(root,"sahilshahx")<<endl;
    insert_word(root,"sah");
    cout<<search_word(root,"sah")<<endl;
    cout<<search_word(root,"")<<endl;
    insert_word(root,"");
    cout<<search_word(root,"")<<endl;
    return 0;
}