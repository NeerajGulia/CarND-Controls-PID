#include "PID.h"

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_in, double Ki_in, double Kd_in) {
    Clear();
    Kp = Kp_in;
    Ki = Ki_in;
    Kd = Kd_in;
}

void PID::UpdateError(double cte) {
    double diff_cte = cte - prev_cte;
    p_error = Kp * cte;
    d_error = Kd * diff_cte;
    i_error = Ki * int_cte;
    int_cte += cte;
    prev_cte = cte;
}

double PID::TotalError() {
    return - p_error - i_error - d_error;
}

void PID::Clear(){
    p_error = d_error = i_error = prev_cte = int_cte = 0.0;
}

