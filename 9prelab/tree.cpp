
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

istream * gis;
string peek;

string tok() 
{ 
    auto r = peek; peek = ""; 
    if (*gis) 
        (*gis) >> peek; 
    return r; 
}



int gid = 0;

struct Tree
{
    int id;
    string op;
    string val;
    Tree * left = nullptr, * right = nullptr;

    Tree(): id(++gid) {}
    Tree(string v): id(++gid), val(v) {}
    Tree(string o, Tree * a, Tree * b): id(++gid), op(o), left(a), right(b) {}
    Tree(const Tree &) = delete;
    ~Tree() { delete left; delete right; }

    string str() const;
    string edges() const;
    string expr() const;
};


Tree * eval_expr();

Tree * eval_prim()
{
    if ( peek == "(" )
    {
        tok();
        return eval_expr();
    }

    return new Tree(tok());
}

Tree * eval_powr()
{
    auto result = eval_prim();

    for (;;)
    {
        if ( peek == "^" )
        {
            auto op = tok();
            auto b = eval_prim();
            result = new Tree(op, result, b);
        }
        else break;
    }
    return result;
}

Tree * eval_term()
{
    auto result = eval_powr();
    for (;;)
    {
        if ( peek == "*" || peek == "/" || peek == "%" )
        {
            auto op = tok();
            auto b = eval_powr();
            result = new Tree(op, result, b);
        }
        else break;
    }
    return result;
}

Tree * eval_expr()
{
    Tree * result = eval_term();
    for (;;)
    {
        if ( peek == "+" || peek == "-" )
        {
            auto op = tok();
            auto b = eval_term();
            result = new Tree(op, result, b);
        }
        else if (peek.empty()) break;
        else if (peek == ")") { tok(); break; }
        else throw "bad operator [" + peek + "]";
    }
    return result;
}

int main()
{
try
{
    for (string line; getline(cin, line);)
    {
        if ( line.empty() ) continue;
        if ( line[0] == '#' ) continue;
        if ( line == "end" ) break;

        istringstream is(line);
        gis = &is; // reset input stream
        gid = 0; // reset id counter
        tok(); // load peek token

        Tree * tree = eval_expr();
        
        cout << "```mermaid\ngraph TD\n"
             << "A(\"" << line << "\")\n"
             << "B(\"" << tree->expr() << "\")\n"
             << "A --> B\n"
             << "style A fill:#ded\n"
             << "style B fill:#dde\n" 
            << tree->edges() << "```\n---\n";

        delete tree;
    }
}
    catch (string s) { cout << "Error: " << s << '\n'; }
    catch (...) { cout << "exception\n"; }
}

string Tree::str() const
{
    if ( op.empty() ) return to_string(id) + "[" + val + "]";
    return to_string(id) + "((\"" + op + "\"))";
}

string Tree::edges() const
{   //Base case for leaves
    if(right==nullptr && left==nullptr){
        return str();
    }

    cout << str() << " --> "; 
    if(left!=nullptr){
        cout << left->str();
    }
    cout << "\n";
    cout << str() << " --> "; 
    if(right!=nullptr){
        cout << right->str();
    }
    cout << "\n";
    if(left!=nullptr && !(left->op.empty())){
        cout << left->edges();
    }
    
    if(right!=nullptr && !(right->op.empty())){
        cout << right->edges();
    }
    
    
    return "";

}


string Tree::expr() const
{
    
    if(left == nullptr && right == nullptr){
        return val;
    }

    if(left->op.empty() && right->op.empty()){
        return left->val + " " + op + " " + right->val;        
    }

    string result;
    if(op == "^"){
        if(left->op != "^"){
            cout << "( " << left->expr() << " ) ";
        }
        else{
            cout << left->expr() << " ";
        }
        cout << op << " ";
        
        if(right->op != "^"){
            
            cout << "( " << right->expr() << " ) ";
        }
        else{
            
            cout << right->expr() << " ";
        }


    }
    else if(op == "*" || op == "/" || op == "%"){
        if(left->op == "+" || left->op == "-"){
            cout << "( " + left->expr() + " ) ";
        }
        else{
            cout << left->expr() << " ";
        }
        cout << op << " ";
        if(right->op == "+" || right->op == "-"){
            cout << "( " + right->expr() + " ) ";
        }
        else{
            cout << right->expr() << " ";
        }

    }
    else{
        cout << left->expr() << " ";
        cout << op << " ";
        cout << right->expr() << " ";
    }
    
        
    
    return result;

}
