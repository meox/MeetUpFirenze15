#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Window
{
public:
    ~Window() { cout << "~Window" << endl; }
};

struct Panel
{
    Panel(uint id) {
        _name = string{"p_"} + to_string(id);
    }
    ~Panel() { cout << "~Panel: " << _name << endl; }
private:
    string _name;
};


class TabbedWindow : public Window
{
public:
    TabbedWindow(uint n)
    {
        for (uint id = 0; id < n; ++id)
            panels.push_back(make_unique<Panel>(id));
    }

    ~TabbedWindow()
    {
        cout << "~TabbedWindow" << endl;
    }
private:
    vector<unique_ptr<Panel>> panels;
    shared_ptr<Panel> main_panel{new Panel(42)};
};


int main()
{
    cout << "Step 1" << endl;
    {
        TabbedWindow mytab{3};
    }

    cout << "Step 2" << endl;
    {
        Window* w = new TabbedWindow(3);
        delete w;
    }

    cout << "Step 3" << endl;
    {
        //unique_ptr<Window> w = make_unique<TabbedWindow>(3);
        auto w = unique_ptr<Window>(new TabbedWindow(3));
    }

    cout << "Step 4" << endl;
    {
        //shared_ptr<Window> w = make_shared<TabbedWindow>(3);
        auto w = shared_ptr<Window>(new TabbedWindow(3));
    }
}

