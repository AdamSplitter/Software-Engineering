#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Structure to represent a node in the Huffman tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq) 
        : ch(ch),
          freq(freq), 
          left(nullptr), 
          right(nullptr) {}
};

// Comparison function for priority queue to order nodes based on their frequency
struct Compare {
    bool operator()(Node* leftNode, Node* rightNode) {
        return leftNode->freq > rightNode->freq; // Fix for min-heap
    }
};

// Build Huffman tree
Node* buildHuffmanTree(const unordered_map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create leaf nodes for each character
    for (const auto& pair : freqMap) {
        pq.emplace(new Node(pair.first, pair.second));
    }

    // Build the tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Internal nodes do not represent any character, so we use '\0' as a placeholder
        Node* internalNode = new Node('\0', left->freq + right->freq);
        internalNode->left = left;
        internalNode->right = right;

        pq.push(internalNode);
    }

    return pq.top();
}

// Generate Huffman codes
void generateHuffmanCodes(Node* root, const string& code, unordered_map<char, string>& codes) {
    if (root == nullptr) return;

    if (root->ch != '\0') {
        codes[root->ch] = code;
    }

    generateHuffmanCodes(root->left, code + "0", codes);
    generateHuffmanCodes(root->right, code + "1", codes);
}

void deleteHuffmanTree(Node* root) {
    if (root == nullptr) return;
    deleteHuffmanTree(root->left);
    deleteHuffmanTree(root->right);
    delete root;
}

int main() {
    string text = "This is an example for Huffman encoding";
    unordered_map<char, int> freqMap;

    // Calculate frequency of each character
    for (char ch : text) {
        freqMap[ch]++;
    }

    // Build Huffman tree
    Node* root = buildHuffmanTree(freqMap);

    // Generate Huffman codes
    unordered_map<char, string> codes;
    generateHuffmanCodes(root, "", codes);

    // Print the codes
    for (auto pair : codes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}