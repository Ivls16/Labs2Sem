#include "searchtree.h"

SearchTreeNode::SearchTreeNode(int key, std::string val): l(nullptr), r(nullptr), key(key), value(val) {

}

void SearchTree::highlight(std::string* string, bool forLong) {
    (*string) = "[" + (*string) + "]";
    if (root) {
        view->clear();
        display(root, new QTreeWidgetItem(view));
        view->expandAll();
    }
    QTimer::singleShot(forLong ? 5000 : 500, &loop, &QEventLoop::quit);
    loop.exec();
    if (!string) {
        return;
    }
    (*string).erase(0, 1);
    (*string).erase((*string).length() - 1);
    if (root) {
        view->clear();
        display(root, new QTreeWidgetItem(view));
        view->expandAll();
    }
}

void SearchTree::display(SearchTreeNode *node, QTreeWidgetItem *viewNode) {
    viewNode->setText(0, QString::number(node->key));
    viewNode->setText(1, QString::fromStdString(node->value));
    if (node->l == nullptr) {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0, "-1");
        viewNode->addChild(item);
    }
    else {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        viewNode->addChild(item);
        display(node->l, item);
    }
    if (node->r == nullptr) {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0, "-1");
        viewNode->addChild(item);
    }
    else {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        viewNode->addChild(item);
        display(node->r, item);
    }
}

void SearchTree::inorder(SearchTreeNode *node, std::vector<SearchTreeNode*>* nodes) {
    if (!node) {
        return;
    }
    inorder(node->l, nodes);
    if (nodes) {
        nodes->push_back(node);
    }
    highlight(&(node->value));
    inorder(node->r, nodes);
}

SearchTreeNode* SearchTree::findByKey(SearchTreeNode *node, int key) {
    if (node == nullptr || node->key == key) {
        return node;
    }
    highlight(&(node->value));
    if (key < node->key) {
        return findByKey(node->l, key);
    }
    else {
        return findByKey(node->r, key);
    }
}

SearchTreeNode* SearchTree::deleteByKey(SearchTreeNode* node, int key) {
    if (node == nullptr) {
        return node;
    }
    highlight(&(node->value));
    if (key < node->key) {
        node->l = deleteByKey(node->l, key);
    }
    if (key > node->key) {
        node->r = deleteByKey(node->r, key);
    }
    if (key == node->key) {
        if (node->l == nullptr && node->r == nullptr) {
            delete node;
            return nullptr;
        }
        else if (node->l == nullptr) {
            SearchTreeNode* temp = node->r;
            delete node;
            return temp;
        }
        else if (node->r == nullptr) {
            SearchTreeNode* temp = node->l;
            delete node;
            return temp;
        }
        else {
            SearchTreeNode* min = findMin(node->r);
            node->key = min->key;
            node->value = min->value;
            node->r = deleteByKey(node->r, min->key);
        }
    }
    return node;
}

SearchTreeNode* SearchTree::findMin(SearchTreeNode* node) {
    if (node == nullptr || (node->l == nullptr && node->r == nullptr)) {
        return node;
    }
    if (node->l) {
        return findMin(node->l);
    }
    else {
        return node;
    }
}

SearchTreeNode *SearchTree::addNode(SearchTreeNode *node, int key, std::string val) {
    if (node == nullptr) {
        return new SearchTreeNode(key, val);
    }
    highlight(&(node->value));
    if (key == node->key) {
        node->value = val;
    }
    if (key < node->key) {
        node->l = addNode(node->l, key, val);
    }
    if (key > node->key) {
        node->r = addNode(node->r, key, val);
    }
    return node;
}

std::string SearchTree::findByKey(int key) {
    SearchTreeNode* node = findByKey(root, key);
    if (!node) {
        return "$";
    }
    view->clear();
    highlight(&(node->value), true);
    return node->value;
}

void SearchTree::deleteByKey(int key) {
    root = deleteByKey(root, key);
    view->clear();
    if (root) {
        display(root, new QTreeWidgetItem(view));
    }
}

void SearchTree::addNode(int key, std::string val) {
    root = addNode(root, key, val);
    view->clear();
    display(root, new QTreeWidgetItem(view));
}

void SearchTree::display() {
    if (root) {
        display(root, new QTreeWidgetItem(view));
    }
}

void SearchTree::inorder(std::vector<SearchTreeNode*>* nodes) {
    inorder(root, nodes);
}

void SearchTree::preorder(SearchTreeNode *node) {
    if (!node) {
        return;
    }
    highlight(&(node->value));
    preorder(node->l);
    preorder(node->r);
}

void SearchTree::postorder(SearchTreeNode *node) {
    if (!node) {
        return;
    }
    postorder(node->l);
    postorder(node->r);
    highlight(&(node->value));
}

void SearchTree::preorder() {
    preorder(root);
}

void SearchTree::postorder() {
    postorder(root);
}

void SearchTree::balance() {
    std::vector<SearchTreeNode*> nodes;
    inorder(&nodes);
    if (nodes.empty()) {
        return;
    }
    std::stack<std::pair<int, int>> st;
    st.emplace(0, (int)nodes.size() - 1);
    setRoot(nodes[((int)nodes.size() - 1) / 2]);
    while (!st.empty()) {
        auto [l, r] = st.top();
        st.pop();
        int md = (l + r) / 2;
        nodes[md]->l = nodes[md]->r = nullptr;
        if (md > l) {
            int md1 = (l + md - 1) / 2;
            nodes[md]->l = nodes[md1];
            st.emplace(l, md - 1);
        }
        if (md < r) {
            int md1 = (r + md + 1) / 2;
            nodes[md]->r = nodes[md1];
            st.emplace(md + 1, r);
        }
    }
    view->clear();
    display();
}

void SearchTree::setRoot(SearchTreeNode *newRoot) {
    root = newRoot;
}

SearchTree::SearchTree(QObject* parentObject, QTreeWidget* parent): root(nullptr), view(parent), QObject(parentObject) {

}

SearchTree::~SearchTree() {
    delete root;
}
