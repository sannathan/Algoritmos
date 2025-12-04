#include "../../../DataStructures/BinarySearchTree.h"
#include <iostream>
#include <string>

using namespace std;

void FillBstWithCharacters(string &nodes, BinarySearchTree &bst)
{
    for (int i = nodes.size() - 1; i >= 0; i--)
    {
        bst.insert(nodes[i]);
    };
}
int main()
{
    BinarySearchTree bst;
    string nodes = "";
    string inputLine;

    while (getline(cin, inputLine))
    {
        if (!inputLine.empty() && inputLine.back() == '\r') {
            inputLine.pop_back();
        }

        if (inputLine.empty()) continue;

        if (inputLine == "*" || inputLine == "$")
        {
            FillBstWithCharacters(nodes, bst);
            bst.printPreorder();
            
            bst.clear();
            nodes = "";

            if (inputLine == "$") break;
        }
        else 
        {
            nodes.append(inputLine);
        }
    }
    
    return 0;
}