#ifndef SBE201_WORDCOUNT_MAPS_MAP_HPP
#define SBE201_WORDCOUNT_MAPS_MAP_HPP

#include <string>
#include <iostream>

namespace map {
    template<typename T1, typename T2>
    struct MapNode {
        T1 key;
        T2 value;
        MapNode<T1, T2> *left, *right;

        MapNode(T1 Key, T2 Value = 0) {
            key = Key;
            value = Value;
            left = nullptr;
            right = nullptr;
        }
    };

    template<typename T1, typename T2>
    class Map {
        MapNode<T1, T2> *root = nullptr;
    public:
        bool isEmpty() const {
            return root == nullptr;
        }

        bool isLeaf() const {
            return root->right == root->left;
        }

        int size() const {
            return size(root);
        }


        bool find(T1 key) const {
            return find(root, key);
        }


        void insert(T1 key) {
            insert(root, key);
        }

        MapNode<T1, T2> *minNode() const {
            if (!root) return nullptr;
            MapNode<T1, T2> *current = root->right, *prev = root;
            while (current) {
                prev = current;
                current = current->left;
            }
            return prev;
        }

        void remove(T1 key) {   //recursively
            remove(root, key);
        }

        T2 &value(T1 key) {
            if (this->find(key)) {
                MapNode<T1, T2> *current = root;
                while (current) {
                    if (current->key == key)
                        return current->value;
                    else if (key > current->key)
                        current = current->right;
                    else
                        current = current->left;
                }
            } else {
                this->insert(key);
                return this->value(key);
            }
        }


        void clear() {
            clear(root);
        }

        void printAll() const {
            inorder(root);
        }

    private:
        static int size(const MapNode<T1, T2> *r) {
            if (!r) return 0;
            return 1 + size(r->right) + size(r->left);
        }

        static bool find(const MapNode<T1, T2> *r, T1 key) {
            if (!r) return false;
            else {
                if (r->key == key)
                    return true;
                else if (key > r->key)
                    return find(r->right, key);
                else
                    return find(r->left, key);
            }
        }

        static void insert(MapNode<T1, T2> *&r, T1 key) {
            if (!r) {
                r = new MapNode<T1, T2>(key);
            } else {
                if (key < r->key)
                    insert(r->left, key);
                else if (key > r->key)
                    insert(r->right, key);
            }
        }

        static void remove(MapNode<T1, T2> *&root, T1 &key) {
            if (root) {
                if (root->key == key) {
                    if (!root->left) {
                        MapNode<T1,T2>*temp=root;
                        root = root->right;
                        delete temp;
                    } else if (!root->right) {
                        MapNode<T1,T2>*temp=root;
                        root = root->left;
                        delete temp;
                    } else {
                        MapNode<T1,T2>*pn=MinNode(root);
                        root->key=pn->key;
                        remove(root->right,pn->key);
                    }
                } else if (key > root->key) {
                    remove(root->right, key);
                } else {
                    remove(root->left, key);
                }
            }
        }

        static void clear(MapNode<T1, T2> *&r) {
            if (r) {
                clear(r->left);
                clear(r->right);
                delete r;
            }
            r = nullptr;
        }

        static void inorder(const MapNode<T1, T2> *r) {
            if (r) {
                std::cout << r->key << ":" << r->value << std::endl;
                inorder(r->left);
                inorder(r->right);
            }
        }

        static MapNode<T1, T2> *MinNode( MapNode<T1,T2>*root){
            if (!root) return nullptr;
            MapNode<T1, T2> *current = root->right, *prev = root;
            while (current) {
                prev = current;
                current = current->left;
            }
            return prev;
        }
    };


}

#endif //SBE201_WORDCOUNT_MAPS_MAP_HPP
