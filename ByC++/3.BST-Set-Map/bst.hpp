#ifndef SBE201_WORDCOUNT_MAPS_BST_HPP
#define SBE201_WORDCOUNT_MAPS_BST_HPP

#include <iostream>
#include <string>
#include <queue>

namespace bst {
    template<typename T>
    struct BSTNode {
        T data;
        BSTNode *left, *right;

        BSTNode(T Data) {
            data = Data;
            left = nullptr;
            right = nullptr;
        }

    };

    template<typename T>
    struct Tree {
    protected:
        BSTNode<T> *root = nullptr;
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

        bool find(T item) const { //iterative version
            BSTNode<T> *pt = root;
            while (pt) {
                if (pt->data == item)
                    return true;
                else if (item > pt->data)
                    pt = pt->right;
                else
                    pt = pt->left;
            }
            return false;
        }

        void insert(T item) { //iterative version
            BSTNode<T> *pt = new BSTNode<T>(item);
            BSTNode<T> *current = root, *prev = nullptr;

            if (!current) {
                root = pt;
                return;
            }
            while (current) {
                prev = current;
                if (item < current->data)
                    current = current->left;
                else
                    current = current->right;
            }

            if (item < prev->data)
                prev->left = pt;
            else
                prev->right = pt;

        }

        BSTNode<T> *minNode() const {   //in right subtree   //iteratively
            if (!root) return nullptr;
            BSTNode<T> *current = root->right, *prev = root;
            while (current) {
                prev = current;
                current = current->left;
            }
            return prev;
        }

//        void remove(T item) { //iteratively
//            if (!root) return;   //empty
//            BSTNode<T> *current = root, *prev = root;
//            while (current) {
//                if (current->data == item)
//                    break;
//                else if (item > current->data) {
//                    prev = current;
//                    current = current->right;
//                } else {
//                    prev = current;
//                    current = current->left;
//                }
//            }
//            if (!current)   //item not found
//                return;
//            if (current == root)
//                deleteNode(prev);
//            else if (item > prev->data)
//                deleteNode(prev->right);
//            else
//                deleteNode(prev->left);
//
//        }
        void remove(T data) {   //recursively
            remove(root, data);
        }

        void clear() {
            clear(root);
        }

        void preorder() const {
            preorder(root);
        }

        void inorder() const {
            inorder(root);
        }

        void postorder() const {
            postorder(root);
        }

        void breadthFirst() const {
            if (!root) return;
            std::queue<BSTNode<T> *> q;
            BSTNode<T> *read = nullptr;
            q.push(root);
            while (!q.empty()) {
                read = q.front();
                std::cout << read->data << " ";
                if (read->left) q.push(read->left);
                if (read->right) q.push(read->right);
                q.pop();
            }
        }

        void setRoot(BSTNode<T> *&r) {
            root = r;
        }

    private:
        static int size(const BSTNode<T> *tree) {
            if (!tree) return 0;
            return 1 + size(tree->left) + size(tree->right);
        }

//        static void deleteNode(BSTNode<T> *&pNode) {
//            BSTNode<T> *pt = pNode;
//            if (!pNode->left) {
//                pNode = pNode->right;
//            } else if (!pNode->right) {
//                pNode = pNode->left;
//            } else {
//                BSTNode<T> *temp = pt->right;
//                while (temp) { //iterate till reach the minNode
//                    pt = temp;
//                    temp = temp->left;
//                }
//                pNode->data = pt->data;
//                //deleting the node
//                temp = pNode;
//                BSTNode<T> *temp1 = temp->right;
//                while (temp1 != pt) {// reaching the previous node
//                    temp = temp1;
//                    temp1 = temp1->left;
//                }
//                if (temp == pNode) {
//                    if (pt->right)     //cheching if there is data at subtree
//                        temp->right = pt->right;
//                    else
//                        temp->right = nullptr;
//                } else {
//                    if (pt->right)     //cheching if there is data at subtree
//                        temp->left = pt->right;
//                    else
//                        temp->left = nullptr;
//                }
//            }
//            delete pt;
//        }
        static void remove(BSTNode<T> *&root, T data) {
            if (root) {
                if (root->data== data) {
                    if (!root->left) {
                        BSTNode<T>*temp=root;
                        root = root->right;
                        delete temp;
                    } else if (!root->right) {
                        BSTNode<T>*temp=root;
                        root = root->left;
                        delete temp;
                    } else {
                        BSTNode<T>*pn=MinNode(root);
                        root->data=pn->data;
                        remove(root->right,pn->data);
                    }
                } else if (data > root->data) {
                    remove(root->right, data);
                } else {
                    remove(root->left, data);
                }
            }
        }

        static void clear(BSTNode<T> *&tree) {
            if (tree) {
                clear(tree->left);
                clear(tree->right);
                delete tree;
            }
            tree = nullptr;
        }

        static void preorder(const BSTNode<T> *tree) {
            if (tree) {
                std::cout << tree->data << " ";
                preorder(tree->left);
                preorder(tree->right);
            }
        }

        static void inorder(const BSTNode<T> *tree) {
            if (tree) {
                inorder(tree->left);
                std::cout << tree->data << " ";
                inorder(tree->right);
            }
        }

        static void postorder(const BSTNode<T> *tree) {
            if (tree) {
                preorder(tree->left);
                postorder(tree->right);
                std::cout << tree->data << " ";
            }
        }
        static BSTNode<T> *MinNode( BSTNode<T>*root){
            if (!root) return nullptr;
            BSTNode<T> *current = root->right, *prev = root;
            while (current) {
                prev = current;
                current = current->left;
            }
            return prev;
        }

    };


}

#endif //SBE201_WORDCOUNT_MAPS_BST_HPP_HPP
