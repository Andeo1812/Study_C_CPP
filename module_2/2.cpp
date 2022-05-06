#include <iostream>
#include <stack>

//    Дано число N < 106 и последовательность целых чисел из [-2^31..2^31] длиной N.
//    Требуется построить бинарное дерево, заданное наивным порядком вставки.
//    Т.е., при добавлении очередного числа K в дерево с корнем root, если root→Key ≤ K, то узел K добавляется
//    в правое поддерево root; иначе в левое поддерево root.
//    Требования: Рекурсия запрещена. Решение должно поддерживать передачу функции сравнения снаружи.
//
//    2_2. Выведите элементы в порядке pre-order (сверху вниз).


template<typename T>
struct Node {
    T data;

    Node *left;
    Node *right;

    Node() = default;

    Node(const T &data) : data(data), left(nullptr), right(nullptr) {};

    ~Node() = default;
};

template<typename T>
class Less {
public:
    bool operator()(const T &l, const T &r) const {
        return l < r;
    }
};

template<typename T, typename CompareRule = Less<T>>
class BinaryTree {
    Node<T> *root;

    CompareRule rule;

    size_t size;
public:
    bool IsEmpty() const;

    bool Add(const T &key);

    bool Delete(const T &key);

    bool Search(const T &key) const;

    void Print(std::ostream &ostream) const;

    BinaryTree() : root(nullptr), size(0) {};

    ~BinaryTree() = default;
};

template<typename T, typename CompareRule>
bool BinaryTree<T, CompareRule>::IsEmpty() const {
    return !size;
}

template<typename T, typename CompareRule>
bool BinaryTree<T, CompareRule>::Add(const T &key) {
    Node<T> **cur = &root;

    while (*cur) {
        Node<T> &node = **cur;

        if (rule(node.data, key)) {
            cur = &node.right;
        } else {
            cur = &node.left;
        }
    }

    *cur = new Node<T>(key);

    ++size;

    return true;
}

template<typename T, typename CompareRule>
bool BinaryTree<T, CompareRule>::Delete(const T &key) {
    Node<T> *cur = root;

    Node<T> *parent = nullptr;

    while (cur && cur->data != key) {
        parent = cur;

        if (rule(cur->data, key)) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }

    if (!cur) {
        return false;
    }

    Node<T> *removed = nullptr;

    if (cur->left == NULL || cur->right == NULL) {
        Node<T> *child = nullptr;
        removed = cur;

        if (cur->left) {
            child = cur->left;
        } else if (cur->right) {
            child = cur->right;
        }

        if (!parent) {
            root = child;
        } else if (parent->left == cur) {
            parent->left = child;
        } else {
            parent->right = child;
        }
    } else {
        Node<T> *most_left = cur->right;
        Node<T> *most_left_parent = cur;

        while (most_left->left != NULL) {
            most_left_parent = most_left;
            most_left = most_left->left;
        }

        cur->data = most_left->data;
        removed = most_left;

        if (most_left_parent->left == most_left) {
            most_left_parent->left = NULL;
        } else {
            most_left_parent->right = most_left->right;
        }
    }

    delete removed;

    return true;
}

template<typename T, typename CompareRule>
bool BinaryTree<T, CompareRule>::Search(const T &key) const {
    Node<T> *tmp = root;

    while (tmp) {
        if (tmp->data == key) {
            return true;
        } else if (rule(tmp->data, key)) {
            tmp = tmp->right;
        } else {
            tmp = tmp->left;
        }
    }

    return false;
}

template<typename T, typename CompareRule>
void BinaryTree<T, CompareRule>::Print(std::ostream &ostream) const {
    if (IsEmpty()) {
        return;
    }

    std::stack < Node<T> * > s;

    s.push(root);

    while (!s.empty()) {
        Node<T> *tmp = s.top();
        s.pop();
        ostream << tmp->data << " ";

        if (tmp->right) {
            s.push(tmp->right);
        }

        if (tmp->left) {
            s.push(tmp->left);
        }
    }
}

void run(std::istream &input, std::ostream &output) {
    BinaryTree<long int> tree;

    size_t n = 0;

    input >> n;

    size_t buf = 0;
    for (size_t i = 0; i < n; ++i) {
        input >> buf;

        tree.Add(buf);
    }

    tree.Print(output);

    output << std::endl;
}


int main() {
    run(std::cin, std::cout);

    return EXIT_SUCCESS;
}
