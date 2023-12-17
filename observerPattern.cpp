#include <iostream>
#include <vector>
#include <algorithm>

class Observer;

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update() = 0;
};

class Subject {
public:
    virtual ~Subject() = default;

    virtual void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    virtual void removeObserver(Observer* observer) {
        // Remove observer from the collection
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    virtual void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update();
        }
    }

    virtual int getState() const {
        return state;
    }

    virtual void setState(int newState) {
        state = newState;
        notifyObservers();
    }

private:
    int state;
    std::vector<Observer*> observers;
};

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(Subject* subject) : subject(subject) {
        subject->addObserver(this);
    }

    ~ConcreteObserver() override {
        subject->removeObserver(this);
    }

    void update() override {
        int newState = subject->getState();
        std::cout << "Observer updated with new state: " << newState << std::endl;
    }

private:
    Subject* subject;
};


int main() {
    Subject subject;
    ConcreteObserver observer1(&subject);
    ConcreteObserver observer2(&subject);

    subject.setState(10);

    return 0;
}
