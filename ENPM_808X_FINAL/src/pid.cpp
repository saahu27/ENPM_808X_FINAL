/**
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/pid.hpp"

#include <cmath>

void controller::PID::SetterError(double Error) {
  error_= Error;
}

double controller::PID::GetterError() { return error_; }

void controller::PID::SetterErrorIntegral(double Error) {
  errorIntegral_ = Error;
}

double controller::PID::GetterErrorIntegral() { return errorIntegral_; }

double controller::PID::Compute(double Error) {

  SetterError(Error);
  error_ = GetterError();

  double P = kp_ * error_;
  double D = kd_ * ( error_ - errorPrevious_ ) * dt;

  errorPrevious_ = error_;

  errorIntegral_ = GetterErrorIntegral();
  errorIntegral_ = errorIntegral_ + error_;

  if (errorIntegral_ > errorIntegralMax_) {
    errorIntegral_ = errorIntegralMax_ ;
  }
  else if (errorIntegral_ < errorIntegralMin_) {
  errorIntegral_ = errorIntegralMin_;
  }
  SetterErrorIntegral(errorIntegral_);

  double I = ki_ * errorIntegral_ ;

  double pid = P + I + D ;

  return pid;
}