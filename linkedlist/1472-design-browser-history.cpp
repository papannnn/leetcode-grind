// I didn't free the memory cuz I'm lazy lol

struct Node {
    string url;
    Node* next;
    Node* prev;

    Node(string _url): url{_url}, next{nullptr}, prev{nullptr} {}
};

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        head = new Node(homepage);
        curr = head;
    }
    
    void visit(string url) {
        curr->next = new Node(url);
        curr->next->prev = curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        while (curr->prev != nullptr && steps--) {
            curr = curr->prev;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while (curr->next != nullptr && steps--) {
            curr = curr->next;
        }
        return curr->url;
    }

private:
    Node* head;
    Node* curr;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */