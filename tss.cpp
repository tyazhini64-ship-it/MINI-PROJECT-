#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class PhraseBank {
public:
    string get() {
        vector<string> s = {"The quick brown fox jumps over the lazy dog while the moon shines brightly over the tranquil meadow", "A semicolon is a small character that can cause the biggest headaches in a source file.", "Practice makes perfect."};
        return s[rand() % 3];
    }
};

class Accuracy {
public:
    double calculate(string target, string input) {
        int correct = 0;
        for (int i = 0; i < target.length() && i < input.length(); i++) {
            if (target[i] == input[i]) correct++;
        }
        return (double)correct / target.length() * 100.0;
    }
};

class Calculator {
public:
    double calculateWPM(int len, double sec) {
        if (sec <= 0) return 0;
        return (len / 5.0) / (sec / 60.0);
    }
};

class Game {
    PhraseBank pb;
    Calculator calc;
    Accuracy acc;
public:
    void run() {
        string target = pb.get();
        string input;

        cout << "Type: " << target << endl;

        time_t start = time(0);
        getline(cin, input);
        time_t end = time(0);

        double duration = difftime(end, start);
        
        cout << "\n--- Results ---" << endl;
        cout << "Time: " << duration << "s" << endl;
        cout << "WPM: " << calc.calculateWPM(input.length(), duration) << endl;
        cout << "Accuracy: " << acc.calculate(target, input) << "%" << endl;
    }
};

int main() {
    srand(time(0));
    Game g;
    g.run();
    return 0;
}