#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <memory>

using namespace std;

struct Node {
    char ch;
    int freq;
    shared_ptr<Node> left, right;

    Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
};

struct compare {
    bool operator()(shared_ptr<Node> l, shared_ptr<Node> r) {
        return l->freq > r->freq;
    }
};

void printCodes(shared_ptr<Node> root, string str) {
    if (!root) return;
    if (root->ch != '$') cout << root->ch << " | " << str << '\n';
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void buildHuffmanTree(char data[], int freq[], int size) {
    priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, compare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(make_shared<Node>(data[i], freq[i]));

    while (minHeap.size() != 1) {
        auto left = minHeap.top(); minHeap.pop();
        auto right = minHeap.top(); minHeap.pop();
        auto top = make_shared<Node>('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
}

int main() {
    char arr[] = {'a', 's', 'i', 'n', ' ', 'c', 'o', 'l', 'e', 'g', 'f', 'h', 'r', 't', 'u', 'd'};
    int freq[] = {4, 3, 3, 2, 5, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Char | Huffman code\n";
    cout << "----------------------\n";
    buildHuffmanTree(arr, freq, size);

    return 0;
}

