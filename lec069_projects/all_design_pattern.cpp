#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <algorithm>

using namespace std;

// === Creational Patterns ===
// 1. Singleton
class Singleton {
    static Singleton* instance;
    Singleton() {}
public:
    static Singleton* getInstance() {
        if (!instance) instance = new Singleton();
        return instance;
    }
};
Singleton* Singleton::instance = nullptr;

// 2. Factory Method
class Product {
public: virtual void use() = 0;
};
class ConcreteProduct : public Product {
public: void use() override { cout << "Using Product\n"; }
};
class Creator {
public:
    Product* factoryMethod() { return new ConcreteProduct(); }
};

// 3. Abstract Factory
class Button { public: virtual void render() = 0; };
class WinButton : public Button { public: void render() override { cout << "Windows Button\n"; }};
class MacButton : public Button { public: void render() override { cout << "Mac Button\n"; }};
class GUIFactory {
public: virtual Button* createButton() = 0; 
};
class WinFactory : public GUIFactory {
public: Button* createButton() override { return new WinButton(); }
};
class MacFactory : public GUIFactory {
public: Button* createButton() override { return new MacButton(); }
};

// 4. Builder
class ProductBuilder {
    string parts;
public:
    ProductBuilder& addPart(const string& part) { parts += part + " "; return *this; }
    string getResult() { return parts; }
};

// 5. Prototype
class Prototype {
public:
    virtual Prototype* clone() = 0;
};
class ConcretePrototype : public Prototype {
    string data;
public:
    ConcretePrototype(string d) : data(d) {}
    Prototype* clone() override { return new ConcretePrototype(*this); }
    void show() { cout << "Data: " << data << endl; }
};

// === Structural Patterns ===
// 6. Adapter
class Target {
public: virtual void request() = 0;
};
class Adaptee {
public: void specificRequest() { cout << "Specific request\n"; }
};
class Adapter : public Target {
    Adaptee* adaptee;
public:
    Adapter(Adaptee* a) : adaptee(a) {}
    void request() override { adaptee->specificRequest(); }
};

// 7. Bridge
class Implementor {
public: virtual void operationImpl() = 0;
};
class ConcreteImpl : public Implementor {
public: void operationImpl() override { cout << "ConcreteImpl\n"; }
};
class Abstraction {
protected: Implementor* impl;
public:
    Abstraction(Implementor* i) : impl(i) {}
    void operation() { impl->operationImpl(); }
};

// 8. Composite
class Component {
public:
    virtual void operation() = 0;
};
class Leaf : public Component {
public: void operation() override { cout << "Leaf\n"; }
};
class Composite : public Component {
    vector<Component*> children;
public:
    void add(Component* c) { children.push_back(c); }
    void operation() override {
        for (auto c : children) c->operation();
    }
};

// 9. Decorator
class Notifier {
public: virtual void send() = 0;
};
class BasicNotifier : public Notifier {
public: void send() override { cout << "Sending Notification\n"; }
};
class NotifierDecorator : public Notifier {
protected: Notifier* wrappee;
public:
    NotifierDecorator(Notifier* n) : wrappee(n) {}
    void send() override { wrappee->send(); }
};
class SMSDecorator : public NotifierDecorator {
public:
    SMSDecorator(Notifier* n) : NotifierDecorator(n) {}
    void send() override {
        NotifierDecorator::send();
        cout << "Sending SMS\n";
    }
};

// 10. Facade
class SubSystem1 { public: void doWork() { cout << "Subsystem1\n"; } };
class SubSystem2 { public: void doWork() { cout << "Subsystem2\n"; } };
class Facade {
    SubSystem1 s1;
    SubSystem2 s2;
public:
    void operation() {
        s1.doWork();
        s2.doWork();
    }
};

// 11. Flyweight
class Flyweight {
    string state;
public:
    Flyweight(string s) : state(s) {}
    void operation() { cout << "Flyweight with " << state << "\n"; }
};
class FlyweightFactory {
    map<string, Flyweight*> pool;
public:
    Flyweight* getFlyweight(string key) {
        if (!pool[key]) pool[key] = new Flyweight(key);
        return pool[key];
    }
};

// 12. Proxy
class Subject {
public: virtual void request() = 0;
};
class RealSubject : public Subject {
public: void request() override { cout << "RealSubject Request\n"; }
};
class Proxy : public Subject {
    RealSubject* real;
public:
    Proxy() { real = new RealSubject(); }
    void request() override { cout << "Proxy: "; real->request(); }
};

// === Behavioral Patterns ===
// 13. Chain of Responsibility
class Handler {
protected: Handler* next = nullptr;
public:
    void setNext(Handler* n) { next = n; }
    virtual void handle(int val) {
        if (next) next->handle(val);
    }
};
class ConcreteHandler : public Handler {
public:
    void handle(int val) override {
        if (val < 10) cout << "Handled by ConcreteHandler\n";
        else Handler::handle(val);
    }
};

// 14. Command
class Command {
public: virtual void execute() = 0;
};
class Receiver {
public: void action() { cout << "Receiver Action\n"; }
};
class ConcreteCommand : public Command {
    Receiver* r;
public:
    ConcreteCommand(Receiver* r) : r(r) {}
    void execute() override { r->action(); }
};

// 15. Interpreter
class Expression {
public: virtual int interpret() = 0;
};
class Number : public Expression {
    int value;
public:
    Number(int v) : value(v) {}
    int interpret() override { return value; }
};

// 16. Iterator
class Iterator {
    vector<int>& data;
    size_t index = 0;
public:
    Iterator(vector<int>& d) : data(d) {}
    bool hasNext() { return index < data.size(); }
    int next() { return data[index++]; }
};

// 17. Mediator
class Mediator;
class Colleague {
protected: Mediator* mediator;
public: Colleague(Mediator* m) : mediator(m) {}
};
class Mediator {
public: virtual void notify(Colleague* sender, string event) = 0;
};
class ConcreteColleague : public Colleague {
public:
    ConcreteColleague(Mediator* m) : Colleague(m) {}
    void triggerEvent() { mediator->notify(this, "Event"); }
};
class ConcreteMediator : public Mediator {
public:
    void notify(Colleague*, string e) override { cout << "Mediator handles: " << e << endl; }
};

// 18. Memento
class Memento {
    string state;
public:
    Memento(string s) : state(s) {}
    string getState() { return state; }
};
class Originator {
    string state;
public:
    void setState(string s) { state = s; }
    Memento* save() { return new Memento(state); }
    void restore(Memento* m) { state = m->getState(); }
    void show() { cout << "State: " << state << endl; }
};

// 19. Observer
class Observer {
public: virtual void update(string msg) = 0;
};
class SubjectObs {
    vector<Observer*> observers;
public:
    void attach(Observer* o) { observers.push_back(o); }
    void notify(string msg) {
        for (auto o : observers) o->update(msg);
    }
};
class ConcreteObserver : public Observer {
public: void update(string msg) override { cout << "Received: " << msg << endl; }
};

// 20. State
class State {
public: virtual void handle() = 0;
};
class Context {
    State* state;
public:
    Context(State* s) : state(s) {}
    void request() { state->handle(); }
};
class ConcreteState : public State {
public: void handle() override { cout << "Concrete State\n"; }
};

// 21. Strategy
class Strategy {
public: virtual void execute() = 0;
};
class ConcreteStrategy : public Strategy {
public: void execute() override { cout << "Strategy executed\n"; }
};
class ContextStrat {
    Strategy* strategy;
public:
    ContextStrat(Strategy* s) : strategy(s) {}
    void doJob() { strategy->execute(); }
};

// 22. Template Method
class AbstractClass {
public:
    void templateMethod() {
        step1();
        step2();
    }
    virtual void step1() { cout << "Step 1\n"; }
    virtual void step2() = 0;
};
class ConcreteClass : public AbstractClass {
public: void step2() override { cout << "Step 2\n"; }
};

// 23. Visitor
class Element;
class Visitor {
public: virtual void visit(Element* e) = 0;
};
class Element {
public: virtual void accept(Visitor* v) = 0;
};
class ConcreteElement : public Element {
public:
    void accept(Visitor* v) override { v->visit(this); }
};
class ConcreteVisitor : public Visitor {
public:
    void visit(Element* e) override { cout << "Visited Element\n"; }
};

// === Main Function ===
int main() {
    cout << "=== All Design Patterns in One File ===\n";

    Singleton::getInstance();
    Creator().factoryMethod()->use();
    MacFactory().createButton()->render();
    cout << ProductBuilder().addPart("A").addPart("B").getResult() << endl;
    ConcretePrototype("demo")->clone()->show();

    Adapter(new Adaptee()).request();
    Abstraction(new ConcreteImpl()).operation();
    Composite comp; comp.add(new Leaf()); comp.operation();
    SMSDecorator(new BasicNotifier()).send();
    Facade().operation();
    FlyweightFactory().getFlyweight("A")->operation();
    Proxy().request();

    ConcreteHandler h1; Handler h2; h1.setNext(&h2); h1.handle(5);
    Receiver r; ConcreteCommand(&r).execute();
    cout << Number(10).interpret() << endl;
    vector<int> v = {1, 2}; Iterator it(v); while (it.hasNext()) cout << it.next() << " ";
    cout << endl;
    ConcreteMediator mediator; ConcreteColleague c(&mediator); c.triggerEvent();
    Originator o; o.setState("old"); auto m = o.save(); o.setState("new"); o.restore(m); o.show();
    SubjectObs s; ConcreteObserver o1; s.attach(&o1); s.notify("Hi!");
    Context(new ConcreteState()).request();
    ContextStrat(new ConcreteStrategy()).doJob();
    ConcreteClass().templateMethod();
    ConcreteElement().accept(new ConcreteVisitor());

    return 0;
}
