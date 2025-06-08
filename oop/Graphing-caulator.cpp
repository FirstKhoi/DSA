#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

void plotGraph(vector<double>& graphPoints, int graphHeight, int graphWidth) {
    for (int y = graphHeight - 1; y >= 0; y--) {
        for (int x = 0; x < graphWidth; x++) {
            if (round(graphPoints[x]) == y) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }            
}

void drawAxis(int graphHeight, int graphWidth) {
    for (int x = 0; x < graphWidth; x++) {
        if (x == graphWidth / 2) {
            cout << "^";
        } else {
            cout << "-";
        }
    }
    cout << endl;

    for (int y = 0; y < graphHeight; y++) {
        if (y == graphHeight / 2) {
            cout << "|";
        } else {
            cout << " ";
        }
    }
    cout << endl;
}

vector<double> calculateGraph(double(*func)(double), int graphWidth, int graphHeight) {
    vector<double> graphPoints(graphWidth);

    double xCenter = graphWidth / 2.0;
    double yCenter = graphHeight / 2.0;

    for (int x = 0; x < graphWidth; x++) {
        double xValue = (x - xCenter) * 0.1;
        double yValue = func(xValue);
        
        int yGraph = round(yCenter + yValue * 5);
        if (yGraph >= 0 && yGraph < graphHeight) {
            graphPoints[x] = yGraph;
        } else {
            graphPoints[x] = -1;
        }
    }
    
    return graphPoints;
}

double line(double x) {
    return 2 * x + 1;
}

double quadratic(double x) {
    return x * x - 3 * x + 2;
}

double sineWave(double x) {
    return sin(x);
}

double cosineWave(double x) {
    return cos(x);
}

double logarithm(double x) {
    if (x <= 0) return NAN;
    return log(x);
}

int main() {
    int graphHeight = 20;
    int graphWidth = 50;

    cout << "Choose the function to graph:" << endl;
    cout << "1. Line (y = 2x + 1)" << endl;
    cout << "2. Quadratic (y = x^2 - 3x + 2)" << endl;
    cout << "3. Sine Wave (y = sin(x))" << endl;
    cout << "4. Cosine Wave (y = cos(x))" << endl;
    cout << "5. Logarithm (y = log(x))" << endl;
    cout << "Enter your choice (1-5): ";
    
    int choice;
    cin >> choice;

    double (*selectedFunction)(double) = nullptr;
    
    switch (choice) {
        case 1: selectedFunction = line; break;
        case 2: selectedFunction = quadratic; break;
        case 3: selectedFunction = sineWave; break;
        case 4: selectedFunction = cosineWave; break;
        case 5: selectedFunction = logarithm; break;
        default: 
            cout << "Invalid choice!" << endl;
            return 1;
    }
    
    vector<double> graphPoints = calculateGraph(selectedFunction, graphWidth, graphHeight);

    drawAxis(graphHeight, graphWidth);
    plotGraph(graphPoints, graphHeight, graphWidth);

    return 0;
}
