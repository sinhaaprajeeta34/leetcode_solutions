class SmallestInfiniteSet {
    set<int> s;

public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) {
            s.insert(i);
        }
    }

    int popSmallest() {
        int x = *s.begin();
        s.erase(s.begin());
        return x;
    }

    void addBack(int num) {
        s.insert(num);
    }
};