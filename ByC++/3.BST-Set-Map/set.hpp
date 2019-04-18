#ifndef SBE201_WORDCOUNT_MAPS_SET_HPP
#define SBE201_WORDCOUNT_MAPS_SET_HPP


#include "bst.hpp"

namespace set {

    using bst::BSTNode;

    template<typename T>
    class Set : public bst::Tree<T> {
    public:
        bool contains(T item) const {      //recursively
            return contains(this->root, item);
        }

        void add(T new_item) {         //recursively
            add(this->root, new_item);
        }

        void printAll() {
            this->inorder();
        }

        BSTNode<T> *Root() { return this->root; }

        Set<T> union_(Set<T> &s2) const {
            Set s3;
            postorder_(this->root, s3);
            postorder_(s2.Root(), s3);
            return s3;
        }

        Set<T> intersect(Set<T> &s2) {
            Set s3;
            intersect(s3, *this, s2.Root());
            return s3;
        }

        bool equals(Set<T> &s2) {
            return equals(*this, s2);
        }

    private:
        void insert();  //preventing insert from using in set
        void find();

        static bool contains(const BSTNode<T> *tree, T item) {
            if (!tree) return false;
            if (tree->data == item)
                return true;
            else if (item > tree->data)
                return contains(tree->right, item);
            else
                return contains(tree->left, item);
        }

        static void add(BSTNode<T> *&tree, T data) {
            if (!tree) {
                tree = new BSTNode<T>(data);
            }
            if (data > tree->data)
                add(tree->right, data);
            else if (data < tree->data)
                add(tree->left, data);
        }

        static void postorder_(const BSTNode<T> *s, Set<T> &s3) {
            if (s) {
                s3.add(s->data);
                postorder_(s->left, s3);
                postorder_(s->right, s3);
            }
        }

        static void intersect(Set<T> &s3, Set<T> &s1, const BSTNode<T> *s2) {
            if (s2) {
                if (s1.contains(s2->data))
                    s3.add(s2->data);
                intersect(s3, s1, s2->left);
                intersect(s3, s1, s2->right);
            }
        }

        static bool equals(Set<T> &s1, Set<T> &s2) {
            if (s1.size() != s2.size())
                return false;
            else {
                std::vector<T> v1, v2;
                traversein(s1.Root(), v1);
                traversein(s2.Root(), v2);
                for (int i = 0; i < v1.size(); ++i) {
                    if (v1[i] != v2[i])
                        return false;
                }
                return true;
            }
        }

        static void traversein(const BSTNode<T> *root1, std::vector<T> &v1) {
            if (root1) {
                v1.push_back(root1->data);
                traversein(root1->left, v1);
                traversein(root1->right, v1);
            }
        }

    };


}
#endif //SBE201_WORDCOUNT_MAPS_SET_HPP
