#include <iostream>
using namespace std;

class Event {
protected:
    char *name;
    int dur;
    static int eventCount;

public:
    Event() {
        name = new char[30];
        dur = 0;
        eventCount++;
    }

    Event(const char *n, int d) {
        name = new char[30];
        int i = 0;
        while (n[i] != '\0') {
            name[i] = n[i];
            i++;
        }
        name[i] = '\0';
        dur = d;
        eventCount++;
    }

    Event(const Event &e) {
        name = new char[30];
        int i = 0;
        while (e.name[i] != '\0') {
            name[i] = e.name[i];
            i++;
        }
        name[i] = '\0';
        dur = e.dur;
    }

    virtual ~Event() {
        delete[] name;
        eventCount--;
    }

    virtual void show() const {
        cout << "Event: " << name << ", Duration: " << dur << " hrs" << endl;
    }

    static int getEventCount() {
        return eventCount;
    }
};

int Event::eventCount = 0;

class TechEvent : public Event {
private:
    int parts;

public:
    static int techEventCount;

    TechEvent() : Event() {
        parts = 0;
        techEventCount++;
    }

    void inputTechEvent() {
        cout << "Enter Tech Event Name: ";
        cin >> name;
        cout << "Enter Duration (hrs): ";
        cin >> dur;
        cout << "Enter Number of Participants: ";
        cin >> parts;
    }

    void show() const override {
        cout << "Tech Event - ";
        Event::show();
        cout << "Participants: " << parts << endl;
    }
};
int TechEvent::techEventCount = 0;

class CultEvent : public Event {
private:
    char theme[20];
    int parts;

public:
    static int cultEventCount;

    CultEvent() : Event() {
        parts = 0;
        cultEventCount++;
    }

    void inputCultEvent() {
        cout << "Enter Cultural Event Name: ";
        cin >> name;
        cout << "Enter Duration (hrs): ";
        cin >> dur;
        cout << "Enter Theme: ";
        cin >> theme;
        cout << "Enter Number of Participants: ";
        cin >> parts;
    }

    void show() const override {
        cout << "Cultural Event - ";
        Event::show();
        cout << "Theme: " << theme << ", Participants: " << parts << endl;
    }
};
int CultEvent::cultEventCount = 0;

class Part {
private:
    char name[30];
    int age;
    float score;
    static int partCount;

public:
    Part() {
        age = 0;
        score = 0;
        partCount++;
    }

    void inputPart() {
        cout << "Enter Participant Name: ";
        cin >> name;
        cout << "Enter Participant Age: ";
        cin >> age;
        cout << "Enter Participant Score: ";
        cin >> score;
    }

    void show() const {
        cout << "Participant: " << name << ", Age: " << age << ", Score: " << score << endl;
    }

    float getScore() const {
        return score;
    }

    static int getPartCount() {
        return partCount;
    }
};
int Part::partCount = 0;

int main() {
    int techEventNum, cultEventNum, partNum;
    cout << "How many Tech Events were conducted? ";
    cin >> techEventNum;

    TechEvent *techEvents = new TechEvent[techEventNum];
    for (int i = 0; i < techEventNum; i++) {
        cout << "\n--- Enter Details for Tech Event " << (i + 1) << " ---\n";
        techEvents[i].inputTechEvent();
    }

    cout << "\nHow many Cultural Events were conducted? ";
    cin >> cultEventNum;

    CultEvent *cultEvents = new CultEvent[cultEventNum];
    for (int i = 0; i < cultEventNum; i++) {
        cout << "\n--- Enter Details for Cultural Event " << (i + 1) << " ---\n";
        cultEvents[i].inputCultEvent();
    }

    cout << "\nHow many participants registered? ";
    cin >> partNum;

    Part *participants = new Part[partNum];
    for (int i = 0; i < partNum; i++) {
        cout << "\n--- Enter Details for Participant " << (i + 1) << " ---\n";
        participants[i].inputPart();
    }

    float highestScore = -1;
    int winnerIndex = -1;
    for (int i = 0; i < partNum; i++) {
        if (participants[i].getScore() > highestScore) {
            highestScore = participants[i].getScore();
            winnerIndex = i;
        }
    }

    cout << "\n--- Displaying All Events and Participants ---\n";

    for (int i = 0; i < techEventNum; i++) {
        cout << "\n[Tech Event " << (i + 1) << "]\n";
        techEvents[i].show();
    }

    for (int i = 0; i < cultEventNum; i++) {
        cout << "\n[Cultural Event " << (i + 1) << "]\n";
        cultEvents[i].show();
    }

    cout << "\n--- Participant Details ---\n";
    for (int i = 0; i < partNum; i++) {
        participants[i].show();
    }

    if (winnerIndex != -1) {
        cout << "\nThe Winner is:\n";
        participants[winnerIndex].show();
    } else {
        cout << "\nNo participants found.\n";
    }

    cout << "\nTotal Tech Events: " << TechEvent::techEventCount << endl;
    cout << "Total Cultural Events: " << CultEvent::cultEventCount << endl;
    cout << "Total Participants: " << Part::getPartCount() << endl;

    delete[] techEvents;
    delete[] cultEvents;
    delete[] participants;

    return 0;
}
