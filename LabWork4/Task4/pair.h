template<typename U, typename V>
class Pair {
public:
    U first;
    V second;

    Pair() = default;
    Pair(U f, V s): first(f), second(s) {}
};