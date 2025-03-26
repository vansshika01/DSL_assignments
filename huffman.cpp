#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;


struct Node {
    char data;         
    int frequency;    
    Node* left;     
    Node* right;     

    Node(char val, int freq) : data(val), frequency(freq), left(nullptr), right(nullptr) {}
};


struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency; 
    }
};


void generateCodes(Node* root, const string& code, unordered_map<char, string>& codes) {
    if (!root) return;

    if (!root->left && !root->right) {
        codes[root->data] = code;
    }

    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}


Node* buildHuffmanTree(const string& input, unordered_map<char, string>& codes) {

    unordered_map<char, int> frequency;
    for (char ch : input) {
        frequency[ch]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    for (const auto& pair : frequency) {
        minHeap.push(new Node(pair.first, pair.second));
    }

 
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* internal = new Node('\0', left->frequency + right->frequency);
        internal->left = left;
        internal->right = right;
      
        minHeap.push(internal);
    }
   
    Node* root = minHeap.top();

    generateCodes(root, "", codes);

    return root;
}

string encode(const string& input, const unordered_map<char, string>& codes) {
    string encodedString;
    for (char ch : input) {
        cout<<ch<<":"<<codes.at(ch)<<endl;
        encodedString += codes.at(ch);
    }
    return encodedString;
}

string decode(Node* root, const string& encodedString) {
    string decodedString;
    Node* current = root;
    for (char bit : encodedString) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (!current->left && !current->right) {
            decodedString += current->data;
            current = root;
        }
    }
    return decodedString;
}

int main() {
    string input = "hello world!";
    cout << "Original String: " << input << endl;

    unordered_map<char, string> codes;
    Node* root = buildHuffmanTree(input, codes);

    string encodedString = encode(input, codes);

    string decodedString = decode(root, encodedString);

    cout << "Encoded String: " << encodedString << endl;
    cout << "Decoded String: " << decodedString << endl;

    return 0;
}

