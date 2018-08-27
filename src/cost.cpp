//
// Created by Ryan on 2018/8/26.
//

#include "cost.h"

/*
 * Initialize Cost
 */
Cost::Cost() {}

Cost::~Cost() {}

double Cost::calculate_cost() {
  vector<double> costs = {cost_f, cost_s, cost_l, cost_c, cost_e};
  vector<double> weights = {w_f, w_s, w_l, w_c, w_e};
  double total_cost = 0;
  for(int i=0; i<costs.size(); i++) {
    total_cost += costs[i] * weights[i];
  }
  return total_cost;
}

/* perception the surronding environment of our vehicle
 * via sensor fusion data
 * find the nearest in front and behind the vehicle
 * in the s direction in each lane

auto Cost::perception(auto sensor_fusion, int prev_size, double car_s) {

  // check each car data from sensor fusion
  for(int i=0; i < sensor_fusion.size(); i++) {
    // car is my lane
    float d = sensor_fusion[i][6];
    double vx = sensor_fusion[i][3];
    double vy = sensor_fusion[i][4];
    double check_speed = sqrt(vx*vx + vy*vy);
    double check_car_s = sensor_fusion[i][5];

    check_car_s += ((double)prev_size*.02*check_speed);  //if using previous points can s value out

    double check_distance = check_car_s - car_s;
    int check_lane;
    // find the lane
    check_lane = d / 4;
    // find the nearest distance between check_car and our vehicle in s direction
    if(check_distance>0 && check_distance < min_front_dis[check_lane]) {
      this -> min_front_dis[check_lane] = check_distance;
    }
    else if(check_distance<0 && check_distance>min_behind_dis[check_lane]) {
      this -> min_behind_dis[check_lane] = check_distance;
    }
  }
}

float Cost::keep_lane_cost(int lane, double ref_vel) {
  // reset costs
  cost_f = 0.0;
  cost_s = 0.0;
  cost_e = 0.0;
  // too close is in the danger of collision, reset the safety cost
  if(min_front_dis[lane]<30) {
    cost_s = 1.0;
  }
  // else reset the efficiency cost
  else {
    cost_e = static_cast<float>((49.5 - ref_vel) / 49.5);
    //cost_e = 1.0;
  }
  cost_kl = (float) w_f * cost_f + (float) w_s * cost_s + (float) w_e * cost_e;
  return 0;
}

float Cost::turn_left_cost(int lane, double ref_vel) {
  // reset costs
  cost_f = 0.0;
  cost_s = 0.0;
  cost_e = 0.0;
  // Feasibility Cost
  if(lane == 0) {
    // cannot turn left in lane 0
    cost_f = 1.0;
  }
  else{
    // Safety Cost
    if (min_front_dis[lane-1]<100 || min_behind_dis[lane-1]>-50) {
      cost_s = 1.0;
    }
  }
  cost_lcl = (float) w_f * cost_f + (float) w_s * cost_s + (float) w_e * cost_e;
  return 0;
}

float Cost::turn_right_cost(int lane, double ref_vel) {
  // reset costs
  cost_f = 0.0;
  cost_s = 0.0;
  cost_e = 0.0;
  // Feasibility Cost
  if(lane == 2) {
    // cannot turn right in lane 2
    cost_f = 1.0;
  }
  else{
    // Safety Cost
    if (min_front_dis[lane+1]<100 || min_behind_dis[lane+1]>-50) {
      cost_s = 1.0;
    }
    // Efficiency Cost: prefer turn left than turn right
    cost_e = 1.0;
  }
  cost_lcr = (float) w_f * cost_f + (float) w_s * cost_s + (float) w_e * cost_e;
  return 0;
}

int Cost::find_best_cost() {
  int lane_change;

  // find the best cost
  if (cost_lcl >= cost_kl) {
    if (cost_lcr >= cost_kl) {
      // KL cost is the smallest
      lane_change = 0;
    }
    else {  // cost_lcl < cost_kl
      if (cost_lcr >= cost_lcl) {
        // LCL cost is the smallest
        lane_change = -1;
      }
      else {
        // LCR cost is the smallest
        lane_change = 1;
      }
    }
  }
  return lane_change;
}
*/