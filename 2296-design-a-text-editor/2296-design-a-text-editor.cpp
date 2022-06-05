class TextEditor {
public:
    string before, after;
    void addText(string text) {
        before.insert(end(before), begin(text), end(text));
    }
    int deleteText(int k) {
        k = min(k, (int)before.size());
        before.resize(before.size() - k);
        return k;
    }
    string cursorLeft(int k) {
        while(k-- && !before.empty()) {
            after.push_back(before.back());
            before.pop_back();
        }
        return before.substr(before.size() - min((int)before.size(), 10));
    }
    string cursorRight(int k) {
        while(k-- && !after.empty()) {
            before.push_back(after.back());
            after.pop_back();
        }
        return before.substr(before.size() - min((int)before.size(), 10));
    }
};
