#include <iostream>
#include <vector>
#include <cmath>

// Activation function (Sigmoid)
double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

// Derivative of sigmoid (for backpropagation)
double sigmoid_derivative(double x) {
    return x * (1 - x);
}

// Main function for training a single-layer neural network
int main() {
    // Input data (XOR problem)
    std::vector<std::vector<double>> inputs = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    std::vector<double> outputs = {0, 1, 1, 0}; // Expected XOR outputs

    // Weights initialization (random values)
    double weights[2] = {0.5, -0.5}; // Example values, you can randomize these
    double bias = 0.0;
    double learning_rate = 0.1;

    // Training the neural network
    for (int epoch = 0; epoch < 10000; ++epoch) {
        for (size_t i = 0; i < inputs.size(); ++i) {
            double sum = bias;
            for (size_t j = 0; j < inputs[i].size(); ++j) {
                sum += inputs[i][j] * weights[j];
            }
            double output = sigmoid(sum);

            // Calculate the error
            double error = outputs[i] - output;

            // Backpropagation to adjust weights and bias
            for (size_t j = 0; j < inputs[i].size(); ++j) {
                weights[j] += learning_rate * error * sigmoid_derivative(output) * inputs[i][j];
            }
            bias += learning_rate * error * sigmoid_derivative(output);
        }
    }

    // Print the results
    std::cout << "Trained Weights: " << weights[0] << ", " << weights[1] << std::endl;
    std::cout << "Trained Bias: " << bias << std::endl;

    // Test the neural network
    std::cout << "\nTesting the Neural Network:" << std::endl;
    for (const auto& input : inputs) {
        double sum = bias;
        for (size_t j = 0; j < input.size(); ++j) {
            sum += input[j] * weights[j];
        }
        double output = sigmoid(sum);
        std::cout << "Input: " << input[0] << ", " << input[1] << " -> Output: " << output << std::endl;
    }

    return 0;
}
