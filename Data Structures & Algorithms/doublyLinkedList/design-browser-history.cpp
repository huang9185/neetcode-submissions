struct N{
    N* p;
    N* n;
    string url;
};
class BrowserHistory {
    N* cur;
public:
    BrowserHistory(string homepage) {
        cur = new N{nullptr, nullptr, homepage};
    }
    
    void visit(string url) {
        N* tmp = new N{cur, nullptr, url};
        cur->n = tmp;
        cur = tmp;
    }
    
    string back(int steps) {
        for (int s = steps; s > 0 && cur->p; --s) cur = cur->p;
        return cur->url;
    }
    
    string forward(int steps) {
        for (int s = steps; s > 0 && cur->n; --s) cur = cur->n;
        return cur->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

