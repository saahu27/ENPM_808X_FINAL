/**
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/TDD.hpp"

#include <cmath>

void controller::PID::SetterErrorPrevious(double Error) {
  errorPrevious_ = Error;
}

double controller::PID::GetterErrorPrevious() { return errorPrevious_; }

void controller::PID::SetterErrorIntegral(double Error) {
  errorIntegral_ = Error;
}

double controller::PID::GetterErrorIntegral() { return errorIntegral_; }

double controller::PID::ComputeVel(double targetVel, double currentVel) {
  double error = targetVel - currentVel;

  double p_term = kp_ * error;

  double integral = GetterErrorIntegral();
  integral += error * dt_;
  double i_term = ki_ * integral;
  SetterErrorIntegral(integral);

  double prev_error = GetterErrorPrevious();
  double derivative = (error - prev_error) / dt_;
  double d_term = kd_ * derivative;
  SetterErrorPrevious(error);

  double output = p_term + i_term + d_term;
  return output;
}

double controller::PID::RunController(double targetVel, double currentVel) {

  return currentVel;
}