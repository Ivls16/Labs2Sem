#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include <string>
#include <cstddef>
#include <QDebug>
#include <QTreeWidget>
#include <QEventLoop>
#include <QTimer>
#include <stack>

struct SearchTreeNode {
    SearchTreeNode *l;
    SearchTreeNode *r;
    int key;
    std::string value;

    SearchTreeNode(int key, std::string val);
};

class SearchTree: public QObject {
    Q_OBJECT
private:
    QEventLoop loop;

    QTreeWidget* view;

    SearchTreeNode* root;

    void highlight(std::string* string, bool forLong = false);
    void display(SearchTreeNode* node, QTreeWidgetItem* viewNode);
    void inorder(SearchTreeNode* node, std::vector<SearchTreeNode*>* nodes = nullptr);
    void preorder(SearchTreeNode* node);
    void postorder(SearchTreeNode* node);

    SearchTreeNode* findByKey(SearchTreeNode* node, int key);
    SearchTreeNode* deleteByKey(SearchTreeNode* node, int key);
    SearchTreeNode* findMin(SearchTreeNode* node);
    SearchTreeNode* addNode(SearchTreeNode* node, int key, std::string val);

public:
    std::string findByKey(int key);
    void deleteByKey(int key);
    void addNode(int key, std::string val);

    void display();
    void inorder(std::vector<SearchTreeNode*>* nodes = nullptr);
    void preorder();
    void postorder();

    void balance();

    void clear();
    void setRoot(SearchTreeNode* newRoot);

    SearchTree(QObject* parentObject = nullptr, QTreeWidget* parent = nullptr);
    ~SearchTree();
};

#endif // SEARCHTREE_H
