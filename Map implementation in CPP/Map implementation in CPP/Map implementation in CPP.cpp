#include <iostream>

template<typename T1, typename T2>
struct pair {
    T1 first;
    T2 second;

    // Constructors
    pair(): first(0), second("") {}
    pair(const T1& a, const T2& b) : first(a), second(b) {}

    // Operators
    bool operator==(const pair& other) const {
        return first == other.first && second == other.second;
    }

    bool operator!=(const pair& other) const {
        return !(*this == other);
    }

    bool operator<(const pair& other) const {
        return (first < other.first) || (first == other.first && second < other.second);
    }
};

template<typename T1, typename T2>
pair<T1, T2> make_pair(const T1& a, const T2& b) {
    return pair<T1, T2>(a, b);
}

template <typename K, typename V>
struct tNode {
    pair<K, V> data;
    tNode* parent;
    tNode* left;
    tNode* right;
    bool is_Head;

    tNode() : parent(nullptr), left(nullptr), right(nullptr), is_Head(true) {}
};

template <typename K, typename V>
class map {
    tNode<K, V>* H; // Head node
    int n;          // Number of elements

public:
    map() {
        H = new tNode<K, V>;
        H->left = H;
        H->right = H;
        H->parent = H;
        n = 0;
    }

    void insert(const K& key, const V& value) {
        tNode<K, V>* new_node = new tNode<K, V>;
        new_node->data = make_pair(key, value);
        new_node->left = H;
        new_node->right = H;

        if (n == 0) {
            new_node->parent = H;
            H->parent = new_node;
        }
        else {
            tNode<K, V>* current = H->parent;
            tNode<K, V>* parent = nullptr;

            while (current != H) {
                parent = current;
                if (key == current->data.first) {
                    current->data.second = value; // Update value if key already exists
                    delete new_node;
                    return;
                }
                else if (key < current->data.first) {
                    current = current->left;
                }
                else {
                    current = current->right;
                }
            }

            if (key < parent->data.first) {
                parent->left = new_node;
            }
            else {
                parent->right = new_node;
            }
            new_node->parent = parent;
        }
        n++;
    }

    bool find(const K& key, V& value) const {
        tNode<K, V>* current = H->parent;
        while (current != H) {
            if (key == current->data.first) {
                value = current->data.second;
                return true;
            }
            else if (key < current->data.first) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return false;
    }

    void erase(const K& key) {
        tNode<K, V>* current = H->parent;
        tNode<K, V>* parent = H;

        while (current != H) {
            if (key == current->data.first) {
                break;
            }
            parent = current;
            if (key < current->data.first) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        if (current == H) {
            std::cout << "The key isn't found" << std::endl;
            return;
        }

        if (current->left == H && current->right == H) {
            if (parent->left == current) {
                parent->left = H;
            }
            else {
                parent->right = H;
            }
            delete current;
        }
        else if (current->left != H && current->right == H) {
            if (parent->left == current) {
                parent->left = current->left;
            }
            else {
                parent->right = current->left;
            }
            current->left->parent = parent;
            delete current;
        }
        else if (current->left == H && current->right != H) {
            if (parent->left == current) {
                parent->left = current->right;
            }
            else {
                parent->right = current->right;
            }
            current->right->parent = parent;
            delete current;
        }
        else {
            tNode<K, V>* successor = current->right;
            tNode<K, V>* successor_parent = current;
            while (successor->left != H) {
                successor_parent = successor;
                successor = successor->left;
            }
            current->data = successor->data;

            if (successor_parent->left == successor) {
                successor_parent->left = successor->right;
            }
            else {
                successor_parent->right = successor->right;
            }
            if (successor->right != H) {
                successor->right->parent = successor_parent;
            }
            delete successor;
        }
        n--;
    }

    class iterator {
        tNode<K, V>* ptr;
        friend class map<K, V>;

    public:
        iterator() : ptr(nullptr) {}
        iterator(tNode<K, V>* node) : ptr(node) {}

        iterator& operator++() {
            if (!ptr->right->is_Head) {
                ptr = ptr->right;
                while (!ptr->left->is_Head) {
                    ptr = ptr->left;
                }
            }
            else {
                tNode<K, V>* parent = ptr->parent;
                while (ptr == parent->right && !parent->is_Head) {
                    ptr = parent;
                    parent = parent->parent;
                }
                ptr = parent;
            }
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator!=(const iterator& other) const {
            return ptr != other.ptr;
        }

        pair<K, V> operator*() const {
            return ptr->data;
        }
    };

    iterator begin() const {
        tNode<K, V>* current = H->parent;
        if (current == H) {
            return iterator(H);
        }
        while (current->left != H) {
            current = current->left;
        }
        return iterator(current);
    }

    iterator end() const {
        return iterator(H);
    }

    ~map() {
        while (H->parent != H) {
            erase(H->parent->data.first);
        }
        delete H;
    }
};

int main() {
    map<int, std::string> m;

    // Insert elements
    m.insert(10, "ten");
    m.insert(5, "five");
    m.insert(15, "fifteen");
    m.insert(3, "three");
    m.insert(7, "seven");

    // Print all elements using iterator
    std::cout << "Elements in the map: \n";
    for (map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it) {
        pair<int, std::string> p = *it;
        std::cout << p.first << ": " << p.second << "\n";
    }

    // Find an element
    std::string value;
    if (m.find(7, value)) {
        std::cout << "Found key 7 with value: " << value << std::endl;
    }
    else {
        std::cout << "Key 7 not found" << std::endl;
    }

    // Erase an element
    std::cout << "Erasing key 5...\n";
    m.erase(5);

    // Print all elements again
    std::cout << "Elements in the map after erasing key 5: \n";
    for (map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it) {
        pair<int, std::string> p = *it;
        std::cout << p.first << ": " << p.second << "\n";
    }

    return 0;
}
