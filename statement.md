# Need for Speed: Energy Shift Challenge

In _Need for Speed: Energy Shift_, an immersive racing game, you find yourself behind the wheel of a high-performance car, aiming to blitz through a straight racetrack that stretches from point `0` to a point `L`. The challenge, however, isn't as straightforward as it appears to be.

Scattered between the starting point and your finish line are `n` speed-up pads, each having its unique attributes. The `i`-th speed-up pad on your path begins at point `x_i`, concludes at point `y_i`, and delivers a speed boost of `s_i` units to your car as you drive over it. These speed-up pads do not overlap and are positioned strictly within the boundaries of `[0, L]`. They could potentially be back-to-back but never intermingle.

Your car is equipped with an energy system that must be managed with precision to make the most of the race. Starting with zero energy, you must ensure that the energy levels don't dip into the negative. Your car's speed, denoted by `v`, is adjustable at any given moment within the range `[0, 2]`. Changing your speed has a direct impact on your energy consumption - increasing speed increases energy consumption at a rate of `v` units per second.

Here's where things get interesting. Your car has an energy regeneration feature that restores energy at a rate of `1` unit per second. This means that while your energy depletes at a rate of `v` units per second, it also regenerates at a fixed rate, resulting in a net energy change of `(1-v)` units per second. This could translate into energy recovery when `v` is less than `1` or energy depletion when `v` exceeds `1`.

To illustrate, maintaining a constant speed of `1` will stabilize your energy levels as the consumption equals regeneration. Lowering your speed to `0.77`, on the other hand, results in energy generation at a rate of `0.23` units per second as the regeneration outpaces the consumption.

The control is in your hands. You have the freedom to modulate your speed at any moment, even at non-integer positions, within the limit `[0, 2]`. Bear in mind that every component in this race, including your speed, energy level, and the use of speed-up pads, operates continuously and not in a step-by-step manner.

Given these parameters, your task is to strategize and find the quickest way to traverse from point `0` to point `L`. Good luck, and may speed be with you!

# Input

The first line of the input comprises of two integers, `n` and `L` `(1≤n≤200000, 1≤L≤10^9)`, signifying the count of speed-up pads on the track and the total length of the track, respectively.

Following this, there are $n$ lines of input, each containing two integers `x_i`, `y_i`, and a real value `s_i` `(0≤x_i<y_i≤L, 0.1≤s_i≤10.0)`. These values represent the starting point, ending point, and speed increase value of the $i$-th speed-up pad. The speed increase value `s_i` is presented with up to `9` digits precision after the decimal point.

It is ensured that none of the speed-up pads overlap or intersect positively. They are ordered in the input from their position on the track, from the start to end. In other words, for `1≤i≤n−1`, the end point `y_i` of a pad is less than or equal to the starting point $x_i+1$ of the next pad.

# Output

The output should consist of a single real number that represents the minimum time required to complete the track from point `0` to `L`. Your answer will be deemed acceptable if the absolute or relative deviation from the correct answer does not surpass `10^-9`.
