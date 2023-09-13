#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<double> x_values;
    vector<double> y_values;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        x_values.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        double y;
        cin >> y;
        y_values.push_back(y);
    }

//    for (int i = 0; i < n; i++) {
//        cout << x_values[i] << " " << y_values[i] << endl;
//    }

    double zigmaX = 0;
    double zigmaY = 0;
    for (int i = 0; i < n; i++) {
        zigmaX += x_values[i];
        zigmaY += y_values[i];
    }

    double xMean = zigmaX / n;
    double yMean = zigmaY / n;

    double xMinusXBar = 0;
    double yMinusYBar = 0;

    double xMinusXBarSquared = 0;
    double yMinusYBarSquared = 0;

    double xMinusXBarTimesYMinusYBar = 0;

    for (int i = 0; i < n; i++) {
        double first = (x_values[i] - xMean);
        double second = (y_values[i] - yMean);
        xMinusXBar += first;
        yMinusYBar += second;
        xMinusXBarSquared += pow(first, 2);
        yMinusYBarSquared += pow(second, 2);
        xMinusXBarTimesYMinusYBar += (first * second);
    }

    double numerator = xMinusXBarTimesYMinusYBar;
    double denominator = sqrt(xMinusXBarSquared * yMinusYBarSquared);

    double r_value = numerator / denominator;

    cout << "r value is: " << r_value << endl;

    double betaHat = xMinusXBarTimesYMinusYBar / xMinusXBarSquared;
    double alphaHat = yMean - (betaHat * xMean);

    cout << "Simple Linear Regression equation is: ";
    cout << "YHat = " << alphaHat << " + " << betaHat << " * Xi" << endl;

    return 0;
}