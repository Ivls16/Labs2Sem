#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>
#include <stdexcept>
#include <QListWidget>

class Queue: public QObject {
    Q_OBJECT

private:
    struct Node {
        int val;
        Node* next;

        Node(int val): val(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size_;

public:
    Queue();
    ~Queue();

    void push(int val);
    void pop();
    const int& front() const;
    const int& back() const;
    size_t size() const;
    bool empty() const;
    QString str();
    void insertAfterMax(Queue* other);

    void displayToQListWidget(QListWidget* widget);

signals:
    void sizeChanged();
};

#endif // QUEUE_H
