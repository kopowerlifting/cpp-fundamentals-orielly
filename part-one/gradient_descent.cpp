// gradient_descent.cpp
// the first iteration of this program is just do simple coordinate descent to find the best fit line for a set of points
#include <iostream>
#include <vector>
#include <cmath>

// y_hat = mx + b
// we will use the mean squared error as our loss function
// MSE = (1/n) * sum((y_i - y_hat_i)^2)
// where n is the number of observations, y_i is the actual value, and y_hat_i is the predicted value

// latex would be MSE = \frac{\sum_{i=1}^{n} (y_i - \hat{y}_i)^2}{n}