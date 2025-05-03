#include<bits/stdc++.h>

using namespace std;
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void buildCodes(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    buildCodes(root->left, str + "0", huffmanCode);
    buildCodes(root->right, str + "1", huffmanCode);
}

void HuffmanCoding(string text) {

    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for (auto pair : freq) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        minHeap.push(merged);
    }

    Node* root = minHeap.top();
    unordered_map<char, string> huffmanCode;
    buildCodes(root, "", huffmanCode);

    for (auto pair : huffmanCode) {
        cout << pair.first << ": " << pair.second << endl;
    }
    string encoded = "";
    for (char ch : text) {
        encoded += huffmanCode[ch];
    }
    cout<< encoded << endl;
}

int main() {
    string text = "ccbcbde";
    HuffmanCoding(text);
    return 0;
}
