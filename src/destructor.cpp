#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct Window
{
    virtual ~Window() { cout << "~Window" << endl; }
};

struct Panel
{
    Panel(Window& w){}
    ~Panel() { cout << "~Panel" << endl; }
};


class TabbedWindow : public Window
{
public:
    TabbedWindow(uint n) : nw{n}
    {
        for (uint i = 0; i < nw; ++i)
            panels.push_back(make_shared<Panel>(*this));
    }
    ~TabbedWindow()
    {
        cout << "~TabbedWindow" << endl;
    }
private:
    uint nw;
    vector<shared_ptr<Panel>> panels;
};


int main()
{
    TabbedWindow tb{5};
}

