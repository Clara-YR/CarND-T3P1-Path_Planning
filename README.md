[//]: # (Image References)

[image0]: ./Cost_Function.jpg "how cost function work"


# CarND-Path-Planning-Project

**My Dependencies**

- cmake (>= 3.5)
- make (>= 4)
- gcc/g++ >= 5.4
- uWebSockets
	- Run either `install-mac.sh` (or `install-ubuntu.sh`)
	- If you install from source, checkout to commit e94b6e1, i.e.
	
		```
		git clone https://github.com/uWebSockets/uWebSockets 
	cd uWebSockets
	git checkout e94b6e1
		```

**Simulator**

You can download the Term3 Simulator which contains the Path Planning Project from this [link] (https://github.com/udacity/self-driving-car-sim/releases/tag/T3_v1.2).

**Busic Build**

1. Clone the repo from this [link](https://github.com/udacity/CarND-Path-Planning-Project)
(run `sh install-mac.sh` at first)
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./path_planning`.

# Procedure of Path Planning

__Localization >> Prediction >> Behavior Planning >> Trjectory Generation__

# Behavior Planning

- Cost Function
- Check Lane Logic

## Cost Fuction

I create a new class `Cost` in order to update cost while checking sensor fusion data.

**Feasibility >> Safety >> Legality >> Comfort >> Efficiency**

I set weights for different factors of influence as bellow to follow the above order of importance.

|FACTORS|Feasibily|Safety|Legality|Comfort|Efficiency|
|:---:|:-------:|:----:|:------:|:-----:|:--------:|
|VARIABLES|`w_f`|`w_s`|`w_l`|`w_c`|`w_e`|
|WEIGHTS|10 000|1000|100|10|1|

## Check Lane Logic

- __KL__ -- Keep Lane
- __LCL__ -- Lane Change Left
- __LCR__ -- Lane Change Right

I make a table to demonstrate how my cost function choose the best cost in different conditions.

![alt text][image0]

To be spefic, below is the structure of my code logic to perspective the surronding conditionsby sensor fusion data, and update costs for behaviors accordingly. 

-  __Too Close__ -- The car infront of us is too close(with 30 meters).
	- __Feasibility & our `lane`__ 
		- unfeasible to turn left when `lane = 0`
		- unfeasible to turn right when `lane = 2`
	- __Safety & cars in adjacent lane__

- __Far Enough__ -- The car in foront of us is far away enough(futher than 30 meters).
	- __update LCL & LCR cost__ -- 


**Tips**

_When check front cars_

1. Only check car in the same lane for bool `too_close`. 
2. Use `continue` to break the current for loop and jump to the next step when `too_close = true`

_When check adjacent cars_

1. Only check the adjecent car when `too_close = true`
2. There is no need to know our own `lane` since we only need to the relative lane position via `check_lane - lane`. 

# Trjectory Generation

Take use of 'spline' library instread of quintic polynomial  as it's eariser to generate smooth and comfort trajectory.
	


