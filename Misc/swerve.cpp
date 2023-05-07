using namespace std;
#include <bits/stdc++.h>
#define nl '\n'

signed main() {

    double leftx, lefty, rightx, gyro;
    cout << "Enter leftx, lefty, rightx, and gryo in that order" << nl;
    cin >> leftx >> lefty >> rightx >> gyro;

    gyro = gyro * M_PI/180;

    double strafex = (leftx * cos(gyro)) + (lefty * sin(gyro));
    double strafey = (lefty * cos(gyro)) - (leftx * sin(gyro));

    cout << strafex << " " << strafey << nl;

    double motion[4][2];

    for (int i = 0; i < 4; i++)
    motion[i][0] = strafex,
    motion[i][1] = strafey;

    double rot[4][2] = {};
    for (int i = 0; i < 4; i++)
    rot[i][0] = rightx * cos((double)(M_PI / 4.0 - (M_PI / 2 * i))),
    rot[i][1] = rightx * sin((double)(M_PI / 4.0 - (M_PI / 2 * i)));

    double final[4][2];
    for (int i = 0; i < 4; i++)
    for (int j = 0; j < 2; j++)
        final[i][j] = motion[i][j] + rot[i][j];

    double angle[4];
    double speed[4];

    for (int i = 0; i < 4; i++) {
    double ax = final[i][0];
    double ay = final[i][1];
    if (ax == 0 && ay == 0) {
        angle[i] = speed[i] = 0;
        continue;
    }
    if (ax == 0)
        angle[i] = M_PI / 2.0 * (abs(ay) / ay);
    else
        angle[i] = (ax) / (abs(ax)) * atan(ay / ax);
    speed[i] = sqrt((ax * ax) + (ay * ay));
    }
    cout<< nl;

    for (int i = 0; i < 4; i++)
    cout << "motor " << i + 1 << " is going at a speed of " << speed[i] << " "
            << " with an angle of " << angle[i] << nl;
    cout << nl;
    
}