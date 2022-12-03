/**
 * @file pid.hpp
 * @author Sahruday Patti (sahruday@umd.edu)
 * @brief header file
 * @version 0.1
 * @date 2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef INCLUDE_TDD_HPP_
#define INCLUDE_TDD_HPP_

#include <iostream>

/** @namespace controller TDD.hpp
 *  "include/../include/TDD.hpp"
 *  @brief Utility functions for PID
 */

namespace controller {
/**
 * @brief class PID contains utility functions for developing a PID controller
 */
class PID {
 public:
  /**
   * @brief current goal point
   * @param setPoint_ current set point updated
  */
  float setPoint_ = 0.0;

  /**
   * @brief Getter for private variable errorPrevious_
   * @return errorPrevious_
   */

  double GetterError();

  /**
   * @brief Setter for private variable errorPrevious_
   * @param Error the present error at the end of loop is set as previous error
   */

  void SetterError(double Error);

  /**
   * @brief Getter for private variable errorIntegral_
   * @return errorIntegral_
   */

  double GetterErrorIntegral();

  /**
   * @brief Setter for private variable errorPrevious_
   * @param Error the present error at the end of loop is added to integral
   * error
   */

  void SetterErrorIntegral(double Error);

  /**
   * @brief method to compute PID Output
   * @param targetVel the velocity to which we need to converge
   * @param currentVel the current velocity
   * @return CurrentVel after output
   */

  double RunController(double error_);

 private:
  /**
   * @brief integral constant chosen
   * @param ki_ private variable chosen
   */
  const double ki_ = 0.1;
  /**
   * @brief proportional constant chosen
   * @param kp_ private variable chosen and set
   */
  const double kp_ = 0.01;  //

  /**
   * @brief derivative constant chosen
   * @param kd_ private variable chosen and set
   */
  const double kd_ = 0.001;

  /**
   * @brief variable to update the previous error
   * @param error_
   */
  double error_;
  /**
   * @brief variable to update the integral error
   * @param errorIntegral_
   */
  double errorIntegral_;

  /**
   * @brief variable to update the integral error
   * @param errorPrevious_
   */
  double errorPrevious_;

};
}  // namespace controller

#endif  // INCLUDE_TDD_HPP_