#include "queue.h"

Queue::Queue(): head(nullptr), tail(nullptr), size_(0) {

}

Queue::~Queue() {
    while (!empty()) {
        pop();
    }
}

void Queue::push(int val) {
    if (empty()) {
        head = tail = new Node(val);
        size_++;
        emit sizeChanged();
        return;
    }
    tail->next = new Node(val);
    tail = tail->next;
    size_++;
    emit sizeChanged();
}

void Queue::pop() {
    if (empty()) {
        throw std::out_of_range("");
    }
    Node* newhead = head->next;
    delete head;
    head = newhead;
    size_--;
    emit sizeChanged();
}

const int &Queue::front() const {
    if (empty()) {
        throw std::out_of_range("");
    }
    return head->val;
}

const int &Queue::back() const {
    if (empty()) {
        throw std::out_of_range("");
    }
    return tail->val;
}

size_t Queue::size() const {
    return size_;
}

bool Queue::empty() const {
    return size() == 0;
}

QString Queue::str() {
    QString res;
    for (Node* it = head; it != tail->next; it = it->next) {
        res += QString::number(it->val) + " ";
    }
    return res;
}

void Queue::insertAfterMax(Queue *other) {
    int mx = 0;
    for (Node* it = head; it != tail->next; it = it->next) {
        mx = std::max(mx, it->val);
    }
    for (Node* it = head; it != tail->next; it = it->next) {
        if (it->val == mx) {
            size_ += other->size();
            Node* nxt = it->next;
            it->next = other->head;
            if (nxt) {
                other->tail->next = nxt;
            }
            else {
                tail = other->tail;
            }
            other->size_ = 0;
            other->head = nullptr;
            break;
        }
    }
}

void Queue::displayToQListWidget(QListWidget* widget) {
    if (empty()) {
        return;
    }
    for (Node* it = head; it != tail->next; it = it->next) {
        QString tostr = QString::number(it->val);
        if (it == head) {
            tostr += "\t<- head";
        }
        if (it == tail) {
            tostr += "\t<- tail";
        }
        widget->addItem(tostr);
    }
}
