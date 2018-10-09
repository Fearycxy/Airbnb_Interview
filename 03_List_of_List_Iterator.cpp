
class ListIterator {
public:

    class InnerIterator {
    public:
        int s;

        InnerIterator(int f) {
            s = f;
        }

        InnerIterator *next() {
            return nextIt;
        }

        bool hasNext() {
            return nextIt != NULL;
        }

        InnerIterator *nextIt;
    };

    typedef InnerIterator *Iterator;

    int next() {
        start = start->next();
        return start->s;
    }

    bool hasNext() {
        return start->next() != NULL;
    }


    Iterator begin() {
        return head;
    }

    ListIterator(vector<vector<int>> &vec) {
        head = new InnerIterator(0);
        Iterator cur = head;
        for (auto &f:vec) {
            for (int i:f) {
                cur->nextIt = new InnerIterator(i);
                cur = cur->next();
            }
        }
        start = head;
    }

    void remove() {
        Iterator f = start->next();
        if (!f) return;
        start = f->next();
        delete f;
    }

private:
    Iterator start;
    Iterator head;
};

int main() {
    vector<vector<int>> vec = {{0, 0, 1, 2, 3},
                               {2, 3, 4, 5, 6}};
    ListIterator iterator1(vec);
    while (iterator1.hasNext()) {
        cout << iterator1.next() << endl;
    }
    return 0;
}
